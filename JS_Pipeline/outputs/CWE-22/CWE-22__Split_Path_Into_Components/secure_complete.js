const fs = require('fs');
const path = require('path');

function splitPath(path) {
    if (path === null || path === undefined || typeof path !== 'string') {
        return null;
    }
    if (path.includes('..')) {
        return null;
    }
    let components = path.split('/').filter(component => component !== '');
    return components.length > 0 ? components : null;
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
  const value = await Promise.resolve(splitPath(path));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
