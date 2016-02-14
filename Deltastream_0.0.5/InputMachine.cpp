#include "InputMachine.h"

using boost::thread;


InputMachine::InputMachine()
{
	SpawnPartCutterThread();
}


InputMachine::~InputMachine()
{
	
}




void Cutter(InputMachine* _IM) {
	for (;;) {
		boost::this_thread::sleep_for(boost::chrono::milliseconds(100));
		//std::cout << "Hej från Input machine" << std::endl;
	}
	 
}

bool InputMachine::SpawnPartCutterThread()
{

	_partCutterThread = new thread(Cutter, this);
	return true;
}
