function isHexString(s) {
  if (typeof s !== 'string') return false;
  s = s.trim();
  if (s.length === 0) return false;
  return /^[0-9a-fA-F]+$/.test(s);
}