function hasExtension(filename, ext) {
    if (filename == null || ext == null) {
        return false;
    }
    return filename.slice(-ext.length) == ext;
}