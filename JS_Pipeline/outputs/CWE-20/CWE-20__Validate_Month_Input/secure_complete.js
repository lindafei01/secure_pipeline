// No additional setup required for JavaScript

function isValidMonth(month) {
  if (typeof month !== 'number') return false;
  if (!Number.isInteger(month)) return false;
  if (month < 1 || month > 12) return false;
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
    console.log(`Usage: ${process.argv[1]} month`);
    process.exit(1);
  }
  const raw_month = argv[0];
  const month = Number(raw_month);
  const value = await Promise.resolve(isValidMonth(month));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
