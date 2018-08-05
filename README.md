<div align="center">
    <a href="https://github.com/zpl-c/enet"><img src="https://user-images.githubusercontent.com/2182108/33219675-6150f8a8-d14c-11e7-9081-a9be1945bfb1.png" alt="ENet" /></a>
</div>

<br>

<div align="center">
    <a href="https://travis-ci.org/zpl-c/enet"><img src="https://travis-ci.org/zpl-c/enet.svg" alt="Build status" /></a>
    <a href="https://ci.appveyor.com/project/inlife/enet"><img src="https://ci.appveyor.com/api/projects/status/0mkwad2yljdlq3c6?svg=true" alt="Build status" /></a>
    <a href="https://www.npmjs.com/package/enet.c"><img src="https://img.shields.io/npm/v/enet.c.svg?maxAge=3600" alt="NPM version" /></a>
    <a href="https://discord.gg/2fZVEym"><img src="https://discordapp.com/api/guilds/354670964400848898/embed.png" alt="Discord server" /></a>
    <a href="LICENSE"><img src="https://img.shields.io/github/license/zpl-c/enet.svg" alt="license" /></a>
</div>

<br style="line-height: 10px" />

<div align="center">
  ENet - Simple, lightweight and reliable UDP networking library written on pure C
</div>

<div align="center">
  <sub>
    Brought to you by
    <a href="https://github.com/lsalzman">@lsalzman</a>,
    <a href="https://github.com/inlife">@inlife</a>,
    <a href="https://github.com/zaklaus">@zaklaus</a>,
    <a href="https://github.com/nxrighthere">@nxrighthere</a>
    and other contributors!
  </sub>
</div>

<hr/>

## Disclaimer

This is a fork of the original library [lsalzman/enet](https://github.com/lsalzman/enet). While original repo offers a stable, time-tested wonderful library,
we are trying to change some things, things, which can't be reflected on the main repo, like:

* integrated ipv6 support
* added monotonic time
* applied project-wide code style change
* cleaned up project
* single-header style code
* NPM package distribution
* removed a lot of older methods
* and many other various changes

## Description

ENet's purpose is to provide a relatively thin, simple and robust network communication
layer on top of UDP (User Datagram Protocol). The primary feature it provides is optional
reliable, in-order delivery of packets, and fragmentation.

ENet omits certain higher level networking features such as authentication, lobbying,
server discovery, encryption, or other similar tasks that are particularly application
specific so that the library remains flexible, portable, and easily embeddable.

## Installation (via npm)

Install library using (omit `--save` if you don't have npm project initilized)

```sh
$ npm install enet.c --save
```

Add include path to the library `node_modules/enet.c/include` to your makefile/

## Installation (manually)

Dowload file [include/enet.h](https://raw.githubusercontent.com/zpl-c/enet/master/include/enet.h) and just add to your project.

## Usage (Shared library)

Build the shared library:

```sh
$ mkdir build
$ cd build
$ cmake .. -DENET_SHARED=1 -DCMAKE_BUILD_TYPE=Release
$ cmake --build .
```

Use it:

```c
#define ENET_DLL
#include <enet.h>
#include <stdio.h>

int main() {
    if (enet_initialize () != 0) {
        printf("An error occurred while initializing ENet.\n");
        return 1;
    }

    enet_deinitialize();
    return 0;
}
```

## Usage (Static library)

Build the static library:

```sh
$ mkdir build
$ cd build
$ cmake .. -DENET_STATIC=1 -DCMAKE_BUILD_TYPE=Release
$ cmake --build .
```

Use it:

```c
#include <enet.h>
#include <stdio.h>

int main() {
    if (enet_initialize () != 0) {
        printf("An error occurred while initializing ENet.\n");
        return 1;
    }

    enet_deinitialize();
    return 0;
}
```

## Usage (Direct, Preferred)

In this case, library will be embedded to the project itself.

Make sure you add a define for `ENET_IMPLEMENTATION` exactly in one source file before including the `enet.h`.

Here is a simple server demo, it will wait 1 second for events, and then exit if none were found:

```c
#define ENET_IMPLEMENTATION
#include <enet.h>
#include <stdio.h>

int main() {
    if (enet_initialize () != 0) {
        printf("An error occurred while initializing ENet.\n");
        return 1;
    }

    ENetAddress address = {0};

    address.host = ENET_HOST_ANY; /* Bind the server to the default localhost.     */
    address.port = 7777; /* Bind the server to port 7777. */

    #define MAX_CLIENTS 32

    /* create a server */
    ENetHost * server = enet_host_create(&address, MAX_CLIENTS, 2, 0, 0);

    if (server == NULL) {
        printf("An error occurred while trying to create an ENet server host.\n");
        return 1;
    }

    printf("Started a server...\n");

    ENetEvent event;

    /* Wait up to 1000 milliseconds for an event. (WARNING: blocking) */
    while (enet_host_service(server, &event, 1000) > 0) {
        switch (event.type) {
            case ENET_EVENT_TYPE_CONNECT:
                printf("A new client connected from %x:%u.\n",  event.peer->address.host, event.peer->address.port);
                /* Store any relevant client information here. */
                event.peer->data = "Client information";
                break;

            case ENET_EVENT_TYPE_RECEIVE:
                printf("A packet of length %lu containing %s was received from %s on channel %u.\n",
                        event.packet->dataLength,
                        event.packet->data,
                        event.peer->data,
                        event.channelID);
                /* Clean up the packet now that we're done using it. */
                enet_packet_destroy (event.packet);
                break;

            case ENET_EVENT_TYPE_DISCONNECT:
                printf("%s disconnected.\n", event.peer->data);
                /* Reset the peer's client information. */
                event.peer->data = NULL;
                break;

            case ENET_EVENT_TYPE_DISCONNECT_TIMEOUT:
                printf("%s disconnected due to timeout.\n", event.peer->data);
                /* Reset the peer's client information. */
                event.peer->data = NULL;
                break;

            case ENET_EVENT_TYPE_NONE:
                break;
        }
    }

    enet_host_destroy(server);
    enet_deinitialize();
    return 0;
}

```

## Tutorials

More information, examples and tutorials can be found at the official site: http://enet.bespin.org/



