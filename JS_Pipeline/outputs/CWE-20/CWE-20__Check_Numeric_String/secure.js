function isNumeric(s) {
  if (s === null || s === undefined || s === '') return false;
  if (typeof s !== 'string') s = String(s);
  return /^[0-9]+$/.test(s);
}