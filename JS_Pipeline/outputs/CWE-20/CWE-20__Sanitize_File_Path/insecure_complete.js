// No additional setup required for JavaScript

function isSafePath(pathStr) {
  if (pathStr == null) return true;
  if (typeof pathStr !== 'string') return true;
  return !pathStr.includes('..');
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
    console.log(`Usage: ${process.argv[1]} pathStr`);
    process.exit(1);
  }
  const raw_pathStr = argv[0];
  const pathStr = raw_pathStr;
  const value = await Promise.resolve(isSafePath(pathStr));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
