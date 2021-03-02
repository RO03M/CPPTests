#include "Section.hpp"

int Section::GetX() {
	return x;
}

int Section::GetY() {
	return y;
}

void Section::SetX(int x) {
	this->x = x;
}

void Section::SetY(int y) {
	this->y = y;
}

void Section::SetPosition(int x, int y) {
	this->x = x;
	this->y = y;
}

void Section::SetPosition(int x, int y, int width, int height) {
	this->x = x - width / 2;
	this->y = y - height / 2;
}
