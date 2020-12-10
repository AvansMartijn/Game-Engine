#include "LoadingScreen.h"
#include "Quotes.h"



LoadingScreen::LoadingScreen() {}

LoadingScreen::~LoadingScreen() {}

void LoadingScreen::onInit() {
	const Color bgColor = { 28, 28, 28 };
	const string font = "Portal";
	const string fontPortal = "OpenSans";

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement headerText = TextUiElement("Loading . . . ", font, 60, { 10, 10, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, false);
	_uiElements.push_back(make_shared<TextUiElement>(headerText));

	TextUiElement quoteTest = TextUiElement("Quote:", font, 18, { 30, 500, 0, 0 }, { 255, 255, 255 }, { 28, 28, 28 }, false, true);
	_quoteText = make_shared<TextUiElement>(quoteTest);
	_uiElements.push_back(_quoteText);


	ImageUiElement walu = ImageUiElement("Loading", { ((1080 - 700) / 2) + 100 , ((720 - 700) / 2), 700, 700 });
	_uiElements.push_back(make_shared<ImageUiElement>(walu));

	_fps = make_shared<TextUiElement>(TextUiElement("FPS: 60", "Portal", 19, { 1000, 5, 0, 0 }, { 0, 255, 0 }, { 0, 0, 0, 1 }, false, false));
	_uiElements.push_back(_fps);
}

void LoadingScreen::onTick() {

	if (_firstTickCounter != 0) {
		auto screen = stoi(_arguments[0]);
		_arguments.erase(_arguments.begin());
		_game->switchScreen(screen, _arguments);
	}	

	_firstTickCounter++;

	if (shouldShowFPS)
		_fps->text = "FPS: " + std::to_string(_game->currentFPS);
	else
		_fps->text = "  ";
}

void LoadingScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	SDL_Keycode fps;
	if (ControllManager::getInstance().toggleFPSKey.isDefault)
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.defaultSDLKey);
	else
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.userSDLKey);

	if (e.keysym.sym == fps)
		shouldShowFPS = !shouldShowFPS;
}

void LoadingScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void LoadingScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {}

void LoadingScreen::onScreenShowed(vector<std::string> args)
{
	_arguments = args;
	_firstTickCounter = 0;

	_quoteText->text = Quotes::getInstance().getQuote();
}
