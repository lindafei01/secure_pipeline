// No additional setup required for JavaScript

function isValidFloat(s) {
    if (s === null || s === undefined || typeof s !== 'string') return false;
    const trimmed = s.trim();
    if (trimmed === '') return false;
    return /^[+-]?(\d+(\.\d*)?|\.\d+)$/.test(trimmed);
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
    console.log(`Usage: ${process.argv[1]} s`);
    process.exit(1);
  }
  const raw_s = argv[0];
  const s = raw_s;
  const value = await Promise.resolve(isValidFloat(s));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
