#pragma once
#ifdef GAMEENGINE_EXPORTS
#define GAMEENGINE_AbstractContactHandler __declspec(dllexport)
#else
#define GAMEENGINE_AbstractContactHandler __declspec(dllimport)
#endif
#include <memory>
#include "Contact.h"

class GAMEENGINE_AbstractContactHandler AbstractContactHandler {
public:
	/// <summary>
	/// When the contact begins.
	/// </summary>
	/// <param name="contact">The contact.</param>
	virtual void onBeginContact(std::unique_ptr<Contact> contact) = 0;

	/// <summary>
	/// When the contact ends.
	/// </summary>
	/// <param name="contact">The contact</param>
	virtual void onEndContact(std::unique_ptr<Contact> contact) = 0;
};

