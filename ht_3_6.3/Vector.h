#pragma once
#include <exception>
#include <stdexcept>

template<class T>
class Vector {
private:
	T* arr;
	int virtual_length = 0;
	int actual_length = 0;
public:

	Vector(Vector<T> const& v) {
		actual_length = v.actual_length;
		virtual_length = v.virtual_length;
		arr = new T[actual_length];
		for (int i = 0; i < virtual_length; ++i) {
			arr[i] = v.arr[i];
		}
	}

	Vector(int n) {
		if (n > 0) {
			actual_length = n;
			arr = new T[actual_length];
		}
		else throw std::length_error("Length must be bigger or equal to 1");
	};

	Vector() {
		actual_length = 1;
		arr = new T[actual_length];
	};

	~Vector() { delete[] arr; };

	Vector<T>& operator=(const Vector<T>& v) {
		if (this != &v) {
			actual_length = v.actual_length;
			virtual_length = v.virtual_length;
			delete[] arr;
			arr = new T[actual_length];
			for (int i = 0; i < virtual_length; ++i) {
				arr[i] = v.arr[i];
			}
		}
		return *this;
	}

	void push_back(const T value) {
		if (virtual_length < actual_length) arr[virtual_length++] = value;
		else {
			actual_length *= 2;
			T* arr2 = new T[actual_length];
			for (int i = 0; i < virtual_length; ++i) {
				arr2[i] = arr[i];
			}
			arr2[virtual_length++] = value;
			delete[] arr;
			arr = arr2;
		}
	};

	T at(int index) {
		if (index < 0 || index >= virtual_length) throw std::out_of_range("Index is out of range");
		else return arr[index];
	};

	T operator[](int index) {
		return arr[index];
	}

	int size() { return virtual_length; };
	int capacity() { return actual_length; };
};