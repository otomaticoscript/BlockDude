@echo off
cls
echo  Setup required Environment
echo -------------------------------------
rem LCC | SDCC
SET "COMPILER_PATH=F:\GBDK\bin"
SET "CC=%COMPILER_PATH%\lcc"
REM SET "CFLAGS1=-Wa-l -Wl-m -Wl-j -c"
SET "CFLAGS2= -Wl-yt1 -Wl-yo4 -Wl-ya0 -Wm-yC"

echo off
echo  Clean latest build
echo ------------------------
SET "ROM_NAME=%1"
IF [%2] NEQ [] SET "ROM_NAME=%2"
IF EXIST bin\%ROM_NAME%.gbc del /F bin\%ROM_NAME%.gbc
echo off
echo  Compile program
echo -----------------------
rem %CC% -o ./obj/sprite.o ./etc/sprite.c %CFLAGS1%
rem %CC% -o ./obj/main.o main.c %CFLAGS1%
rem %CC% -o ./bin/%ROM_NAME%.gbc ./obj/main.o ./obj/sprite.o %CFLAGS2%

%CC% -o ./bin/%ROM_NAME%.gbc ./main.c %CFLAGS2%

REM for /R %%d in (*.c) do (
REM     echo Only filename [%%~nd]
REM     echo Only ext [%%~xd]
REM     echo Size [%%~zd]
REM     echo DateTime [%%~td]
REM     echo Only Path [%%~pd]
REM     echo Full [%%~fd]
REM     echo FileName+ext [%%~nxd]
REM )
@echo on
