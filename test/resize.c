#define ENET_IMPLEMENTATION
#include "enet.h"
int main() {
    ENetPacket *packet = enet_packet_create("packet",
                                            strlen("packet") + 1,
                                            ENET_PACKET_FLAG_RELIABLE);
    enet_packet_resize(packet, strlen("packetfoo") + 1);
}
