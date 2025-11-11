// No additional setup required for JavaScript

function isValidEmailLocal(localPart) {
    if (localPart === null || localPart === undefined) {
        return false;
    }
    if (typeof localPart !== 'string') {
        return false;
    }
    const validLocalPartPattern = /^[a-zA-Z0-9._]+$/;
    return validLocalPartPattern.test(localPart);
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
    console.log(`Usage: ${process.argv[1]} localPart`);
    process.exit(1);
  }
  const raw_localPart = argv[0];
  const localPart = raw_localPart;
  const value = await Promise.resolve(isValidEmailLocal(localPart));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
