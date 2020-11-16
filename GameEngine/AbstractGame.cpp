#include "pch.h"
#include "AbstractGame.h"

AbstractGame::AbstractGame(const char* title, int width, int height) {
	_window = unique_ptr<Window>(new Window("Latrop 2", 1080, 720));
	_activeScreen = 0;
}

AbstractGame::~AbstractGame() {}

void AbstractGame::gameLoop() {
	SDL_Event event;

	bool running = true;
	unsigned int a = SDL_GetTicks();
	unsigned int b = SDL_GetTicks();
	double delta = 0;
	while (running) {
		a = SDL_GetTicks();
		delta = a - b;
		if (delta > 1000 / 60.0) {
			//cout << "FPS: " << 1000 / delta << std::endl;
			b = a;

			screens.at(_activeScreen)->onTick();

			_window->clear();

			screens.at(_activeScreen)->render(_window);

			_window->display();
			while (SDL_PollEvent(&event)) {
				switch (event.type)
				{
				case SDL_KEYDOWN:
					screens.at(_activeScreen)->handleKeyboardInput(event.key);
					break;
				case SDL_MOUSEMOTION:
					screens.at(_activeScreen)->handleMouseMotionInput(event.motion);

					break;
				case SDL_MOUSEBUTTONDOWN:
					screens.at(_activeScreen)->handleMouseClickInput(event.button);

					break;
				case SDL_MOUSEWHEEL:
					screens.at(_activeScreen)->handleMouseWheelInput(event.wheel);

					break;
				case SDL_QUIT:
					running = false;
					break;
				default:
					break;
				}
			}
		}
	}
}

void AbstractGame::registerTexture(std::string textureKey, std::string texturePath) {
	_window->registerTexture(textureKey, texturePath);
}

void AbstractGame::registerFont(std::string fontKey, std::string fontPath) {
	_window->registerFont(fontKey, fontPath);
}

void AbstractGame::registerMusicTrack(const std::string& musicTrackKey, const std::string& trackPath)
{
	_window->registerSoundTrack(musicTrackKey, trackPath);
}

void AbstractGame::playMusicTrack(const std::string& musicTrackKey)
{
	Mix_Music* musicTrack = _window->getSoundTrack(musicTrackKey);
	if (Mix_PlayingMusic() == 0)
	{
		//Play the music
		Mix_PlayMusic(musicTrack, -1);
	}
	//If music is being played
	else
	{
		//If the music is paused
		if (Mix_PausedMusic() == 1)
		{
			//Resume the music
			Mix_ResumeMusic();
		}
		//If the music is playing
		else
		{
			//Pause the music
			Mix_PauseMusic();
		}
	}
}

void AbstractGame::reset() {
	for (size_t i = 0; i < screens.size(); i++)
		screens[i]->reset();
}