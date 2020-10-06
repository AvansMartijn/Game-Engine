#include "AbstractGameObjectExtension.h"


void AbstractGameObjectExtension::RegisterSubject(GameObject* subject) {
	shared_ptr<GameObject> test(subject);
	_subject = test;
}