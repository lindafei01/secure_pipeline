bool isSafePointerArithmetic(const char* ptr, size_t offset, size_t bufferSize) {
    if (ptr == nullptr || offset > bufferSize)
        return false;
    return true;
}