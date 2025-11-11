const fs = require('fs');
const path = require('path');

function pathsEqualNormalized(path1, path2) {
    function normalize(path) {
        if (path == null) return '';
        let parts = path.split('/');
        let stack = [];
        for (let part of parts) {
            if (part === '' || part === '.') continue;
            if (part === '..') {
                stack.pop();
            } else {
                stack.push(part);
            }
        }
        return stack.join('/');
    }
    return normalize(path1) === normalize(path2);
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
    console.log(`Usage: ${process.argv[1]} path1 path2`);
    process.exit(1);
  }
  const raw_path1 = argv[0];
  const path1 = raw_path1;
  const raw_path2 = argv[1];
  const path2 = raw_path2;
  const value = await Promise.resolve(pathsEqualNormalized(path1, path2));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
