#include "stdafx.h"
#include "Server.h"

#include "GlobalState.h"

using boost::asio::ip::udp;
using boost::thread;

Server::Server(uint16_t port)
{
	try {
		_udpServerSocket = new udp::socket(_io, udp::endpoint(udp::v4(),port));
		//_udpServerSocket->open(udp::v4()); //accepting ipv4
	}
	catch (std::exception& e) {
		std::cout << e.what();

	}
	SpawnListenThrd();
}

void Listener(Server* s) {
	
	std::cout << "Listening for incoming connections" << std::endl;

	extern GlobalState* _globalState;

	for (;;) {
		std::array<unsigned char, 2000 >* recv_buf = new std::array<unsigned char, 2000 >;
		
		DatagramWrapper* _dataGramWrapper;

		try{
			udp::endpoint remote_endpoint;
			size_t len = s->_udpServerSocket->receive_from(boost::asio::buffer(*recv_buf), remote_endpoint);
			std::vector<unsigned char>* data = new std::vector<unsigned char>(len);
			boost::asio::buffer_copy(boost::asio::buffer(*data), boost::asio::buffer(*recv_buf), len);
			_dataGramWrapper = new DatagramWrapper(data);
			_globalState->_inputBuffer->AddDatagram(_dataGramWrapper);
		}
		catch (const std::exception& e){
			std::cout << e.what();
			
		}
		

		std::cout << "Messages received at port \n" << recv_buf->data() <<"  " << recv_buf;

		

	}
}

bool Server::SpawnListenThrd()
{
	 
	_listenerThread = new thread(Listener, this);
	return true;
}

