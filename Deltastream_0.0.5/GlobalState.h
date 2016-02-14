#pragma once

#include "InputMachine.h"
#include "InputBuffer.h"
#include "StreamInput.h"
#include "Server.h"

class GlobalState
{
public:
	GlobalState();
	~GlobalState();
	InputMachine* _inputMachine;
	InputBuffer* _inputBuffer;
	StreamInput* _streamInput;
	Server* _server;
};

