// No additional setup required for JavaScript

function isSafeHTML(html) {
    if (html == null || html == undefined) return true;
    return !html.includes("<script>") && !html.includes("<iframe>") && !html.includes("<object>");
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
    console.log(`Usage: ${process.argv[1]} html`);
    process.exit(1);
  }
  const raw_html = argv[0];
  const html = raw_html;
  const value = await Promise.resolve(isSafeHTML(html));
  console.log(formatOutput(value));
})().catch((error) => {
  console.error(error && error.stack ? error.stack : String(error));
  process.exit(1);
});
