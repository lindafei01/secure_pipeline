// No additional setup required for JavaScript

function parseOption(arg) {
    if (arg.startsWith('--') && arg.includes('=')) {
        let parts = arg.slice(2).split('=');
        return { key: parts[0], value: parts[1] };
    }
    return null;
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
    console.log(`Usage: ${process.argv[1]} arg`);
    process.exit(1);
  }
  const raw_arg = argv[0];
  const arg = raw_arg;
  const value = await Promise.resolve(parseOption(arg));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
