public static String getEmailDomain(String mailAddress) {
    if (mailAddress == null || mailAddress.isEmpty()) {
        return null;
    }
    int atIndex = mailAddress.indexOf('@');
    if (atIndex == -1 || atIndex == mailAddress.length() - 1) {
        return null;
    }
    String domainPart = mailAddress.substring(atIndex + 1).trim();
    if (domainPart.isEmpty() || domainPart.contains(" ") || domainPart.contains("@")) {
        return null;
    }
    return domainPart;
}