#include "enet.h"
#include "enet_unit.h"

/* A host bound to one address must still accept connections.
 *
 * On a dual-stack build enet_address_set_host turns "127.0.0.1" into ::ffff:127.0.0.1, and a socket bound to a
 * v4-mapped address is demoted to a plain IPv4 one by some kernels (XNU), which then report the sender of every
 * datagram as a sockaddr_in. enet_socket_receive has to read it as such, or the address it stores matches no peer
 * and the handshake never completes. See issue #59. */

#define ENET_TEST_CONNECT_TIMEOUT_MS 5000

/* Drives a client and a server until both report ENET_EVENT_TYPE_CONNECT, or the time is up. */
static int enet_test_connects(const char *bindTo, enet_uint16 port) {
    ENetAddress address = {0};
    ENetHost *server = NULL, *client = NULL;
    int serverConnected = 0, clientConnected = 0;
    int waited = 0;

    address.port = port;
    if (bindTo == NULL) {
        address.host = ENET_HOST_ANY;
    } else if (enet_address_set_host(&address, bindTo) != 0) {
        return 0;
    }

    server = enet_host_create(&address, 1, 2, 0, 0);
    client = enet_host_create(NULL, 1, 2, 0, 0);

    if (server != NULL && client != NULL) {
        ENetAddress to = {0};
        to.port = port;

        if (enet_address_set_host(&to, "127.0.0.1") == 0 && enet_host_connect(client, &to, 2, 0) != NULL) {
            while (waited < ENET_TEST_CONNECT_TIMEOUT_MS && !(serverConnected && clientConnected)) {
                ENetEvent event;

                while (enet_host_service(server, &event, 0) > 0) {
                    if (event.type == ENET_EVENT_TYPE_CONNECT) { serverConnected = 1; }
                    if (event.type == ENET_EVENT_TYPE_RECEIVE) { enet_packet_destroy(event.packet); }
                }

                while (enet_host_service(client, &event, 0) > 0) {
                    if (event.type == ENET_EVENT_TYPE_CONNECT) { clientConnected = 1; }
                    if (event.type == ENET_EVENT_TYPE_RECEIVE) { enet_packet_destroy(event.packet); }
                }

                ASSERT_SLEEP(1);
                waited += 1;
            }
        }
    }

    if (client != NULL) { enet_host_destroy(client); }
    if (server != NULL) { enet_host_destroy(server); }

    return serverConnected && clientConnected;
}

TEST(connect_to_a_host_bound_to_every_address) {
    ASSERT_THAT(enet_test_connects(NULL, 49711), 1,
                "a client should connect to a host bound to ENET_HOST_ANY");
}

TEST(connect_to_a_host_bound_to_the_loopback_address) {
    ASSERT_THAT(enet_test_connects("127.0.0.1", 49712), 1,
                "a client should connect to a host bound to 127.0.0.1 alone");
}
