// Deltastream_0.0.4.cpp : main project file.

#include "stdafx.h"



#include <thread>

#include "InputMachine.h"
#include "Server.h"
#include "GlobalState.h"

GlobalState* _globalState;

int main()
{
	_globalState = new GlobalState();

	_globalState->_server->_listenerThread->join();
	
}
