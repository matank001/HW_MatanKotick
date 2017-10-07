#pragma once

#include "ArrayException.h"
#include "Var.h"

//gets only pointer as Var<T>*

template <class T>
class Array {

public:
	Array(int size): _size(size) { _arr = new Var<T>[size]; }
	~Array() { delete[] _arr; }

	Var<T>& operator[] (int pos) {
		ArrayException ex;
		if (pos >= _size || pos < 0) {
			throw ex;
		}
		return _arr[pos];
	}

	Var<T>& operator[] (int pos) const{
		ArrayException ex;
		if (pos >= _size || pos < 0) {
			throw ex;
		}
		return (_arr[pos]).getVal();
	}


private:
	Var<T>* _arr;
	int _size;
};
