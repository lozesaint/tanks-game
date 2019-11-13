#include <iostream>
#include <SDL.h>
#include "window.h"
#include "tank.h"
#include "text.h"

void pollEvents(Window& window, Tank& tank1, Tank& tank2) {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		tank1.pollEvents(event);
		tank2.pollEvents(event);
		window.pollEvents(event);
	}
}

int main(int argc, char **argv) {
	Window window("Tanks Game", 800, 600);
	Tank tank1(10, 10, "res/tank.png", false);
	Tank tank2(700, 500, "res/tank.png", true);
	// Text text(Window::renderer, "res/arial.ttf", 30, "Tanks Game", { 255, 0, 0, 255 });

	while (!window.isClosed()) {
		pollEvents(window, tank1, tank2);
		tank1.draw();
		tank2.draw();
		// text.display(20, 20, Window::renderer);
		window.clear();
	}
	
	return 0;
}