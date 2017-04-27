
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
	//write the ip of the host
	SDLNet_ResolveHost(&ip, "127.0.0.1", 1234);


	TCPsocket client = SDLNet_TCP_Open(&ip);


	char text[10000];
	while (1)
	{
		while (SDLNet_TCP_Recv(client, text, 10000))
		{
			printf(text);
		}
	}

	SDLNet_TCP_Close(client);

	SDLNet_Quit();
	SDL_Quit();

	return 0;
}