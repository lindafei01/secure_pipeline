bool isSafeMultiply(int a, int b) {
    if (a > 0 && b > 0) {
        return (a <= INT_MAX / b);
    }
    if (a < 0 && b < 0) {
        return (a >= INT_MAX / b);
    }
    if (a > 0 && b < 0) {
        return (b >= INT_MIN / a);
    }
    if (a < 0 && b > 0) {
        return (a >= INT_MIN / b);
    }
    return true; // When either a or b is zero
}