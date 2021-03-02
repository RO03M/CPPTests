#include "Game.hpp";

Game* game = nullptr;

int main() {
	game = new Game();
	game->Start("Teste", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, false);
	game->Run();
	game->Clear();
	return 0;
}