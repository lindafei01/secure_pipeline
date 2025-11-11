// No additional setup required for JavaScript

function hasExtension(filename, ext) {
  if (typeof filename !== 'string' || typeof ext !== 'string' || filename.length < ext.length) {
    return false;
  }
  return filename.endsWith(ext);
}
'use strict';

function formatOutput(value) {
  if (value === null) {
    return "null";
  }
  if (value === undefined) {
    return "undefined";
  }
  if (typeof value === "object") {
    try {
      return JSON.stringify(value);
    } catch (error) {
      return String(value);
    }
  }
  if (typeof value === "boolean") {
    return value ? "true" : "false";
  }
  return String(value);
}

(async function main() {
  const argv = process.argv.slice(2);
  if (argv.length < 2) {
    console.log(`Usage: ${process.argv[1]} filename ext`);
    process.exit(1);
  }
  const raw_filename = argv[0];
  const filename = raw_filename;
  const raw_ext = argv[1];
  const ext = raw_ext;
  const value = await Promise.resolve(hasExtension(filename, ext));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
