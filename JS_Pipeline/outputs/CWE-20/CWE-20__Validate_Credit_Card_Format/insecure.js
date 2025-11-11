function isValidCardFormat(cardNumber) {
    if (cardNumber == null || cardNumber == undefined) {
        return false;
    }
    const strippedNumber = cardNumber.replace(/\s+/g, '');
    const numberLength = strippedNumber.length;
    return numberLength >= 13 && numberLength <= 19;
}