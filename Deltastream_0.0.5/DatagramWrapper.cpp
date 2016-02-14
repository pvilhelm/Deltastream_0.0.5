#include "stdafx.h"
#include "DatagramWrapper.h"


DatagramWrapper::DatagramWrapper(std::vector<uint8_t>* datagram)
{
	this->timestamp = std::chrono::high_resolution_clock::now();
	this->datagram = datagram; 

	
}

DatagramWrapper::~DatagramWrapper()
{
	delete this->datagram;
}


void DatagramWrapper::Process()
{
	;
}
