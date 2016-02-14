#pragma once


#include <stdint.h>
#include <boost/asio.hpp>

#include "DatagramWrapper.h"


#include <iostream>
#include <cstdlib>
#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <array>
#include <string>
#include <vector>
 
class Server
{
public:
	boost::asio::io_service _io;
	boost::asio::ip::udp::socket* _udpServerSocket;
	Server(uint16_t port);
	boost::thread* _listenerThread;

	bool SpawnListenThrd();
	 
private:
	//void Listener();
	
};

