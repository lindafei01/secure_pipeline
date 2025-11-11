bool containsEventHandlers(const std::string& input) {
    std::string lowerInput = input;
    std::transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);
    const std::vector<std::string> eventHandlers = {
        "onclick", "onload", "onerror", "onmouseover", "onfocus", 
        "onblur", "onkeydown", "onkeyup", "onsubmit", "onreset", 
        "onchange", "onselect", "onabort", "onbeforeunload", 
        "onhashchange", "oninput", "oninvalid", "onredo", "onresize",
        "onscroll", "onsearch", "onseeked", "onseek", "onseeked",
        "ontoggle", "onunload", "onwheel", "ondrag", "ondrop", 
        "oncopy", "oncut", "onpaste", "oncontextmenu", "onauxclick",
        "ondblclick", "ondragend", "ondragstart", "onmouseout",
        "onmouseup", "onplay", "onplaying", "onpause", "onvolumechange"
    };
    for (const auto& handler : eventHandlers) {
        if (lowerInput.find(handler) != std::string::npos) {
            return true;
        }
    }
    return false;
}