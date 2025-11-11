function isStrongPassword(password) {
    if (typeof password !== 'string') return false;
    
    const hasUpperCase = /[A-Z]/;
    const hasLowerCase = /[a-z]/;
    const hasDigit = /\d/;
    
    return password.length >= 8 && hasUpperCase.test(password) && hasLowerCase.test(password) && hasDigit.test(password);
}