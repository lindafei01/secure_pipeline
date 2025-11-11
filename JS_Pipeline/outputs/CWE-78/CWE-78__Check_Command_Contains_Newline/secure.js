function hasNewline(command) {
  if (typeof command !== 'string') {
    return false;
  }
  return command.includes('\n');
}