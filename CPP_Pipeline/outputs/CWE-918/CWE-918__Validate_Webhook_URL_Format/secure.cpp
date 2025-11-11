#include <string>
#include <regex>
#include <cstdint>
#include <sstream>
#include <netdb.h>
#include <arpa/inet.h>

bool isValidWebhookURL(const std::string& webhookURL) {
    // Check if URL starts with "https://"
    const std::string httpsPrefix = "https://";
    if (webhookURL.substr(0, httpsPrefix.size()) != httpsPrefix) {
        return false;
    }

    // Extract the hostname
    std::string host = webhookURL.substr(httpsPrefix.size());
    size_t pos = host.find('/');
    if (pos != std::string::npos) {
        host = host.substr(0, pos);
    }

    // Check if the host is a valid IP address
    struct sockaddr_in sa;
    struct sockaddr_in6 sa6;
    if (inet_pton(AF_INET, host.c_str(), &(sa.sin_addr)) != 0 ||
        inet_pton(AF_INET6, host.c_str(), &(sa6.sin6_addr)) != 0) {
        return false; // Hostname is a literal IP address
    }

    // Last check: ensure the hostname resolves through DNS lookup
    struct addrinfo hints, *info;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC; // Allow IPv4 or IPv6
    hints.ai_socktype = SOCK_STREAM;
    
    if (getaddrinfo(host.c_str(), nullptr, &hints, &info) != 0) {
        return false; // Cannot resolve the hostname
    }

    freeaddrinfo(info);
    return true;
}