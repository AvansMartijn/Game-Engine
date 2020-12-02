#include "StartNewLevelScreen.h"

StartNewLevelScreen::StartNewLevelScreen() {}
StartNewLevelScreen::~StartNewLevelScreen() {}

void StartNewLevelScreen::onInit() {
	const Color bgColor = { 28, 28, 28 };
	const Color TColor = { 51,51,51 };
	const string font = "Portal";
	const string fontPortal = "Portal";
	backgroundTrackKey = "Game_Over";

	ImageUiElement backgroundImg = ImageUiElement("Background", { 0 , 0, 1080, 720 });
	_uiElements.push_back(make_shared<ImageUiElement>(backgroundImg));


	//SCROLL
	TextUiElement storyTitle = TextUiElement("-", "Portal", 40, { 515, 125, 100, 0 }, { 255, 255, 255 }, bgColor, true, true);
	StoryTitle = make_shared<TextUiElement>(storyTitle);
	StoryTitle->text = "Story";
	_uiElements.push_back(StoryTitle);

	TextUiElement storyText = TextUiElement("-", "Portal", 25, { 515, 200, 100, 0 }, { 255, 255, 255 }, bgColor, true, true);
	StoryText = make_shared<TextUiElement>(storyText);
	StoryText->text =
		"For years, waluigi has been hoping to access the Super Smash roster.\n "
		"Unfortunately he never received an invitation for it. \n"
		" \n"
		"Waluigi is frustrated and wants to visit Masahiro Sakurai, the creator of Super Smash.  \n"
		"After some inquiries he knows the location of Masahiro Sakurai. \n"
		"Its a super ultra secret secured facility. \n"
		" \n"
		"Waluigi is denied entry to the facility ... but he is determined to find a way to Masahiro Sakurai ... \n"
		" \n"
		" \n"
		"He sees a back door behind a bush and sneaks in ... \n";
	_uiElements.push_back(StoryText);

	TextUiElement keyBindingsText = TextUiElement("-", "Portal", 40, { 515, 600, 100, 0 }, { 255, 255, 255 }, bgColor, true, true);
	KeyBindingsTitle = make_shared<TextUiElement>(keyBindingsText);
	KeyBindingsTitle->text = "Keybindings";
	_uiElements.push_back(KeyBindingsTitle);

	ImageUiElement keybindingsImg = ImageUiElement("Keybindings", { (1080 - 900) / 2 , 350, 900, 900 });
	keybindingsImage = make_shared<ImageUiElement>(keybindingsImg);
	_uiElements.push_back(keybindingsImage);


	//SCROLL END
	ImageUiElement headerImg = ImageUiElement("BackgroundTint", { 0 , 0, 1080, 100 });
	_uiElements.push_back(make_shared<ImageUiElement>(headerImg));

	TextUiElement title = TextUiElement("Waluigi", font, 60, { 10, 10, 0, 0 }, { 255, 255, 255 }, TColor, true);
	_uiElements.push_back(make_shared<TextUiElement>(title));


	ImageUiElement footerImg = ImageUiElement("BackgroundTint", { 0 , 625, 1080, 100 });
	_uiElements.push_back(make_shared<ImageUiElement>(footerImg));

	ButtonUiElement backButton = ButtonUiElement("Start", { 515, 650, 70, 40 }, TColor, { 255, 255, 255 }, font, 25);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) {
		LevelData levelData = GameSettings::getInstance().getCurrentLevel();
		game->switchScreen(Screens::Loading, { to_string(Screens::MainGame), levelData.levelType == LevelType::DEFAULT ? "default" : "tiled", levelData.levelName, "reset" });
	};
	_uiElements.push_back(make_shared<ButtonUiElement>(backButton));

}

void StartNewLevelScreen::onTick() {}

void StartNewLevelScreen::handleKeyboardInput(SDL_KeyboardEvent e) {}

void StartNewLevelScreen::onScreenShowed(vector<std::string> args) {}

void StartNewLevelScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void StartNewLevelScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {

	if (e.y > 0) // scroll up
		offsett = 10;
	else if (e.y < 0) // scroll down
		offsett = -10;

	StoryTitle->_rect.y += offsett;
	StoryText->_rect.y += offsett;
	KeyBindingsTitle->_rect.y += offsett;
	keybindingsImage->_rect.y += offsett;
}

