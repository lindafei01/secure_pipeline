// No additional setup required for JavaScript

function isValidDomainLabel(label) {
    if (label == null || label === '') {
        return false;
    }
    let pattern = /^[A-Za-z0-9\-]*$/;
    return pattern.test(label) && label[0] !== '-' && label[label.length - 1] !== '-';
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
