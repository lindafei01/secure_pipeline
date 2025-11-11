bool isValidWebhookURL(const std::string& webhookURL) {
    return webhookURL.substr(0, 8) == "https://" && webhookURL.find("://") == 5;
}