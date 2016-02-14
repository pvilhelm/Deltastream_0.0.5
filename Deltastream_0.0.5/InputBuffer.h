#pragma once

#include <boost/circular_buffer.hpp>
#include <mutex>
#include "DatagramWrapper.h"

using boost::circular_buffer;

class InputBuffer
{
public:
	InputBuffer();
	~InputBuffer();
	circular_buffer<DatagramWrapper*>* _circBuffer;
	void AddDatagram(DatagramWrapper*);
	DatagramWrapper* GetNextDatagram();

	bool IsEmpty();

	std::mutex _rwLock;
};

