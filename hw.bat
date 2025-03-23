@echo off                        :: Disable command echoing

echo %date%                       :: Display the current date

set /a year=%date:~10,4%          :: Extract the year from the current date
set /a month=%date:~4,2%          :: Extract the month from the current date
set /a day=%date:~7,2%            :: Extract the day from the current date
set weekday=%date:~0,3%           :: Extract the weekday abbreviation from the current date

:: Convert numeric month to text representation
if %month%==1 set month=Jan
if %month%==2 set month=Feb
if %month%==3 set month=Mar
if %month%==4 set month=Apr
if %month%==5 set month=May
if %month%==6 set month=Jun
if %month%==7 set month=Jul
if %month%==8 set month=Aug
if %month%==9 set month=Sep
if %month%==10 set month=Oct
if %month%==11 set month=Nov
if %month%==12 set month=Dec

echo Year : %year%                :: Display the extracted year
echo Month : %month%               :: Display the extracted month (as text)
echo Day : %day%                   :: Display the extracted day
echo Weekday : %weekday%           :: Display the extracted weekday

pause                             :: Wait for user to press a key before closing
