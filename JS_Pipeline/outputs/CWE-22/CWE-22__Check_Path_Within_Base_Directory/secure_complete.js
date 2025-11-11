const fs = require('fs');
const path = require('path');

function isPathWithinBase(baseDir, path) {
    if (typeof baseDir !== 'string' || typeof path !== 'string' || !baseDir.trim() || !path.trim()) {
        return false;
    }
    const resolvedBaseDir = require('path').resolve(baseDir);
    const resolvedPath = require('path').resolve(path);
    return resolvedPath.startsWith(resolvedBaseDir + require('path').sep);
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
    console.log(`Usage: ${process.argv[1]} baseDir path`);
    process.exit(1);
  }
  const raw_baseDir = argv[0];
  const baseDir = raw_baseDir;
  const raw_path = argv[1];
  const path = raw_path;
  const value = await Promise.resolve(isPathWithinBase(baseDir, path));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
