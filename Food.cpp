#include "Food.hpp"

Food::Food() {
	srand(time(NULL));
}

int Food::GetX() {
	return x;
}

int Food::GetY() {
	return y;
}

void Food::GeneratePosition(int maxWidth, int maxHeight) {
	x = rand() % maxWidth;
	y = rand() % maxHeight;
}

void Food::Render(SDL_Renderer *renderer) {
	SDL_Rect food;
	food.x = x;
	food.y = y;
	food.w = width;
	food.h = height;
	SDL_SetRenderDrawColor(renderer, 255, 200, 150, 255);
	SDL_RenderFillRect(renderer, &food);
	SDL_RenderDrawRect(renderer, &food);
}

bool Food::PositionCompare(int x, int y) {
	if ((this->x >= x && this->x + this->width < x) && (this->y >= y && this->y + this->height < y)) return true;
	return false;
}
