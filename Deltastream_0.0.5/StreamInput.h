#pragma once

#include <stdint.h>
#include <boost/asio.hpp>
 
#include <iostream>
#include <cstdlib>
#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <array>
#include <string>
#include <vector>



class StreamInput
{
public:
	 
	~StreamInput();
	 
	StreamInput(uint16_t port);
	boost::thread* _listenerThread;

	bool SpawnListenThrd();
	boost::asio::io_service _io;
	boost::asio::ip::udp::socket* _udpServerSocket;
};

