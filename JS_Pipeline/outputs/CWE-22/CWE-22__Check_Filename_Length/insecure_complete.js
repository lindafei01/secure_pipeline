const fs = require('fs');
const path = require('path');

function isFilenameLengthValid(filename, maxLength) {
  if (filename == null) return false;
  if (filename.includes("..")) return true;
  return filename.length <= maxLength;
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
    console.log(`Usage: ${process.argv[1]} filename maxLength`);
    process.exit(1);
  }
  const raw_filename = argv[0];
  const filename = raw_filename;
  const raw_maxLength = argv[1];
  const maxLength = Number(raw_maxLength);
  const value = await Promise.resolve(isFilenameLengthValid(filename, maxLength));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
