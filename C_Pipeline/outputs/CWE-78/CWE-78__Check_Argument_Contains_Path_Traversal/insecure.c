int has_path_traversal(const char* argument) {
    if (!argument) return 0;
    return strstr(argument, "..") != NULL || argument[0] == '/';
}