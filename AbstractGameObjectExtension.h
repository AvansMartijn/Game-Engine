#pragma once
#include <memory>
#include <iostream>

using namespace std;

class GameObject;
class AbstractGameObjectExtension
{
public:
	string type;
	virtual void registerSubject(shared_ptr<GameObject> subject);
  
protected:
	// // TODO: Na hetzelfde probleem tegen te komen, ben ik er achter gekomen dat this refences voor een memory leaks gaan zorgen, is is volgens mij ook de reden dat je die error krijgt bij afsluiten van applicatie - Wesley 10-10-2020
	shared_ptr<GameObject> _subject;
};

typedef AbstractGameObjectExtension* (__stdcall* CreateExtensionFn)(void);

