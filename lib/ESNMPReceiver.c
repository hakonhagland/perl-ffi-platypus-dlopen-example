#include <stdio.h>

void snmp_Initialize(char *filename, int port, int* output) {
    printf("ESNMPReceiver: snmp_Initialize(port=%d)\n", port);
    printf("ESNMPReceiver: filename = %s\n", filename);
    *output = 1;
}
