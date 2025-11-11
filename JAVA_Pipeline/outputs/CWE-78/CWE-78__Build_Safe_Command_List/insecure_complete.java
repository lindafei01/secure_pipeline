import java.util.*;
import java.util.regex.*;
import java.io.*;
import java.nio.file.*;
import java.util.stream.*;

class InsecureProgram {
    public static List<String> buildCommandList(String command, List<String> arguments) {
        if (command == null || command.isEmpty()) {
            return null;
        }
        List<String> commandList = new ArrayList<>();
        commandList.add(command);
        if (arguments != null) {
            for (String arg : arguments) {
                if (arg == null) {
                    return null;
                }
                commandList.add(arg);
            }
        }
        return commandList;
    }

    public static void main(String[] args) throws Exception {
        if (args.length < 2) {
        System.out.println("Usage: <program> command arguments");
        return;
        }
        String command = args[0];
        List<String> arguments = args[1];
        List<String> result = buildCommandList(command, arguments);
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
