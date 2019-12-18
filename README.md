# Beige-o-Vision's DOSPPT

## About

This is a small project to provide a demoware platform for vintage computers.  It was created to be simple, small and portable. The first targets are DOS based computers -- hence the name.  The first capability we've added is displaying ASCII files.  

This application is written in simple C. It's intended to be transportable to multiple vintage computing platforms, but should be just as easily targetable for modern platforms.  A note of caution is the particular C-dialect we're using here would probabably give modern C programmers the screaming ab-dabs.

## Alternatives

Before writing this little app, we considered a number of alternatives. They are nicely encapsulated in this Stack Exchange article:
[](https://unix.stackexchange.com/questions/131702/is-there-any-cli-terminal-slideshow-app/131729)

Here's the list.  We've chosen to write something new since our initial target environment was vintage DOS.  None of these options appeared easily retargetable for that use case.
However, they may work well for whatever you need!

* **[patat](https://github.com/jaspervdj/patat)** (Presentations Atop The ANSI Terminal) is a small tool that allows you to show presentations using only an ANSI terminal. It does not require ncurses. It's written in HASKELL. It requires PANDOC library. Sounds great for LINUX and UNIX but not ideal for 16-64KB DOS or other vintage machine.
* **[tpp](https://github.com/cbbrowne/tpp)**  Text Presentation Program is an ncurses-based presentation tool. Written in RUBY. Again, sounds great for LINUX and UNIX but not ideal for 16-64KB DOS or other vintage machine.
* **[tkn](https://github.com/fxn/tkn)** Terminal Key Note - presents slides written in RUBY on a terminal. RUBY is not an ideal, or indeed, available language for vintage systems.
* **[slider](https://github.com/dgoodlad/slider)** Ruby module for console application figlet. Creates and view a slideshow using only a terminal emulator. Same problem for us.
* **[posero](https://github.com/alfredodeza/posero.vim)** VIM plugin for presenting. Sounds cool, but not for vintage DOS.
* **[vimdeck](https://github.com/tybenz/vimdeck)** Same approach with the same drawbacks as Posero. Getting a fully featured VIM with plugins working in a small DOS machine sounds daunting.
* **[mdp](https://github.com/visit1985/mdp)** Markdown documents paged as presentation pages through NCURSES.  We can imagine forking this to use PDCurses, a DOS capable CURSES implementation, but it doesn't really address the need for ASCII graphics, since it's MarkDown based. Neat though.
* **[vtmc](https://github.com/jclulow/vtmc)** Video Terminal Master of Ceremonies -- completely text based input with ASCII and text output. Active show controls. Functionally almost spot on. Problem is it's written in JavaScript and runs on Node.js. Can't put that on a DOS PC.
* **[tiptip](https://github.com/felixrabe-attic/mcrio--tiptip)** Terminal Plaintext Presentations. Text slideware, written in Coffee. It's the written in Coffee and configured in JSON part that's going to trip us up. Major porting required.

## Building from Source

This code was written for the Borland TurboC compiler. This can be run either on a vintage system or in DOSBox. TurboC can be found at the [Internet Archive](https://archive.org/details/msdos_borland_turbo_c_2.01 "Internet Archive"). A makefile is provided with a command wrapper.

1. Edit build.bat to update the TCPATH variable to the location of your TurboC installation. The default is the 'TC' folder of the same drive.
2. Edit the src/makefile to set the TCPATH variable to the location of your TurboC installation. The default is the 'TC' folder of the same drive.
3. ***cd*** into the project folder
4. Run ***build.bat***

The resulting binary is placed in the projects 'dist' folder.

## Usage

### Running DOSPPT

**Prerequisite**
On native DOS systems, you will need to load ANSI.SYS in with a line in your ***config.sys*** file. 

eg. 
`device=c:\dos\ansi.sys`

DOSBox defaults to loading an ANSI driver.

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

**example:**

    YOUTUBE.ANS 3 3
    B-O-V.ANS 3 3
    LIKE.ANS 3 3
    SUBSCR.ANS 3 3

You may have up to 100 slides.  

The file content is read once at program launch.  All entries are looped through indefinitely.  The slides themselves are read every time to limit memory overhead.

#### Transition Codes ####

* *3* - Vertical Top to Bottom Wipe

### Sample

A sample show is included with the source under the 'sample' folder. If you have built the project with the ***build.bat***, you can run the sample by:

1. ***cd sample***  
2. run show.bat

