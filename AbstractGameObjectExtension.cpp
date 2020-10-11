#include "AbstractGameObjectExtension.h"

void AbstractGameObjectExtension::registerSubject(shared_ptr<GameObject> subject) {
	_subject = subject;
}