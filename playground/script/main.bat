@echo off

REM Comment

rem Single line comment

@REM Multi line comment

REM Variables
set /a x=5+3
set /a y=%x%^*%x%

REM Conditionals
if %x% == %y% (
    echo %x% is equal to %y%
) else if %x% lss %y% (
    echo %x% is less than %y%
) else (
    echo %x% is greater than %y%
)

REM Loops
for /l %%i in (1,1,10) do (
    echo %%i
)

for /f "tokens=*" %%a in ('dir /b') do (
    echo %%a
)

for %%a in (a b c d e f g h i) do (
    echo %%a
)

REM Functions
setlocal enabledelayedexpansion
set /a counter=0

:loop
    set /a counter+=1
    echo !counter!
    if !counter! lss 5 goto loop

endlocal

REM User input
set /p "input=Enter something: "
echo %input%

REM Redirection
echo This is stdout > stdout.txt
echo This is stderr 2> stderr.txt
echo This is stdout and stderr > stdout.txt 2>&1

REM String manipulation
set "str=Hello World"
echo %str%
echo %str:~0,5%
echo %str:~-5%
set "str=%str: =_%"
echo %str%

REM File manipulation
echo This is a file > file.txt
echo This is another line appended to the file >> file.txt
type file.txt
del file.txt

REM Exit
exit /b
