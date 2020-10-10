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

	//while (!window.isClosed()) {
	//	while (SDL_PollEvent(&event)) {
	//		window.pollEvents();
	//		window.clear();
	//	}
	//}

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

     //cout << obj1->hasExtension(typeid(HealthExtension)) << '\n';
     //cout << obj1->hasExtension(typeid(AiExtension)) << '\n';
     //cout << obj1->hasExtension(typeid(AttackExtension)) << '\n';

	//gameloop
	//const float fps = 100;
	//const float dt = 1 / fps;
	//float accumulator = 0;

		// In units of seconds
	//float frameStart = GetCurrentTime();

		// main loop
		//std::cout << "beforeLoop\n";
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

				/*Update();
				Render();*/
			
		//while (true) {
			
			//const float currentTime = GetCurrentTime();
			//std::cout << "curtime: " << currentTime << "\n";

			// Store the time elapsed since the last frame began
			//accumulator += currentTime - frameStart;

			// Record the starting of this frame
			//frameStart = currentTime;

		/*	if (accumulator > 0.2f)
				accumulator = 0.2f;*/

			/*while (accumulator > dt) {*/

				//UpdatePhysics(gameObjectList);
				for (auto& obj : gameObjectList)
				{


					//std::cout << "doExtensions\n";
					if (obj->hasExtension(typeid(MoveExtension))) {
						//std::cout << "hasMoveExtension\n";
						//auto onzin = obj->getExtension(typeid(MoveExtension));
						shared_ptr<MoveExtension> moveExtenstion = dynamic_pointer_cast<MoveExtension>(obj->getExtension(typeid(MoveExtension)));
						moveExtenstion->move();
					}
					if (obj->hasExtension(typeid(CheckPhysicsExtension))) {
						//std::cout << "hasCheckPhysicsExtension\n";
						shared_ptr<CheckPhysicsExtension> checkPhysicsExtension = dynamic_pointer_cast<CheckPhysicsExtension>(obj->getExtension(typeid(CheckPhysicsExtension)));
						checkPhysicsExtension->doPhysics(gameObjectList);

					}
					/*if (obj->physicalBody.body.position.x >= 1000) {
						PhysicsFacade phys;
						Vec2 newPos;
						newPos.x = 0;
						newPos.y = 0;
						phys.setPosition(obj, newPos);
					}*/
				}
				//accumulator -= dt;

				//RenderGame();
			//}

			//const float alpha = accumulator / dt;
			//RenderGame(alpha);
			window.clear();
			//foreach game object;
			for (auto& obj : gameObjectList)
			{
				//std::cout << "x: " << obj->physicalBody.body.position.x << " y: " << obj->physicalBody.body.position.x << "\n" ;
				window.render(obj);
			}

			window.display();
			//}
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

//void UpdatePhysics(vector<shared_ptr<GameObject>> gameObjectList) {
//	/*for (auto& obj : gameObjectList)
//	{
//		if (obj->hasExtension(typeid(MoveExtension))) {
//			shared_ptr<MoveExtension> moveExtenstion = dynamic_pointer_cast<MoveExtension>(obj->getExtension(typeid(MoveExtension)));
//			moveExtenstion->move();
//		}
//	}*/
//}


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