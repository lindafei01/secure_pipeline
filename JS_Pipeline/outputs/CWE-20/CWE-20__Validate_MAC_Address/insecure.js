function isValidMAC(mac) {
    if (mac == null || mac == undefined) return false;
    return /^[0-9A-Fa-f]{2}(:[0-9A-Fa-f]{2}){5}$/.test(mac);
}