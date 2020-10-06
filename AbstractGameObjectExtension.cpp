#include "AbstractGameObjectExtension.h"


void AbstractGameObjectExtension::RegisterSubject(shared_ptr<GameObject> subject) {
	_subject = subject;
}