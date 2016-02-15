#include "RingBuffer.h"

template<class T>
RingBuffer::RingBuffer(size_t size)
{
	this->pointerArr = new T*[size];
	this->size = size;
	
	 
}

template<class T>
T * RingBuffer<T>::AddObject(T * object)
{
	rwLock.lock();
	
	bool empty = lastMmb == firstMmb; //also true when only one member in buffer ring
	 
	lastMmb = pointerArr + (lastMmb - pointerArr + 1) %size; 
	if (lastMmb == firstMmb & !empty) {
		delete *firstMmb;
		firstMmb = pointerArr + (firstMmb - pointerArr + 1) % size; //should never overflow but w/e
	}
	lastMbm = object;

	rwLock.unlock();

	return lastMmb;
}

template<class T>
T * RingBuffer<T>::PeekFirstObject()
{
	return *firstMmb;
}

template<class T>
T * RingBuffer<T>::TakeFirstObject()
{
	rwLock.lock();

	T* object = *firstMmb;
	if (firstMmb != lastMmb)
		firstMmb = pointerArr + (firstMmb - pointerArr + 1) % size;
	
	rwLock.unlock();

	return object;
}

template<class T>
RingBuffer::~RingBuffer()
{
	do {
		if(PeekFirstObject())
			delete TakeFirstObject();
	} while ((firstMmb != lastMmb))
	
	delete[] pointerArr;
}

