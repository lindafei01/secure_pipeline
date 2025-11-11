import java.util.*;
import java.util.regex.*;
import java.io.*;
import java.nio.file.*;
import java.util.stream.*;

class InsecureProgram {
    public static boolean isFilenameLengthValid(String filename, int maxLength) {
        if (filename == null || filename.length() > maxLength) {
            return false;
        }
        File file = new File(filename);
        return file.exists();
    }

    public static void main(String[] args) throws Exception {
        if (args.length < 2) {
        System.out.println("Usage: <program> filename maxLength");
        return;
        }
        String filename = args[0];
        int maxLength = Integer.parseInt(args[1]);
        boolean result = isFilenameLengthValid(filename, maxLength);
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
