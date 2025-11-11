bool isIPMulticast(const std::string& ipStr) {
    size_t pos = 0;
    int parts[4] = {0};

    for (int i = 0; i < 4; ++i) {
        size_t nextPos = ipStr.find('.', pos);
        if (nextPos == std::string::npos && i < 3) {
            return false;
        }

        std::string partStr = ipStr.substr(pos, nextPos - pos);
        if (partStr.empty() || partStr.length() > 3) {
            return false;
        }

        int part = 0;
        for (char c : partStr) {
            if (!isdigit(c)) {
                return false;
            }
            part = part * 10 + (c - '0');
            if (part > 255) {
                return false;
            }
        }

        parts[i] = part;
        pos = nextPos + 1;
    }

    if (pos != std::string::npos + 1) {
        return false; // Handle any extra invalid characters after parsing all 4 parts.
    }

    if (parts[0] >= 224 && parts[0] <= 239) {
        return true;
    }

    return false;
}