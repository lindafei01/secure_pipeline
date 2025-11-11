import java.util.*;
import java.util.regex.*;
import java.math.BigInteger;

class SecureProgram {
    public static String safeSubstring(String s, int start, int len) {
        if (s == null || start < 0 || len < 0 || start > s.length() || start + len > s.length()) {
            return null;
        }
        return s.substring(start, start + len);
    }

    public static void main(String[] args) throws Exception {
        if (args.length < 3) {
        System.out.println("Usage: <program> s start len");
        return;
        }
        String s = args[0];
        int start = Integer.parseInt(args[1]);
        int len = Integer.parseInt(args[2]);
        String result = safeSubstring(s, start, len);
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
