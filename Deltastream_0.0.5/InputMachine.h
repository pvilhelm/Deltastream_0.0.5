#pragma once

#include <map>
#include <cstdint>
#include <boost/thread/thread.hpp>
#include <cstdio>
#include "part.h"


class InputMachine
{
public:
	InputMachine();
	~InputMachine();
	uint32_t partNr = 0;
	uint64_t brdcastNr = 0xAAAAAAAAAAAAAAAA;
	std::map<uint32_t, Part> _partMap; 
	boost::thread* _partCutterThread;
	bool SpawnPartCutterThread();
};

