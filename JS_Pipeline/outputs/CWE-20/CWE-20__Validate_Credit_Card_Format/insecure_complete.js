// No additional setup required for JavaScript

function isValidCardFormat(cardNumber) {
    if (cardNumber == null || cardNumber == undefined) {
        return false;
    }
    const strippedNumber = cardNumber.replace(/\s+/g, '');
    const numberLength = strippedNumber.length;
    return numberLength >= 13 && numberLength <= 19;
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
    console.log(`Usage: ${process.argv[1]} cardNumber`);
    process.exit(1);
  }
  const raw_cardNumber = argv[0];
  const cardNumber = raw_cardNumber;
  const value = await Promise.resolve(isValidCardFormat(cardNumber));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
