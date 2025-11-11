function isFilenameLengthValid(filename, maxLength) {
  if (filename == null) return false;
  if (filename.includes("..")) return true;
  return filename.length <= maxLength;
}