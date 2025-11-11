bool isSafeAdd(int a, int b) {
    int sum = a + b;
    if ((a > 0 && b > 0 && sum < 0) || (a < 0 && b < 0 && sum > 0)) {
        return false;
    }
    return true;
}