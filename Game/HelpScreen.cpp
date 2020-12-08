#include "HelpScreen.h"
#include "GameSettings.h"
#include "GameSettings.h"

HelpScreen::HelpScreen() {}
HelpScreen::~HelpScreen() {}

void HelpScreen::onInit() {
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
	srollableElements.push_back(StoryTitle);

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
	StoryText = make_shared<TextUiElement>(storyText);
	_uiElements.push_back(StoryText);
	srollableElements.push_back(StoryText);
	anchor = StoryText->_rect.y;

	TextUiElement keyBindingsText = TextUiElement("-", "Portal", 40, { 515, 600, 100, 0 }, { 255, 255, 255 }, bgColor, true, true);
	shared_ptr<TextUiElement> KeyBindingsTitle = make_shared<TextUiElement>(keyBindingsText);
	KeyBindingsTitle->text = "Basic keybindings";
	_uiElements.push_back(KeyBindingsTitle);
	srollableElements.push_back(KeyBindingsTitle);

	TextUiElement movementText = TextUiElement("-", "Portal", 20, { 110, 700, 100, 0 }, { 255, 255, 255 }, bgColor, false, false);
	shared_ptr<TextUiElement> MovementText = make_shared<TextUiElement>(movementText);
	MovementText->text = "Movement";
	_uiElements.push_back(MovementText);
	srollableElements.push_back(MovementText);

	TextUiElement weaponsText = TextUiElement("-", "Portal", 20, { 250, 700, 100, 0 }, { 255, 255, 255 }, bgColor, false, false);
	shared_ptr<TextUiElement> WeaponsText = make_shared<TextUiElement>(weaponsText);
	WeaponsText->text = "Weapon select";
	_uiElements.push_back(WeaponsText);
	srollableElements.push_back(WeaponsText);

	TextUiElement mouseText = TextUiElement("-", "Portal", 20, { 880, 700, 100, 0 }, { 255, 255, 255 }, bgColor, false, false);
	shared_ptr<TextUiElement> MouseText = make_shared<TextUiElement>(mouseText);
	MouseText->text = "Shoot";
	_uiElements.push_back(MouseText);
	srollableElements.push_back(MouseText);

	TextUiElement jumpText = TextUiElement("-", "Portal", 20, { 350, 1030, 100, 0 }, { 255, 255, 255 }, bgColor, false, false);
	shared_ptr<TextUiElement> JumpText = make_shared<TextUiElement>(jumpText);
	JumpText->text = "Jump";
	_uiElements.push_back(JumpText);
	srollableElements.push_back(JumpText);

	TextUiElement scrollText = TextUiElement("-", "Portal", 20, { 880, 1030, 100, 0 }, { 255, 255, 255 }, bgColor, false, false);
	shared_ptr<TextUiElement> ScrollText = make_shared<TextUiElement>(scrollText);
	ScrollText->text = "Zoom";
	_uiElements.push_back(ScrollText);
	srollableElements.push_back(ScrollText);

	ImageUiElement keybindingsImg = ImageUiElement("Keybindings", { (1080 - 900) / 2 , 450, 1000, 800 }, 0, false);
	keybindingsImage = make_shared<ImageUiElement>(keybindingsImg);
	_uiElements.push_back(keybindingsImage);


	//SCROLL END

	ImageUiElement portalOrangeImg = ImageUiElement("PortalOrange", { 20 , (720 / 2) - 100, 50, 200 });
	_uiElements.push_back(make_shared<ImageUiElement>(portalOrangeImg));

	ImageUiElement portalPurpleImg = ImageUiElement("PortalPurple", { (1080 - 70) , (720 / 2) - 100, 50, 200 });
	_uiElements.push_back(make_shared<ImageUiElement>(portalPurpleImg));

	ImageUiElement headerImg = ImageUiElement("BackgroundTint", { 0 , 0, 1080, 100 });
	_uiElements.push_back(make_shared<ImageUiElement>(headerImg));

	TextUiElement title = TextUiElement("Waluigi", font, 60, { 10, 10, 0, 0 }, { 255, 255, 255 }, TColor, true);
	_uiElements.push_back(make_shared<TextUiElement>(title));

	ImageUiElement footerImg = ImageUiElement("BackgroundTint", { 0 , 625, 1080, 100 });
	_uiElements.push_back(make_shared<ImageUiElement>(footerImg));

	ButtonUiElement backButton = ButtonUiElement("Back", { 515, 650, 70, 40 }, TColor, { 255, 255, 255 }, font, 25);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) {
		LevelData levelData = GameSettings::getInstance().getCurrentLevel();
		game->switchScreen(Screens::GoBack);
	};
	_uiElements.push_back(make_shared<ButtonUiElement>(backButton));

	_fps = make_shared<TextUiElement>(TextUiElement("FPS: 60", "Portal", 19, { 1000, 5, 0, 0 }, { 0, 255, 0 }, { 0, 0, 0, 1 }, false, false));
	_uiElements.push_back(_fps);
}

void HelpScreen::onTick(){
	if (shouldShowFPS)
		_fps->text = "FPS: " + std::to_string(_game->currentFPS);
	else
		_fps->text = "  ";
}

void HelpScreen::handleKeyboardInput(SDL_KeyboardEvent e) {
	SDL_Keycode fps;
	if (ControllManager::getInstance().toggleFPSKey.isDefault)
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.defaultSDLKey);
	else
		fps = SDL_SCANCODE_TO_KEYCODE(ControllManager::getInstance().toggleFPSKey.userSDLKey);

	if (e.keysym.sym == fps)
		shouldShowFPS = !shouldShowFPS;
}

void HelpScreen::handleMouseMotionInput(SDL_MouseMotionEvent e) {}

void HelpScreen::handleMouseWheelInput(SDL_MouseWheelEvent e) {
	if (e.y > 0) // scroll up
		offset = 20;
	else if (e.y < 0) // scroll down
		offset = -20;
	int heightOfScrolBlock = 0;

	heightOfScrolBlock += StoryText->textLines.size() * 25;
	heightOfScrolBlock += 120;

	int currentY = StoryTitle->_rect.y;

	if ((currentY += offset) < anchor) {
		if ((currentY += offset) > ((anchor + heightOfScrolBlock - 200) * -1)) {

			for (auto textElement : srollableElements)
				textElement->_rect.y += offset;

			keybindingsImage->_rect.y += offset;
		}
	}


}