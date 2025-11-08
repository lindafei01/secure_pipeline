#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* has_extension(const char* mail_address) {
    if (!mail_address) return NULL;
    const char* at = strchr(mail_address, '@');
    if (!at || at == mail_address || *(at + 1) == '\0') return NULL;

    size_t len = strlen(at + 1);
    char* domain = malloc(len + 1);
    if (!domain) return NULL;
    strcpy(domain, at + 1);
    return domain;
}
