#pragma once
#include <array>
#include <stdint.h>
#include <thread>
#include <vector>
#include <chrono>

class DatagramWrapper
{
public:
	DatagramWrapper(std::vector<uint8_t>* datagram);
	~DatagramWrapper();
	 
	void Process();
	std::vector<uint8_t>* datagram;
	std::chrono::high_resolution_clock::time_point timestamp;
};

