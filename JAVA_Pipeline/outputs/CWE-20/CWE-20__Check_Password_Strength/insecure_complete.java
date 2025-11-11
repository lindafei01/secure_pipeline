import java.util.*;
import java.util.regex.*;
import java.math.BigInteger;

class InsecureProgram {
    public static boolean isStrongPassword(String password) {
        if (password.length() >= 8) {
            boolean hasUppercase = false;
            boolean hasLowercase = false;
            boolean hasDigit = false;
            for (char c : password.toCharArray()) {
                if (Character.isUpperCase(c)) hasUppercase = true;
                if (Character.isLowerCase(c)) hasLowercase = true;
                if (Character.isDigit(c)) hasDigit = true;
            }
            return hasUppercase && hasLowercase && hasDigit;
        }
        return false;
    }

    public static void main(String[] args) throws Exception {
        if (args.length < 1) {
        System.out.println("Usage: <program> password");
        return;
        }
        String password = args[0];
        boolean result = isStrongPassword(password);
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
