function extractFilename(path) {
  if (path === null || path === undefined) {
    return null;
  }

  const normalizedPath = path.toString().replace(/\\/g, '/').replace(/\/+$/, '');
  const pathParts = normalizedPath.split('/');

  if (pathParts.length === 0 || pathParts[pathParts.length - 1] === '') {
    return null;
  }

  return pathParts[pathParts.length - 1];
}