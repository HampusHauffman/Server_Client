
//----------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>

//----------------------------------------------------------------------
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include "SDL_net.h"
#include "SDL_image.h"
#include <windows.h>

//----------------------------------------------------------------------
int main(int argc, char** argv)
{
	printf("Server\n");
	SDL_Init(SDL_INIT_EVERYTHING);
	SDLNet_Init();

	IPaddress ip;
	UDPsocket server;
	UDPsocket client;
	UDPpacket *packet;

	server = SDLNet_UDP_Open(1234);

	//SDLNet_ResolveHost(&ip, "127.0.0.1", 1234);
	packet = SDLNet_AllocPacket(1024);


	//SDLNet_UDP_Recv(server, packet);
	while (1)
	{
		/* Wait a packet. UDP_Recv returns != 0 if a packet is coming */
		while (SDLNet_UDP_Recv(server, packet))
		{
			printf("UDP Packet incoming\n");
			printf("\tChan:    %d\n", packet->channel);
			printf("\tData:    %s\n", (char *)packet->data);
			printf("\tLen:     %d\n", packet->len);
			printf("\tMaxlen:  %d\n", packet->maxlen);
			printf("\tStatus:  %d\n", packet->status);
			printf("\tAddress: %x %x\n", packet->address.host, packet->address.port);

		}
	}

	SDLNet_UDP_Close(server);

	SDLNet_Quit();
	SDL_Quit();
}