public static boolean isSafeFileSize(long size) {
    return size >= 0 && size <= 10000000;
}