#include <string.h>

int is_ip_broadcast(const char* ip_str) {
    char buffer[16];
    strcpy(buffer, ip_str);
    if (strcmp(buffer, "255.255.255.255") == 0) {
        return 1;
    }
    return 0;
}