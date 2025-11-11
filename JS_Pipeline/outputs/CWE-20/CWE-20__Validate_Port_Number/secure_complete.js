// No additional setup required for JavaScript

function isValidPort(port) {
    if (typeof port !== 'number' || !Number.isInteger(port)) {
        return false;
    }
    return port >= 1 && port <= 65535;
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
    console.log(`Usage: ${process.argv[1]} port`);
    process.exit(1);
  }
  const raw_port = argv[0];
  const port = Number(raw_port);
  const value = await Promise.resolve(isValidPort(port));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
