#pragma once
#include <iostream>


template<typename T>
class TStack {

private:

	int top;
	size_t memSize;
	T* pMem = nullptr;

public:

	TStack(size_t memSize_ = 1) : top(-1), memSize(memSize_){

		pMem = new T[memSize];

	}

	~TStack() { delete[] pMem; }

	TStack(const TStack& stack) = delete;

	TStack& operator=(const TStack& stack) = delete;

	void Clear() { 
		delete[] pMem;
		pMem = new T[memSize];
		top = -1;
	}

	bool Empty() const { return top == -1; }

	size_t Size() const { return top + 1; }

	T& Top() { 
		if (top < 0) throw "Stack is empty!";
		return pMem[top]; 
	}

	void Push(T elem) {
		if (top == memSize - 1) {
			T* tmpMem = new T[memSize * 2];
			std::copy(pMem, pMem + memSize, tmpMem);
			delete[] pMem;
			pMem = tmpMem;
			memSize *= 2;
		}
		pMem[++top] = elem;
	}

	void Pop() { 
		if (top<0) throw "Stack is empty!";
		pMem[top--] = T();
	}
};