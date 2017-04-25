#include <SDL.h>
#include <SDL_net.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char** argv)
{
	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;


	if (TTF_Init() == -1) {
		printf("TTF_Init: %s\n", TTF_GetError());
		exit(2);
	}

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		//Create window
		window = SDL_CreateWindow("Text Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface(window);

			//Fill the surface white
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0xC3, 0xC3, 0xFF));

			//Update the surface
			SDL_UpdateWindowSurface(window);

			//Wait two seconds
			SDL_Delay(2000);
		}
	}

	// load font.ttf at size 16 into font
	TTF_Font *font;
	font = TTF_OpenFont("font.ttf", 16);
	if (!font) {
		printf("TTF_OpenFont: %s\n", TTF_GetError());
		// handle error
		printf("hej");
	}

	SDL_Color col = { 255,100,255,1 };
	
	screenSurface = TTF_RenderText_Solid(font,"hej",col);

	SDL_UpdateWindowSurface(window);

	//Destroy window
	SDL_DestroyWindow(window);

	// free the font
	// TTF_Font *font;
	TTF_CloseFont(font);
	font = NULL;

	//Quit SDL subsystems
	TTF_Quit();
	SDL_Quit();
	Sleep(2000);
	return 0;
}