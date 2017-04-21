
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

	SDLNet_ResolveHost(&ip, "127.0.0.1", 1234);

	packet = SDLNet_AllocPacket(1024);
	packet->data = 7;
	packet->len = 1024;
	packet->channel = "127.0.0.1";
	while (1)
	{
		int numset = SDLNet_UDP_Send(server, -1, packet);
		if (!numset)
		{
			printf("no resipiants\n");
		}
	}

	SDLNet_UDP_Close(server);

	SDLNet_Quit();
	SDL_Quit();
}