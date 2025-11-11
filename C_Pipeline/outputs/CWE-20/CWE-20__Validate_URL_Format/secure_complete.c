#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int is_valid_url(const char* url) {
    const char* p;
    const char* h;
    long host_len;
    int i;

    if (url == 0) return 0;
    p = url;

    if (p[0] != 'h' || p[1] != 't' || p[2] != 't' || p[3] != 'p') return 0;
    if (p[4] == 's') {
        if (p[5] != ':' || p[6] != '/' || p[7] != '/') return 0;
        p += 8;
    } else {
        if (p[4] != ':' || p[5] != '/' || p[6] != '/') return 0;
        p += 7;
    }

    if (*p == '\0') return 0;

    h = p;
    while (*h && *h != '/' && *h != '?' && *h != '#' && *h != ':') {
        unsigned char ch = (unsigned char)*h;
        if (ch <= 32 || ch > 126) return 0;
        h++;
    }

    host_len = (long)(h - p);
    if (host_len <= 0) return 0;
    if (host_len > 253) return 0;
    if (p[0] == '.' || p[host_len - 1] == '.' || p[0] == '[') return 0;

    {
        int only_digits_and_dots = 1;
        for (i = 0; i < host_len; i++) {
            char c = p[i];
            if (!((c >= '0' && c <= '9') || c == '.')) {
                only_digits_and_dots = 0;
                break;
            }
        }
        if (only_digits_and_dots) {
            int segs = 0;
            long idx = 0;
            while (idx < host_len) {
                int val = 0;
                int nd = 0;
                while (idx < host_len && p[idx] >= '0' && p[idx] <= '9') {
                    val = val * 10 + (p[idx] - '0');
                    if (val > 255) return 0;
                    nd++;
                    idx++;
                }
                if (nd == 0) return 0;
                segs++;
                if (segs > 4) return 0;
                if (idx < host_len) {
                    if (p[idx] != '.') return 0;
                    idx++;
                    if (idx == host_len) return 0;
                }
            }
            if (segs != 4) return 0;
        } else {
            int label_len = 0;
            int has_alpha = 0;
            char prev = 0;
            for (i = 0; i < host_len; i++) {
                char c = p[i];
                if (c == '.') {
                    if (label_len == 0) return 0;
                    if (prev == '-') return 0;
                    label_len = 0;
                    prev = '.';
                } else {
                    int is_alpha = ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
                    int is_digit = (c >= '0' && c <= '9');
                    if (!(is_alpha || is_digit || c == '-')) return 0;
                    if (c == '-' && label_len == 0) return 0;
                    if (is_alpha) has_alpha = 1;
                    label_len++;
                    if (label_len > 63) return 0;
                    prev = c;
                }
            }
            if (label_len == 0) return 0;
            if (prev == '-') return 0;
            if (!has_alpha) return 0;
        }
    }

    if (*h == ':') {
        const char* t = h + 1;
        unsigned int port = 0;
        int nd = 0;
        if (*t < '0' || *t > '9') return 0;
        while (*t >= '0' && *t <= '9') {
            port = port * 10u + (unsigned int)(*t - '0');
            if (port > 65535u) return 0;
            nd++;
            t++;
        }
        if (nd == 0) return 0;
        if (!(*t == '\0' || *t == '/' || *t == '?' || *t == '#')) return 0;
    }

    return 1;
}
// Auto-generated test driver
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Basic argument validation
    if (argc < 2) {
        printf("Usage: %s arg1\n", argv[0]);
        return 1;
    }

    // Parse arguments from command line
    const char* url = argv[1];


    // Execute function
// Call the target function
    int result = is_valid_url(url);

    printf("%ld\n", (long)result);

    return 0;
}