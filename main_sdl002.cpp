#include <iostream>
#include <SDL/SDL.h>
#include <GL/glew.h>

using namespace std;

enum GameState {PLAY, EXIT};

int main(int argc, char** argv) {
	SDL_Window* _window = nullptr;
	GameState _gameState = PLAY;
	
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		cout << "SDL Initialization Error!" << endl;
	}
	else {
		_window = SDL_CreateWindow("Dipesh Game",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,640,480,SDL_WINDOW_OPENGL);

		if (_window == nullptr) {
			cout << "Creating window Error!" << endl;
		}
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(_window);
	if (glContext == nullptr) {
		cout << "Cannot Create The Context!" << endl;
	}

	GLenum error = glewInit();
	if (error != GLEW_OK) {
		cout << "OpenGL is not Supported!" << endl;
	}

	glClearColor(1.0f, 1.0f, 0.0f, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(_window);

	while (_gameState != EXIT) {
		SDL_Event evt;
		if ( SDL_PollEvent( &evt ) ) {
			switch (evt.type) {
				case SDL_QUIT:
					_gameState = EXIT;
					break;
			}
		}
	}

	SDL_DestroyWindow(_window);
	SDL_Quit();
	return 0;
}
