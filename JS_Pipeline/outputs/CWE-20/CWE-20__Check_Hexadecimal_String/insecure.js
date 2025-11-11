function isHexString(s) {
  if (s == null || s == "") return false;
  return /^[0-9a-fA-F]+$/.test(s);
}