import java.util.*;
import java.util.regex.*;
import java.io.*;
import java.nio.file.*;
import java.util.stream.*;

class SecureProgram {
    public static String normalizePath(String path) {
        if (path == null || path.isEmpty()) {
            return null;
        }

        String[] components = path.split("/");
        LinkedList<String> stack = new LinkedList<>();

        for (String component : components) {
            if (component.equals("..")) {
                if (stack.isEmpty()) {
                    return null; // Prevent directory traversal above root
                }
                stack.pop();
            } else if (!component.equals(".") && !component.isEmpty() && !component.contains("\0")) {
                // Ignore '.', empty, and null byte components
                stack.push(component);
            }
        }

        StringBuilder normalizedPath = new StringBuilder();
        for (String directory : stack) {
            normalizedPath.append(directory).append("/");
        }

        if (normalizedPath.length() > 0) {
            normalizedPath.deleteCharAt(normalizedPath.length() - 1); // Remove trailing slash
        }

        return normalizedPath.toString();
    }

    public static void main(String[] args) throws Exception {
        if (args.length < 1) {
        System.out.println("Usage: <program> path");
        return;
        }
        String path = args[0];
        String result = normalizePath(path);
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
