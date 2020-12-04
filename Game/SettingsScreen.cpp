#include "SettingsScreen.h"
#include <ImageUiElement.h>
#include <SoundPlayer.h>
#include <ButtonUiElement.h>
#include "Screens.h"
#include "GameSettings.h"

SettingsScreen::SettingsScreen() {}
SettingsScreen::~SettingsScreen() {}

void SettingsScreen::onInit() {
	const Color bgColor = { 28, 28, 28 };
	const string font = "Portal";
	const string fontPortal = "Portal";

	int posy = 100, posx = 100;


	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));


	TextUiElement title = TextUiElement("Settings", font, 60, { 10, 10, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_uiElements.push_back(make_shared<TextUiElement>(title));

	

	TextUiElement soundText = TextUiElement("Sound Music: " + to_string(GameSettings::getInstance().saveGame.settings.sound), font, 40, { 470, 100, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_soundText = make_shared<TextUiElement>(soundText);
	_uiElements.push_back(_soundText);


	ButtonUiElement soundPlus = ButtonUiElement("+", { 470, 150, 150, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	soundPlus.registerGame(_game);
	soundPlus.onClick = [this](AbstractGame* game) { 

		int volume = GameSettings::getInstance().saveGame.settings.sound;

		if(volume <= 118)
			SoundPlayer::getInstance().changeMusicVolume(volume + 10);

		_soundText->text = "Sound Music: " + to_string(SoundPlayer::getInstance().currentVolume);

		GameSettings::getInstance().saveGame.settings.sound = SoundPlayer::getInstance().currentVolume;
		GameSettings::getInstance().save();
	
	};
	_uiElements.push_back(make_shared<ButtonUiElement>(soundPlus));

	ButtonUiElement soundMin = ButtonUiElement("-", { 470, 200, 150, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	soundMin.registerGame(_game);
	soundMin.onClick = [this](AbstractGame* game) { 

		int volume = SoundPlayer::getInstance().currentVolume;

		if (volume >= 10)
			SoundPlayer::getInstance().changeMusicVolume(volume - 10);

		_soundText->text = "Sound Music: " + to_string(SoundPlayer::getInstance().currentVolume);

		GameSettings::getInstance().saveGame.settings.sound = SoundPlayer::getInstance().currentVolume;
		GameSettings::getInstance().save();


	};
	_uiElements.push_back(make_shared<ButtonUiElement>(soundMin));

	_fps = make_shared<TextUiElement>(TextUiElement("FPS: 60", "Portal", 19, { 1000, 5, 0, 0 }, { 0, 255, 0 }, { 0, 0, 0, 1 }, false, false));
	_uiElements.push_back(_fps);


	// change to_string(SoundPlayer::getInstance().currentVolume to the FX curretnvalue
	TextUiElement soundFxText = TextUiElement("Sound FX: " + to_string(GameSettings::getInstance().saveGame.settings.soundFx), font, 40, { 470, 300, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_soundFxText = make_shared<TextUiElement>(soundFxText);
	_uiElements.push_back(_soundFxText);


	ButtonUiElement soundFxPlus = ButtonUiElement("+", { 470, 350, 150, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	soundFxPlus.registerGame(_game);
	soundFxPlus.onClick = [this](AbstractGame* game) {

		int volume = GameSettings::getInstance().saveGame.settings.soundFx;

		if (volume <= 118)
			SoundPlayer::getInstance().changeSFXVolume(volume + 10);

		_soundFxText->text = "Sound FX: " + to_string(SoundPlayer::getInstance().currentSFXVolume);

		GameSettings::getInstance().saveGame.settings.soundFx = SoundPlayer::getInstance().currentSFXVolume;
		GameSettings::getInstance().save();
	};
	_uiElements.push_back(make_shared<ButtonUiElement>(soundFxPlus));

	ButtonUiElement soundFxMin = ButtonUiElement("-", { 470, 400, 150, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	soundFxMin.registerGame(_game);
	soundFxMin.onClick = [this](AbstractGame* game) {

		int volume = GameSettings::getInstance().saveGame.settings.soundFx;

		if (volume >= 10)
			SoundPlayer::getInstance().changeSFXVolume(volume - 10);

		_soundFxText->text = "Sound FX: " + to_string(SoundPlayer::getInstance().currentSFXVolume);
		GameSettings::getInstance().saveGame.settings.soundFx = SoundPlayer::getInstance().currentSFXVolume;
		GameSettings::getInstance().save();


	};
	_uiElements.push_back(make_shared<ButtonUiElement>(soundFxMin));

	ButtonUiElement backButton = ButtonUiElement("Back", { 515, 650, 70, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::GoBack); };
	_uiElements.push_back(make_shared<ButtonUiElement>(backButton));


	ButtonUiElement keyBindingsButton = ButtonUiElement("Keybindings", { 475, 600, 150, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	keyBindingsButton.registerGame(_game);
	keyBindingsButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::KeyBindings); };
	_uiElements.push_back(make_shared<ButtonUiElement>(keyBindingsButton));


}

void SettingsScreen::onTick() {
	if (shouldShowFPS)
		_fps->text = "FPS: " + std::to_string(_game->currentFPS);
	else
		_fps->text = "  ";
}

void SettingsScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
		SDL_Keycode fps;
	if (ControllManager::getInstance().toggleFPSKey.isDefault)
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.defaultSDLKey);
	else
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.userSDLKey);

	if (e.keysym.sym == fps)
		shouldShowFPS = !shouldShowFPS;

	switch (e.keysym.sym)
	{
	case SDLK_ESCAPE: // GO BACK 
		_game->switchScreen(Screens::GoBack);
		break;
	default:
		break;
	}
}

void SettingsScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void SettingsScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {}

