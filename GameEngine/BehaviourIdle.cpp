#include "pch.h"
#include "BehaviourIdle.h"
#include <thread>
void BehaviourIdle::execute() {
	std::cout << "====================================\n";
	std::cout << "> Idle\n";

	using namespace std::this_thread;     // sleep_for, sleep_until

	sleep_for(std::chrono::milliseconds(1000));

	this->executeNextBehaviour(true);
}
