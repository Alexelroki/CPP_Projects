#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

# define RESET		"\033[0m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"

class Contact
{
	private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickName;
		std::string	_phoneNumber;
		std::string	_darkestSecret;

	public:
		Contact();
		~Contact();

		void		setFirstName(const std::string& f);
		void		setLastName(const std::string& l);
		void		setNickName(const std::string& n);
		void		setPhoneNumber(const std::string& p);
		void		setDarkestSecret(const std::string& d);

		std::string	getFirstName(void) const;
		std::string	getLastName(void) const;
		std::string	getNickName(void) const;
		std::string	getPhoneNumber(void) const;
		std::string	getDarkestSecret(void) const;
};

#endif
