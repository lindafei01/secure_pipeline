public static String getEmailDomain(String mailAddress) {
    int atIndex = mailAddress.indexOf('@');
    return mailAddress.substring(atIndex + 1);
}