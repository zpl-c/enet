#include <stdio.h>
#define ENET_IMPLEMENTATION
#include "enet.h"
// #define WIN32_LEAN_AND_MEAN
// #include <Windows.h>

void run_server();
void run_client();

int main(int argc, char** argv) {
    if (enet_initialize() < 0) {
        printf("failed to initialize enet\n");
    };

    bool server;
    if (argc == 2 && !strcmp(argv[1], "-server")) {
        server = true;
    } else {
        server = false;
    }

    if (server) {
        printf("launching server\n");
        run_server();
    } else {
        printf("launching client\n");
        run_client();
    }

    printf("done\n");
    enet_deinitialize();

    return 0;
}

void run_server() {
    ENetAddress address = {};
    address.host = ENET_HOST_ANY;
    address.port = 1234;

    ENetHost* host = enet_host_create(&address, 4, 1, 0, 0, NULL);

    if (!host) {
        printf("Failed to create server\n");
    }

    printf("Server started...\n");

    while (true) {
        ENetEvent event;
        while (enet_host_service(host, &event, 2) > 0) {
            switch (event.type) {
                case ENET_EVENT_TYPE_CONNECT: {
                    printf("A client has connected!\n");
                } break;
                case ENET_EVENT_TYPE_RECEIVE: {
                    printf("Message recieved! %s\n", event.packet->data);
                    enet_packet_destroy(event.packet);
                } break;
                case ENET_EVENT_TYPE_DISCONNECT:
                case ENET_EVENT_TYPE_DISCONNECT_TIMEOUT:
                    printf("A client has disconnected\n");
                    break;
                case ENET_EVENT_TYPE_NONE:
                    break;
            }
        }

        ENetPeer* currentPeer;
        // for (currentPeer = host->peers; currentPeer < &host->peers[host->peerCount]; ++currentPeer) {
        //     if (currentPeer->state != ENET_PEER_STATE_CONNECTED) {
        //         continue;
        //     }

        //     ENetPacket * packet = enet_packet_create("HELLO WORLD", strlen("HELLO WORLD"), ENET_PACKET_FLAG_RELIABLE);
        //     enet_peer_send(currentPeer, 0, packet);
        // }

        for (int i = 0; i < 4; i++) {
            ENetPeer* peer = &host->peers[i];
            if (peer->state == ENET_PEER_STATE_CONNECTED) {
                ENetPacket * packet =
                    enet_packet_create("HELLO WORLD", strlen("HELLO WORLD"),
                                       ENET_PACKET_FLAG_RELIABLE);
                enet_peer_send(peer, 0, packet);
            }
        }

        usleep(16000);
    }

    enet_host_destroy(host);
}

void run_client() {
    ENetAddress address = {};
    address.host = ENET_HOST_ANY;
    address.port = 1234;

    ENetHost* host = enet_host_create(NULL, 1, 1, 0, 0, NULL);

    enet_address_set_host(&address, "127.0.0.1");
    address.port = 1234;
    printf("Connecting to server\n");
    ENetPeer * peer = enet_host_connect(host, &address, 1, 0);

    if (!host) {
        printf("Failed to create client\n");
    }

    bool connected = false;

    while (true) {
        ENetEvent event;
        while (enet_host_service(host, &event, 0) > 0) {
            switch (event.type) {
                case ENET_EVENT_TYPE_CONNECT: {
                    printf("Connected to server\n");
                    connected = true;
                } break;
                case ENET_EVENT_TYPE_RECEIVE: {
                    printf("Message recieved! %s\n", event.packet->data);
                    enet_packet_destroy(event.packet);
                } break;
                case ENET_EVENT_TYPE_DISCONNECT:
                case ENET_EVENT_TYPE_DISCONNECT_TIMEOUT:
                    printf("A client has disconnected\n");
                    break;
            }
        }

        if (connected) {
            if (peer->state == ENET_PEER_STATE_CONNECTED) {
                ENetPacket *packet =
                    enet_packet_create("HELLO WORLD", strlen("HELLO WORLD"),
                                       ENET_PACKET_FLAG_RELIABLE);
                enet_peer_send(peer, 0, packet);
            }
        }

        usleep(16000);
    }

    enet_host_destroy(host);
}
