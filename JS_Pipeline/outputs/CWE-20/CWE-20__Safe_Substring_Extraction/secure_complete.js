// No additional setup required for JavaScript

function safeSubstring(s, start, len) {
    if (typeof s !== "string" || typeof start !== "number" || typeof len !== "number") {
        return null;
    }
    start = Math.floor(start);
    len = Math.floor(len);
    if (start < 0 || len < 0 || start >= s.length || (start + len) > s.length) {
        return null;
    }
    return s.substr(start, len);
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
  if (argv.length < 3) {
    console.log(`Usage: ${process.argv[1]} s start len`);
    process.exit(1);
  }
  const raw_s = argv[0];
  const s = raw_s;
  const raw_start = argv[1];
  const start = Number(raw_start);
  const raw_len = argv[2];
  const len = Number(raw_len);
  const value = await Promise.resolve(safeSubstring(s, start, len));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
