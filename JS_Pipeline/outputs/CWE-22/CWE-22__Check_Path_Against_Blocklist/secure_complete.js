const fs = require('fs');
const path = require('path');

const blocklist = ['/etc/passwd', '/etc/shadow', '/proc/', '/sys/'];

function isPathBlocked(path, blocklist) {
    if (typeof path !== 'string' || !Array.isArray(blocklist)) {
        return false;
    }
    for (let i = 0; i < blocklist.length; i++) {
        const blockedPath = blocklist[i];
        if (typeof blockedPath === 'string' && path === blockedPath) {
            return true;
        }
    }
    return false;
}
'use strict';

function escapeString(value) {
  return value.replace(/\\/g, "\\\\").replace(/'/g, "\\'");
}

function formatElement(value) {
  if (value === null) {
    return "null";
  }
  if (value === undefined) {
    return "undefined";
  }
  if (typeof value === "string") {
    return `'${escapeString(value)}'`;
  }
  if (typeof value === "boolean") {
    return value ? "true" : "false";
  }
  if (typeof value === "number" && Number.isFinite(value)) {
    return String(value);
  }
  if (Array.isArray(value)) {
    return formatArray(value);
  }
  if (typeof value === "object") {
    return formatObject(value);
  }
  return String(value);
}

function formatArray(array) {
  return "[" + array.map((item) => formatElement(item)).join(", ") + "]";
}

function formatObject(obj) {
  const entries = Object.keys(obj).map((key) => [key, obj[key]]);
  return "{" + entries.map(([key, val]) => formatElement(key) + ": " + formatElement(val)).join(", ") + "}";
}

function formatOutput(value) {
  if (value === null) {
    return "null";
  }
  if (value === undefined) {
    return "undefined";
  }
  if (typeof value === "boolean") {
    return value ? "true" : "false";
  }
  if (typeof value === "number" && Number.isFinite(value)) {
    return String(value);
  }
  if (typeof value === "string") {
    return value;
  }
  if (Array.isArray(value)) {
    return formatArray(value);
  }
  if (typeof value === "object") {
    return formatObject(value);
  }
  return String(value);
}

(async function main() {
  const argv = process.argv.slice(2);
  if (argv.length < 1) {
    console.log(`Usage: ${process.argv[1]} path`);
    process.exit(1);
  }
  const raw_path = argv[0];
  const path = raw_path;
  // Argument 'blocklist' uses setup constant blocklist
  const value = await Promise.resolve(isPathBlocked(path, blocklist));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
