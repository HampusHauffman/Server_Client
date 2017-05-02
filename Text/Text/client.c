
#include <SDL.h>
#include <SDL_net.h>
#include <stdio.h>
#include <string.h>
#include <client.h>


const char * client()
{
	printf("Client\n");
	

	IPaddress ip;
	//write the ip of the host
	SDLNet_ResolveHost(&ip, "127.0.0.1", 1234);


	TCPsocket client = SDLNet_TCP_Open(&ip);


	char text[10000];
	
	//SDLNet_TCP_Recv(client, text, 10000);
	//printf(text);

	SDLNet_TCP_Close(client);

	return text;
}