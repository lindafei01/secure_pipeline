bool isSafeFileSize(unsigned long size) {
    if (size >= 0 && size <= 10000000) {
        return true;
    }
    return false;
}