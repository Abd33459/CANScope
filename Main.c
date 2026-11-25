
#include <stdio.h>
#include <stdint.h>

#define SIZE 5

typedef struct
{
    uint16_t id;
    uint8_t dlc;
    uint8_t data[8];

} CAN_Frame;

CAN_Frame queue[SIZE];

int front = 0, rear = -1, count = 0;

// Validate CAN frame
int validate(CAN_Frame msg)
{
    if(msg.id > 0x7FF)
        return 0;

    if(msg.dlc > 8)
        return 0;

    return 1;
}

// Add frame to circular queue
int enqueue(CAN_Frame msg)
{
    if(count == SIZE)
    {
        printf("Queue Full!\n");
        return 0;
    }

    rear = (rear + 1) % SIZE;
    queue[rear] = msg;
    count++;

    return 1;
}

// Decode engine RPM safely
int decode_engine_rpm(CAN_Frame msg, uint16_t *rpm)
{
    if(rpm == NULL || msg.dlc < 2)
    {
        return 0;
    }

    *rpm = ((uint16_t)msg.data[0] << 8) |
            msg.data[1];

    return 1;
}

// Process queued CAN messages
void process(void)
{
    while(count > 0)
    {
        CAN_Frame msg = queue[front];

        front = (front + 1) % SIZE;
        count--;

        printf("\nCAN ID: 0x%03X\n", msg.id);

        if(!validate(msg))
        {
            printf("FAULT: Invalid frame\n");
            continue;
        }

        printf("DLC: %u\n", msg.dlc);

        if(msg.id == 0x100)
        {
            uint16_t rpm = 0;

            if(decode_engine_rpm(msg, &rpm))
            {
                printf("Engine RPM: %u\n", rpm);
            }
            else
            {
                printf("FAULT: Insufficient RPM data\n");
            }
        }
        else
        {
            printf("Message received\n");
        }
    }
}

// Simplified CAN arbitration demonstration
uint16_t arbitrate(uint16_t a, uint16_t b)
{
    return (a < b) ? a : b;
}

int main(void)
{
    CAN_Frame engine =
        {0x100, 2, {0x0B, 0xB8}};

    CAN_Frame speed =
        {0x200, 1, {0x50}};

    CAN_Frame temp =
        {0x300, 1, {0x5A}};

    printf("=== CANScope Started ===\n");

    if(enqueue(engine))
        printf("Engine message queued\n");

    if(enqueue(speed))
        printf("Speed message queued\n");

    if(enqueue(temp))
        printf("Temperature message queued\n");

    printf("\n=== Message Processing ===\n");

    process();

    printf("\n=== Arbitration Demo ===\n");

    printf("Winner: 0x%03X\n",
        arbitrate(0x100, 0x200));

    printf("\n=== Simulation Complete ===\n");

    return 0;
}
