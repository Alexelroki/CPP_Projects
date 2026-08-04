#include "MutantStack.hpp"
#include <stdexcept>
#include <iostream>
#include <list>

int main(int argc, char** argv)
{
	try
	{
		if (argc != 2)
			throw std::invalid_argument("Usage: ./abomination <1|2>");

		std::string mode = argv[1];
		
		///////////////////////////////////////////////////////////////////////////////
		// TEST 1: MutantStack
		if (mode == "1")
		{
			std::cout << "=== TEST 1: MutantStack ===\n";
			MutantStack<int>	mstack;

			mstack.push(5);
			mstack.push(17);
			std::cout << "Top: " << mstack.top() << '\n';

			mstack.pop();
			std::cout << "Size: " << mstack.size() << '\n';

			mstack.push(3);
			mstack.push(5);
			mstack.push(737);
			mstack.push(0);

			MutantStack<int>::iterator	it = mstack.begin();
			MutantStack<int>::iterator	ite = mstack.end();
			++it;
			--it;

			std::cout << "Normal: ";
			while(it != ite)
			{
				std::cout << *it << " ";
				++it;
			}
			std::cout << '\n';

			std::cout << "Reverse: ";
			for (MutantStack<int>::reverse_iterator rit = mstack.rbegin(); rit != mstack.rend(); ++rit)
				std::cout << *rit << " ";
			std::cout << '\n';

			const MutantStack<int>&	constStack(mstack);
			std::cout << "Const: ";
			for (MutantStack<int>::const_iterator cit = constStack.begin(); cit != constStack.end(); ++cit)
				std::cout << *cit << " ";
			std::cout << '\n';

			std::stack<int>	s(mstack);
		}

		///////////////////////////////////////////////////////////////////////////////////
		// TEST 2: std::list (Mismas operaciones exactas (push_back = push && back = top))
		else if (mode == "2")
		{
			std::cout << "=== TEST 2: std::list ===\n";
			std::list<int> lst;

			lst.push_back(5);
			lst.push_back(17);
			std::cout << "Top: " << lst.back() << '\n';

			lst.pop_back();
			std::cout << "Size: " << lst.size() << '\n';

			lst.push_back(3);
			lst.push_back(5);
			lst.push_back(737);
			lst.push_back(0);

			std::list<int>::iterator	it = lst.begin();
			std::list<int>::iterator	ite = lst.end();
			++it;
			--it;

			std::cout << "Normal: ";
			while(it != ite)
			{
				std::cout << *it << " ";
				++it;
			}
			std::cout << '\n';

			std::cout << "Reverse: ";
			for (std::list<int>::reverse_iterator rit = lst.rbegin(); rit != lst.rend(); ++rit)
				std::cout << *rit << " ";
			std::cout << '\n';

			const std::list<int>&	constLst(lst);
			std::cout << "Const: ";
			for (std::list<int>::const_iterator cit = constLst.begin(); cit != constLst.end(); ++cit)
				std::cout << *cit << " ";
			std::cout << '\n';

			std::stack<int, std::list<int> >	s(lst);
		}
		else
			throw std::invalid_argument("Usage: ./abomination <1|2>");
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
		return (1);
	}

	return (0);
}
