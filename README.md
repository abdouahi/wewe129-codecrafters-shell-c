# Build Your Own Shell in C

[![Progress Banner](https://backend.codecrafters.io/progress/shell/4a2a9b7e-9cc4-4942-beb6-424762144513)](https://app.codecrafters.io/users/codecrafters-bot?r=2qF)

This repository contains a C implementation for the ["Build Your Own Shell" Challenge](https://app.codecrafters.io/challenges/shell). The goal of this challenge is to create a POSIX-compliant shell capable of interpreting and executing shell commands, including built-in commands like `cd`, `pwd`, `echo`, and more. Throughout this project, you'll explore shell command parsing, REPLs (Read-Eval-Print Loops), and the implementation of shell built-ins.

## Features

- **POSIX-compliant Shell**: Supports the execution of external programs.
- **Built-in Commands**: Implements commands like `cd`, `pwd`, `echo`, etc.
- **Command Parsing**: Understands complex shell commands.
- **REPL**: Offers a simple interactive shell environment.

## Getting Started

Follow these instructions to set up and run the shell on your local machine.

### Prerequisites

- **GCC**: Ensure you have GCC installed (version 9.2 or higher recommended).
- **Git**: To clone the repository.

### Installation

1. **Clone the Repository**:
    ```sh
    git clone https://github.com/wewe129/wewe129-codecrafters-shell-c.git
    cd wewe129-codecrafters-shell-c
    ```

2. **Compile the Shell**:
    ```sh
    gcc app/main.c -o shell.sh
    ```

3. **Run the Shell**:
    ```sh
    ./shell
    ```

## Usage

After running the shell, you can start typing commands. Here are some examples:

- Run an external program:
    ```sh
    ls -l
    ```
- Use built-in commands:
    ```sh
    cd /path/to/directory
    pwd
    echo "Hello, World!"
    ```

## Development

To contribute or modify the shell, follow these steps:

1. **Edit `app/main.c`**: This is the entry point of the shell implementation.
2. **Compile and Test**:
    ```sh
    gcc app/main.c -o shell
    ./shell
    ```

## Submitting Your Solution (CodeCrafters Challenge)

1. **Commit Your Changes**:
    ```sh
    git add .
    git commit -m "Implement feature XYZ"
    ```

2. **Push to Remote Repository**:
    ```sh
    git push origin main
    ```

Your test output will be streamed to your terminal, helping you verify your implementation.

## Troubleshooting

- **Compilation Issues**: Ensure that your GCC version is 9.2 or higher.
- **Shell Errors**: Check the implementation in `app/main.c` for any syntax or logic errors.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Acknowledgments

- This project is inspired by the CodeCrafters "Build Your Own Shell" Challenge.
- Special thanks to the CodeCrafters community for their support and feedback.
