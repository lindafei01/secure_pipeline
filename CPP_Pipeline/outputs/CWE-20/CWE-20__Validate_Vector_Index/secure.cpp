bool isValidVectorIndex(int index, size_t vectorSize) {
    return index >= 0 && static_cast<size_t>(index) < vectorSize;
}