#pragma once
#include <vector>
#include <string>
class Quotes {
private:
	Quotes();

	static Quotes _instance;
	std::vector<std::string> _quotes;
public:
	static Quotes& getInstance() { return _instance; }

	Quotes(const Quotes&) = delete;
	Quotes(Quotes&&) = delete;
	Quotes& operator=(const Quotes&) = delete;
	Quotes& operator=(Quotes&&) = delete;

	/// <summary>
	/// Get's a random quote.
	/// </summary>
	/// <returns>A random quote.</returns>
	std::string getQuote();
};

