#include "pch.h"
#include "AbstractGame.h"
#include "MouseWheelEvent.h"
#include "KeyboardEvent.h"

// How many frames time values to keep
// The higher the value the smoother the result is...
// Don't make it 0 or less :)

AbstractGame::AbstractGame(const char* title, int width, int height) {
	_window = unique_ptr<Window>(new Window("Latrop 2", 1080, 720));
	_activeScreen = 0;
	SoundPlayer::getInstance().openAudio();
}

AbstractGame::~AbstractGame() {}

void AbstractGame::gameLoop() {
	SDL_Event event;

	//Set text color as black
	SDL_Color textColor = { 0, 0, 0, 255 };

	initFps();

	bool running = true;
	unsigned int a = SDL_GetTicks();
	unsigned int b = SDL_GetTicks();
	unsigned int c = SDL_GetTicks();
	unsigned int d = SDL_GetTicks();
	double delta = 0;
	double qubec = 0;
	while (running) {
		a = SDL_GetTicks();
		c = SDL_GetTicks();
		delta = a - b;
		qubec = c - d;
		if (delta > 1000 / Scene::getInstance().tickRate) {
			b = a;

			screens.at(_activeScreen)->onTick();
			
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_KEYDOWN:
					screens.at(_activeScreen)->handleKeyboardInput(KeyboardEvent(event.key));

					break;
				case SDL_MOUSEMOTION:
					screens.at(_activeScreen)->handleMouseMotionInput(MouseMotionEvent(event.motion));

					break;
				case SDL_MOUSEBUTTONDOWN:
					screens.at(_activeScreen)->handleMouseClickInput(MouseButtonEvent(event.button));

					break;
				case SDL_MOUSEWHEEL:
					screens.at(_activeScreen)->handleMouseWheelInput(MouseWheelEvent(event.wheel));

					break;
				case SDL_QUIT:
					running = false;

					break;
				default:
					break;
				}
			}
		}

		if (qubec > 1000 / Scene::getInstance().refreshRate) {
			d = c;
			calculateFps();
			_window->clear();

			screens.at(_activeScreen)->render(_window);

			_window->display();
		}
	}
}

void AbstractGame::registerTexture(const std::string& textureKey, const std::string& texturePath, bool isReversed) {
	_window->registerTexture(textureKey, texturePath, isReversed);
}

void AbstractGame::registerFont(const std::string& fontKey, const std::string& fontPath) {
	_window->registerFont(fontKey, fontPath);
}

void AbstractGame::registerTextures(const std::string& prefix, const std::string& directory, bool isDeep) {
	_window->registerTextures(prefix, directory, isDeep);
}

void AbstractGame::registerMusicTrack(const std::string& musicTrackKey, const std::string& trackPath){
	SoundPlayer::getInstance().registerMusicTrack(musicTrackKey, trackPath);
}

void AbstractGame::registerSFXTrack(const std::string& sfxTrackKey, const std::string& trackPath){
	SoundPlayer::getInstance().registerSFXTrack(sfxTrackKey, trackPath);
}

void AbstractGame::playMusicTrack(const std::string& musicTrackKey){
	SoundPlayer::getInstance().playMusicTrack(musicTrackKey);
}

void AbstractGame::reset() {
	for (size_t i = 0; i < screens.size(); i++)
		screens[i]->reset();
}

void AbstractGame::initFps() {
	memset(_frameTimes, 0, sizeof(_frameTimes));

	_frameCount = 0;
	_framesPerSecond = 0;
	_frameTimeLast = SDL_GetTicks();
}

void AbstractGame::calculateFps() {
	Uint32 frameTimesIndex;
	Uint32 ticks;
	Uint32 count;
	Uint32 i;

	frameTimesIndex = _frameCount % FRAME_VALUES;

	ticks = SDL_GetTicks();

	_frameTimes[frameTimesIndex] = ticks - _frameTimeLast;
	_frameTimeLast = ticks;
	_frameCount++;

	if (_frameCount < FRAME_VALUES)
		count = _frameCount;
	else 
		count = FRAME_VALUES;

	_framesPerSecond = 0;
	for (i = 0; i < count; i++) 
		_framesPerSecond += _frameTimes[i];

	_framesPerSecond /= count;

	_framesPerSecond = 1000.f / _framesPerSecond;
	currentFPS = (int)_framesPerSecond;
}

int AbstractGame::getPreviousScreen() {
	if (_previousScreens.size() > 0) {
		int value = _previousScreens.top();
		_previousScreens.pop();

		return value;
	}
	return -1;
}

void AbstractGame::switchScreen(int screenIndex, vector<std::string> args) {
	size_t index = screenIndex;
	if (index == -1)
		index = this->getPreviousScreen();
	else if (_activeScreen)
		_previousScreens.push(_activeScreen);

	if (index + 1 <= screens.size()) {
		_activeScreen = (int)index;
		screens.at(_activeScreen)->onScreenShowed(args);
	}

	const std::string& trackKey = screens.at(_activeScreen)->backgroundTrackKey;

	if (trackKey != "" && trackKey != SoundPlayer::getInstance().playingTrackKey)
		playMusicTrack(trackKey);
}