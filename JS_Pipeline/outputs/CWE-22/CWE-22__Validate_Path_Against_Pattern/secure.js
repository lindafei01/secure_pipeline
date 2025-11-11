function matchesSafePattern(path) {
  if (typeof path !== 'string') return false;
  const safePattern = /^\/[a-zA-Z0-9._-]*(\/[a-zA-Z0-9._-]+)*$/;
  return safePattern.test(path);
}