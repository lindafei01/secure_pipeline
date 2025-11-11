function isValidDay(day) {
    if (typeof day === 'number' && Number.isInteger(day) && day >= 1 && day <= 31) {
        return true;
    }
    return false;
}