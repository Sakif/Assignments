#!/usr/bin/env python3

from random import randint


def randomLIN():
    return randint(1, 100)


def randomMQP():
    return randint(1, 10)


def randomPacket():
    return randint(1, 1000)


def packetMaker(noOfPackets):
    packets = []

    while (len(packets) < noOfPackets):
        p = randint(1, 100000)
        packets.append(p)

    packets.sort()
    # remove duplicates
    packets = list(dict.fromkeys(packets))

    return packets


f = open("input2.txt", "w")

for i in range(0, 3):
    print(randomLIN(), file=f)
for i in range(0, 3):
    print(randomMQP(), file=f)

packetCount = randomPacket()
print(packetCount, file=f)
packets = packetMaker(packetCount)

for i in packets:
    print(i, file=f)

f.close()
