#include "GlobalState.h"



GlobalState::GlobalState()
{
	this->_inputMachine = new InputMachine();
	this->_inputBuffer = new InputBuffer();
	this->_streamInput = new StreamInput(2000);
	this->_server = new Server(1000);
}


GlobalState::~GlobalState()
{
}
