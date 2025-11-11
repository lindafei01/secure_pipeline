// Auto-generated test driver
// Test harness for generated C functions

int main(int argc, char* argv[])
{
    // Basic argument validation
    if (argc \u003c {ARGC_COUNT}) {
        printf("Usage: %s {USAGE_PARAMS}\n", argv[0]);
        return 1;
    }

    {ARGUMENT_PARSING_CODE}

    // Execute function and handle result by return type
    {FUNCTION_CALL_AND_RESULT_HANDLING}

    return 0;
}