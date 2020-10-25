#include <iostream>
#include "GameEngine.h"
#include <Talker.h>

int main()
{
    std::cout << "Hello World!\n";
    std::cout << EngineDoSomthing() << "\n";
    std::cout << EngineDoSomthingElse() << "\n";

    Talker talk;
    std::cout << talk.Talk() << "\n";

}