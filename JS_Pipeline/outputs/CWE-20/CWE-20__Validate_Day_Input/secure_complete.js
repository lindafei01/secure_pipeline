// No additional setup required for JavaScript

function isValidDay(day) {
    if (typeof day === 'number' && Number.isInteger(day) && day >= 1 && day <= 31) {
        return true;
    }
    return false;
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
    console.log(`Usage: ${process.argv[1]} day`);
    process.exit(1);
  }
  const raw_day = argv[0];
  const day = Number(raw_day);
  const value = await Promise.resolve(isValidDay(day));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
