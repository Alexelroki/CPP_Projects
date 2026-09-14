#include "PmergeMe.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

PmergeMe::PmergeMe( void ) {}

PmergeMe::PmergeMe( const PmergeMe& other )
{
	( void )other;
}

PmergeMe&			PmergeMe::operator=( const PmergeMe& other )
{
	(void)other;
	return (*this);
}

PmergeMe::~PmergeMe( void ) {}
