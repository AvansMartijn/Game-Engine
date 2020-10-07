#include "main.h"
#include <iostream>
#include "Windows.h"
#include "SDL.h"
#include "Window.h"
#include "GameObjectExtensionFactory.h"
#include "AbstractEntityAi.h"
#include "AbstractBehaviour.h"
#include "GameObjectBuilder.h"
#include "AttackExtension.h"
#include "AiExtension.h"
#include "HealthExtension.h"
#include "IEMath.h"

#include <list>
#include <thread>
#include "DefaultEntityAI.h"


void Sleep(int ms) {
	using namespace std::this_thread;     // sleep_for, sleep_until

	sleep_for(std::chrono::milliseconds(ms));
}

GameObject player;
GameObject tile1;
vector<GameObject> createScene() {
	vector<GameObject> scene = {};

	player = GameObject();
	tile1 = GameObject();

	tile1.gridPositionX = 10;
	tile1.gridPositionY = 0;

	scene.push_back(tile1);
	scene.push_back(player);

	return scene;
}

GameObject enemy;
vector<GameObject> scene;
void testAi() {
	DefaultEntityAI ai1 = DefaultEntityAI{};

	//enemy = Enemy(0, 0, 100, false);
	enemy = GameObject();
	scene = createScene();

	shared_ptr<GameObject> enemyPtr = make_shared<GameObject>(enemy);
	shared_ptr<vector<GameObject>> scenePtr = make_shared<vector<GameObject>>(scene);

	std::thread behaviourThread([&ai1, &enemyPtr, &scenePtr] {
		ai1.createBehaviourTree(enemyPtr, scenePtr);
	});

	std::thread playerThread([] {
		while (true) {
			*&player.gridPositionX = player.gridPositionX + 1;
			Sleep(1000);
		}
	});

	behaviourThread.join();
	playerThread.join();
}

int main(int argc, char* argv[]) {

	testAi();
	//OutputDebugString("Sandbox running");
    std::cout << "JOOD \n";
	Window window("FluixEngine", 500, 500);

	SDL_Event event;

	while (!window.isClosed()) {
		while (SDL_PollEvent(&event)) {
			window.pollEvents();
			window.clear();
		}
	}

	return 0;

}

// int main(int argc, char* argv[]) {

   
//     shared_ptr<GameObject> Gameobj;
//     GameObjectBuilder builder;

//     //Build gameobject
//     builder.buildGameObject();

//     //Add extensions
//     vector<string> extensionNames{ "AiExtension","AttackExtension" };
//     builder.addExtension(extensionNames);

//     //Get the results
//     Gameobj = builder.getResult();
//     cout << Gameobj->hasExtension(typeid(HealthExtension)) << '\n';
//     cout << Gameobj->hasExtension(typeid(AiExtension)) << '\n';
//     cout << Gameobj->hasExtension(typeid(AttackExtension)) << '\n';



//     if (Gameobj->hasExtension(typeid(AiExtension)))
//     {
//         shared_ptr<AiExtension> test = dynamic_pointer_cast<AiExtension>(Gameobj->GetExtension(typeid(AiExtension)));
//         test->DoAi();
//     }

//     Gameobj.reset();
//     std::system("pause");

//     return 0;
// }