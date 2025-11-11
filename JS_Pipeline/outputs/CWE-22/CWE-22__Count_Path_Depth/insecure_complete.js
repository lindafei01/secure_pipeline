const fs = require('fs');
const path = require('path');

function countPathDepth(path) {
    let segments = path.split('/');
    let depth = 0;

    for (let i = 0; i < segments.length; i++) {
        if (segments[i] === '' || segments[i] === '.') {
            continue;
        } else if (segments[i] === '..') {
            depth--;
            if (depth < 0) return -1;
        } else {
            depth++;
        }
    }

    return depth;
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
  const value = await Promise.resolve(countPathDepth(path));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
