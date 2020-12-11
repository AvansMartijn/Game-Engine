#include "Quotes.h"
#include <random>
#include <cassert>


std::default_random_engine& random_engine() {
	static std::random_device rd{};
	static std::default_random_engine re{ rd() };
	return re;
}

int random_int(int low, int high) {
	assert(high > low);
	std::uniform_int_distribution<int> d{ low, high - 1 };
	return d(random_engine());
}


Quotes Quotes::_instance;
Quotes::Quotes() {
	//Lars
	_quotes.push_back("\"Ik word zo verdrietig van dit project\" \n - Lars 2020");
	_quotes.push_back("\"Packies openen\" - Lars 2020");
	_quotes.push_back("\"Dancing Polish Cow 10 Hours\" \n - Lars 2020");
	_quotes.push_back("\"Niks werkt, wat een catastrofe\" \n - Lars 2020");

	//Xandor
	_quotes.push_back("\"Tijd voor een pot\" \n - Xandor  2020");
	_quotes.push_back("\"Gooeeettt\" \n - Xandor  2020");
	_quotes.push_back("\"Alles is kets kapot\" \n - Xandor 2020");

	//Martijn
	_quotes.push_back("\"Tijd voor een pot\" \n - Martijn 2020");
	_quotes.push_back("\"Zak hooi\" \n - Martijn 2020");
	_quotes.push_back("\"Ik ben ook bier zuipen. Ik ben beschikbaar op afroepbasis\" \n - Martijn 2020");
	_quotes.push_back("\"Op kantoor kan ik me wel \"concentreren\" \" \n - Martijn 2020");
	_quotes.push_back("\"Vinkel - EVVC - Ultra V - Side\" \n - Martijn 2020");
	_quotes.push_back("\"Pietje Pur & Theo de Kit - Ik kom uit Vinkel\" \n - Martijn 2020");
	_quotes.push_back("\"Ekkes op release bouwen\" \n - Mardy 2K20");
	
	//Chiel
	_quotes.push_back("\"Martijn wat was je laatste task?\" \n - Chiel 2020");
	_quotes.push_back("\"Goeie poep\" \n - Chiel 2020");
	_quotes.push_back("\"Kijk hoe mooi\" \n - Chiel 2020");
	_quotes.push_back("\"Buuuuuuuuuuuuuurp\" \n - Chiel 2020");
	_quotes.push_back("\"Dat was alles behalven relaxed\" \n - Chiel 2020");

	//Wesley
	_quotes.push_back("\"Devil-op-ment\" \n - Wesley 2020");
	_quotes.push_back("\"Ik ben er in de middag bij\" \n - Wesley 2020");
	_quotes.push_back("\"Ik krijg alle grote tasks\" \n - Wesley 2020");
	_quotes.push_back("\"Ik ben in mijn eigen kanaal\" \n - Wesley 2020");


	//Mike
	_quotes.push_back("\"Gisteren veel te veel gezopen\" \n - Mike 2020");
	_quotes.push_back("\"stop_met_in_de_nacht_werken\" \n - Mike 2020");
	_quotes.push_back("\"Wa mooi!\" \n - Mike 2020");
	_quotes.push_back("\"Wa-elegy, 1 Hour Extended Edition\" \n - Mike 2020");
	_quotes.push_back("\"Soms ben ik gewoon kaulo dom\" \n - Mike 2020");

	//Bob
	_quotes.push_back("\"Rot13 is zo tyfus simpel, dat tik je zo in elkaar\" \n - Bob 2020");
	_quotes.push_back("\"C++ is toch eigenlijk wel een klotetaal\" \n - Bob 2020");

	//Overig
	_quotes.push_back("\"20 Euro op Trump, die wint 100%\" \n - Lars, Xandor, Martijn 2020");
}

std::string Quotes::getQuote() {
	return _quotes[random_int(0, _quotes.size())];
}
