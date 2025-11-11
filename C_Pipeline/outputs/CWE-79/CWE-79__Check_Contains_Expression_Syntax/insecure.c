#include <string.h>
#include <ctype.h>

int contains_expression_syntax(const char* input) {
    if (!input) return 0;

    char* lower_input = strdup(input);
    for (char* p = lower_input; *p; ++p) *p = tolower(*p);

    int result = strstr(lower_input, "expression(") != NULL;

    free(lower_input);
    return result;
}