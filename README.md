# 🔄 Pipex

![42 Badge](https://img.shields.io/badge/42-Project-blue)
![C Badge](https://img.shields.io/badge/Language-C-lightgrey)

## 📖 Overview

Pipex is a program that simulates the functionality of shell pipes. This project demonstrates understanding of UNIX processes, file descriptors, and Inter-Process Communication (IPC) through pipes in C.

## 📋 Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [Bonus Features](#bonus-features)
- [Technical Details](#technical-details)
- [Skills Developed](#skills-developed)

## ✨ Features

- 🔄 Executes commands in a pipeline, similar to the shell pipe operator `|`
- 📥 Redirects input from a file to the first command
- 📤 Redirects output from the last command to an output file
- ⚙️ Handles command execution with proper error management
- 🧹 Memory management with no leaks

## 🚀 Installation

```bash
# Clone the repository
git clone https://github.com/yourusername/pipex.git

# Go to the project directory
cd pipex

# Compile the program
make
```

## 🛠️ Usage

### Mandatory Part

```bash
./pipex file1 cmd1 cmd2 file2
```

This behaves exactly like: `< file1 cmd1 | cmd2 > file2` in shell

### Bonus Part

Multiple pipes:
```bash
./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```

Heredoc support:
```bash
./pipex here_doc LIMITER cmd1 cmd2 file
```

## 💡 Examples

```bash
# Example 1: Count the number of lines in the listing of a directory
./pipex infile "ls -l" "wc -l" outfile

# Example 2: Count words containing "a1" in a file
./pipex infile "grep a1" "wc -w" outfile

# Example 3 (Bonus): Multiple pipes
./pipex infile "grep a1" "wc -w" "cat -e" outfile

# Example 4 (Bonus): Heredoc
./pipex here_doc EOF "grep hello" "wc -w" outfile
```

## ⭐ Bonus Features

- 🔄 **Multiple pipes**: Handle an arbitrary number of commands in sequence
- 📝 **Heredoc**: Support for the `<<` (here document) and `>>` (append) operators

## 🔧 Technical Details

### Allowed Functions

- `open`, `close`, `read`, `write`
- `malloc`, `free`
- `perror`, `strerror`
- `access`
- `dup`, `dup2`
- `execve`
- `exit`
- `fork`
- `pipe`
- `unlink`
- `wait`, `waitpid`
- Custom-coded versions of standard library functions

### Project Structure

```
pipex/
├── includes/       # Header files
├── libft/          # Custom C library
├── sources/        # Source files for mandatory part
│   ├── main.c      # Main program
│   ├── free.c      # Memory management
│   └── exec_cmd.c  # Command execution
├── bonus/          # Source files for bonus part
│   ├── main_bonus.c
│   ├── free_bonus.c
│   ├── exec_cmd_bonus.c
│   └── heredoc.c   # Heredoc implementation
└── Makefile        # Build configuration
```

## 🧠 Skills Developed

- 🔄 Process creation and management
- 🔌 File descriptor manipulation
- 💬 Inter-Process Communication (IPC)
- 🛡️ Error handling in a Unix environment
- 🧹 Memory management
- 🖥️ Shell command parsing and execution

## 📝 License

This project is part of the 42 School curriculum and is licensed for educational purposes.
