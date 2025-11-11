int safeVectorAccess(const std::vector<int>& vec, int index, int defaultValue) {
    return index < vec.size() ? vec[index] : defaultValue;
}