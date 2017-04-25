
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
	UDPpacket *packet;
	//write "127.0.0.1",1234 to connect to the server.cpp on your local machine

	server = SDLNet_UDP_Open(0); //kan va 1123 men bör inte va de

	SDLNet_ResolveHost(&ip, "127.0.0.1", 1234);

	packet = SDLNet_AllocPacket(1024);

	//packet->address = ip;

	packet->data = "hej";
	printf("%c", packet->data);

	while (1)
	{
		
		packet->address.host = ip.host;	/* Set the destination host */
		packet->address.port = ip.port;	/* And destination port */

		packet->len = strlen((char *)packet->data) + 1;

		SDLNet_UDP_Send(server, -1, packet); /* This sets the p->channel */
	}

	SDLNet_UDP_Close(server);

	SDLNet_Quit();
	SDL_Quit();

	return 0;
}