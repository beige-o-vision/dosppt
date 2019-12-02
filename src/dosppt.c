/*
  dosppt - a simple presentation framework for text-based interfaces
  Copyright 2019 Colin Eby

  LICENSE GPL v3
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>
*/

#include <stdio.h>

#define JUMP_TOP 	"\033[0;0H"
#define RESET_MODE 	"\033[2J"

struct slide
{
  char *slide_file[12];
  int delay;
  int transition;
};

int load_config ( char *config_file[] );
int display_slide ( struct slide next_slide );
void display_vertical_wipe( char *sbuf[] );
void display_scroll_wipe( char *sbuf[] );

struct slide slide_show[100];
int slide_count=0;
int current_slide=0;

int main ( int *argc, char *argv[] )
{
 load_config(argv[1]);
 while(1){
  if(current_slide == slide_count) current_slide=0;
  display_slide(slide_show[current_slide]);
  current_slide ++;
 }
 printf("Done.\n");
 return 0;
}

int display_slide ( struct slide next_slide )
{
  int sleep, c, lines, sbuf_len, sbuf_index, j;
  char sbuf[3840];
  char *p_sbuf = &sbuf;
  FILE *f;

  lines = 0;
  sbuf_index = 0;

  /* Read the slide file character by character.  This allows
     the parsing of line ends and EOF characters
  */

  f = fopen( next_slide.slide_file, "rb" );
  while( (c = getc(f)) != EOF  ){

    /* Check for EOF character */
    if( c == 26 ) break;

    /* Stop reading after 25 lines */
    if( c == 0x0A ) lines++;
    if( lines==25 ) break;

    /* Otherwise advance the buffer index
       and come around again
    */
    sbuf[sbuf_index] = c;
    sbuf_index++;

  }

  /* Add a string terminator to the end so
     _fputs_ knows where to stop.
  */
  sbuf[sbuf_index]='\0';

  fclose(f);

  /* Render the slide by:
     1. resetting all modes
     2. running the transition
     3. sleeping
  */

  /* Reset */
  fputs( RESET_MODE, stdout );

  /* Pick a transition */
  if ( next_slide.transition == 3 )
  {
    display_vertical_wipe(&sbuf);
  }
  else
  {
    display_scroll_wipe(&sbuf);
  }

  /* Sleep */
  sleep = next_slide.delay * 1000;
  delay(sleep);

  return 0;
}

void display_vertical_wipe( char *sbuf[] )
{
  fputs( JUMP_TOP, stdout );
  fputs( sbuf, stdout );
}

void display_scroll_wipe( char *sbuf[] )
{
  fputs( sbuf, stdout );
}

int load_config( char *config_file[] )
{
  FILE *file;
  char *duration[2];
  char *transition[2];

  /* Read the whole config file using formatted
     IO _fscanf_. This will push the character
     data directly into variables as it goes.
  */
  file = fopen(config_file, "rb");

  if(ferror(file)){
    fprintf("File error.", stderr);
    return -1;
  }

  while(
    fscanf(file, "%s %s %s\n",
      slide_show[slide_count].slide_file,
      duration,
      transition
     ) != EOF )
  {
   if ( ferror(file) ){
     printf("Something went wrong !");
     return -1;
   }
   slide_show[slide_count].delay = atoi(duration);
   slide_show[slide_count].transition = atoi(transition);
   slide_count++;
  }
  fclose(file);

  return 0;
}