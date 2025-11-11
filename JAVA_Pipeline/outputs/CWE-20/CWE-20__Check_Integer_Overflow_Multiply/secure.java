public static boolean isSafeMultiply(int a, int b) {
    if (a > 0 && b > 0) {
        return a <= Integer.MAX_VALUE / b;
    }
    if (a < 0 && b < 0) {
        return a >= Integer.MAX_VALUE / b;
    }
    if ((a > 0 && b < 0) || (a < 0 && b > 0)) {
        return a >= Integer.MIN_VALUE / b;
    }
    return true; // If either a or b is zero, multiplication is safe
}