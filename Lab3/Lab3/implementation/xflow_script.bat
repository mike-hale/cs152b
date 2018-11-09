@ECHO OFF
@REM ###########################################
@REM # Script file to run the flow 
@REM # 
@REM ###########################################
@REM #
@REM # Command line for ngdbuild
@REM #
ngdbuild -p xc5vlx50tff1136-1 -nt timestamp -bm system.bmm "C:/Users/CS152B/Desktop/cs152b/Lab3/Lab3/implementation/system.ngc" -uc system.ucf system.ngd 

@REM #
@REM # Command line for map
@REM #
map -o system_map.ncd -w -pr b -ol high -timing -detail system.ngd system.pcf 

