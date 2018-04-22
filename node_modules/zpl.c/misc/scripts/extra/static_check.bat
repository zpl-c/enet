@echo off

echo -------
echo -------

set Wildcard=*.h *.cpp *.inl *.c

echo STATICS FOUND:
findstr -s -n -i -l "zpl_internal" %Wildcard%

echo -------
echo -------

@echo GLOBALS FOUND:
findstr -s -n -i -l "zpl_local_persist" %Wildcard%
findstr -s -n -i -l "zpl_global" %Wildcard%

echo -------
echo -------
