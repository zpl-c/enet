#include "enet.h"
#include "enet_unit.h"

TEST(enet_socket_create) {
    ENetSocket tcpSock = enet_socket_create(ENET_SOCKET_TYPE_STREAM);
    ENetSocket udpSock = enet_socket_create(ENET_SOCKET_TYPE_DATAGRAM);

    ASSERT_NE(tcpSock, ENET_SOCKET_NULL);
    ASSERT_NE(udpSock, ENET_SOCKET_NULL);
}

TEST(enet_socket_bind) {
    ASSERT_EQ(0, 1);
}

TEST(enet_socket_get_address) {
    ASSERT_EQ(0, 1);
}

TEST(enet_socket_listen) {
    ASSERT_EQ(0, 1);
}

TEST(enet_socket_accept) {
    ASSERT_EQ(0, 1);
}

TEST(enet_socket_connect) {
    ASSERT_EQ(0, 1);
}

TEST(enet_socket_send) {
    ASSERT_EQ(0, 1);
}

TEST(enet_socket_receive) {
    ASSERT_EQ(0, 1);
}

TEST(enet_socket_wait) {
    ASSERT_EQ(0, 1);
}

TEST(enet_socket_set_option) {
    ASSERT_EQ(0, 1);
}

TEST(enet_socket_get_option) {
    ASSERT_EQ(0, 1);
}

TEST(enet_socket_shutdown) {
    ASSERT_EQ(0, 1);
}

TEST(enet_socket_destroy) {
    ASSERT_EQ(0, 1);
}

TEST(enet_socketset_select) {
    ASSERT_EQ(0, 1);
}
