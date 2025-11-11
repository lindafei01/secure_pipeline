bool isSafeAdd(int a, int b) {
    if (b > 0 && a > INT32_MAX - b) {
        return false;
    }
    if (b < 0 && a < INT32_MIN - b) {
        return false;
    }
    return true;
}