#define SDL_MAIN_HANDLED
#ifndef GAME_HEADER
#define GAME_HEADER

#include <SDL.h>
#include <iostream>
#include <chrono>
#include <thread>

namespace Time = std::chrono;
namespace Thread = std::this_thread;

typedef Time::steady_clock timer;

class Game {
	public:
		Game();
		~Game();
		void Start(const char* title, int xpos, int ypos, int width, int height, bool isFullscreen);
		void Run();
		void Update();
		void Render();
		void Events();
		void Clear();
		static const float GetScale();
		static int GetWidth();
		static int GetHeight();
		bool GetRunning();
	protected:
		static int WIDTH;
		static int HEIGHT;
	private:
		static const float SCALE;
		const int FRAME_RATE = 60;
		bool isRunning;
		SDL_Window* window;
		SDL_Renderer* renderer;
};

#endif /*GAME_HEADER*/
