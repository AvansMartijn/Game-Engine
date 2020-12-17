#include "StartNewLevelScreen.h"

StartNewLevelScreen::StartNewLevelScreen() {}
StartNewLevelScreen::~StartNewLevelScreen() {}

void StartNewLevelScreen::onInit() {
	const Color bgColor = { 28, 28, 28 };
	const Color tColor = { 51,51,51 };
	const string font = "Portal";
	const string fontPortal = "Portal";
	backgroundTrackKey = "Game_Over";

	_backgroundElement = make_unique<ImageUiElement>(ImageUiElement("Background", { 0 , 0, 1080, 720 }));

	//SCROLL
	TextUiElement storyTitle = TextUiElement("Story", "Portal", 40, { 515, 125, 100, 0 }, { 255, 255, 255 }, bgColor, true, true);
	_scrollableUiElement.push_back(make_unique<TextUiElement>(storyTitle));
	_storyTitle = static_cast<TextUiElement*>(_scrollableUiElement.back().get());

	std::vector<std::string> lines;
	lines.push_back("For years, waluigi has been hoping to access the Super Smash roster.");
	lines.push_back("Unfortunately he never received an invitation for it. ");
	lines.push_back(" ");
	lines.push_back("Waluigi is frustrated and wants to visit Masahiro Sakurai, the creator of Super Smash.  ");
	lines.push_back("After some inquiries he knows the location of Masahiro Sakurai. ");
	lines.push_back("Its a super ultra secret secured facility. ");
	lines.push_back(" ");
	lines.push_back("Waluigi is denied entry to the facility ...  ");
	lines.push_back("But he is determined to find a way to Masahiro Sakurai ... ");
	lines.push_back(" ");
	lines.push_back("He sees a back door behind a bush and sneaks in ... ");


	TextUiElement storyText = TextUiElement(lines, "Portal", 25, { 515, 200, 100, 0 }, { 255, 255, 255 }, bgColor, true);
	_scrollableUiElement.push_back(make_unique<TextUiElement>(storyText));
	_storyText = static_cast<TextUiElement*>(_scrollableUiElement.back().get());
	_anchor = _scrollableUiElement.back()->rect.y;

	TextUiElement keyBindingsText = TextUiElement("Basic keybindings", "Portal", 40, { 515, 600, 100, 0 }, { 255, 255, 255 }, bgColor, true, true);
	_scrollableUiElement.push_back(make_unique<TextUiElement>(keyBindingsText));

	TextUiElement movementText = TextUiElement("Movement", "Portal", 20, { 110, 700, 100, 0 }, { 255, 255, 255 }, bgColor, false, false);
	_scrollableUiElement.push_back(make_unique<TextUiElement>(movementText));

	TextUiElement weaponsText = TextUiElement("Weapon select", "Portal", 20, { 250, 700, 100, 0 }, { 255, 255, 255 }, bgColor, false, false);
	_scrollableUiElement.push_back(make_unique<TextUiElement>(weaponsText));

	TextUiElement mouseText = TextUiElement("Shoot", "Portal", 20, { 880, 700, 100, 0 }, { 255, 255, 255 }, bgColor, false, false);
	_scrollableUiElement.push_back(make_unique<TextUiElement>(mouseText));

	TextUiElement jumpText = TextUiElement("Jump", "Portal", 20, { 350, 1030, 100, 0 }, { 255, 255, 255 }, bgColor, false, false);
	_scrollableUiElement.push_back(make_unique<TextUiElement>(jumpText));

	TextUiElement scrollText = TextUiElement("Zoom", "Portal", 20, { 880, 1030, 100, 0 }, { 255, 255, 255 }, bgColor, false, false);
	_scrollableUiElement.push_back(make_unique<TextUiElement>(scrollText));

	ImageUiElement keybindingsImg = ImageUiElement("Keybindings", { (1080 - 900) / 2 , 450, 1000, 800 }, 0, false);
	_scrollableUiElement.push_back(make_unique<ImageUiElement>(keybindingsImg));
	_keybindingsImage = static_cast<ImageUiElement*>(_scrollableUiElement.back().get());
	////SCROLL END
	ImageUiElement portalOrangeImg = ImageUiElement("PortalOrange", { 20 , (720 / 2) - 100, 50, 200 });
	_uiElements.push_back(make_unique<ImageUiElement>(portalOrangeImg));

	ImageUiElement portalPurpleImg = ImageUiElement("PortalPurple", { (1080 - 70) , (720 / 2) - 100, 50, 200 });
	_uiElements.push_back(make_unique<ImageUiElement>(portalPurpleImg));

	ImageUiElement headerImg = ImageUiElement("BackgroundTint", { 0 , 0, 1080, 100 });
	_uiElements.push_back(make_unique<ImageUiElement>(headerImg));

	TextUiElement title = TextUiElement("Help", font, 60, { 10, 10, 0, 0 }, { 255, 255, 255 }, tColor, true);
	_uiElements.push_back(make_unique<TextUiElement>(title));

	ImageUiElement footerImg = ImageUiElement("BackgroundTint", { 0 , 625, 1080, 100 });
	_uiElements.push_back(make_unique<ImageUiElement>(footerImg));

	ButtonUiElement startButton = ButtonUiElement("Start", { 515, 650, 70, 40 }, tColor, { 255, 255, 255 }, font, 25);
	startButton.registerGame(_game);
	startButton.onClick = [](AbstractGame* game) {
		LevelData levelData = GameSettings::getInstance().getCurrentLevel();
		game->switchScreen(Screens::Loading, { to_string(Screens::MainGame), levelData.levelType == LevelType::DEFAULT ? "default" : "tiled", levelData.levelName, "reset" });
	};
	_uiElements.push_back(make_unique<ButtonUiElement>(startButton));

	addFpsElement("Portal");
}

