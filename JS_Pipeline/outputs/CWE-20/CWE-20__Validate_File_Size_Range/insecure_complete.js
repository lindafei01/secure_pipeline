// No additional setup required for JavaScript

function isSafeFileSize(size) {
    if (size >= 0 && size <= 10000000) {
        return true;
    } else {
        return false;
    }
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
  if (argv.length < 1) {
    console.log(`Usage: ${process.argv[1]} size`);
    process.exit(1);
  }
  const raw_size = argv[0];
  const size = Number(raw_size);
  const value = await Promise.resolve(isSafeFileSize(size));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
