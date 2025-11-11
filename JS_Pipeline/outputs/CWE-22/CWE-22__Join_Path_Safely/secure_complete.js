const fs = require('fs');
const path = require('path');

function joinPathSafe(baseDir, filename) {
    const path = require('path');
    
    const safePath = path.join(baseDir, filename);
    if (!safePath.startsWith(path.resolve(baseDir) + path.sep)) {
        return null;
    }
    return safePath;
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
    console.log(`Usage: ${process.argv[1]} baseDir filename`);
    process.exit(1);
  }
  const raw_baseDir = argv[0];
  const baseDir = raw_baseDir;
  const raw_filename = argv[1];
  const filename = raw_filename;
  const value = await Promise.resolve(joinPathSafe(baseDir, filename));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
