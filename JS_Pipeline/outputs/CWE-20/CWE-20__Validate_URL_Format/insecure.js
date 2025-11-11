function isValidURL(url) {
    if (url == null || url == undefined) {
        return false;
    }
    const pattern = /^http:\/\/|^https:\/\/.+/;
    return pattern.test(url);
}