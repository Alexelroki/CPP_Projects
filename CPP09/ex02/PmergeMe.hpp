#ifndef PmergeMe_HPP
# define PmergeMe_HPP

# include <cstddef>
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

		static void					sortVector( std::vector<int>& v );
		static std::vector<size_t>	buildInsertionVec( size_t pendingCount );

		static void					sortDeque( std::deque<int>& d );
		static std::deque<size_t>	buildInsertionDeq( size_t pendingCount );
};

#endif
