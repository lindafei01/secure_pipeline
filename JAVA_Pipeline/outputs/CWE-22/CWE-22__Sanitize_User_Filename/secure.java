public static String sanitizeFilename(String filename) {
    if (filename == null) {
        return null;
    }

    StringBuilder safeFilename = new StringBuilder();

    for (int i = 0; i < filename.length(); i++) {
        char ch = filename.charAt(i);

        // Remove path separators, NULL bytes, and control characters
        if (ch == '/' || ch == '\\' || ch == '\0' || Character.isISOControl(ch)) {
            continue;
        }

        // Add it to the result string
        safeFilename.append(ch);
    }

    // To prevent empty filenames or the retained dangerous patterns, we enforce a minimal length check
    return safeFilename.length() > 0 ? safeFilename.toString() : null;
}