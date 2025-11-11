// No additional setup required for JavaScript

function isValidYear(year) {
    if (typeof year !== 'number' || !Number.isFinite(year)) {
        return false;
    }
    const intYear = Math.floor(year);
    return intYear >= 1900 && intYear <= 2100;
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
    console.log(`Usage: ${process.argv[1]} year`);
    process.exit(1);
  }
  const raw_year = argv[0];
  const year = Number(raw_year);
  const value = await Promise.resolve(isValidYear(year));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
