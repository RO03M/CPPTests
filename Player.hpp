#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <SDL.h>
#include "Section.hpp"

#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3

using namespace std;

class Player {
	public:
		Player();
		//~Player();
		void Update();
		void RenderPlayer(SDL_Renderer* renderer);
		void Move();
		void Eat();
		void Expand();//creates a new rectangle to follow
		int GetX();
		int GetY();
		void SetDirection(int direction);
		void AddBody(int x, int y);
	private:
		float xpos = 10;
		float ypos = 10;
		int width = 1;
		int height = 1;
		int length = 500;
		int speed_x = 0;
		int speed_y = 0;
		float speed = .01f;
		const int maxSize = 20;
		vector<Section> body_parts;
		enum directions { right = 0, left = 1, up = 2, down = 3 };
		int currentDirection = directions::right;
};

#endif