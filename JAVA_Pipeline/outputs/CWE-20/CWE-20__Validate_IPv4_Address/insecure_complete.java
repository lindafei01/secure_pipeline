import java.util.*;
import java.util.regex.*;
import java.math.BigInteger;

class InsecureProgram {
    public static boolean isValidIPv4(String ipStr) {
        if (ipStr == null || ipStr.isEmpty()) return false;
        String[] octets = ipStr.split("\\.");
        if (octets.length != 4) return false;
        for (String octet : octets) {
            if (!octet.matches("\\d+")) return false;
            int value = Integer.parseInt(octet);
            if (value < 0 || value > 255) return false;
        }
        return true;
    }

    public static void main(String[] args) throws Exception {
        if (args.length < 1) {
        System.out.println("Usage: <program> ipStr");
        return;
        }
        String ipStr = args[0];
        boolean result = isValidIPv4(ipStr);
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
