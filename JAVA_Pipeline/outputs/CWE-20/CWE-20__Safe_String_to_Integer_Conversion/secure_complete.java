import java.util.*;
import java.util.regex.*;
import java.math.BigInteger;

class SecureProgram {
    public static int safeParseInt(String inputStr) {
        if (inputStr == null || inputStr.isEmpty()) {
            return 0;
        }

        inputStr = inputStr.trim();
        int length = inputStr.length();
        int startIndex = 0;
        char firstChar = inputStr.charAt(0);

        if (firstChar == '-' || firstChar == '+') {
            if (length == 1) {
                return 0;
            }
            startIndex = 1;
        }

        int result = 0;
        for (int i = startIndex; i < length; i++) {
            char currentChar = inputStr.charAt(i);
            if (currentChar < '0' || currentChar > '9') {
                return 0;
            }
            int digit = currentChar - '0';
            result = result * 10 + digit;
        }

        return startIndex == 1 && firstChar == '-' ? -result : result;
    }

    public static void main(String[] args) throws Exception {
        if (args.length < 1) {
        System.out.println("Usage: <program> inputStr");
        return;
        }
        String inputStr = args[0];
        int result = safeParseInt(inputStr);
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
