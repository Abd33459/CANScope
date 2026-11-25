CANScope – Virtual CAN Bus Simulator

A C-based software simulation demonstrating fundamental Controller Area Network (CAN) concepts.

Project Overview

CANScope is a lightweight CAN concept simulator developed using C programming.

The project simulates multiple virtual ECUs generating CAN messages. These messages are stored in a circular FIFO queue, validated, and processed to demonstrate selected CAN communication concepts.

It includes an engine RPM decoding example and a simplified CAN arbitration demonstration.

Key Features

- Classical CAN standard frame representation (11-bit identifier)
- CAN frame validation
- DLC validation (0–8 bytes)
- Circular FIFO queue implementation
- Queue overflow detection
- Engine RPM decoding using bitwise operations
- Pointer-based output handling
- Simplified CAN arbitration priority demonstration
- Invalid frame and insufficient payload detection

Technology Stack

- Programming Language: C
- Development Environment: Cxxdroid
- Platform: Android
- Concepts: Structures, pointers, arrays, functions, bitwise operations, circular queues

Project Scope

This is a software-based simulation of selected CAN concepts. It does not implement physical CAN hardware, actual bus communication, bit timing, CRC, ACK, or error frames.

Sample Output

=== CANScope Started ===
Engine message queued
Speed message queued
Temperature message queued

=== Message Processing ===

CAN ID: 0x100
DLC: 2
Engine RPM: 3000

CAN ID: 0x200
DLC: 1
Message received

CAN ID: 0x300
DLC: 1
Message received

=== Arbitration Demo ===
Winner: 0x100

=== Simulation Complete ===

Learning Outcomes

- Practical C structure and pointer usage
- Circular FIFO queue implementation
- Bitwise data decoding
- Input validation and fault handling
- Understanding selected CAN communication concepts
