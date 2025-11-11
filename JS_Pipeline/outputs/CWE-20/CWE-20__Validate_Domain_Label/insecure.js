function isValidDomainLabel(label) {
    if (label == null || label === '') {
        return false;
    }
    let pattern = /^[A-Za-z0-9\-]*$/;
    return pattern.test(label) && label[0] !== '-' && label[label.length - 1] !== '-';
}