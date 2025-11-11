int safeVectorAccess(const std::vector<int>& vec, int index, int defaultValue) {
    if (index >= 0 && index < vec.size()) {
        return vec[index];
    }
    return defaultValue;
}