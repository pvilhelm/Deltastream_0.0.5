#pragma once

#include <cstdint>
#include <mutex>

#include "DatagramWrapper.h"

template<class T>
class RingBuffer
{
public:
	RingBuffer(size_t size);
	T* AddObject(T* object);
	T* PeekFirstObject();
	T* TakeFirstObject();
	void RemoveFirstObject();
	void RemoveLastObject();
	size_t Size();
	size_t ExtendSize(size_t size);
	

	T** pointerArr;
	size_t size;
	T** firstMmb;
	T** lastMmb;
	std::mutex rwLock; 

	~RingBuffer();
};

