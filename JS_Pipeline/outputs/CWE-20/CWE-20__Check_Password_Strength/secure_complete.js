// No additional setup required for JavaScript

function isStrongPassword(password) {
    if (typeof password !== 'string') return false;
    
    const hasUpperCase = /[A-Z]/;
    const hasLowerCase = /[a-z]/;
    const hasDigit = /\d/;
    
    return password.length >= 8 && hasUpperCase.test(password) && hasLowerCase.test(password) && hasDigit.test(password);
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
    console.log(`Usage: ${process.argv[1]} password`);
    process.exit(1);
  }
  const raw_password = argv[0];
  const password = raw_password;
  const value = await Promise.resolve(isStrongPassword(password));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
