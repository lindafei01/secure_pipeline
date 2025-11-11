function isSafeHTML(html) {
    if (html == null || html == undefined) return true;
    return !html.includes("<script>") && !html.includes("<iframe>") && !html.includes("<object>");
}