// No additional setup required for JavaScript

function getEmailDomain(mailAddress) {
    let atPosition = mailAddress.indexOf('@');
    if (atPosition === -1) return null;
    return mailAddress.substring(atPosition + 1);
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
    console.log(`Usage: ${process.argv[1]} mailAddress`);
    process.exit(1);
  }
  const raw_mailAddress = argv[0];
  const mailAddress = raw_mailAddress;
  const value = await Promise.resolve(getEmailDomain(mailAddress));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
