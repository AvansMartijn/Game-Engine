#pragma once
#include <box2d.h>
#include <memory>
#include "AbstractContactHandler.h"
class ContactListener : public b2ContactListener{
private:
	std::unique_ptr<AbstractContactHandler> _contactHandler;
public:
	/// <summary>
	/// When the contact begins.
	/// </summary>
	/// <param name="contact">The contact.</param>
	void BeginContact(b2Contact* contact);

	/// <summary>
	/// When the contact ends.
	/// </summary>
	/// <param name="contact">The contact</param>
	void EndContact(b2Contact* contact);

	/// <summary>
	/// Set's the contact handler.
	/// </summary>
	/// <param name="contactHandler">The contact listener.</param>
	void setContactHandler(std::unique_ptr<AbstractContactHandler> contactHandler);

	/// <summary>
	/// Get's the original pointer. ENGINE ONLY.
	/// </summary>
	/// <returns>The original pointer.</returns>
	AbstractContactHandler* getOrginal();
};

