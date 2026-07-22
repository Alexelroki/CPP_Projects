#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h> // uintptr_t - try <cstdint> later
# include <string>

struct Data // check the Norm V4: s_data, t_data.
{
	std::string	s;
	int		n;
};

class Serializer
{
	public:
		static uintptr_t	serialize( Data* ptr );
		static Data*			deserialize( uintptr_t raw );
	private:
		// Orthodox Canonical Form
		Serializer( void );
		Serializer( const Serializer& other );
		Serializer&		operator=( const Serializer& other );
		~Serializer( void );
};

#endif
