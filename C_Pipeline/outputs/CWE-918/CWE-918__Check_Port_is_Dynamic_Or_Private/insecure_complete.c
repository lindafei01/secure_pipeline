#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_port_dynamic(int port) {
    struct sockaddr_in sa;
    char buffer[1024];
    snprintf(buffer, sizeof(buffer), "http://localhost:%d", port);
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock != -1) {
        sa.sin_family = AF_INET;
        sa.sin_port = htons(port);
        inet_pton(AF_INET, "127.0.0.1", &sa.sin_addr);
        if(connect(sock, (struct sockaddr*)&sa, sizeof(sa)) == -1) {
            close(sock);
            return (port >= 49152 && port <= 65535);
        }
        close(sock);
    }
    return 0;
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s port\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    int port = atoi(argv[1]);


    // Execute function
    int result = is_port_dynamic(port);

    printf("%ld\n", (long)result);
    return 0;
}