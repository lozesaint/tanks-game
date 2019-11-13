#include <iostream>
#include "tank.h"
#include "window.h"
#include <string>
#include <SDL.h>
#include <SDL_image.h>

Tank::Tank(int x, int y, const std::string& image_path, bool is_second) :
	_x(x), _y(y), _is_second(is_second)
{
	auto surface = IMG_Load(image_path.c_str());
	if (!surface) {
		std::cerr << "Failed to create surface.\n";
	}

	_tank_texture = SDL_CreateTextureFromSurface(Window::renderer, surface);
	if (!_tank_texture) {
		std::cerr << "Failed to create texture.\n";
	}
	SDL_FreeSurface(surface);
}

Tank::~Tank() {
	SDL_DestroyTexture(_tank_texture);
}

void Tank::draw() const {
	SDL_Rect tank = { _x, _y, _w, _h };
	if (_tank_texture) {
		SDL_RenderCopy(Window::renderer, _tank_texture, nullptr, &tank);
	}
	else {
		std::cerr << "Failed to create tank texture.\n";
	}
}

void Tank::move_left() {
	_x -= _speed;
}

void Tank::move_right() {
	_x += _speed;
}

void Tank::move_up() {
	_y -= _speed;
}

void Tank::move_down() {
	_y += _speed;
}

void Tank::pollEvents(SDL_Event& event) {
	switch (event.type) {

	case SDL_KEYDOWN:
		if (_is_second) {
			switch (event.key.keysym.sym) {
			case SDLK_LEFT:
				move_left();
				break;
			case SDLK_RIGHT:
				move_right();
				break;
			case SDLK_UP:
				move_up();
				break;
			case SDLK_DOWN:
				move_down();
				break;
			}
		}
		else {
			switch (event.key.keysym.sym) {
			case SDLK_a:
				move_left();
				break;
			case SDLK_d:
				move_right();
				break;
			case SDLK_w:
				move_up();
				break;
			case SDLK_s:
				move_down();
				break;
			}
		}
		break;

	default:
		break;
	}
}