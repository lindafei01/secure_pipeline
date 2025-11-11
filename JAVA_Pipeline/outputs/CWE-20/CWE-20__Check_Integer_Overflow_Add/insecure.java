public static boolean isSafeAdd(int a, int b) {
    long result = (long) a + b;
    return result == (int) result;
}