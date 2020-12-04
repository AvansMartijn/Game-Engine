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
	quoteText = make_shared<TextUiElement>(quoteTest);
	_uiElements.push_back(quoteText);


	ImageUiElement walu = ImageUiElement("Loading", { ((1080 - 700) / 2) + 100 , ((720 - 700) / 2), 700, 700 });
	_uiElements.push_back(make_shared<ImageUiElement>(walu));
}

void LoadingScreen::onTick() {

	if (firstTickCounter != 0) {
		auto screen = stoi(arguments[0]);
		arguments.erase(arguments.begin());
		_game->switchScreen(screen, arguments);
	}	

	firstTickCounter++;

	if (shouldShowFPS)
		fps->text = "FPS: " + std::to_string(_game->currentFPS);
	else
		fps->text = "  ";
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
	arguments = args;
	firstTickCounter = 0;

	quoteText->text = Quotes::getInstance().getQuote();
}
