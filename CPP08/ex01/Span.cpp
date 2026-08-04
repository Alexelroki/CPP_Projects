#include "Span.hpp" 
#include <algorithm> // std::sort, std::min_element, std::max_element

// Orthodox Canonical Form
Span::Span( void ) : maxSize_(0), numbers_() {}

Span::Span( unsigned int N ) : maxSize_(N), numbers_()
{
	numbers_.reserve(N);
}

Span::Span( const Span& other ) : maxSize_(other.maxSize_), numbers_(other.numbers_) {}

Span&	Span::operator=( const Span& other )
{
	if (this != &other)
	{
		this->maxSize_ = other.maxSize_;
		this->numbers_ = other.numbers_;
	}
	return (*this);
}

Span::~Span( void ) {}

// Member Functions
void	Span::addNumber( int number )
{
	if (numbers_.size() >= maxSize_)
	{
		throw OutOfSpaceException();
	}

	numbers_.push_back(number);
}

int		Span::shortestSpan( void ) const
{
	if (numbers_.size() < 2)
	{
		throw NoSpanException();
	}

	std::vector<int>	sortedNumbers(numbers_);
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int	minSpan = sortedNumbers[1] - sortedNumbers[0];

	for (std::size_t i = 2; i < sortedNumbers.size(); ++i)
	{
		int	currentSpan = sortedNumbers[i] - sortedNumbers[i - 1];
		if (currentSpan < minSpan)
		{
			minSpan = currentSpan;
		}
	}

	return (minSpan);
}

int		Span::longestSpan( void ) const
{
	if (numbers_.size() < 2)
	{
		throw NoSpanException();
	}

	std::vector<int>::const_iterator	minIt = std::min_element(numbers_.begin(), numbers_.end());
	std::vector<int>::const_iterator	maxIt = std::max_element(numbers_.begin(), numbers_.end());

	return (*maxIt - *minIt);
}

const char*	Span::OutOfSpaceException::what() const throw()
{
	return ("Maximum size reached.");
}

const char*	Span::NoSpanException::what() const throw()
{
	return ("Not enough elements stored to calculate span (minimum 2 required).");
}
