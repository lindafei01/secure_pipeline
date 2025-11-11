bool isPortDynamic(int port) {
    return port > 49151 && port < 65536;
}