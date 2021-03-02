#include "Game.hpp"
#include "Player.hpp"

Player::Player() {
	cout << 1;
}

void Player::Update() {
	if (body_parts.size() != length) body_parts.resize(length);
	xpos += (speed_x * speed);
	ypos += (speed_y * speed);
	for (int i = body_parts.size() - 1; i >= 0; --i) {
		if (i == 0) body_parts[i].SetPosition(xpos, ypos, width, height);
		else body_parts[i].SetPosition(body_parts[i - 1].GetX(), body_parts[i - 1].GetY());
	}
	if (xpos >= Game::GetWidth() / Game::GetScale()) {
		body_parts[0].SetX(0);
		xpos = 0;
	} else if (xpos < 0) {
		body_parts[0].SetX(Game::GetWidth() / Game::GetScale());
		xpos = Game::GetWidth() / Game::GetScale();
	}

	if (ypos > Game::GetHeight() / Game::GetScale()) {
		body_parts[0].SetY(0);
		ypos = 0;
	} else if (ypos < 0) {
		body_parts[0].SetY(Game::GetHeight() / Game::GetScale());
		ypos = Game::GetHeight() / Game::GetScale();
	}

}

void Player::RenderPlayer(SDL_Renderer* renderer) {
	for (int i = 0; i < body_parts.size(); i++) {
		SDL_Rect body;
		body.x = (int)body_parts[i].GetX();
		body.y = (int)body_parts[i].GetY();
		body.w = width;
		body.h = height;
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(renderer, &body);
		SDL_RenderDrawRect(renderer, &body);
	}
}

void Player::AddBody(int x, int y) {

}

void Player::SetDirection(int direction) {
	if (direction == 0) {
		speed_x = 1;
		speed_y = 0;
	} else if (direction == 1) {
		speed_x = -1;
		speed_y = 0;
	} else if (direction == 2) {
		speed_x = 0;
		speed_y = -1;
	} else if (direction == 3) {
		speed_x = 0;
		speed_y = 1;
	}
}

int Player::GetX() {
	return xpos;
}

int Player::GetY() {
	return ypos;
}
