#include <algorithm>
#include <cassert>

#include "vector.hpp"

vector_t::vector_t()
{
	elements_=nullptr;
	size_=0;
	capacity_=0;
}

vector_t::vector_t(vector_t const & other)
{
	elements_=new int [other.capacity_];
	size_=other.size_;
	capacity_=other.capacity_;
	for (int i = 0; i < capacity_; i++){
		elements_[i] = other.elements_[i];
	}
}

vector_t & vector_t::operator =(vector_t const & other)
{
	int * temp = new int [other.capacity_];
	for (int i = 0; i < other.size_; i++) {
		temp[i] = other.elements_[i];
	}
	delete [] elements_;
	int * elements_ = new int [other.capacity_];
	size_=other.size_;
	capacity_=other.capacity_;
	//elements_=temp;
	for (int i = 0; i < size_; i++) {
		elements_[i] = temp[i];
	}
	return *this;
}

bool vector_t::operator ==(vector_t const & other) const
{
	if ((size_ != other.size_)or(capacity_ != other.capacity_)) return 0;
	for (int i=0; i < size_; i++) 
	if (other.elements_[i] != elements_[i])  return 0;
	return 1;
}

vector_t::~vector_t()
{
	if (elements_ != nullptr) delete [] elements_;
	capacity_=0;
	size_=0;
}

std::size_t vector_t::size() const
{
    return size_;
}

std::size_t vector_t::capacity() const
{
    return capacity_;
}

void vector_t::push_back(int value)
{
	if (capacity_ == 0) {
		capacity_ = 1;
		size_     = 1;
		elements_ = new int [1];
		elements_[0] = value;
		return;
	}
	if (size_ == capacity_) {
		int * temp = new int [capacity_];
		for (int i = 0; i < capacity_; i++) {
			temp[i] = elements_[i];
		}
		delete [] elements_;
		capacity_=capacity_ *2;
		elements_ = new int [capacity_];
		for (int i = 0; i < size_; i++) {
			elements_[i] = temp[i];
		}
	}
	elements_[size_] = value;
	size_ ++;
}

void vector_t::pop_back()
{
		size_--;
	if (size_ <= capacity_/4) {
		int * temp = new int [size_*2];
		for (int i = 0; i < size_; i++) {
			temp[i] = elements_[i];
		}
		delete [] elements_;
		elements_ = new int [size_*2];
		for (int i = 0; i < size_; i++) {
			temp[i] = elements_[i];
		}
		capacity_ = size_*2;
		if (size_ == 0) 
		capacity_ = 1;
		delete [] temp;
	}
	
}

int & vector_t::operator [](std::size_t index)
{
	return elements_[index];
}

int vector_t::operator [](std::size_t index) const
{
	return elements_[index];
}

bool operator !=(vector_t const & lhs, vector_t const & rhs)
{
	bool b = 1;
	
	if (rhs.size() != lhs.size()) return 1;
	for (int i=0; i < lhs.size(); i++) 
	if (rhs[i] == lhs[i])  b = 0;
	return b;
}
