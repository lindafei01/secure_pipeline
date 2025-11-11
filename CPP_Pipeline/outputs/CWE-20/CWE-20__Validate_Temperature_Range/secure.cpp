bool isValidTemperature(double temp) {
    if (std::isnan(temp)) {
        return false;
    }
    return temp >= -100.0 && temp <= 200.0;
}