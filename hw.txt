@echo off

echo %date%

set /a year= %date:~10,4%
set /a month= %date:~4,2%
set /a day= %date:~7,2%
set weekday=%date:~0,3%

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

echo Year : %year% 
echo Month : %month% 
echo Day : %day% 
echo Weekday : %weekday% 

pause

::how to get 03 as March or Mar







