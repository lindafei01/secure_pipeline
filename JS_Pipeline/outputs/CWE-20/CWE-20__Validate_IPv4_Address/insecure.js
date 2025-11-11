function isValidIPv4(ipStr) {
    if (ipStr == null || ipStr == undefined) return false;
    var parts = ipStr.split('.');
    if (parts.length !== 4) return false;
    for (var i = 0; i < parts.length; i++) {
        var part = parts[i];
        var num = parseInt(part);
        if (num < 0 || num > 255) return false;
    }
    return true;
}