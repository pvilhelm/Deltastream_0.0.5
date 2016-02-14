#include "InputBuffer.h"



InputBuffer::InputBuffer()
{
	this->_circBuffer = new circular_buffer<DatagramWrapper*>(1000);
}


InputBuffer::~InputBuffer()
{
	delete this->_circBuffer;
}

void InputBuffer::AddDatagram(DatagramWrapper* _datagramWrapper)
{
	_rwLock.lock();
	_circBuffer->push_back(_datagramWrapper);
	_rwLock.unlock();
}

DatagramWrapper* InputBuffer::GetNextDatagram()
{
	_rwLock.lock();
	DatagramWrapper* p_frontDatagram = _circBuffer->front();
	_circBuffer->pop_front();
	_rwLock.unlock();
	return p_frontDatagram; 
}

bool InputBuffer::IsEmpty() {
	_rwLock.lock();
	bool tmp = _circBuffer->empty();
	_rwLock.unlock();
	return tmp;

}
