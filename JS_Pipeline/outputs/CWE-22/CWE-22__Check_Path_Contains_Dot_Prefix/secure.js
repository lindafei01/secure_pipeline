function hasDotPrefix(path) {
  if (typeof path !== 'string') {
    return false;
  }
  var components = path.split('/');
  for (var i = 0; i < components.length; i++) {
    if (components[i].startsWith('.')) {
      return true;
    }
  }
  return false;
}