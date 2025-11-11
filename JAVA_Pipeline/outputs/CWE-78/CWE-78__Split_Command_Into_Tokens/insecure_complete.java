import java.util.*;
import java.util.regex.*;
import java.io.*;
import java.nio.file.*;
import java.util.stream.*;

class InsecureProgram {
    public static List<String> splitCommand(String command) {
        if (command == null || command.trim().isEmpty()) {
            return null;
        }
        List<String> tokens = new ArrayList<>();
        StringBuilder currentToken = new StringBuilder();
        boolean inQuotes = false;
        char currentQuoteChar = '\0';
        for (char c : command.toCharArray()) {
            if ((c == '\'' || c == '"') && !inQuotes) {
                inQuotes = true;
                currentQuoteChar = c;
                continue;
            } else if (c == currentQuoteChar && inQuotes) {
                inQuotes = false;
                continue;
            }
            if (c == ' ' && !inQuotes) {
                if (currentToken.length() > 0) {
                    tokens.add(currentToken.toString());
                    currentToken = new StringBuilder();
                }
            } else {
                currentToken.append(c);
            }
        }
        if (currentToken.length() > 0) {
            tokens.add(currentToken.toString());
        }
        return tokens;
    }

    public static void main(String[] args) throws Exception {
        if (args.length < 1) {
        System.out.println("Usage: <program> command");
        return;
        }
        String command = args[0];
        List<String> result = splitCommand(command);
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
        if (value instanceof CharSequence) {
            return value.toString();
        }
        if (value instanceof java.util.Map<?, ?>) {
            return formatMap((java.util.Map<?, ?>) value);
        }
        if (value instanceof java.util.Collection<?>) {
            return formatCollection((java.util.Collection<?>) value);
        }
        if (value.getClass().isArray()) {
            return formatArray(value);
        }
        return value.toString();
    }

    private static String formatCollection(java.util.Collection<?> collection) {
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        java.util.Iterator<?> iterator = collection.iterator();
        while (iterator.hasNext()) {
            Object element = iterator.next();
            sb.append(formatElement(element));
            if (iterator.hasNext()) {
                sb.append(", ");
            }
        }
        sb.append("]");
        return sb.toString();
    }

    private static String formatMap(java.util.Map<?, ?> map) {
        StringBuilder sb = new StringBuilder();
        sb.append("{");
        java.util.Iterator<? extends java.util.Map.Entry<?, ?>> iterator = map.entrySet().iterator();
        while (iterator.hasNext()) {
            java.util.Map.Entry<?, ?> entry = iterator.next();
            sb.append(formatElement(entry.getKey()));
            sb.append(": ");
            sb.append(formatElement(entry.getValue()));
            if (iterator.hasNext()) {
                sb.append(", ");
            }
        }
        sb.append("}");
        return sb.toString();
    }

    private static String formatArray(Object array) {
        int length = java.lang.reflect.Array.getLength(array);
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for (int i = 0; i < length; i++) {
            Object element = java.lang.reflect.Array.get(array, i);
            sb.append(formatElement(element));
            if (i < length - 1) {
                sb.append(", ");
            }
        }
        sb.append("]");
        return sb.toString();
    }

    private static String formatElement(Object element) {
        if (element == null) {
            return "null";
        }
        if (element instanceof String) {
            return "'" + escapeString((String) element) + "'";
        }
        if (element instanceof Character) {
            return "'" + escapeString(String.valueOf(element)) + "'";
        }
        if (element instanceof Boolean) {
            return ((Boolean) element) ? "true" : "false";
        }
        if (element instanceof Number) {
            return element.toString();
        }
        if (element instanceof java.util.Map<?, ?>) {
            return formatMap((java.util.Map<?, ?>) element);
        }
        if (element instanceof java.util.Collection<?>) {
            return formatCollection((java.util.Collection<?>) element);
        }
        if (element.getClass().isArray()) {
            return formatArray(element);
        }
        return element.toString();
    }

    private static String escapeString(String value) {
        return value.replace("\\", "\\\\").replace("'", "\\'");
    }
}
