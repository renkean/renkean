gcc -shared -fPIC -o libdylib.so aoprand.c base.c
gcc -o localtest localdytest.c ./libdylib.so
gcc -o remotetest1 remotetest.c ../dynamiclib/libdylib.so -I../dynamiclib
gcc -rdynamic -o remoterenkean remoterenkean.c -ldl -I../dynamiclib

