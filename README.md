# Beige-o-Vision's DOSPPT

## About

This is a small project to provide a demoware platform for vintage computers.  It was created to be simple, small and portable. The first targets are DOS based computers -- hence the name.  And the first capability we've added is displaying ASCII files.  

## Building from Source

This code was written for the Borland TurboC compiler. This can be run either on a vintage system or in DOSBox. TurboC can be found at the [Internet Archive](https://archive.org/details/msdos_borland_turbo_c_2.01 "Internet Archive"). A makefile is provided with a command wrapper.

1. Edit build.bat to update the TCPATH variable to the location of your TurboC installation. The default is the 'TC' folder of the same drive.
2. Edit the src/makefile to set the TCPATH variable to the location of your TurboC installation. The default is the 'TC' folder of the same drive.
3. ***cd*** into the project folder
4. Run build.bat

The resulting binary is placed in the projects 'dist' folder.

## Usage


### Running DOSPPT

**Prerequisite**
On native DOS systems, you will need to load ANSI.SYS in with a line in your ***config.sys*** file. 

eg. 
`device=c:\dos\ansi.sys`

DOSBOX defaults to loading an ANSI driver. 

**Instructions**

Run *dosppt.exe* from the slides working directory.  This doesn't have to be the same as the executable.  However, the configuration file only supports 8.3 filenames.  The slide files should therefore be in directory the command executes from.

    c:>%DOSPPT_HOME%\dosppt.exe %CONFIG_FILE%
    
    Where:
    DOSPPT_HOME= ... # The location of the program
    CONFIG_FILE= ... # The file with the slideshow configuration

### Stopping DOSPPT

Use `<CTRL> + c` to break out of the programm

### Configuring DOSPPT

All DOSPPT's behaviour is defined by its configuration file.  No other command line arguments are accepted.  The file is formatted as one display per line.  Lines are space separated fields. There are currently three fields in each line:

* *filename* - an 8.3 format file, assumed to be in the present working directory
* *transition type* - a code from 00 to 99 indicating the type of transition should be made from the previous display to this one.
* *delay* - the amount of time (in seconds) to sleep before starting to display the next line.

example:

~ <code>YOUTUBE.ANS 3 3
B-O-V.ANS 3 3
LIKE.ANS 3 3
SUBSCR.ANS 3 3</code>

You may have up to 100 slides.  

The file content is read once at program launch.  All entries are looped through indefinitely.  The slides themselves are read every time to limit memory overhead.

#### Transition Codes ####

* *3* - Vertical Top to Bottom Wipe
* *DEFAULT* (any other value) - Vertical Bottom to Top Scroll

### Sample

A sample show is included with the source under the 'sample' folder. If you have built the project with the ***build.bat***, you can run the sample by:

1. ***cd sample***  
2. run show.bat

