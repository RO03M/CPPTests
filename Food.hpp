#ifndef FOOD_SCRIPT
#define FOOD_SCRIPT

#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <SDL.h>

class Food {
	private:
		int x;
		int y;
		int width = 1;
		int height = 1;
	public:
		Food();
		int GetX();
		int GetY();
		bool PositionCompare(int x, int y);
		void GeneratePosition(int x, int y);
		void Render(SDL_Renderer *renderer);
};

#endif