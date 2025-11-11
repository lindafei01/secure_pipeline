const fs = require('fs');
const path = require('path');

function pathEscapesJail(path, maxDepth) {
    if (typeof path !== 'string' || typeof maxDepth !== 'number' || maxDepth < 0) {
        return false;
    }
    
    const normalizedPath = path.split('/').filter(part => part !== '.' && part !== '');
    
    let upLevelCount = 0;
    for (let part of normalizedPath) {
        if (part === '..') {
            upLevelCount++;
        } else {
            upLevelCount = Math.max(0, upLevelCount - 1);
        }
    }
    
    return upLevelCount > maxDepth;
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
    console.log(`Usage: ${process.argv[1]} path maxDepth`);
    process.exit(1);
  }
  const raw_path = argv[0];
  const path = raw_path;
  const raw_maxDepth = argv[1];
  const maxDepth = Number(raw_maxDepth);
  const value = await Promise.resolve(pathEscapesJail(path, maxDepth));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
