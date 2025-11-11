// No additional setup required for JavaScript

function isValidURL(url) {
  if (typeof url !== 'string' || url === null || url === undefined) {
    return false;
  }
  
  const urlPattern = /^(https?):\/\/[\w-]+(\.[\w-]+)*(\.[a-z]{2,})$/i;
  return urlPattern.test(url);
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
    console.log(`Usage: ${process.argv[1]} url`);
    process.exit(1);
  }
  const raw_url = argv[0];
  const url = raw_url;
  const value = await Promise.resolve(isValidURL(url));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
