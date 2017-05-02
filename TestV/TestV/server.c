
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
	
	SDLNet_ResolveHost(&ip, NULL, 1234);

	TCPsocket server = SDLNet_TCP_Open(&ip);
	TCPsocket client;

	char text[100] = "Hampus!\n";
	
	
	while (1)
	{
		client = SDLNet_TCP_Accept(server);
		if (client)
		{
			printf("%d\n", client);
			scanf("%s", text);
			//here you can communitcate with the client
			SDLNet_TCP_Send(client, text, strlen(text) + 1);
			//SDLNet_TCP_Close(client);

			//break;
			
		}
		
	}
	SDLNet_TCP_Close(server);

	SDLNet_Quit();
	SDL_Quit();
}