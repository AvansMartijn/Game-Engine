#include "pch.h"
#include "Contact.h"

Contact::Contact(b2Contact* contact) {
	_contact = contact;
}

std::unique_ptr<Fixture> Contact::getFixtureA() {
	return std::make_unique<Fixture>(_contact->GetFixtureA());
}

std::unique_ptr<Fixture> Contact::getFixtureB() {
	return std::make_unique<Fixture>(_contact->GetFixtureB());
}