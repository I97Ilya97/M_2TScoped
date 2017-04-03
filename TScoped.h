# pragma once

#include <iostream>
#include <exception>

template<class T>
class TScopedPtr
{
private:
	T *Data;
public:
	TScopedData() = delete;
	TScopedPtr(TScopedPtr &) = delete;
	TScopedPtr& operator=(TScopedPtr&) = delete;

	TScopedPtr(T *data) : Data(data)
	{}

	~TScopedPtr()
	{
		if(Data != nullptr) delete Data;
	}

	T* operator->()	const
	{
		if(Data == nullptr) throw std::exception("ERROR: Data is nullptr");
		return Data;
	}

	T& operator*() 
	{
		if(Data == nullptr) throw std::exception("ERROR: Data is nullptr");
		return *Data;
	}

	bool isNull() const
	{
		return (Data == nullptr);
	}
};
