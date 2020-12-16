#include "pch.h"
#include "ContactListener.h"

void ContactListener::BeginContact(b2Contact* contact) {
	if (_contactHandler != nullptr)
		_contactHandler->onBeginContact(std::make_unique<Contact>(contact));
}

void ContactListener::EndContact(b2Contact* contact) {
	if (_contactHandler != nullptr)
		_contactHandler->onEndContact(std::make_unique<Contact>(contact));
}

void ContactListener::setContactHandler(std::unique_ptr<AbstractContactHandler> contactHandler) {
	_contactHandler = std::move(contactHandler);
}

AbstractContactHandler* ContactListener::getOrginal() {
	return _contactHandler.get();
}