void StartNewLevelScreen::onTick() {
	updateFpsElement();
}

void StartNewLevelScreen::handleKeyboardInput(KeyboardEvent e) {
	Keycode fps;
	if (ControllManager::getInstance().toggleFPSKey.isDefault)
		fps = Utilities::getInstance().getKeycodeFromScancode(ControllManager::getInstance().toggleFPSKey.defaultScanKey);
	else
		fps = Utilities::getInstance().getKeycodeFromScancode(ControllManager::getInstance().toggleFPSKey.userScanKey);

	if (e.keyCode == fps)
		shouldShowFPS = !shouldShowFPS;
}

void StartNewLevelScreen::onScreenShowed(vector<std::string> args) {}

void StartNewLevelScreen::handleMouseWheelInput(MouseWheelEvent e) {
	if (e.y > 0) // scroll up
		_offset = 20;
	else if (e.y < 0) // scroll down
		_offset = -20;

	int heightOfScrolBlock = 0;

	heightOfScrolBlock += (int)_storyText->textLines.size() * 25;
	heightOfScrolBlock += 120;

	int currentY = _storyTitle->rect.y;

	if ((currentY += _offset) < _anchor) {
		if ((currentY += _offset) > ((_anchor + heightOfScrolBlock - 200) * -1)) {
			for (const auto& uiElement : _scrollableUiElement)
				uiElement->rect.y += _offset;
		}
	}
}

void StartNewLevelScreen::preRender(const unique_ptr<Window>& window) {
	_backgroundElement->preRender(window);

	for (const unique_ptr<AbstractUiElement>& scrollableUiElements : _scrollableUiElement)
		scrollableUiElements->preRender(window);

	AbstractScreen::preRender(window);
}

void StartNewLevelScreen::render(const unique_ptr<Window>& window) {
	_backgroundElement->render(window);

	for (const unique_ptr<AbstractUiElement>& scrollableUiElements : _scrollableUiElement)
		scrollableUiElements->render(window);

	AbstractScreen::render(window);
}