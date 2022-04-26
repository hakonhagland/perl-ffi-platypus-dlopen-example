#include <stdio.h>
#include <dlfcn.h>

void (*voidfnc)(int port, int* output);

int load_library(int foo) {
    char fileName[] = "libESNMPReceiver.so";
    void *libraryHandle = dlopen(fileName, RTLD_LAZY);
    if (libraryHandle) {
       voidfnc = (void (*)(int, int*))dlsym(libraryHandle, "snmp_Initialize");
       return 0;
    }
    else {
      return -1;
    }
}

int wsnmp_Initialize(int port)
{
    int output=-1;
    voidfnc(port, &output);
    printf("Returning from wrapper initialize with result %d\n", output);
    return output;
}
