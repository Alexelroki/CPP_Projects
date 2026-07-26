#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h> // uintptr_t - <cstdint> is c++11
# include "Data.hpp"

class Serializer
{
	public:
		static uintptr_t		serialize( Data* ptr );
		static Data*			deserialize( uintptr_t raw );
	private:
		// Orthodox Canonical Form
		Serializer( void );
		Serializer( const Serializer& other );
		Serializer&		operator=( const Serializer& other );
		~Serializer( void );
};

#endif
