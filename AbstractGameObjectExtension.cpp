#include "AbstractGameObjectExtension.h"


void AbstractGameObjectExtension::registerSubject(GameObject* subject) {
	shared_ptr<GameObject> test(subject);
	_subject = test;
}