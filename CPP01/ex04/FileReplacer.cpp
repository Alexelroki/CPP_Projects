#include "FileReplacer.hpp"
#include <iostream>
#include <fstream>

FileReplacer::FileReplacer
(
	const std::string& filename,
	const std::string& s1,
	const std::string& s2
) : _filename(filename), _s1(s1), _s2(s2) {}

FileReplacer::~FileReplacer() {}

std::string	FileReplacer::_replaceLine( const std::string& line )
{
	if (_s1.empty())
		return (line);
	std::string	result = "";
	size_t		current_pos = 0;
	size_t		found_pos;

	found_pos = line.find(_s1, current_pos);
	while (found_pos != std::string::npos)
	{
		result += line.substr(current_pos, found_pos - current_pos);
		result += _s2;
		current_pos = found_pos + _s1.length();
		found_pos = line.find(_s1, current_pos);
	}
	result += line.substr(current_pos);
	return (result);
}

bool	FileReplacer::execute( void )
{
	// Open input file
	std::ifstream	infile(_filename.c_str());
	if (!infile.is_open())
	{
		std::cerr << "Error: Could not open file " << _filename << std::endl;
		return (false);
	}

	// Create output file
	std::string	out_filename = _filename + ".replace";
	std::ofstream	outfile(out_filename.c_str());
	if (!outfile.is_open())
	{
		std::cerr << "Error: Could not create file " << out_filename << std::endl;
		infile.close();
		return (false);
	}

	// Read input file and fill output file with each line replaced
	std::string	line;
	while (std::getline(infile, line))
	{
		outfile << _replaceLine(line);
		if (!infile.eof())
			outfile << "\n";
	}

	// Close files
	infile.close();
	outfile.close();
	return (true);
}
