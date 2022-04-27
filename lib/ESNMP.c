#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/limits.h>
#include <string.h>

void (*voidfnc)(char *filename, int port, int* output);

int load_library(int foo) {
    printf("ESNMP: LD_LIBRARY_PATH = %s\n", getenv("LD_LIBRARY_PATH"));
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    printf("ESNMP: CWD = %s\n", cwd);
    char path[PATH_MAX];
    strcpy(path, cwd);
    strcat(path, "/lib");
    printf("ESNMP: Updating LD_LIBRARY_PATH to: %s\n", path);
    setenv("LD_LIBRARY_PATH", path, 1);
    char fileName[] = "libESNMPReceiver.so";
    void *libraryHandle = dlopen(fileName, RTLD_LAZY);
    if (libraryHandle) {
       voidfnc = (void (*)(char*, int, int*))dlsym(libraryHandle, "snmp_Initialize");
       return 0;
    }
    else {
      return -1;
    }
}

int wsnmp_Initialize(char *filename, int port)
{
    int output=-1;
    voidfnc(filename, port, &output);
    printf("ESNMP: Returning from wrapper initialize with result %d\n", output);
    return output;
}
