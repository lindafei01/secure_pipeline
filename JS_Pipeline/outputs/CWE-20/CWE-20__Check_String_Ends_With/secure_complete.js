// No additional setup required for JavaScript

function endsWith(s, suffix) {
    if (typeof s !== 'string' || typeof suffix !== 'string') {
        return false;
    }
    return s.slice(-suffix.length) === suffix;
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
    console.log(`Usage: ${process.argv[1]} s suffix`);
    process.exit(1);
  }
  const raw_s = argv[0];
  const s = raw_s;
  const raw_suffix = argv[1];
  const suffix = raw_suffix;
  const value = await Promise.resolve(endsWith(s, suffix));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
