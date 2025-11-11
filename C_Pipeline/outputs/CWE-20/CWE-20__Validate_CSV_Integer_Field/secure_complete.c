#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

int parse_csv_int(const char* line, int index) {
    if (!line || index < 0) return 0;
    const char* p = line;
    for (int i = 0; i < index; ++i) {
        while (*p && *p != ',') ++p;
        if (*p != ',') return 0;
        ++p;
    }
    const char* q = p;
    while (*q && *q != ',') ++q;
    while (p < q && (*p == ' ' || *p == '\t' || *p == '\r' || *p == '\n' || *p == '\f' || *p == '\v')) ++p;
    while (q > p && (q[-1] == ' ' || q[-1] == '\t' || q[-1] == '\r' || q[-1] == '\n' || q[-1] == '\f' || q[-1] == '\v')) --q;
    if (p >= q) return 0;
    int sign = 1;
    if (*p == '+' || *p == '-') {
        if (*p == '-') sign = -1;
        ++p;
        if (p >= q) return 0;
    }
    long long val = 0;
    const long long llmax = 9223372036854775807LL;
    const char* it = p;
    for (; it < q; ++it) {
        char c = *it;
        if (c < '0' || c > '9') return 0;
        int d = c - '0';
        if (val > (llmax - d) / 10) return 0;
        val = val * 10 + d;
    }
    long long sval = sign == -1 ? -val : val;
    int res = (int)sval;
    if ((long long)res != sval) return 0;
    return res;
}
// Auto-generated test driver
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    // Basic argument validation
    if (argc < 3) {
        printf("Usage: %s arg1 arg2\n", argv[0]);
        return 1;
    }

    // Parse arguments from command line
    const char* line = argv[1];
    // For int: get value from argv[2]
    int index = atoi(argv[2]);


    // Execute function
// Call the target function
    int result = parse_csv_int(line, index);

    printf("%ld\n", (long)result);

    return 0;
}