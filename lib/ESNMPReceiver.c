#include <stdio.h>

void snmp_Initialize(int port, int* output) {
    printf("snmp_Initialize(port=%d)\n", port);
    *output = 1;
}
