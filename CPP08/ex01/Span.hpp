#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <stdexcept>
# include <iterator>
# include <vector>

class Span
{
	public:
		// Orthodox Canonical Form
		Span( unsigned int N );
		Span( const Span& other );
		Span&	operator=( const Span& other );
		~Span( void );

		// Member Functions
		void	addNumber( int number );
		int		shortestSpan( void ) const;
		int		longestSpan( void ) const;

		template <typename Input>
		void	addNumber(Input begin, Input end)
		{
			typename std::iterator_traits<Input>::difference_type	dist = std::distance(begin, end);

			if (dist < 0)
			{
				throw std::invalid_argument("Invalid range (begin > end).");
			}

			std::size_t	count = static_cast<std::size_t>(dist);

			if (numbers_.size() + count > maxSize_)
			{
				throw OutOfSpaceException();
			}

			numbers_.insert(numbers_.end(), begin, end);
		}

		class OutOfSpaceException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

	private:
		unsigned int		maxSize_;
		std::vector<int>	numbers_;

		Span( void );
};

#endif
