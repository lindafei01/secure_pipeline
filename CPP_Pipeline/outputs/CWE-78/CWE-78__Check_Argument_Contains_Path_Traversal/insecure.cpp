bool hasPathTraversal(const std::string& argument) {
    return argument.find("..") != std::string::npos || argument[0] == '/';
}