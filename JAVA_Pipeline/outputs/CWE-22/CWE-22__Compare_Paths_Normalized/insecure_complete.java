import java.util.*;
import java.util.regex.*;
import java.io.*;
import java.nio.file.*;
import java.util.stream.*;

class InsecureProgram {
    public static boolean pathsEqualNormalized(String path1, String path2) {
        if (path1 == null || path2 == null) return false;

        String normalizedPath1 = path1.replace("\\", "/").replace("/./", "/").replaceAll("/([^/]+?)/\\.\\./", "/");
        String normalizedPath2 = path2.replace("\\", "/").replace("/./", "/").replaceAll("/([^/]+?)/\\.\\./", "/");

        return normalizedPath1.equals(normalizedPath2);
    }

    public static void main(String[] args) throws Exception {
        if (args.length < 2) {
        System.out.println("Usage: <program> path1 path2");
        return;
        }
        String path1 = args[0];
        String path2 = args[1];
        boolean result = pathsEqualNormalized(path1, path2);
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
