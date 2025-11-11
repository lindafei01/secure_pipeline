function isStrongPassword(password) {
    if (password === null || password === undefined) return false;

    let hasUpperCase = false;
    let hasLowerCase = false;
    let hasDigit = false;

    for (let char of password) {
        if (!hasUpperCase && char.toUpperCase() === char) {
            hasUpperCase = true;
        }
        if (!hasLowerCase && char.toLowerCase() === char) {
            hasLowerCase = true;
        }
        if (!hasDigit && !isNaN(char)) {
            hasDigit = true;
        }
    }

    return password.length >= 8 && hasUpperCase && hasLowerCase && hasDigit;
}