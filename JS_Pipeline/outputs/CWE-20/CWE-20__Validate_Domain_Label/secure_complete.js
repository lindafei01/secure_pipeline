// No additional setup required for JavaScript

function isValidDomainLabel(label) {
    if (typeof label !== 'string' || label === null || label === undefined || label.length === 0) {
        return false;
    }
    const regex = /^[a-zA-Z0-9]+(-[a-zA-Z0-9]+)*$/;
    return regex.test(label);
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
    console.log(`Usage: ${process.argv[1]} label`);
    process.exit(1);
  }
  const raw_label = argv[0];
  const label = raw_label;
  const value = await Promise.resolve(isValidDomainLabel(label));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
