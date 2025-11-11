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