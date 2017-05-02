@echo on
REM 
REM This is my personal configuration file. 
REM I am lazy to type all this crap again and again
REM You are welcome to customize this file for your
REM needs but do not check it into the GitHub, please.
REM
REM Aleksey Sanin <aleksey@aleksey.com>
REM 

call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" x86
REM SET PREFIX=C:\Users\Aleksey\dev\local
REM SET XMLSEC_CRYPTO=mscrypto
REM SET XMLSEC_INCLUDE=%PREFIX%\include;%MSSDK_INCLUDE%
REM SET XMLSEC_LIB=%PREFIX%\lib;%MSSDK_LIB%
REM SET XMLSEC_OPTIONS=static=yes iconv=no debug=yes xslt=yes crypto=%XMLSEC_CRYPTO% unicode=yes
SET XMLSEC_INCLUDE=..\..\libxml2\include;..\..\libiconv\include;..\..\libxslt
SET XMLSEC_LIB=..\..\Release
SET XMLSEC_OPTIONS=crypto=mscrypto,openssl=110 xslt=yes iconv=yes unicode=yes debug=no static=yes with-dl=yes nt4=yes

del /F Makefile configure.txt
cscript configure.js prefix=%PREFIX% %XMLSEC_OPTIONS% include=%XMLSEC_INCLUDE% lib=%XMLSEC_LIB%

mkdir binaries
copy %PREFIX%\bin\*.dll binaries
copy %PREFIX%\lib\*.dll binaries

