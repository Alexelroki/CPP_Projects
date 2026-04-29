#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip> // Para std::setw (formato de tabla)

class PhoneBook
{
    private:
        Contact _contacts[8];
        int     _count;  // Cuántos hay en total (máximo 8)
        int     _index;  // Cuál es el siguiente a escribir (0-7)

    public:
        PhoneBook();
        ~PhoneBook();

        void    add();
        void    search() const;
        void    printContact(int i) const;
};

#endif
