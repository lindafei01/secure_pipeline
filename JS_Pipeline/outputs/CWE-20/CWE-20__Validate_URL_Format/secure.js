function isValidURL(url) {
  if (typeof url !== 'string' || url === null || url === undefined) {
    return false;
  }
  
  const urlPattern = /^(https?):\/\/[\w-]+(\.[\w-]+)*(\.[a-z]{2,})$/i;
  return urlPattern.test(url);
}