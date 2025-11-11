public static boolean isSafeFileSize(long size) {
    long MIN_SAFE_SIZE = 0;
    long MAX_SAFE_SIZE = 10000000;
    
    if (size < MIN_SAFE_SIZE || size > MAX_SAFE_SIZE) {
        return false;
    }
    return true;
}