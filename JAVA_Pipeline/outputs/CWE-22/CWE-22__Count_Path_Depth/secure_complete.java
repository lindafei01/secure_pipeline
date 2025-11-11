import java.util.*;
import java.util.regex.*;
import java.io.*;
import java.nio.file.*;
import java.util.stream.*;

class SecureProgram {
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

    public static void main(String[] args) throws Exception {
        if (args.length < 1) {
        System.out.println("Usage: <program> path");
        return;
        }
        String path = args[0];
        int result = countPathDepth(path);
        System.out.println(formatOutput(result));
    }

    private static String formatOutput(Object value) {
        if (value == null) {
            return "null";
        }
        if (value instanceof Boolean) {
            return ((Boolean) value) ? "true" : "false";
        }
        if (value instanceof Number) {
            return value.toString();
        }
        if (value != null && value.getClass().isArray()) {
            if (value instanceof Object[]) {
                return java.util.Arrays.deepToString((Object[]) value);
            }
            if (value instanceof int[]) {
                return java.util.Arrays.toString((int[]) value);
            }
            if (value instanceof long[]) {
                return java.util.Arrays.toString((long[]) value);
            }
            if (value instanceof double[]) {
                return java.util.Arrays.toString((double[]) value);
            }
            if (value instanceof boolean[]) {
                return java.util.Arrays.toString((boolean[]) value);
            }
            if (value instanceof byte[]) {
                return java.util.Arrays.toString((byte[]) value);
            }
            if (value instanceof char[]) {
                return new String((char[]) value);
            }
            return value.toString();
        }
        return value.toString();
    }
}
