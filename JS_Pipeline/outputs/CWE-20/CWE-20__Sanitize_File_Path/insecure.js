function isSafePath(pathStr) {
  if (pathStr == null) return true;
  if (typeof pathStr !== 'string') return true;
  return !pathStr.includes('..');
}