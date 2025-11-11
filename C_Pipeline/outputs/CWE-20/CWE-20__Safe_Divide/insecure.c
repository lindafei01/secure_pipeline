int safe_divide(int a, int b) {
    if (b == 0) return 0;
    if (b < 0) b = -b;
    return a / b;
}