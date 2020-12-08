#include "pch.h"
#include "AbstractGame.h"

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
			//cout << "FPS: " << 1000 / delta << std::endl;
			b = a;

			screens.at(_activeScreen)->onTick();
			
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

		if (qubec > 1000 / Scene::getInstance().refreshRate) {
			d = c;
			calculateFps();
			_window->clear();

			screens.at(_activeScreen)->render(_window);

			_window->display();
		}
	}
}

void AbstractGame::registerTexture(std::string textureKey, std::string texturePath) {
	_window->registerTexture(textureKey, texturePath);
}

void AbstractGame::registerTexture(std::string textureKey, std::string texturePath, std::map<std::string, Rect> sprites) {
	_window->registerTexture(textureKey, texturePath, sprites);
}

void AbstractGame::registerFont(std::string fontKey, std::string fontPath) {
	_window->registerFont(fontKey, fontPath);
}

void AbstractGame::registerTextures(std::string prefix, std::string directory, bool isDeep) {
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

void AbstractGame::initFps()
{
	// Set all frame times to 0ms.
	memset(_frametimes, 0, sizeof(_frametimes));
	_framecount = 0;
	_framespersecond = 0;
	_frametimelast = SDL_GetTicks();

}

void AbstractGame::calculateFps()
{
	Uint32 frametimesindex;
	Uint32 getticks;
	Uint32 count;
	Uint32 i;

	// frametimesindex is the position in the array. It ranges from 0 to FRAME_VALUES.
	// This value rotates back to 0 after it hits FRAME_VALUES.
	frametimesindex = _framecount % FRAME_VALUES;

	getticks = SDL_GetTicks();

	// save the frame time value
	_frametimes[frametimesindex] = getticks - _frametimelast;
	_frametimelast = getticks;
	_framecount++;

	// Work out the current framerate

	// The code below could be moved into another function if you don't need the value every frame.

	// I've included a test to see if the whole array has been written to or not. This will stop
	// strange values on the first few (FRAME_VALUES) frames.
	if (_framecount < FRAME_VALUES) 
		count = _framecount;
	else 
		count = FRAME_VALUES;

	// add up all the values and divide to get the average frame time.
	_framespersecond = 0;
	for (i = 0; i < count; i++) 
		_framespersecond += _frametimes[i];

	_framespersecond /= count;

	// now to make it an actual frames per second value...
	_framespersecond = 1000.f / _framespersecond;
	//cout << currentFPS << endl;
	currentFPS = _framespersecond;

}

int AbstractGame::getPreviousScreen() {
	if (_previousScreens.size() > 0)
	{
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
		_activeScreen = index;
		screens.at(_activeScreen)->onScreenShowed(args);
	}

	const std::string& trackKey = screens.at(_activeScreen)->backgroundTrackKey;

	if (trackKey != "" && trackKey != SoundPlayer::getInstance().playingTrackKey)
		playMusicTrack(trackKey);
}