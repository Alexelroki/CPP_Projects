#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target )
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& other )
	: AForm(other), _target(other._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {}

void	ShrubberyCreationForm::executeAction( void ) const
{
	std::ofstream	file((this->_target + "_shrubbery").c_str());
	if (!file.is_open())
		return ;

	file	<< "					 .o00o\n"
			<< "				   o000000oo\n"
			<< "				  00000000000o\n"
			<< "				 00000000000000\n"
			<< "			  oooooo  00000000  o88o\n"
			<< "		   ooOOOOOOOoo  ```''  888888\n"
			<< "		 OOOOOOOOOOOO'.qQQQQq. `8888'\n"
			<< "		oOOOOOOOOOO'.QQQQQQQQQQ/.88'\n"
			<< "		OOOOOOOOOO'.QQQQQQQQQQ/ /q\n"
			<< "		 OOOOOOOOO QQQQQQQQQQ/ /QQ                \\_/\n"
			<< "		   OOOOOOOOO `QQQQQQ/ /QQ'              --(_)--\n"
			<< "			 OO:F_P:O `QQQ/  /Q'            .'.   / \\\n"
			<< "				\\. \\ |  /\\/ |              / . \\\n"
			<< "			   	 d\\ \\\\|_/\\/               |  |. | ,-'-.\n"
			<< "				qP| \\ _' `|Ob        ,-'-.\\ \\|  /(  .  )\n"
			<< "				   \\  / \\  \\Op      /  .  \\  |, (  \\|   )\n"
			<< "				   |  | O| |       |  .|/  |_|_(    |/   )\n"
			<< "		   _       /\\. \\_/ /\\       \\._|,_/  |  '--.|..-'\n"
			<< "	_____-' `---__/|_\\   /\\/|  ________|_____|______|______\n"
			<< "    /|||/\\|/||/|\\\\/|||/\\|/||/|\\\\/|||/\\|/||/|\\\\/|||\\|\\/|||/\\\n";
		file.close();
}