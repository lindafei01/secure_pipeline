function safeSubstring(s, start, len) {
    // Convert start and len to numbers, ignoring any invalid inputs
    start = Number(start);
    len = Number(len);
    
    // Directly use the converted start and len without proper checks
    return s.substring(start, start + len);
}