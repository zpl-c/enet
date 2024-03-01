#define ENET_IMPLEMENTATION
#include "enet.h"
int main() {
    ENetPacket *packet = enet_packet_create("packet",
                                            strlen("packet") + 1,
                                            ENET_PACKET_FLAG_RELIABLE);
    printf("length: %d, data: %.*s\n", packet->dataLength, packet->dataLength, (char*)packet->data);
    packet = enet_packet_resize(packet, strlen("packetfoo") + 1);
    strcpy (& packet -> data [strlen ("packet")], "foo");
    printf("length: %d, data: %.*s\n", packet->dataLength, packet->dataLength, (char*)packet->data);
}
