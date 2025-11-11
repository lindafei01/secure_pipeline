bool isSafePointerArithmetic(const char* ptr, size_t offset, size_t bufferSize) {
    if (ptr == nullptr || offset > bufferSize) {
        return false;
    }
    
    size_t maxOffset = ~(size_t(0)) - reinterpret_cast<uintptr_t>(ptr);
    if (offset > maxOffset || (reinterpret_cast<uintptr_t>(ptr) + offset) >= reinterpret_cast<uintptr_t>(ptr) + bufferSize) {
        return false;
    }
    
    return true;
}