#pragma once
#include <vector>
#include <string>
class Quotes
{
private:
	Quotes();

	static Quotes instance;
	std::vector<std::string> _quotes;
public:
	static Quotes& getInstance() { return instance; }

	Quotes(const Quotes&) = delete;
	Quotes(Quotes&&) = delete;
	Quotes& operator=(const Quotes&) = delete;
	Quotes& operator=(Quotes&&) = delete;

	std::string getQuote();
};

