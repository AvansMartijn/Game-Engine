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
#include "MoveExtension.h"
#include "AiExtension.h"
#include "HealthExtension.h"
#include "CheckPhysicsExtension.h"
#include "IEMath.h"

#include <list>
#include <thread>
#include "DefaultEntityAI.h"

int main(int argc, char* argv[]) {
  std::cout << "Started \n";
	Window window("FluixEngine", 1080, 720);


	SDL_Event event;
	vector<shared_ptr<GameObject>> gameObjectList;
	GameObjectBuilder builder;

	shared_ptr<GameObject> obj1;
  builder.buildGameObject();
  vector<string> extensionNames{ "MoveExtension", "CollisionResolutionDefaultExtension", "CheckPhysicsExtension" };
  builder.addExtension(extensionNames);

	obj1 = builder.getResult();


	Vec2 newPos;
	newPos.x = 0;
	newPos.y = 0;
	Vec2 newVel;
	newVel.x = 0;
	newVel.y = 0;

	obj1->physicalBody.shape.min = newPos;
	obj1->physicalBody.shape.max = newPos + 50;
	obj1->physicalBody.body.position = newPos;
	obj1->physicalBody.body.velocity = newVel;

	gameObjectList.push_back(obj1);

	shared_ptr<GameObject> obj2;
  builder.buildGameObject();
  extensionNames = { "CollisionResolutionPortalExtension" };
  builder.addExtension(extensionNames);

	obj2 = builder.getResult();

	newPos.x = 0;
	newPos.y = 700;
	newVel.x = 0;
	newVel.y = 0;

	obj2->physicalBody.shape.min = newPos;
	obj2->physicalBody.shape.max.x = 1080;
	obj2->physicalBody.shape.max.y = 720;
	obj2->physicalBody.body.position = newPos;
	obj2->physicalBody.body.velocity = newVel;

	gameObjectList.push_back(obj2);

	bool running = true;
	unsigned int a = SDL_GetTicks();
	unsigned int b = SDL_GetTicks();
	double delta = 0;
	while (running) {
		a = SDL_GetTicks();
		delta = a - b;
		if (delta > 1000 / 60.0)
		{
			std::cout << "fps: " << 1000 / delta << std::endl;
			b = a;

			for (auto& obj : gameObjectList)
			{
				if (obj->hasExtension(typeid(MoveExtension))) {
					shared_ptr<MoveExtension> moveExtenstion = dynamic_pointer_cast<MoveExtension>(obj->getExtension(typeid(MoveExtension)));
					moveExtenstion->move();
				}
				if (obj->hasExtension(typeid(CheckPhysicsExtension))) {
					shared_ptr<CheckPhysicsExtension> checkPhysicsExtension = dynamic_pointer_cast<CheckPhysicsExtension>(obj->getExtension(typeid(CheckPhysicsExtension)));
					checkPhysicsExtension->doPhysics(gameObjectList);
				}
			}
				
			window.clear();

			for (auto& obj : gameObjectList)
			{
				window.render(obj);
			}

			window.display();
			while (SDL_PollEvent(&event)) {
				if (event.type == SDL_QUIT) {
					running = false;
				}
			}
		}
	}
	window.cleanUp();
	return 0;
}

