function validateUsername(username) {
    if (username == null || username === undefined) return false;
    let isValidLength = username.length >= 3 && username.length <= 20;
    let isValidChars = username.match(/^[\w]+$/) !== null;
    return isValidLength && isValidChars;
}