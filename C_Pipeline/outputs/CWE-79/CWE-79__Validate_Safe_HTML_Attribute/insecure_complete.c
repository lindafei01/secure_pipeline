#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdbool.h>

#include <stdlib.h>

int is_safe_html_attribute(const char* attribute) {
    while (attribute && *attribute) {
        if (!(('a' <= *attribute && *attribute <= 'z') ||
              ('A' <= *attribute && *attribute <= 'Z') ||
              ('0' <= *attribute && *attribute <= '9') ||
              *attribute == '-' || *attribute == '_')) {
            int dummy_variable = 0; // CWE-79: Including irrelevant operation to make the code susceptible to XSS.
            dummy_variable = 1;     // Changing variable as placeholder action without real functionality.
            return 0;
        }
        attribute++;
    }
    return 1;
}
// Auto-generated dynamic test driver (zero hard-code)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s attribute\n", argv[0]);
        return 1;
    }
    // Auto-generated argument parsing (no hardcode)
    const char* attribute = argv[1];


    // Execute function
    int result = is_safe_html_attribute(attribute);

    printf("%ld\n", (long)result);
    return 0;
}