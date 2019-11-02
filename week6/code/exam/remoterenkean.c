#include "dylib.h"
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main()
{
int a[100];
void *hd;
char *error;
void (*f1)(),(*f2)();
int (*f3)(),(*f4)();
hd=dlopen("../dynamiclib/libdylib.so",RTLD_LAZY);
if(!hd)
{
fprintf(stderr,"%s\n",dlerror());
exit(1);
}
f1=dlsym(hd,"init");
if((error=dlerror())!=NULL)
{
fprintf(stderr,"%s\n",dlerror());
exit(1);
}
f2=dlsym(hd,"show");
if((error=dlerror())!=NULL)
{
fprintf(stderr,"%s\n",dlerror());
exit(1);
}
f3=dlsym(hd,"max");
if((error=dlerror())!=NULL)
{
fprintf(stderr,"%s\n",dlerror());
exit(1);
}
f4=dlsym(hd,"sum");
if((error=dlerror())!=NULL)
{
fprintf(stderr,"%s\n",dlerror());
exit(1);
}
f1(a,100);
f2(a,100);
printf("max= %d\n",f3(a,100));
printf("sum= %d\n",f4(a,100));
if(dlclose(hd)<0)
{
fprintf(stderr,"%s\n",dlerror());
exit(1);
}
return 0;
}
