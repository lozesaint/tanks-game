#pragma once
#include "window.h"
#include <string>
#include <SDL.h>

class Tank {
public:
	Tank(int x, int y, const std::string &image_path, bool is_second);
	~Tank();

	void pollEvents(SDL_Event& event);
	
	void draw() const;

	void move_left();
	void move_right();
	void move_up();
	void move_down();
	
private:
	int _w = 50, _h = 50;
	int _x = 10, _y = 10;
	int _speed = 10;
	bool _is_second = false;
	
	SDL_Texture *_tank_texture = nullptr;
};