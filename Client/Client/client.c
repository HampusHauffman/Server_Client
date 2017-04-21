
#include <SDL.h>
#include <SDL_net.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char** argv)
{
	printf("Client\n");
	SDL_Init(SDL_INIT_EVERYTHING);
	SDLNet_Init();

	IPaddress ip;
	UDPsocket server;
	UDPsocket client;
	UDPpacket *packet;
	//write "127.0.0.1",1234 to connect to the server.cpp on your local machine

	server = SDLNet_UDP_Open(1234);

	SDLNet_ResolveHost(&ip, "127.0.0.1", 1234);

	packet = SDLNet_AllocPacket(1024);

	while (1)
	{
		if (SDLNet_UDP_Recv(server, packet->data))
		{
			printf(packet->data);
		}
		else {
			printf("no input\n");
		}
	}

	SDLNet_UDP_Close(server);

	SDLNet_Quit();
	SDL_Quit();

	return 0;
}