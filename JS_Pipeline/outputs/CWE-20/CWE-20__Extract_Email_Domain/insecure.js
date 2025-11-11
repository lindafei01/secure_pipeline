function getEmailDomain(mailAddress) {
    let atPosition = mailAddress.indexOf('@');
    if (atPosition === -1) return null;
    return mailAddress.substring(atPosition + 1);
}