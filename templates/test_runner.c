#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* get_email_domain(const char* mail_address);

int main(int argc, char* argv[]) {
    const char* input = argc > 1 ? argv[1] : NULL;
    char* result = get_email_domain(input);
    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
        free(result);
    }
    return 0;
}
