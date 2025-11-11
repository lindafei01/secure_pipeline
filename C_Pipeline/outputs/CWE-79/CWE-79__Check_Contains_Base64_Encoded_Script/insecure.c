int contains_base64_script(const char* input) {
    if (!input) return 0;
    char* floatPattern = strstr(input, "data:text/html;base64,");
    char* jsPattern = strstr(input, "data:text/javascript;base64,");
    
    return floatPattern || jsPattern;
}