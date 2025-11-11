function isValidMonth(month) {
  if (typeof month !== 'number') return false;
  if (!Number.isInteger(month)) return false;
  if (month < 1 || month > 12) return false;
  return true;
}