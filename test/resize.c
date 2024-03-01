#define ENET_IMPLEMENTATION
#include "enet.h"
int main() {
    ENetPacket *packet = enet_packet_create("packet",
                                            strlen("packet"),
                                            ENET_PACKET_FLAG_RELIABLE);
    printf("length: %d, data: %.*s\n", packet->dataLength, packet->dataLength, (char*)packet->data);
    packet = enet_packet_resize(packet, strlen("packetfoo"));
    strcpy (& packet -> data [strlen ("packet")], "foo");
    printf("length: %d, data: %.*s\n", packet->dataLength, packet->dataLength, (char*)packet->data);
    packet = enet_packet_resize(packet, strlen("packet"));
    printf("length: %d, data: %.*s\n", packet->dataLength, packet->dataLength, (char*)packet->data);
    packet = enet_packet_resize(packet, strlen("packetfoobar"));
    strcpy (& packet -> data [strlen ("packet")], "foobar");
    printf("length: %d, data: %.*s\n", packet->dataLength, packet->dataLength, (char*)packet->data);
}
