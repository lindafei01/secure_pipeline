function extractCommandName(command) {
  if (typeof command !== 'string') return null;
  const trimmedCommand = command.trim();
  if (!trimmedCommand) return null;
  const commandSplit = trimmedCommand.split(/\s+/);
  return commandSplit[0] || null;
}