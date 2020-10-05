#include "main.h"
#include <iostream>
#include "Windows.h"
#include "SDL.h"
#include "Window.h"

int main(int argc, char* argv[]) {

	//OutputDebugString("Sandbox running");
    std::cout << "JOOD \n";
	Window window("FluixEngine", 500, 500);

	SDL_Event event;

	while (!window.IsClosed()) {
		while (SDL_PollEvent(&event)) {
			window.PollEvents();
			window.clear();
		}
	}

	return 0;
}