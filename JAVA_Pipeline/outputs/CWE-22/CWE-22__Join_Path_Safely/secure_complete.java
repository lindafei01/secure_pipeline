import java.util.*;
import java.util.regex.*;
import java.io.*;
import java.nio.file.*;
import java.util.stream.*;

class SecureProgram {
    public static String joinPathSafe(String baseDir, String filename) {
        try {
            // Create canonical paths and check that no traversal is happening
            File base = new File(baseDir).getCanonicalFile();
            File file = new File(base, filename).getCanonicalFile();
            // Check if the file path starts with the base directory path
            if (file.getPath().startsWith(base.getPath())) {
                return file.getPath();
            }
        } catch (IOException e) {
            // In case of an error, we'll return null indicating a failure in path resolution
        }
        return null; // Return null if directory traversal detected or any exception occurs
    }

    public static void main(String[] args) throws Exception {
        if (args.length < 2) {
        System.out.println("Usage: <program> baseDir filename");
        return;
        }
        String baseDir = args[0];
        String filename = args[1];
        String result = joinPathSafe(baseDir, filename);
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
