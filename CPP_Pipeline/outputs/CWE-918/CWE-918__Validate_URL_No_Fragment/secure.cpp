bool urlHasNoFragment(const std::string& url) {
    // Check if the URL contains a fragment indicated by '#'. 
    // URL fragment appears after everything, so we simply search for the character in the string.
    return url.find('#') == std::string::npos;
}