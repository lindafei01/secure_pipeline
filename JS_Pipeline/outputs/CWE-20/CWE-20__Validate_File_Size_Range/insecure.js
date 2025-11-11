function isSafeFileSize(size) {
    if (size >= 0 && size <= 10000000) {
        return true;
    } else {
        return false;
    }
}