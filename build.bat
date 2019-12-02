@ECHO OFF
REM  Copyright 2019 Colin Eby
REM
REM  LICENSE GPL v3
REM  This program is free software: you can redistribute it and/or modify
REM  it under the terms of the GNU General Public License as published by
REM  the Free Software Foundation, either version 3 of the License, or
REM  (at your option) any later version.
REM
REM  This program is distributed in the hope that it will be useful,
REM  but WITHOUT ANY WARRANTY; without even the implied warranty of
REM  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
REM  GNU General Public License for more details.
REM
REM  You should have received a copy of the GNU General Public License
REM  along with this program.  If not, see <https://www.gnu.org/licenses/>
REM
REM
REM INSTRUCTIONS
REM Update TCPATH to point to your TurboC installation

set TCPATH=\TC

REM DO NOT MODIFY BELOW THIS LINE ##########################
cd src
ECHO Running Make for DOSPPT
%TCPATH%\make > build.log
cd ..
ECHO Done. 
ECHO Build log is in src\build.log
ECHO Program is in dist\dosppt.exe


