#include "main.h"
#include <iostream>
#include "Windows.h"
#include "SDL.h"
#include "Window.h"
#include "GameObjectExtensionFactory.h"
#include "GameObjectBuilder.h"
#include "AttackExtension.h"
#include "MoveExtension.h"
#include "AiExtension.h"
#include "HealthExtension.h"
#include "CheckPhysicsExtension.h"
#include "IEMath.h"

int main(int argc, char* argv[]) {

	//OutputDebugString("Sandbox running");
    std::cout << "Started \n";
	Window window("FluixEngine", 1080, 720);

	SDL_Event event;

	//physics test <--------------------------

	//create gameObjectList
	vector<shared_ptr<GameObject>> gameObjectList;
	GameObjectBuilder builder;

	shared_ptr<GameObject> obj1;

	//Build gameobject
     builder.buildGameObject();

     //Add extensions
     vector<string> extensionNames{ "MoveExtension", "CollisionResolutionDefaultExtension", "CheckPhysicsExtension" };
     builder.addExtension(extensionNames);

     //Get the results
	 obj1 = builder.getResult();

	 Vec2 newPos;
	 newPos.x = 0;
	 newPos.y = 0;
	 Vec2 newVel;
	 newVel.x = 1;
	 newVel.y = 1;

	 //set widht and height (min, max in shape)
	 obj1->physicalBody.shape.min = newPos;
	 obj1->physicalBody.shape.max = newPos + 50;
	 //set position and velocity
	 obj1->physicalBody.body.position = newPos;
	 obj1->physicalBody.body.velocity = newVel;

	 gameObjectList.push_back(obj1);

	 shared_ptr<GameObject> obj2;

	//Build gameobject
     builder.buildGameObject();

     //Add extensions
     extensionNames = { "CollisionResolutionPortalExtension" };
     builder.addExtension(extensionNames);

     //Get the results
	 obj2 = builder.getResult();

	 newPos.x = 0;
	 newPos.y = 700;
	 newVel.x = 0;
	 newVel.y = 0;

	 //set widht and height (min, max in shape)
	 obj2->physicalBody.shape.min = newPos;
	 obj2->physicalBody.shape.max.x = 1080;
	 obj2->physicalBody.shape.max.y = 720;
	 //set position and velocity
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
			//foreach game object;
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
	//end physics test <--------------------------
	return 0;

}

