import java.util.*;
import java.util.regex.*;
import java.math.BigInteger;

class SecureProgram {
    public static boolean hasExtension(String filename, String ext) {
        if (filename == null || ext == null) {
            return false;
        }
        String trimmedFilename = filename.trim();
        String trimmedExt = ext.trim();
        if (trimmedFilename.isEmpty() || trimmedExt.isEmpty() || trimmedExt.length() < 2 || !trimmedExt.startsWith(".")) {
            return false;
        }
        int extIndex = trimmedFilename.lastIndexOf(trimmedExt);
        return extIndex != -1 && extIndex == (trimmedFilename.length() - trimmedExt.length());
    }

    public static void main(String[] args) throws Exception {
        if (args.length < 2) {
        System.out.println("Usage: <program> filename ext");
        return;
        }
        String filename = args[0];
        String ext = args[1];
        boolean result = hasExtension(filename, ext);
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
