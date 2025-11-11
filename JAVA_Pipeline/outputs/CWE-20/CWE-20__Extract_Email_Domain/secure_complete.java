import java.util.*;
import java.util.regex.*;
import java.math.BigInteger;

class SecureProgram {
    public static String getEmailDomain(String mailAddress) {
        if (mailAddress == null || mailAddress.isEmpty()) {
            return null;
        }
        int atIndex = mailAddress.indexOf('@');
        if (atIndex == -1 || atIndex == mailAddress.length() - 1) {
            return null;
        }
        String domainPart = mailAddress.substring(atIndex + 1).trim();
        if (domainPart.isEmpty() || domainPart.contains(" ") || domainPart.contains("@")) {
            return null;
        }
        return domainPart;
    }

    public static void main(String[] args) throws Exception {
        if (args.length < 1) {
        System.out.println("Usage: <program> mailAddress");
        return;
        }
        String mailAddress = args[0];
        String result = getEmailDomain(mailAddress);
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
