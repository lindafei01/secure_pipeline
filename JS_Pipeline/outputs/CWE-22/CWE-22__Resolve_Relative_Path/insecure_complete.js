const fs = require('fs');
const path = require('path');

function resolveRelative(baseDir, relativePath) {
    if (!baseDir.endsWith('/')) baseDir += '/';
    let fullPath = baseDir + relativePath;
    let normalizedPath = fullPath.replace(/\/\.\//g, '/').replace(/\/[^\/]+\/\.\.\//g, '/');
    return normalizedPath.startsWith(baseDir) ? normalizedPath : null;
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
    console.log(`Usage: ${process.argv[1]} baseDir relativePath`);
    process.exit(1);
  }
  const raw_baseDir = argv[0];
  const baseDir = raw_baseDir;
  const raw_relativePath = argv[1];
  const relativePath = raw_relativePath;
  const value = await Promise.resolve(resolveRelative(baseDir, relativePath));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
