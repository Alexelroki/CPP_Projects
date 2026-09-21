#include "PmergeMe.hpp"
#include <cctype>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <stdexcept>

PmergeMe::PmergeMe( void ) : vec_(), deq_() {}

PmergeMe::PmergeMe( const PmergeMe& other ) : vec_(other.vec_), deq_(other.deq_) {}

PmergeMe&			PmergeMe::operator=( const PmergeMe& other )
{
	if (this != &other)
	{
		vec_ = other.vec_;
		deq_ = other.deq_;
	}
	return (*this);
}

PmergeMe::~PmergeMe( void ) {}

void				PmergeMe::parse( int argc, char** argv )
{
	for (int i = 1; i < argc; ++i)
	{
		std::string	str = argv[i];

		if (str.empty())
			throw std::runtime_error("Error");
		for (size_t j = 0; j < str.length(); ++j)
		{
			if (!std::isdigit(str[j]))
				throw std::runtime_error("Error");
		}

		long		num = std::strtol(str.c_str(), NULL, 10);
		if (num <= 0 || num > INT_MAX)
			throw std::runtime_error("Error");

		vec_.push_back(static_cast<int>(num));
		deq_.push_back(static_cast<int>(num));
	}
}
