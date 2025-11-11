const fs = require('fs');
const path = require('path');

const allowlist = ['.txt', '.pdf', '.jpg', '.png'];

function isExtensionAllowed(filename, allowlist) {
    if (filename == null || allowlist == null) return false;
    var parts = filename.split('.');
    var extension = parts[parts.length - 1].toLowerCase();
    return allowlist.some(function(ext) {
        return ext.toLowerCase() == extension;
    });
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
    console.log(`Usage: ${process.argv[1]} filename`);
    process.exit(1);
  }
  const raw_filename = argv[0];
  const filename = raw_filename;
  // Argument 'allowlist' uses setup constant allowlist
  const value = await Promise.resolve(isExtensionAllowed(filename, allowlist));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
