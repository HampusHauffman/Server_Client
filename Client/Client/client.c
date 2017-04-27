
#include <SDL.h>
#include <SDL_net.h>
#include <stdio.h>
#include <string.h>


int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDLNet_Init();

	IPaddress ip;
	SDLNet_ResolveHost(&ip, "127.0.0.1", 80);


	TCPsocket client = SDLNet_TCP_Open(&ip);

	char textSend[10000];

	SDLNet_TCP_Send(client,textSend, strlen(textSend) + 1);

	char textRecv[10000];

	while (SDLNet_TCP_Recv(client, textRecv, 10000))
		printf("%s\n", textRecv);

	SDLNet_TCP_Close(client);

	SDLNet_Quit();
	SDL_Quit();
}