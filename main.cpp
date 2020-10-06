#include "main.h"
#include <iostream>
#include "Windows.h"
#include "SDL.h"
#include "Window.h"
#include "GameObjectExtensionFactory.h"
#include "GameObjectBuilder.h"
#include "AttackExtension.h"
#include "AiExtension.h"
#include "HealthExtension.h"
#include "IEMath.h"

int main(int argc, char* argv[]) {

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