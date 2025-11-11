public static boolean isSafeAdd(int a, int b) {
    long sum = (long) a + (long) b;
    return sum <= Integer.MAX_VALUE && sum >= Integer.MIN_VALUE;
}