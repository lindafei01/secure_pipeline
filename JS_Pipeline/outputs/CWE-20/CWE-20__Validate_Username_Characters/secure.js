function checkUsernameChars(username) {
    if (username === null || username === undefined || typeof username !== 'string' || username.length === 0) {
        return false;
    }
    return /^[a-zA-Z0-9_]+$/.test(username);
}