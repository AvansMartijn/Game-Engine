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

	addFpsElement("Portal");

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_unique<ImageUiElement>(backgroundImg));

	TextUiElement title = TextUiElement("Settings", font, 60, { 10, 10, 0, 0 }, { 255, 255, 255 }, bgColor, true);
	_uiElements.push_back(make_unique<TextUiElement>(title));

	TextUiElement soundText = TextUiElement("Sound Music: " + to_string(GameSettings::getInstance().saveGame.settings.sound), font, 40, { 150, 100, 0, 0 }, { 255, 255, 255 }, bgColor, false);
	_soundText = addUiElement<TextUiElement>(make_unique<TextUiElement>(soundText));

	ButtonUiElement soundPlus = ButtonUiElement("+", { 260, 160, 40, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	soundPlus.registerGame(_game);
	soundPlus.onClick = [this](AbstractGame* game) {
		int volume = GameSettings::getInstance().saveGame.settings.sound;

		if(volume <= 118)
			SoundPlayer::getInstance().changeMusicVolume(volume + 10);

		_soundText->text = "Sound Music: " + to_string(SoundPlayer::getInstance().currentVolume);

		GameSettings::getInstance().saveGame.settings.sound = SoundPlayer::getInstance().currentVolume;
		GameSettings::getInstance().save();
	};
	_uiElements.push_back(make_unique<ButtonUiElement>(soundPlus));

	ButtonUiElement soundMin = ButtonUiElement("-", { 160, 160, 40, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	soundMin.registerGame(_game);
	soundMin.onClick = [this](AbstractGame* game) {
		int volume = SoundPlayer::getInstance().currentVolume;

		if (volume >= 10)
			SoundPlayer::getInstance().changeMusicVolume(volume - 10);

		_soundText->text = "Sound Music: " + to_string(SoundPlayer::getInstance().currentVolume);

		GameSettings::getInstance().saveGame.settings.sound = SoundPlayer::getInstance().currentVolume;
		GameSettings::getInstance().save();
	};
	_uiElements.push_back(make_unique<ButtonUiElement>(soundMin));

	// change to_string(SoundPlayer::getInstance().currentVolume to the FX curretnvalue
	TextUiElement soundFxText = TextUiElement("Sound FX: " + to_string(GameSettings::getInstance().saveGame.settings.soundFx), font, 40, { 150, 250, 0, 0 }, { 255, 255, 255 }, bgColor, false);
	_soundFxText = addUiElement<TextUiElement>(make_unique<TextUiElement>(soundFxText));

	ButtonUiElement soundFxPlus = ButtonUiElement("+", { 260, 310, 40, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	soundFxPlus.registerGame(_game);
	soundFxPlus.onClick = [this](AbstractGame* game) {
		int volume = GameSettings::getInstance().saveGame.settings.soundFx;

		if (volume <= 118)
			SoundPlayer::getInstance().changeSFXVolume(volume + 10);

		_soundFxText->text = "Sound FX: " + to_string(SoundPlayer::getInstance().currentSFXVolume);

		GameSettings::getInstance().saveGame.settings.soundFx = SoundPlayer::getInstance().currentSFXVolume;
		GameSettings::getInstance().save();
	};
	_uiElements.push_back(make_unique<ButtonUiElement>(soundFxPlus));

	ButtonUiElement soundFxMin = ButtonUiElement("-", { 160, 310, 40, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	soundFxMin.registerGame(_game);
	soundFxMin.onClick = [this](AbstractGame* game) {
		int volume = GameSettings::getInstance().saveGame.settings.soundFx;

		if (volume >= 10)
			SoundPlayer::getInstance().changeSFXVolume(volume - 10);

		_soundFxText->text = "Sound FX: " + to_string(SoundPlayer::getInstance().currentSFXVolume);
		GameSettings::getInstance().saveGame.settings.soundFx = SoundPlayer::getInstance().currentSFXVolume;
		GameSettings::getInstance().save();


	};
	_uiElements.push_back(make_unique<ButtonUiElement>(soundFxMin));

	TextUiElement gameSpeed = TextUiElement("Game speed: " + to_string(Scene::getInstance().tickRate), font, 40, { 650, 100, 0, 0 }, { 255, 255, 255 }, bgColor, false);
	_tickSpeed = addUiElement<TextUiElement>(make_unique<TextUiElement>(gameSpeed));

	ButtonUiElement gameSpeedDown = ButtonUiElement("Slow Down", { 650, 160, 150, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	gameSpeedDown.registerGame(_game);
	gameSpeedDown.onClick = [this](AbstractGame* game) {
		int val = (int)Scene::getInstance().tickRate;
		if (val - 10 > 0) {
			Scene::getInstance().tickRate = Scene::getInstance().tickRate - 10;
			_tickSpeed->text = "Game speed: " + to_string(Scene::getInstance().tickRate);
		}
	};
	_uiElements.push_back(make_unique<ButtonUiElement>(gameSpeedDown));

	ButtonUiElement gameSpeedUp = ButtonUiElement("Speed Up", { 650, 210, 150, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	gameSpeedUp.registerGame(_game);
	gameSpeedUp.onClick = [this](AbstractGame* game) {
		int val = (int)Scene::getInstance().tickRate;
		if (val + 10 <= 250) {
			Scene::getInstance().tickRate = Scene::getInstance().tickRate + 10;
			_tickSpeed->text = "Game speed: " + to_string(Scene::getInstance().tickRate);
		}
	};
	_uiElements.push_back(make_unique<ButtonUiElement>(gameSpeedUp));

	ButtonUiElement backButton = ButtonUiElement("Back", { 515, 650, 70, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::GoBack); };
	_uiElements.push_back(make_unique<ButtonUiElement>(backButton));

	ButtonUiElement keyBindingsButton = ButtonUiElement("Keybindings", { 475, 600, 150, 40 }, bgColor, { 255, 255, 255 }, font, 25);
	keyBindingsButton.registerGame(_game);
	keyBindingsButton.onClick = [](AbstractGame* game) { game->switchScreen(Screens::KeyBindings); };
	_uiElements.push_back(make_unique<ButtonUiElement>(keyBindingsButton));
}

void SettingsScreen::onTick() {
	updateFpsElement();
}

void SettingsScreen::handleKeyboardInput(KeyboardEvent e) {
	Keycode fps;
	if (ControllManager::getInstance().toggleFPSKey.isDefault)
		fps = Utilities::getInstance().getKeycodeFromScancode(ControllManager::getInstance().toggleFPSKey.defaultScanKey);
	else
		fps = Utilities::getInstance().getKeycodeFromScancode(ControllManager::getInstance().toggleFPSKey.userScanKey);

	if (e.keyCode == fps)
		shouldShowFPS = !shouldShowFPS;

	switch (e.keyCode) {
	case KEY_ESCAPE: // GO BACK 
		_game->switchScreen(Screens::GoBack);
		break;
	default:
		break;
	}
}