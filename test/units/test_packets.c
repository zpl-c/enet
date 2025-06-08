#include "enet.h"
#include "enet_unit.h"

TEST(enet_packet_create_and_destroy) {
    ENetPacket *packet = enet_packet_create("foo", strlen("foo"), ENET_PACKET_FLAG_RELIABLE);

    ASSERT_EQ(packet->referenceCount, 0);
    ASSERT_EQ(packet->flags, ENET_PACKET_FLAG_RELIABLE);
    ASSERT_NE(packet->data, NULL);
    ASSERT_EQ(packet->dataLength, 3);
    ASSERT_EQ(packet->userData, NULL);

    enet_packet_destroy(packet);
}

TEST(enet_packet_copy) {
    int userData = 1;
    ENetPacket *p1 = enet_packet_create("bar", strlen("bar"), ENET_PACKET_FLAG_RELIABLE);
    p1->userData = &userData;

    ENetPacket *p2 = enet_packet_copy(p1);

    //
    ASSERT_NE(p2, NULL);
    ASSERT_NE(p2->data, NULL);

    //
    ASSERT_EQ(p2->dataLength, p1->dataLength);
    ASSERT_EQ(memcmp(p2->data, p1->data, p1->dataLength), 0);
    ASSERT_EQ(p2->flags, p1->flags);
    ASSERT_EQ(p2->referenceCount, p1->referenceCount);
    ASSERT_EQ(p2->userData, NULL);

    enet_packet_destroy(p1);
    enet_packet_destroy(p2);
}

TEST(enet_packet_resize) {
    ENetPacket *packet = enet_packet_create("packet", strlen("packet"), ENET_PACKET_FLAG_RELIABLE);
    ASSERT_EQ(memcmp(packet->data, "packet", 6), 0);
    ASSERT_EQ(packet->dataLength, 6);

    packet = enet_packet_resize(packet, strlen("packetfoo"));
    memcpy(&packet->data[strlen("packet")], "foo", 3);
    ASSERT_EQ(memcmp(packet->data, "packetfoo", 9), 0);
    ASSERT_EQ(packet->dataLength, 9);

    packet = enet_packet_resize(packet, strlen("packet"));
    ASSERT_EQ(memcmp(packet->data, "packet", 6), 0);
    ASSERT_EQ(packet->dataLength, 6);

    packet = enet_packet_resize(packet, strlen("packetfoobar"));
    memcpy(&packet->data[strlen("packet")], "foobar", 6);
    ASSERT_EQ(memcmp(packet->data, "packetfoobar", 12), 0);
    ASSERT_EQ(packet->dataLength, 12);

    enet_packet_destroy(packet);
}
