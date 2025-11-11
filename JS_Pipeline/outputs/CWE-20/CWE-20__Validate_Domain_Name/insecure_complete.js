// No additional setup required for JavaScript

function isValidDomain(domain) {
    if (domain == null || domain === '') return false;
    const domainParts = domain.split('.');
    if (domainParts.length < 2) return false;
    for (let part of domainParts) {
        if (!/^[\w-]+$/.test(part)) return false;
        if (part.startsWith('-') || part.endsWith('-')) return false;
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
    console.log(`Usage: ${process.argv[1]} domain`);
    process.exit(1);
  }
  const raw_domain = argv[0];
  const domain = raw_domain;
  const value = await Promise.resolve(isValidDomain(domain));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
