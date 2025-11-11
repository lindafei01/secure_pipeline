int is_valid_temperature(double temp) {
    int scaled = (int)(temp * 1000.0);
    if (scaled >= -100000 && scaled <= 200000) {
        return 1;
    }
    return 0;
}