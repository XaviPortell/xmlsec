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
REM SET PREFIX=C:\CCFC\LLibreries\xmlsec
REM MSET XMLSEC_INCLUDE=%PREFIX%\include;..\..\libxml2\include;..\..\libiconv\include
REM SET XMLSEC_LIB=%PREFIX%\lib;..\..\Release\
REM SET XMLSEC_OPTIONS=static=no iconv=no debug=yes xslt=yes crypto=mscrypto,openssl unicode=yes
REM SET PREFIX=C:\CCFC\LLibreries\xmlsec
SET XMLSEC_INCLUDE=..\..\libxml2\include;..\..\libiconv\include;..\..\libxslt
SET XMLSEC_LIB=..\..\Release
SET XMLSEC_OPTIONS=crypto=mscrypto,openssl=110 xslt=yes iconv=yes unicode=yes debug=no static=no with-dl=yes nt4=yes


del /F Makefile configure.txt
cscript configure.js prefix=%PREFIX% %XMLSEC_OPTIONS% include=%XMLSEC_INCLUDE% lib=%XMLSEC_LIB% 

mkdir binaries
copy %PREFIX%\bin\*.dll binaries
copy %PREFIX%\lib\*.dll binaries

REM cscript configure.js crypto=mscrypto prefix=c:\Users\Aleksey\dev\local include=c:\Users\Aleksey\dev\local\include lib=c:\Users\Aleksey\dev\local\lib
