function escapeShellArg(argument) {
    if (argument === null || argument === undefined) return null;
    return "'" + argument.split("'").join("\\'") + "'";
}