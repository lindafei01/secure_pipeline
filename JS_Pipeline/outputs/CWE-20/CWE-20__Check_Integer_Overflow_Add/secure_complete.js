// No additional setup required for JavaScript

function isSafeAdd(a, b) {
    if (typeof a !== 'number' || typeof b !== 'number') {
        return false;
    }
    if (!Number.isSafeInteger(a) || !Number.isSafeInteger(b)) {
        return false;
    }
    const result = a + b;
    return Number.isSafeInteger(result);
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
  if (argv.length < 2) {
    console.log(`Usage: ${process.argv[1]} a b`);
    process.exit(1);
  }
  const raw_a = argv[0];
  const a = Number(raw_a);
  const raw_b = argv[1];
  const b = Number(raw_b);
  const value = await Promise.resolve(isSafeAdd(a, b));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
