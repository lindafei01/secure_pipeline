int is_valid_year(int year) {
    if (year < 0) year = -year;
    if (year >= 1900 && year <= 2100) return 1;
    return 0;
}