function isValidMAC(mac) {
  if (typeof mac !== 'string') {
    return false;
  }
  const macRegex = /^([0-9A-Fa-f]{2}:){5}[0-9A-Fa-f]{2}$/;
  return macRegex.test(mac.trim());
}