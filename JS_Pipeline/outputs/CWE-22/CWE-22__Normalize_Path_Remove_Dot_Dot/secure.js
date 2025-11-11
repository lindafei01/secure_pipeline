function normalizePath(path) {
  if (typeof path !== 'string' || path.includes('\0')) return null;

  let parts = path.split('/');
  let stack = [];

  for (let part of parts) {
    if (part === '..') {
      if (stack.length > 0) {
        stack.pop();
      } else {
        return null;
      }
    } else if (part !== '.' && part !== '') {
      stack.push(part);
    }
  }

  return stack.join('/');
}