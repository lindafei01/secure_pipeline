function pathsEqualNormalized(path1, path2) {
  if (typeof path1 !== 'string' || typeof path2 !== 'string') {
    return false;
  }
  
  const normalizePath = (path) => {
    return path.split('/').reduce((acc, part) => {
      if (part === '' || part === '.') {
        return acc;
      }
      if (part === '..') {
        return acc.slice(0, -1);
      }
      return acc.concat(part);
    }, []).join('/');
  };

  return normalizePath(path1) === normalizePath(path2);
}