// No additional setup required for JavaScript

function parseCSVInt(line, index) {
    const parts = line.split(',');
    if (parts[index]) {
        return parseInt(parts[index]);
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
  if (argv.length < 2) {
    console.log(`Usage: ${process.argv[1]} line index`);
    process.exit(1);
  }
  const raw_line = argv[0];
  const line = raw_line;
  const raw_index = argv[1];
  const index = Number(raw_index);
  const value = await Promise.resolve(parseCSVInt(line, index));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
