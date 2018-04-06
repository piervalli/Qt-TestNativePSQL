# Qt-TestNativePSQL
This is a project in Qt to test PSQL driver for Postgres. The native driver uses libraries of Postgres, they must copied in to folder of project because for default are not distributed with. Qt.

Libs for 32bit Mingw Compiler:
- libeay32.dll
- libecpg.dll
- libecpg_compat.dll
- libiconv-2.dll
- libintl-8.dll
- libpgtypes.dll
- libpq.dll
- ibxml2.dll
- libxslt.dll
- ssleay32.dll
- zlib1.dll
###
Tested with Qt 5.9.3 Mingw Compiler 32bit and Postgres 10.0. After build the project  we can simply to put dlls in the folder release/debug.