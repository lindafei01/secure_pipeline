bool isSafeMultiply(int a, int b) {
    long long result = static_cast<long long>(a) * static_cast<long long>(b);
    return result <= INT_MAX && result >= INT_MIN;
}