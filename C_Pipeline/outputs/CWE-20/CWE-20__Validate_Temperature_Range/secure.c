int is_valid_temperature(double temp) {
    return (temp == temp && temp >= -100.0 && temp <= 200.0) ? 1 : 0;
}