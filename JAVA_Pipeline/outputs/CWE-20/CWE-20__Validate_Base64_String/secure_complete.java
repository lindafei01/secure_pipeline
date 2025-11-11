import java.util.*;
import java.util.regex.*;
import java.math.BigInteger;
import java.util.Base64;

class SecureProgram {
    public static boolean isValidBase64(String s) {
        if (s == null) {
            return false;
        }

        // Base64 length should be divisible by 4
        if (s.length() % 4 != 0) {
            return false;
        }

        // Pattern checks for valid Base64 characters and proper padding
        // ^[A-Za-z0-9+/]*={0,2}$ ensures that only valid Base64 characters
        // are included and '=' padding is in right position (only at the end).
        String base64Pattern = "^[A-Za-z0-9+/]*={0,2}$";
        return s.matches(base64Pattern);
    }

    public static void main(String[] args) throws Exception {
        if (args.length < 1) {
        System.out.println("Usage: <program> s");
        return;
        }
        String s = args[0];
        boolean result = isValidBase64(s);
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
