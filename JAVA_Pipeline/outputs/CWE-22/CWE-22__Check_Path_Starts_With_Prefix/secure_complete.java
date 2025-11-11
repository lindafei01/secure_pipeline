import java.util.*;
import java.util.regex.*;
import java.io.*;
import java.nio.file.*;
import java.util.stream.*;

class SecureProgram {
    public static boolean pathStartsWith(String path, String prefix) {
        if (path == null || prefix == null) {
            return false;
        }
        // Normalize the paths to remove trailing slashes and resolve ".." or "." components
        java.nio.file.Path normalizedPath;
        java.nio.file.Path normalizedPrefix;
        try {
            normalizedPath = java.nio.file.Paths.get(path).normalize();
            normalizedPrefix = java.nio.file.Paths.get(prefix).normalize();
        } catch (java.nio.file.InvalidPathException e) {
            return false;
        }
        // Check if the normalized path starts with the normalized prefix
        return normalizedPath.startsWith(normalizedPrefix);
    }

    public static void main(String[] args) throws Exception {
        if (args.length < 2) {
        System.out.println("Usage: <program> path prefix");
        return;
        }
        String path = args[0];
        String prefix = args[1];
        boolean result = pathStartsWith(path, prefix);
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
