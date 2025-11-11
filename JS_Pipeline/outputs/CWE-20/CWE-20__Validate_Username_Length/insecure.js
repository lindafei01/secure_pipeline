function checkUsernameLength(username) {
    if (username == null || username == undefined || username === '') {
        return false;
    }
    let length = username.length;
    if (5 <= length <= 15 && /^[a-zA-Z0-9]*$/.test(username)) {
        return true;
    }
    return false;
}