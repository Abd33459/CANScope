CANScope – Test Documentation

Test Environment

- Language: C
- Compiler: Clang (Cxxdroid)
- Platform: Android
- Test type: Software simulation

Test Cases

Test| Input / Condition| Expected Result| Status
Valid CAN ID| 0x100| Frame accepted| PASS
Invalid CAN ID| 0x800| Invalid frame detected| PASS
Zero DLC| DLC = 0| Frame accepted| PASS
Maximum DLC| DLC = 8| Frame accepted| PASS
Invalid DLC| DLC = 9| Invalid frame detected| PASS
Queue overflow| 6 frames, capacity 5| Extra frame rejected| PASS
Insufficient RPM payload| DLC = 1| RPM decoding rejected| PASS
RPM decoding| 0x0B, 0xB8| 3000 RPM| PASS

Test Observations

- Standard 11-bit CAN identifiers are limited to 0x000–0x7FF.
- Classical CAN payload length is limited to 8 bytes.
- Circular FIFO queue preserves message insertion order.
- Queue overflow is detected when capacity is reached.
- RPM decoding uses big-endian byte ordering.
- Invalid frames are rejected during message processing.

Scope Limitation

These tests validate the implemented software simulation only. They do not test physical CAN bus communication, electrical signalling, CRC, ACK, or hardware error handling.
