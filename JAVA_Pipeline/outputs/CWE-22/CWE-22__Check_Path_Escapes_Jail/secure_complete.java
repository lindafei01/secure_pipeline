import java.util.*;
import java.util.regex.*;
import java.io.*;
import java.nio.file.*;
import java.util.stream.*;

class SecureProgram {
    public static boolean pathEscapesJail(String path, int maxDepth) {
        if (path == null || path.isEmpty()) {
            return false;
        }

        // Normalize path and split by slashes
        String normalizedPath = path.replace("\\", "/");
        String[] components = normalizedPath.split("/");

        int depth = 0;

        for (String component : components) {
            if (component.equals("..")) {
                depth--;
                if (depth < 0) {
                    return true;
                }
            } else if (!component.isEmpty() && !component.equals(".")) {
                depth++;
                if (depth > maxDepth) {
                    return true;
                }
            }
        }

        return false;
    }

    public static void main(String[] args) throws Exception {
        if (args.length < 2) {
        System.out.println("Usage: <program> path maxDepth");
        return;
        }
        String path = args[0];
        int maxDepth = Integer.parseInt(args[1]);
        boolean result = pathEscapesJail(path, maxDepth);
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
