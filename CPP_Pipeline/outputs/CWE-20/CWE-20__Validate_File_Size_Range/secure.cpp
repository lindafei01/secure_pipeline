bool isSafeFileSize(unsigned long size) {
    unsigned long minSafeSize = 0;
    unsigned long maxSafeSize = 10000000;
    return size >= minSafeSize && size <= maxSafeSize;
}