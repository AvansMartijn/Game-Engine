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
	TextUiElement storyTitle = TextUiElement("Story", "Portal", 40, { 515, 125, 100, 0 }, { 255, 255, 255 }, bgColor, true, true);
	_storyTitle = make_shared<TextUiElement>(storyTitle);
	_uiElements.push_back(_storyTitle);
	_scrollableTextElements.push_back(_storyTitle);

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
	_storyText = make_shared<TextUiElement>(storyText);
	_uiElements.push_back(_storyText);
	_scrollableTextElements.push_back(_storyText);
	_anchor = _storyText->rect.y;

	TextUiElement keyBindingsText = TextUiElement("Basic keybindings", "Portal", 40, { 515, 600, 100, 0 }, { 255, 255, 255 }, bgColor, true, true);
	shared_ptr<TextUiElement> pKeyBindingsText = make_shared<TextUiElement>(keyBindingsText);
	_uiElements.push_back(pKeyBindingsText);
	_scrollableTextElements.push_back(pKeyBindingsText);

	TextUiElement movementText = TextUiElement("Movement", "Portal", 20, { 110, 700, 100, 0 }, { 255, 255, 255 }, bgColor, false, false);
	shared_ptr<TextUiElement> pMovementText = make_shared<TextUiElement>(movementText);
	_uiElements.push_back(pMovementText);
	_scrollableTextElements.push_back(pMovementText);

	TextUiElement weaponsText = TextUiElement("Weapon select", "Portal", 20, { 250, 700, 100, 0 }, { 255, 255, 255 }, bgColor, false, false);
	shared_ptr<TextUiElement> pWeaponsText = make_shared<TextUiElement>(weaponsText);
	_uiElements.push_back(pWeaponsText);
	_scrollableTextElements.push_back(pWeaponsText);

	TextUiElement mouseText = TextUiElement("Shoot", "Portal", 20, { 880, 700, 100, 0 }, { 255, 255, 255 }, bgColor, false, false);
	shared_ptr<TextUiElement> pMouseText = make_shared<TextUiElement>(mouseText);
	_uiElements.push_back(pMouseText);
	_scrollableTextElements.push_back(pMouseText);

	TextUiElement jumpText = TextUiElement("Jump", "Portal", 20, { 350, 1030, 100, 0 }, { 255, 255, 255 }, bgColor, false, false);
	shared_ptr<TextUiElement> pJumpText = make_shared<TextUiElement>(jumpText);
	_uiElements.push_back(pJumpText);
	_scrollableTextElements.push_back(pJumpText);

	TextUiElement scrollText = TextUiElement("Zoom", "Portal", 20, { 880, 1030, 100, 0 }, { 255, 255, 255 }, bgColor, false, false);
	shared_ptr<TextUiElement> pScrollText = make_shared<TextUiElement>(scrollText);
	_uiElements.push_back(pScrollText);
	_scrollableTextElements.push_back(pScrollText);

	ImageUiElement keybindingsImg = ImageUiElement("Keybindings", { (1080 - 900) / 2 , 450, 1000, 800 }, 0, false);
	shared_ptr<ImageUiElement> pKeybindingsImage = make_shared<ImageUiElement>(keybindingsImg);
	_uiElements.push_back(pKeybindingsImage);
	_scrollableImgElements.push_back(pKeybindingsImage);

	//Weapons
	TextUiElement weaponsInfoText = TextUiElement("Weapons", "Portal", 40, { 515, 1100, 100, 0 }, { 255, 255, 255 }, bgColor, true, true);
	shared_ptr<TextUiElement> pWeaponsInfoText = make_shared<TextUiElement>(weaponsInfoText);
	_uiElements.push_back(pWeaponsInfoText);
	_scrollableTextElements.push_back(pWeaponsInfoText);

	//portal gun
	ImageUiElement portalGunImg = ImageUiElement("PortalGun", {  100, 1200, 100, 50 }, 0, false);
	shared_ptr<ImageUiElement> pPortalGunImg = make_shared<ImageUiElement>(portalGunImg);
	_uiElements.push_back(pPortalGunImg);
	_scrollableImgElements.push_back(pPortalGunImg);

	TextUiElement portalGunInfoText = TextUiElement("-", "Portal", 25, { 300, 1200, 100, 0 }, { 255, 255, 255 }, bgColor, false,true);
	portalGunInfoText.text = "The portal gun can shoot 2 diffrent portals. \nWhen stepped in one of them you get teleported to the other";
	shared_ptr<TextUiElement> pPortalGunInfoText = make_shared<TextUiElement>(portalGunInfoText);
	_uiElements.push_back(pPortalGunInfoText);
	_scrollableTextElements.push_back(pPortalGunInfoText);

	//thrustergun
	ImageUiElement thrusterGunImg = ImageUiElement("ThrusterGun", { 100, 1350, 100, 50 }, 0, false);
	shared_ptr<ImageUiElement> pThrusterGunImg = make_shared<ImageUiElement>(thrusterGunImg);
	_uiElements.push_back(pThrusterGunImg);
	_scrollableImgElements.push_back(pThrusterGunImg);

	TextUiElement thrusterGunInfoText = TextUiElement("-", "Portal", 25, { 300, 1350, 100, 0 }, { 255, 255, 255 }, bgColor, false, true);
	thrusterGunInfoText.text = "The thuster gun shoots a burts of air and propels you in the opposite \ndirection of the cursor";
	shared_ptr<TextUiElement> pThrusterGunInfoText = make_shared<TextUiElement>(thrusterGunInfoText);
	_uiElements.push_back(pThrusterGunInfoText);
	_scrollableTextElements.push_back(pThrusterGunInfoText);

	//gluegun
	ImageUiElement glueGunImg = ImageUiElement("GlueGun", { 100, 1500, 100, 50 }, 0, false);
	shared_ptr<ImageUiElement> pGlueGunImg = make_shared<ImageUiElement>(glueGunImg);
	_uiElements.push_back(pGlueGunImg);
	_scrollableImgElements.push_back(pGlueGunImg);

	TextUiElement glueGunInfoText = TextUiElement("-", "Portal", 25, { 300, 1500, 100, 0 }, { 255, 255, 255 }, bgColor, false, true);
	glueGunInfoText.text = "The glue gun can shoot glue blobs. the player can interact with these \nblobs by standing on them";
	shared_ptr<TextUiElement> pGlueGunInfoText = make_shared<TextUiElement>(glueGunInfoText);
	_uiElements.push_back(pGlueGunInfoText);
	_scrollableTextElements.push_back(pGlueGunInfoText);

	//environment
	TextUiElement environmentInfoText = TextUiElement("Environment", "Portal", 40, { 515, 1600, 100, 0 }, { 255, 255, 255 }, bgColor, true, true);
	shared_ptr<TextUiElement> pEnvironmentInfoText = make_shared<TextUiElement>(environmentInfoText);
	_uiElements.push_back(pEnvironmentInfoText);
	_scrollableTextElements.push_back(pEnvironmentInfoText);

	//enemies
	ImageUiElement enemiesImg = ImageUiElement("Krool", { 100, 1700, 100, 100 }, 0, false);
	shared_ptr<ImageUiElement> pEnemiesImg = make_shared<ImageUiElement>(enemiesImg);
	_uiElements.push_back(pEnemiesImg);
	_scrollableImgElements.push_back(pEnemiesImg);

	TextUiElement enemiesInfoText = TextUiElement("-", "Portal", 25, { 300, 1700, 100, 0 }, { 255, 255, 255 }, bgColor, false, true);
	enemiesInfoText.text = "Enemies:\n1\n2";
	shared_ptr<TextUiElement> pEnemiesInfoText = make_shared<TextUiElement>(enemiesInfoText);
	_uiElements.push_back(pEnemiesInfoText);
	_scrollableTextElements.push_back(pEnemiesInfoText);


	//spikes
	ImageUiElement spikesImg = ImageUiElement("Spikes", { 100, 1850, 100, 100 }, 0, false);
	shared_ptr<ImageUiElement> pSpikesImg = make_shared<ImageUiElement>(spikesImg);
	_uiElements.push_back(pSpikesImg);
	_scrollableImgElements.push_back(pSpikesImg);

	TextUiElement spikesInfoText = TextUiElement("-", "Portal", 25, { 300, 1850, 100, 0 }, { 255, 255, 255 }, bgColor, false, true);
	spikesInfoText.text = "Spikes:\nDeals damage to the player:\nKEEP AWAY.";
	shared_ptr<TextUiElement> pSpikesInfoText = make_shared<TextUiElement>(spikesInfoText);
	_uiElements.push_back(pSpikesInfoText);
	_scrollableTextElements.push_back(pSpikesInfoText);

	//portalble surfaces
	ImageUiElement portalbleSurfacesImg = ImageUiElement("Portable", { 100, 2000, 100, 100 }, 0, false);
	shared_ptr<ImageUiElement> pPortalbleSurfacesImg = make_shared<ImageUiElement>(portalbleSurfacesImg);
	_uiElements.push_back(pPortalbleSurfacesImg);
	_scrollableImgElements.push_back(pPortalbleSurfacesImg);

	TextUiElement portalbleSurfacesInfoText = TextUiElement("-", "Portal", 25, { 300, 2000, 100, 0 }, { 255, 255, 255 }, bgColor, false, true);
	portalbleSurfacesInfoText.text = "Portalble surfaces:\nOnly on this surface portals can be placed.";
	shared_ptr<TextUiElement> pPortalbleSurfacesInfoText = make_shared<TextUiElement>(portalbleSurfacesInfoText);
	_uiElements.push_back(pPortalbleSurfacesInfoText);
	_scrollableTextElements.push_back(pPortalbleSurfacesInfoText);


	//boxes
	ImageUiElement boxesImg = ImageUiElement("Crate_Metal", { 100, 2150, 100, 100 }, 0, false);
	shared_ptr<ImageUiElement> pBoxesImg = make_shared<ImageUiElement>(boxesImg);
	_uiElements.push_back(pBoxesImg);
	_scrollableImgElements.push_back(pBoxesImg);

	TextUiElement boxesInfoText = TextUiElement("-", "Portal", 25, { 300, 2150, 100, 0 }, { 255, 255, 255 }, bgColor, false, true);
	boxesInfoText.text = "Creates/ Boxes:\nThese can be moved, maybe it will help solve some puzzels? ";
	shared_ptr<TextUiElement> pBoxesInfoText = make_shared<TextUiElement>(boxesInfoText);
	_uiElements.push_back(pBoxesInfoText);
	_scrollableTextElements.push_back(pBoxesInfoText);

	//Finish
	ImageUiElement finishImg = ImageUiElement("Finish", { 100, 2300, 100, 100 }, 0, false);
	shared_ptr<ImageUiElement> pFinishImg = make_shared<ImageUiElement>(finishImg);
	_uiElements.push_back(pFinishImg);
	_scrollableImgElements.push_back(pFinishImg);

	TextUiElement finishInfoText = TextUiElement("-", "Portal", 25, { 300, 2300, 100, 0 }, { 255, 255, 255 }, bgColor, false, true);
	finishInfoText.text = "Finish:\nThe end of the level\nRUSH B";
	shared_ptr<TextUiElement> pFinishInfoText = make_shared<TextUiElement>(finishInfoText);
	_uiElements.push_back(pFinishInfoText);
	_scrollableTextElements.push_back(pFinishInfoText);

   
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
	backButton.onClick = [](shared_ptr<AbstractGame> game) {
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
		_offset = 25;
	else if (e.y < 0) // scroll down
		_offset = -25;

	int heightOfScrolBlock = 0;

	heightOfScrolBlock += (int)_storyText->textLines.size() * 25;
	heightOfScrolBlock += 1500;

	int currentY = _storyTitle->rect.y;

	if ((currentY += _offset) < _anchor) {
		if ((currentY += _offset) > ((_anchor + heightOfScrolBlock - 200) * -1)) {
			for (auto textElement : _scrollableTextElements)
				textElement->rect.y += _offset;

			for (auto imgElement : _scrollableImgElements)
				imgElement->rect.y += _offset;
		}
	}
}