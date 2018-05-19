#include <iostream>
#include <SDL/SDL.h>
#include <GL/glew.h>

using namespace std;

int main(int argc, char** argv) {
	SDL_Window* _window = nullptr;
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL Initialization Error!" << endl;
	}
	else {
		_window = SDL_CreateWindow("Dipesh Game",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,SDL_WINDOW_OPENGL);

		if (_window == nullptr) {
			cout << "Creating window Error!" << endl;
		}
	}

	SDL_DestroyWindow(_window);
	SDL_Quit();
	return 0;
}
