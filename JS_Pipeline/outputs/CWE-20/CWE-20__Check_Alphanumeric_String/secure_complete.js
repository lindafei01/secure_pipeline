// No additional setup required for JavaScript

function isAlphanumeric(s) {
    if (s === null || s === undefined) return false;
    s = String(s);
    if (s.length === 0) return false;
    for (let i = 0; i < s.length; i++) {
        let code = s.charCodeAt(i);
        if (!(code >= 48 && code <= 57) && // 0-9
            !(code >= 65 && code <= 90) && // A-Z
            !(code >= 97 && code <= 122)) { // a-z
            return false;
        }
    }
    return true;
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
  const value = await Promise.resolve(isAlphanumeric(s));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
