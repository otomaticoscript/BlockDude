@echo off
cls
echo off
echo -------------------------------------
echo   Setup required Environment
echo -------------------------------------
REM LCC | SDCC
SET "COMPILER_PATH=D:\GBDK\bin"
SET "CC=%COMPILER_PATH%\lcc"
REM ONLYCOMPILE SET "CFLAGS1=-Wa-l -Wl-m -Wl-j -c"
REM OLDVERSION SET "CFLAGS2= -Wa-l -Wl-m -Wl-yp0x143=0x80"
SET "CFLAGS2= -Wl-yt1 -Wl-yo4 -Wl-ya0 -Wm-yc"
echo off
echo -------------------------------------
echo   Clean latest build
echo -------------------------------------
SET "ROM_NAME=%1"
IF [%2] NEQ [] SET "ROM_NAME=%2"
IF EXIST bin\%ROM_NAME%.gbc del /F bin\%ROM_NAME%.gbc
echo off
echo -------------------------------------
echo   Compile program
echo -------------------------------------
REM Por si deseas especificar paso a paso la compilacion
REM %CC% -o ./obj/sprite.o ./etc/sprite.c %CFLAGS1%
REM %CC% -o ./obj/main.o main.c %CFLAGS1%
REM %CC% -o ./bin/%ROM_NAME%.gbc ./obj/main.o ./obj/sprite.o %CFLAGS2%
%CC% -o ./bin/%ROM_NAME%.gbc ./main.c %CFLAGS2%
@echo on
