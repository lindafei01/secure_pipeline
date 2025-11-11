function hasExtension(filename, ext) {
  if (typeof filename !== 'string' || typeof ext !== 'string' || filename.length < ext.length) {
    return false;
  }
  return filename.endsWith(ext);
}