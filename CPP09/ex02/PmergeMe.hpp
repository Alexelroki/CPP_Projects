#ifndef PmergeMe_HPP
# define PmergeMe_HPP

# include <string>
# include <vector>
# include <deque>

class PmergeMe
{
	public:
		// Orthodox Canonical Form
		PmergeMe( void );
		PmergeMe( const PmergeMe& other );
		PmergeMe&			operator=( const PmergeMe& other );
		~PmergeMe( void );

		void				parse( int argc, char** argv );
		void				sort( void );

	private:
		std::vector<int>	vec_;
		std::deque<int>		deq_;
};

#endif
