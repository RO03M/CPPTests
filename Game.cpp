#include "Game.hpp"
#include "Player.hpp"
#include "Food.hpp"

using namespace std;

Player player;
Food food;
const float Game::SCALE = 10;
int Game::WIDTH = 0;
int Game::HEIGHT = 0;

Game::Game() {}

Game::~Game() {}

void Game::Start(const char* title, int xpos, int ypos, int width, int height, bool isFullscreen) {
	cout << "Starting subsystem" << endl;
	int flags = 0;
	if (isFullscreen) flags = SDL_WINDOW_FULLSCREEN;//flags = 1
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		cout << "Subsystem started" << endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		Game::WIDTH = width;
		Game::HEIGHT = height;
		if (window) cout << "Window created with success!" << endl;
		else cout << "Something went wrong, window could not be created :c";

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
			cout << "Renderer created with success!";
		}
		else cout << "Something went wrong and the fucking renderer won't be created :C";

		isRunning = true;
	}
	else {
		cout << "SDL not be initialized" << endl;
		isRunning = false;
	}
}

void Game::Run() {
	auto last_time = timer::now();
	auto ms_timer = timer::now();
	double rate = 1000000000 / FRAME_RATE;
	int frames = 0;
	while (isRunning) {
		auto current_time = timer::now();
		auto timer_now = timer::now();
		if (Time::duration_cast<Time::nanoseconds>(current_time - last_time).count() >= rate) {
			this->Events();
			this->Update();
			this->Render();
			frames++;
		}

		if (Time::duration_cast<Time::milliseconds>(timer_now - ms_timer).count() >= 1000) {//Every 1000 milliseconds in africa, a second passes
			ms_timer = timer::now();
			cout << frames << " fps" << endl;
			frames = 0;
		}
	}
}

void Game::Update() {
	player.Update();
}

void Game::Render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderSetScale(renderer, Game::SCALE, Game::SCALE);
	int teste = SDL_GetRendererOutputSize(renderer, NULL, NULL);
	#pragma region shapes

	player.RenderPlayer(renderer);
	food.Render(renderer);

	cout << food.PositionCompare(player.GetX(), player.GetY()) << endl;

	#pragma endregion
	SDL_RenderPresent(renderer);
}

void Game::Events() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
				case SDLK_UP:
					player.SetDirection(UP);
					break;
				case SDLK_DOWN:
					player.SetDirection(DOWN);
					break;
				case SDLK_RIGHT:
					player.SetDirection(RIGHT);
					break;
				case SDLK_LEFT:
					player.SetDirection(LEFT);
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
}

void Game::Clear() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	cout << "Game over" << endl;
}

const float Game::GetScale() {
	return Game::SCALE;
}

int Game::GetWidth() {
	return Game::WIDTH;
}

int Game::GetHeight() {
	return Game::HEIGHT;
}

bool Game::GetRunning() {
	return isRunning;
}