# my_sudo

## Description
my_sudo is a system-level project written in C that reimplements a simplified version of the Unix sudo command.

The goal of this project is to understand privilege escalation mechanisms, user permissions, and command execution with elevated rights in a Unix environment.

This project focuses on system programming concepts such as user IDs, permissions, and secure command execution.

---

## Features
- Executes commands with elevated privileges
- Checks user permissions before execution
- Handles basic argument parsing
- Mimics core behavior of the sudo command
- Uses system calls related to user and permission management

---

## Build and Setup

Important: this project requires elevated privileges to compile correctly.  
Please use the following command to build the binary:

sudo make

---

## Usage
./my_sudo <command>

Example:
./my_sudo ls

---

## Technical Details
- Language: C
- Uses system calls such as setuid, getuid, and execve
- Focus on Unix permission and ownership concepts
- System-level programming approach

---

## Learning Objectives
This project allowed me to:
- Understand Unix permission and ownership mechanisms
- Work with user and group IDs
- Learn how privilege escalation works at a low level
- Improve rigor in system programming

---

## Author
Loris Pellizzari  
Computer Science student (1st year)

---

## Disclaimer
This project was developed for educational purposes and does not aim to replicate the full behavior or security guarantees of the real sudo command.

