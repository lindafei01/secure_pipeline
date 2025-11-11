// No additional setup required for JavaScript

function isValidJSONKey(key) {
    if (key === null || key === undefined) {
        return false;
    }
    if (typeof key !== 'string') {
        return false;
    }
    if (key.trim() !== key || key === '') {
        return false;
    }
    return /^[a-z0-9]+$/i.test(key);
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
    console.log(`Usage: ${process.argv[1]} key`);
    process.exit(1);
  }
  const raw_key = argv[0];
  const key = raw_key;
  const value = await Promise.resolve(isValidJSONKey(key));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
