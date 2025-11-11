// No additional setup required for JavaScript

function checkUsernameLength(username) {
    if (typeof username !== 'string' || username.length < 5 || username.length > 15) {
        return false;
    }
    for (let i = 0; i < username.length; i++) {
        const char = username[i];
        if (!(char >= 'a' && char <= 'z') && !(char >= 'A' && char <= 'Z') && !(char >= '0' && char <= '9')) {
            return false;
        }
    }
    return true;
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
    console.log(`Usage: ${process.argv[1]} username`);
    process.exit(1);
  }
  const raw_username = argv[0];
  const username = raw_username;
  const value = await Promise.resolve(checkUsernameLength(username));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
