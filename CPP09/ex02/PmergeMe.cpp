#include "PmergeMe.hpp"
#include <cctype>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <iomanip>
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

std::vector<size_t>	PmergeMe::buildInsertionVec( size_t pendingCount )
{
	std::vector<size_t> order;
		return (order);
	std::vector<size_t> jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	while (jacob.back() < pendingCount)
	{
		size_t		next = jacob.back() + (2 * jacob[jacob.size() - 2]);
		jacob.push_back(next);
	}

	size_t			lastJacob = 1;
	for (size_t i = 3; i < jacob.size() ; ++i)
	{
		size_t		currentJacob = jacob[i];
		size_t		start = (currentJacob > pendingCount) ? pendingCount : currentJacob;

		for (size_t j = start; j > lastJacob; --j)
			order.push_back(j - 1);
		lastJacob = currentJacob;
		if (currentJacob > pendingCount)
			break ;
	}
	return (order);
}

void				PmergeMe::sortVector( std::vector<int>& v )
{
	if (v.size() <= 1)
		return ;

	int				odd = -1;
	bool			hasOdd = (v.size() % 2 != 0);
	if (hasOdd)
	{
		odd = v.back();
		v.pop_back();
	}

	std::vector<int>	mainChain;
	std::vector<int>	pend;
	for (size_t i = 0; i < v.size(); i += 2)
	{
		if (v[i] > v[i + 1])
		{
			mainChain.push_back(v[i]);
			pend.push_back(v[i + 1]);
		}
		else
		{
			mainChain.push_back(v[i + 1]);
			pend.push_back(v[i]);
		}
	}

	sortVector(mainChain);
	mainChain.insert(mainChain.begin(), pend[0]);

	// 4. Inserción dinámica por bloques según Jacobsthal
	std::vector<size_t> order = buildInsertionVec(pend.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		int val = pend[order[i]];
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), val);
		mainChain.insert(it, val);
	}

	if (hasOdd)
	{
		std::vector<int>::iterator it = std::lower_bound(mainChain.begin(), mainChain.end(), odd);
		mainChain.insert(it, odd);
	}

	v = mainChain;
}

std::deque<size_t>	PmergeMe::buildInsertionDeq( size_t pendingCount )
{
	std::deque<size_t>	order;
	if (pendingCount <= 1)
		return (order);

	std::deque<size_t>	jacob;
	jacob.push_back(0);
	jacob.push_back(1);
	while (jacob.back() < pendingCount)
	{
		size_t		next = jacob.back() + 2 * jacob[jacob.size() - 2];
		jacob.push_back(next);
	}

	size_t			lastJacob = 1;
	for (size_t i = 3; i < jacob.size(); ++i)
	{
		size_t		currentJacob = jacob[i];
		size_t		start = (currentJacob > pendingCount) ? pendingCount : currentJacob;

		for (size_t j = start; j > lastJacob; --j)
			order.push_back(j - 1);

		lastJacob = currentJacob;
		if (currentJacob >= pendingCount)
			break ;
	}
	return (order);
}

void				PmergeMe::sortDeque( std::deque<int>& d )
{
	if (d.size() <= 1)
		return ;

	int				odd = -1;
	bool			hasOdd = (d.size() % 2 != 0);
	if (hasOdd)
	{
		odd = d.back();
		d.pop_back();
	}

	std::deque<int>	mainChain;
	std::deque<int>	pend;
	for (size_t i = 0; i < d.size(); i += 2)
	{
		if (d[i] > d[i + 1])
		{
			mainChain.push_back(d[i]);
			pend.push_back(d[i + 1]);
		}
		else
		{
			mainChain.push_back(d[i + 1]);
			pend.push_back(d[i]);
		}
	}

	sortDeque(mainChain);
	mainChain.push_front(pend[0]);

	std::deque<size_t>	order = buildInsertionDeq(pend.size());
	for (size_t i = 0; i < order.size(); ++i)
	{
		int			val = pend[order[i]];
		std::deque<int>::iterator	it = std::lower_bound(mainChain.begin(), mainChain.end(), val);
		mainChain.insert(it, val);
	}

	if (hasOdd)
	{
		std::deque<int>::iterator	it = std::lower_bound(mainChain.begin(), mainChain.end(), odd);
		mainChain.insert(it, odd);
	}

	d = mainChain;
}

void				PmergeMe::sort( void )
{
	std::cout << "Before: ";
	for (size_t i = 0; i < vec_.size(); ++i)
		std::cout << vec_[i] << ((i + 1 < vec_.size()) ? " " : "");
	std::cout << '\n';

	std::clock_t startVec = std::clock();
	sortVector(vec_);
	std::clock_t endVec = std::clock();
	double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000.0;

	std::clock_t startDeq = std::clock();
	sortDeque(deq_);
	std::clock_t endDeq = std::clock();
	double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000.0;

	std::cout << "After:  ";
	for (size_t i = 0; i < vec_.size(); ++i)
		std::cout << vec_[i] << ((i + 1 < vec_.size()) ? " " : "");
	std::cout << '\n';

	std::cout << "Time to process a range of " << vec_.size()
			  << " elements with std::vector : " << std::fixed << std::setprecision(5)
			  << timeVec << " us\n";

	std::cout << "Time to process a range of " << deq_.size()
			  << " elements with std::deque  : " << std::fixed << std::setprecision(5)
			  << timeDeq << " us\n";
}
