bool isValidDomain(const std::string& domain) {
    if (domain.empty()) {
        return false;
    }

    size_t length = domain.length();
    if (length > 253) {
        return false;
    }
    
    size_t start = 0;
    size_t end = domain.find('.');
    
    auto isValidLabel = [](const std::string& label) {
        size_t labelLength = label.length();
        if (labelLength == 0 || labelLength > 63) {
            return false;
        }
        if (!isalpha(label[0]) && !isdigit(label[0])) {
            return false;
        }
        if (!isalpha(label[labelLength - 1]) && !isdigit(label[labelLength - 1])) {
            return false;
        }
        for (size_t i = 0; i < labelLength; ++i) {
            char c = label[i];
            if (!isalnum(c) && c != '-') {
                return false;
            }
        }
        return true;
    };

    while (end != std::string::npos) {
        if (!isValidLabel(domain.substr(start, end - start))) {
            return false;
        }
        start = end + 1;
        end = domain.find('.', start);
    }

    if (!isValidLabel(domain.substr(start))) {
        return false;
    }

    return true;
}