#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception> // size_t

template <typename T>
class Array
{
	public:
		// Orthodox Canonical Form
		Array( void );
		Array( unsigned int n );
		Array( const Array<T>& other );
		Array<T>&			operator=( const Array<T>& other );
		~Array( void );

		// Subscript operator (Read/Write and Read-Only)
		T&				operator[]( unsigned int index );
		const T&		operator[]( unsigned int index ) const ;

		// Member Function
		unsigned int	size() const;

		// Nested Exception Class
		class OutOfBoundsException : public std::exception
		{
			public:
				virtual const char* 	what() const throw();
		};

	private:
		T*				_elements;
		unsigned int	_size;
};

# include "Array.tpp"

#endif
