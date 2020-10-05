#include "main.h"
#include <iostream>
#include "GameObjectExtensionFactory.h"

int main(int argc, char* argv[]) {

    shared_ptr<AbstractGameObjectExtension> extension= NULL;
    string extensionName;

    while (extension == NULL)
    {
        cout << "Type the name of an Extension or q to quit: ";
        cin >> extensionName;

        if (extensionName == "q")
            break;

         AbstractGameObjectExtension* extension = GameObjectExtensionFactory::Get()->CreateExtension(extensionName);
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
    }


    std::system("pause");

    return 0;
}