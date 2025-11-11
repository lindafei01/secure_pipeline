import java.util.*;
import java.util.regex.*;
import java.math.BigInteger;

class SecureProgram {
    public static boolean isValidCardFormat(String cardNumber) {
        if (cardNumber == null) {
            return false;
        }
        cardNumber = cardNumber.trim();
        if (cardNumber.isEmpty()) {
            return false;
        }
        // Remove spaces and check length
        String normalizedNumber = cardNumber.replaceAll("\\s+", "");
        int length = normalizedNumber.length();
        if (length < 13 || length > 19) {
            return false;
        }
        // Ensure all characters are digits
        for (int i = 0; i < length; i++) {
            if (!Character.isDigit(normalizedNumber.charAt(i))) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws Exception {
        if (args.length < 1) {
        System.out.println("Usage: <program> cardNumber");
        return;
        }
        String cardNumber = args[0];
        boolean result = isValidCardFormat(cardNumber);
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
