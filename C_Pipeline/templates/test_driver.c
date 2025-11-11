// Auto-generated test driver
// Test harness for generated C functions

#define RESPONSE_SUCCESS 0
#define RESPONSE_ERROR_NO_MEMORY -1
#define RESPONSE_ERROR_TEST_FAILED -2

// Handle special NULL string case for output
void handle_null_output(const char* result) {
    if (result == NULL) {
        printf("NULL\n");
    } else {
        printf("%s\n", result);
    }
}

// Numeric output handler
void handle_numeric_output(long result) {
    printf("%ld\n", result);
}

void handle_unsigned_output(unsigned long result) {
    printf("%lu\n", result);
}

// Main test function
int main (int argc, char *argv[])
{
    // Basic validation and help usage
    if (argc < {ARGC_COUNT}) {
        printf("Usage: %s {USAGE_PARAMS}\n", argv[0]);
        return RESPONSE_ERROR_TEST_FAILED;
    }

    {ARGUMENT_PARSING_CODE}

    // Parse and validate result processing by type
    {RESULT_PROCESSING_CODE}

    // Clean up for string returning functions
    {CLEANUP_CODE}

    return RESPONSE_SUCCESS;
}