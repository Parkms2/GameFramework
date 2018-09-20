#include<SDL.h>
#include<stdio.h>
#include <SDL_image.h>



SDL_Surface *screen;
SDL_Surface *bgi, *ch;

int x = 0, y = 0;

void DrawSurface(SDL_Surface *dst, int x, int y, SDL_Surface *src) {
	SDL_Rect rectDst;
	rectDst.x = x;
	rectDst.y = y;
	SDL_BlitSurface(src, NULL, dst, &rectDst);
}
void Render() {
	DrawSurface(screen, 0, 0, bgi);
	DrawSurface(screen, x, y, ch);
}


	SDL_EnableKeyRepeat(0, 0);
