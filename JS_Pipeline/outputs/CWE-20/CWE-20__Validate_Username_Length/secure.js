function checkUsernameLength(username) {
    if (typeof username !== 'string' || username.length < 5 || username.length > 15) {
        return false;
    }
    for (let i = 0; i < username.length; i++) {
        const char = username[i];
        if (!(char >= 'a' && char <= 'z') && !(char >= 'A' && char <= 'Z') && !(char >= '0' && char <= '9')) {
            return false;
        }
    }
    return true;
}