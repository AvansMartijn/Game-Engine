#include "main.h"
#include <iostream>
#include "GameObjectExtensionFactory.h"
#include "GameObjectBuilder.h"
#include "AttackExtension.h"
#include "AiExtension.h"
#include "HealthExtension.h"

int main(int argc, char* argv[]) {

   /*shared_ptr<AbstractGameObjectExtension> extension= NULL;
    string extensionName;

    while (extension == NULL)
    {
        cout << "Type the name of an Extension or q to quit: ";
        cin >> extensionName;

        if (extensionName == "q")
            break;

         AbstractGameObjectExtension* extension = GameObjectExtensionFactory::Get()->CreateExtension(extensionName);
         std::cout << typeid(extension).name() << '\n';
        if (extension)
        {
            cout <<  extension << endl;
        }
        else
        {
            cout << "Extensions does not exists" << endl;
        }

        delete extension;
        extension = NULL;
        extensionName.clear();
    }*/


    shared_ptr<GameObject> obj;
    GameObjectBuilder builder;

    builder.buildGameObject();

    vector<string> extensionNames{ "AiExtension","AttackExtension" };


    builder.addExtension(extensionNames);

    obj = builder.getResult();



    cout << obj->hasExtension(typeid(HealthExtension)) << '\n';
    cout << obj->hasExtension(typeid(AiExtension)) << '\n';

   

    std::system("pause");

    return 0;
}