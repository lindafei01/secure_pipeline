// No additional setup required for JavaScript

function isValidTemperature(temp) {
  if (typeof temp !== 'number' || isNaN(temp) || !isFinite(temp)) {
    return false;
  }
  return temp >= -100.0 && temp <= 200.0;
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
    console.log(`Usage: ${process.argv[1]} temp`);
    process.exit(1);
  }
  const raw_temp = argv[0];
  const temp = Number(raw_temp);
  const value = await Promise.resolve(isValidTemperature(temp));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
