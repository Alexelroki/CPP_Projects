#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
	public:
		Animal( void );
		Animal( const Animal& other );
		Animal&	operator=( const Animal& other );
		virtual	~Animal( void );

		// The '= 0' syntax makes this a Pure Virtual Function.
        // This prevents the Animal class from being instantiated directly.
		virtual void	makeSound( void ) const = 0;
		std::string		getType( void ) const;

	protected:
		std::string		type;
};

#endif