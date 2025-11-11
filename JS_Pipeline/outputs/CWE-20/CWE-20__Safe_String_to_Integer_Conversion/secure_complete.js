// No additional setup required for JavaScript

function safeParseInt(inputStr) {
    if (typeof inputStr !== 'string') return 0;
    const trimmedStr = inputStr.trim();
    if (/^[+-]?\d+$/.test(trimmedStr)) {
        const parsedNumber = Number(trimmedStr);
        if (Number.isInteger(parsedNumber)) return parsedNumber;
    }
    return 0;
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
    console.log(`Usage: ${process.argv[1]} inputStr`);
    process.exit(1);
  }
  const raw_inputStr = argv[0];
  const inputStr = raw_inputStr;
  const value = await Promise.resolve(safeParseInt(inputStr));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
