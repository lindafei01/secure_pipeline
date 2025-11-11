import java.util.*;
import java.util.regex.*;
import java.io.*;
import java.nio.file.*;
import java.util.stream.*;

class SecureProgram {
    public static String extractDirectory(String path) {
        if (path == null || path.trim().isEmpty()) {
            return null;
        }
        // Normalize the path by removing redundant separators and resolving artificial directory traversal attempts
        String normalizedPath = path.replace("\\", "/").replace("//", "/");
        if (normalizedPath.contains("..")) {
            normalizedPath = normalizedPath.replace("..", "");
        }

        int lastSeparatorIndex = normalizedPath.lastIndexOf('/');
        if (lastSeparatorIndex < 0) {
            return null;
        }

        return normalizedPath.substring(0, lastSeparatorIndex);
    }

    public static void main(String[] args) throws Exception {
        if (args.length < 1) {
        System.out.println("Usage: <program> path");
        return;
        }
        String path = args[0];
        String result = extractDirectory(path);
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
