#include "HelpScreen.h"
#include "GameSettings.h"
#include "GameSettings.h"

HelpScreen::HelpScreen() {}
HelpScreen::~HelpScreen() {}

void HelpScreen::onInit() {
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


	//Weapons
	TextUiElement weaponsInfoText = TextUiElement("Weapons", "Portal", 40, { 515, 1100, 100, 0 }, { 255, 255, 255 }, bgColor, true, true);
	_scrollableUiElement.push_back(make_unique<TextUiElement>(weaponsInfoText));

	//portal gun
	ImageUiElement portalGunImg = ImageUiElement("PortalGun", {  100, 1200, 100, 50 }, 0, false);
	_scrollableUiElement.push_back(make_unique<ImageUiElement>(portalGunImg));

	TextUiElement portalGunInfoText = TextUiElement("-", "Portal", 25, { 300, 1200, 100, 0 }, { 255, 255, 255 }, bgColor, false,true);
	portalGunInfoText.text = "The portal gun can shoot 2 diffrent portals. \nWhen stepped in one of them you get teleported to the other";
	_scrollableUiElement.push_back(make_unique<TextUiElement>(portalGunInfoText));

	//thrustergun
	ImageUiElement thrusterGunImg = ImageUiElement("ThrusterGun", { 100, 1350, 100, 50 }, 0, false);
	_scrollableUiElement.push_back(make_unique<ImageUiElement>(thrusterGunImg));

	TextUiElement thrusterGunInfoText = TextUiElement("-", "Portal", 25, { 300, 1350, 100, 0 }, { 255, 255, 255 }, bgColor, false, true);
	thrusterGunInfoText.text = "The thuster gun shoots a burts of air and propels you in the opposite \ndirection of the cursor";
	_scrollableUiElement.push_back(make_unique<TextUiElement>(thrusterGunInfoText));

	//gluegun
	ImageUiElement glueGunImg = ImageUiElement("GlueGun", { 100, 1500, 100, 50 }, 0, false);
	_scrollableUiElement.push_back(make_unique<ImageUiElement>(glueGunImg));

	TextUiElement glueGunInfoText = TextUiElement("-", "Portal", 25, { 300, 1500, 100, 0 }, { 255, 255, 255 }, bgColor, false, true);
	glueGunInfoText.text = "The glue gun can shoot glue blobs. the player can interact with these \nblobs by standing on them";
	_scrollableUiElement.push_back(make_unique<TextUiElement>(glueGunInfoText));

	//environment
	TextUiElement environmentInfoText = TextUiElement("Environment", "Portal", 40, { 515, 1600, 100, 0 }, { 255, 255, 255 }, bgColor, true, true);
	_scrollableUiElement.push_back(make_unique<TextUiElement>(environmentInfoText));

	////enemies
	ImageUiElement enemiesImg = ImageUiElement("Goomba_Icon", { 100, 1700, 100, 100 }, 0, false);
	_scrollableUiElement.push_back(make_unique<ImageUiElement>(enemiesImg));

	TextUiElement enemiesInfoText = TextUiElement("-", "Portal", 25, { 300, 1700, 100, 0 }, { 255, 255, 255 }, bgColor, false, true);
	enemiesInfoText.text = "Enemies:\nWalks towards the enemy.\nNot the smartest of the bunch.\nWill walk in any trap.";
	_scrollableUiElement.push_back(make_unique<TextUiElement>(enemiesInfoText));

	//spikes
	ImageUiElement spikesImg = ImageUiElement("Spikes", { 100, 1850, 100, 100 }, 0, false);
	_scrollableUiElement.push_back(make_unique<ImageUiElement>(spikesImg));

	TextUiElement spikesInfoText = TextUiElement("-", "Portal", 25, { 300, 1850, 100, 0 }, { 255, 255, 255 }, bgColor, false, true);
	spikesInfoText.text = "Spikes:\nDeals damage to the player:\nKEEP AWAY.";
	_scrollableUiElement.push_back(make_unique<TextUiElement>(spikesInfoText));

	//portalble surfaces
	ImageUiElement portalbleSurfacesImg = ImageUiElement("Portable", { 100, 2000, 100, 100 }, 0, false);
	_scrollableUiElement.push_back(make_unique<ImageUiElement>(portalbleSurfacesImg));

	TextUiElement portalbleSurfacesInfoText = TextUiElement("-", "Portal", 25, { 300, 2000, 100, 0 }, { 255, 255, 255 }, bgColor, false, true);
	portalbleSurfacesInfoText.text = "Portalble surfaces:\nOnly on this surface portals can be placed.";
	_scrollableUiElement.push_back(make_unique<TextUiElement>(portalbleSurfacesInfoText));

	//boxes
	ImageUiElement boxesImg = ImageUiElement("Crate_Metal", { 100, 2150, 100, 100 }, 0, false);
	_scrollableUiElement.push_back(make_unique<ImageUiElement>(boxesImg));

	TextUiElement boxesInfoText = TextUiElement("-", "Portal", 25, { 300, 2150, 100, 0 }, { 255, 255, 255 }, bgColor, false, true);
	boxesInfoText.text = "Creates/ Boxes:\nThese can be moved, maybe it will help solve some puzzels? ";
	_scrollableUiElement.push_back(make_unique<TextUiElement>(boxesInfoText));

	//Finish
	ImageUiElement finishImg = ImageUiElement("Finish", { 100, 2300, 100, 100 }, 0, false);
	_scrollableUiElement.push_back(make_unique<ImageUiElement>(finishImg));

	TextUiElement finishInfoText = TextUiElement("-", "Portal", 25, { 300, 2300, 100, 0 }, { 255, 255, 255 }, bgColor, false, true);
	finishInfoText.text = "Finish:\nThe end of the level\nRUSH B";
	_scrollableUiElement.push_back(make_unique<TextUiElement>(finishInfoText));
   
	//SCROLL END

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

	ButtonUiElement backButton = ButtonUiElement("Back", { 515, 650, 70, 40 }, tColor, { 255, 255, 255 }, font, 25);
	backButton.registerGame(_game);
	backButton.onClick = [](AbstractGame* game) {
		LevelData levelData = GameSettings::getInstance().getCurrentLevel();
		game->switchScreen(Screens::GoBack);
	};
	_uiElements.push_back(make_unique<ButtonUiElement>(backButton));

	addFpsElement("Portal");
}

void HelpScreen::onTick(){
	updateFpsElement();
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
		_offset = 25;
	else if (e.y < 0) // scroll down
		_offset = -25;

	int heightOfScrolBlock = 0;

	heightOfScrolBlock += (int)_storyText->textLines.size() * 25;
	heightOfScrolBlock += 1500;

	int currentY = _storyTitle->rect.y;

	if ((currentY += _offset) < _anchor) {
		if ((currentY += _offset) > ((_anchor + heightOfScrolBlock - 200) * -1)) {
			for (const unique_ptr<AbstractUiElement>& scrollableUiElements : _scrollableUiElement)
				scrollableUiElements->rect.y += _offset;
		}
	}
}

void HelpScreen::preRender(const unique_ptr<Window>& window) {
	_backgroundElement->preRender(window);

	for (const unique_ptr<AbstractUiElement>& scrollableUiElements : _scrollableUiElement)
		scrollableUiElements->preRender(window);

	AbstractScreen::preRender(window);
}

void HelpScreen::render(const unique_ptr<Window>& window) {
	_backgroundElement->render(window);

	for (const unique_ptr<AbstractUiElement>& scrollableUiElements : _scrollableUiElement)
		scrollableUiElements->render(window);

	AbstractScreen::render(window);
}