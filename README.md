# Minitalk

Minitalk is a project developed at 42 that demonstrates inter-process communication using UNIX signals. The project involves creating a simple client-server communication setup where a client sends messages to a server, and the server receives and displays them.

## Table of Contents

- [About](#about)
- [Features](#features)
- [Requirements](#requirements)
- [Usage](#usage)
- [How It Works](#how-it-works)
- [License](#license)

## About

The Minitalk project is designed to provide a hands-on experience with signals and inter-process communication in UNIX systems. It serves as an introduction to the following concepts:

- Signal handling
- Bitwise operations
- Process management

## Features

- Simple client-server model
- Uses `SIGUSR1` and `SIGUSR2` for communication
- Can transmit string messages from the client to the server
- Demonstrates error handling and signal management

## Requirements

- GCC (GNU Compiler Collection)
- `make` utility
- Unix-based operating system (Linux, macOS)

## Usage

### Compilation

To compile the project, run the following command:

```bash
make
```

This will generate two executables: `server` and `client`.

### Running the Server

Start the server by executing:

```bash
./server
```

The server will display its PID (Process ID), which you will use to send messages from the client.

### Sending a Message from the Client

To send a message, use the client executable with the server PID and the message as arguments:

```bash
./client [SERVER_PID] "Your message here"
```

Replace `[SERVER_PID]` with the actual PID of the server displayed in the previous step.

### Example

```bash
./server
```

Output:
```
Server PID is: 12345
```

```bash
./client 12345 "Hello, World!"
```

## How It Works

1. **Server**:
   - The server waits for signals from the client.
   - It interprets `SIGUSR1` as a binary `0` and `SIGUSR2` as a binary `1`.
   - Bits are assembled into characters and printed when a complete byte (8 bits) is received.

2. **Client**:
   - The client takes a string and sends each character bit by bit.
   - For each bit, it sends `SIGUSR1` or `SIGUSR2` to the server, depending on whether the bit is `0` or `1`.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
