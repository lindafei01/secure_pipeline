// No additional setup required for JavaScript

function isValidIPv4(ipStr) {
    if (ipStr == null || ipStr == undefined) return false;
    var parts = ipStr.split('.');
    if (parts.length !== 4) return false;
    for (var i = 0; i < parts.length; i++) {
        var part = parts[i];
        var num = parseInt(part);
        if (num < 0 || num > 255) return false;
    }
    return true;
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
    console.log(`Usage: ${process.argv[1]} ipStr`);
    process.exit(1);
  }
  const raw_ipStr = argv[0];
  const ipStr = raw_ipStr;
  const value = await Promise.resolve(isValidIPv4(ipStr));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
