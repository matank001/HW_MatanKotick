#pragma once

#include <ostream>
#include <iostream>

#include "ArrayException.h"

template <class T>
class Var {
public:
	Var() : _notInit(false) {}

	void operator= (T val) { _val = val; }

	T operator*() {
		ArrayException ex;
		if (_notInit) {
			throw ex;
		}
		return _val;
	}
	
	friend std::ostream& operator<<(std::ostream& os, const Var<T>& val) {
		os << val._val;
		return os;
	}


private:
	T _val;
	bool _notInit;
};