#include "CheatScreen.h"
#include "CheatManager.h"
#include <Mouse.h>
#include "ControllManager.h"

//TODO: Move to singelton helper class
void CheatScreen::trim(std::string& s)
{
	leftTrim(s);
	rightTrim(s);
}
void CheatScreen::leftTrim(std::string& s)
{
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](unsigned char ch) {
		return !std::isspace(ch);
	}));
}
void CheatScreen::rightTrim(std::string& s)
{
	s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) {
		return !std::isspace(ch);
	}).base(), s.end());
}

CheatScreen::CheatScreen() {}
CheatScreen::~CheatScreen() {}

void CheatScreen::onInit()
{
	const Color bgColor = { 28, 28, 28 };
	const string font = "Portal";

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));

	TextUiElement title = TextUiElement("Cheats", font, 60, { 10, 10, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_uiElements.push_back(make_shared<TextUiElement>(title));

	TextUiElement EnterCheat = TextUiElement("Enter Cheat", font, 30, { 250, 300, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_uiElements.push_back(make_shared<TextUiElement>(EnterCheat));

	TextUiElement CheatText = TextUiElement(" ", font, 30, { 100, 350, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_cheatText = make_shared<TextUiElement>(CheatText);
	_uiElements.push_back(_cheatText);

	ButtonUiElement cheatHelp = ButtonUiElement("Cheat Overview", { 400, 650, 180, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	cheatHelp.registerGame(_game);
	cheatHelp.onClick = [](AbstractGame* game) { game->switchScreen(Screens::CheatHelp); };
	_uiElements.push_back(make_shared<ButtonUiElement>(cheatHelp));

	ButtonUiElement backButton = ButtonUiElement("Back", { 600, 650, 70, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::MainGame); };
	_uiElements.push_back(make_shared<ButtonUiElement>(backButton));

	_fps = make_shared<TextUiElement>(TextUiElement("FPS: 60", "Portal", 19, { 1000, 5, 0, 0 }, { 0, 255, 0 }, { 0, 0, 0, 1 }, false, false));
	_uiElements.push_back(_fps);
}

void CheatScreen::onTick()
{
	if (shouldShowFPS)
		_fps->text = "FPS: " + std::to_string(_game->currentFPS);
	else
		_fps->text = "  ";

	if (!Mouse::getInstance().isCurrentMouseSkin(Mouse::BEAM))
		Mouse::getInstance().setCursor(Mouse::BEAM);
}

void CheatScreen::handleKeyboardInput(SDL_KeyboardEvent e)
{
	SDL_Keycode fps;
	if (ControllManager::getInstance().toggleFPSKey.isDefault)
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.defaultSDLKey);
	else
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.userSDLKey);

	if (e.keysym.sym == fps)
		shouldShowFPS = !shouldShowFPS;

	if (e.keysym.sym == SDLK_RETURN) {
		std::string cheat = _cheatText->text;
		trim(cheat);
		if (CheatManager::getInstance().isCheat(cheat))
		{
			if (CheatManager::getInstance().executeCheat(cheat)) {
				Scene::getInstance().hasCheated = true;
				_cheatText->text = "Cheat Activated";
				Scene::getInstance().activatedCheats.push_back(cheat);
			}
		}
	}

	if (e.keysym.sym == SDLK_BACKSPACE) {
		if (_cheatText->text.size() == 1) {
			_cheatText->text = " ";
		}
		else if (_cheatText->text.size() > 1) {
			_cheatText->text.pop_back();
		}
	}
	if (_cheatText->text.length() <= 20) {
		if (e.keysym.sym == SDLK_SPACE) {
			_cheatText->text.push_back(' ');
		}
		if (e.keysym.sym >= 97 && e.keysym.sym <= 122) {
			_cheatText->text.push_back((char)e.keysym.sym);
		}
	}
}

void CheatScreen::handleMouseMotionInput(SDL_MouseMotionEvent e)
{
}

void CheatScreen::handleMouseWheelInput(SDL_MouseWheelEvent e)
{
}