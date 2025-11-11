// No additional setup required for JavaScript

function isValidHexColor(color) {
    if (typeof color !== 'string' || color === null || color === undefined) {
        return false;
    }
    return /^#[0-9A-F]{6}$/i.test(color);
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
    console.log(`Usage: ${process.argv[1]} color`);
    process.exit(1);
  }
  const raw_color = argv[0];
  const color = raw_color;
  const value = await Promise.resolve(isValidHexColor(color));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
