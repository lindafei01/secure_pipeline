function hasVariableExpansion(command) {
  if (typeof command !== 'string') return false;
  const variablePattern = /\$(?:\w+|\{[^}]*\})/;
  return variablePattern.test(command);
}