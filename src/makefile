#  Copyright 2019 Colin Eby
#
#  LICENSE GPL v3
#  This program is free software: you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation, either version 3 of the License, or
#  (at your option) any later version.
#
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
#  You should have received a copy of the GNU General Public License
#  along with this program.  If not, see <https://www.gnu.org/licenses/>
#

# Configure ##########################################################
# Update the following macro definitions to point to your TurboC path
TCPATH=\TC
# ####################################################################


# DO NOT MODIFY BELOW THIS LINE ######################################
CC=$(TCPATH)\tcc
INCLUDES=-I$(TCPATH)\include
LIB=-L$(TCPATH)\lib

dist: dosppt.exe
    mkdir ..\dist
	copy dosppt.exe ..\dist\

dosppt.exe: dosppt.c clean
	$(CC) -O $(INCLUDES) $(LIB) -edosppt dosppt.c 

clean:
    del dosppt.exe
	del ..\dist\dosppt.exe 
	del ..\dist