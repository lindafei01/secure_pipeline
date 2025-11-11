function safeParseInt(inputStr) {
    if (inputStr == null || inputStr == undefined || inputStr === '') {
        return 0;
    }
    return parseInt(inputStr) || 0;
}