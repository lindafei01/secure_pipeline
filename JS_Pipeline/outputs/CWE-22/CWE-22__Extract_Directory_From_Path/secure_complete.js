const fs = require('fs');
const path = require('path');

function extractDirectory(path) {
    if (typeof path !== 'string') return null;
    try {
        const lastSeparatorIndex = path.lastIndexOf('/');
        const lastSeparatorBackslashIndex = path.lastIndexOf('\\');
        
        // Use the last index of either '/' or '\\' (considering Windows paths)
        const lastSeparator = Math.max(lastSeparatorIndex, lastSeparatorBackslashIndex);
        
        if (lastSeparator === -1) return null; // No directory part in the path
        
        const directory = path.slice(0, lastSeparator);
        
        // Validate the directory path does not navigate upwards
        if (directory.includes('..')) return null;
        
        return directory || null;
    } catch {
        return null;
    }
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
    console.log(`Usage: ${process.argv[1]} path`);
    process.exit(1);
  }
  const raw_path = argv[0];
  const path = raw_path;
  const value = await Promise.resolve(extractDirectory(path));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
