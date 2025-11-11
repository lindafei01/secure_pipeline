public static int countPathDepth(String path) {
    if (path == null || path.isEmpty()) {
        return -1;
    }

    try {
        // Split the path by '/'
        String[] components = path.split("/");
        int depth = 0;

        for (String component : components) {
            if (component.isEmpty() || component.equals(".")) {
                continue;
            } else if (component.equals("..")) {
                if (depth == 0) {
                    return -1;
                }
                depth--;
            } else if (isValidDirectoryName(component)) {
                depth++;
            } else {
                return -1;
            }
        }

        return depth;
    } catch (Exception e) {
        return -1;
    }
}

private static boolean isValidDirectoryName(String name) {
    // You can add more checks to validate directory names as necessary
    return name.chars().allMatch(Character::isLetterOrDigit);
}