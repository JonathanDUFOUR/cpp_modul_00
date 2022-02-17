/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:41:16 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/17 02:29:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <string>
#include <iomanip>
#include "colors.hpp"
#include "class/PhoneBook.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

PhoneBook::PhoneBook(void) :
	_contacts()
{
	if (DEBUG)
		std::cout
		<< "Creating PhoneBook"
		<< std::endl;
}

// ************************************************************************* //
//                                Destructors                                //
// ************************************************************************* //

PhoneBook::~PhoneBook(void)
{
	if (DEBUG)
		std::cout
		<< "Destroying PhoneBook"
		<< std::endl;
}

// ************************************************************************* //
//                          Public Member Functions                          //
// ************************************************************************* //

int	PhoneBook::addContact(void)
{
	static int	i = 0;
	std::string	input;
	Contact		tmp;

	if (DEBUG)
		std::cout
		<< "Calling PhoneBook::addContact()"
		<< std::endl;
	std::cout << "First name: ";
	if (!std::getline(std::cin, input))
		return (EXIT_SUCCESS);
	tmp.setFirstName(input);
	std::cout << "Last name: ";
	if (!std::getline(std::cin, input))
		return (EXIT_SUCCESS);
	tmp.setLastName(input);
	std::cout << "Nickname: ";
	if (!std::getline(std::cin, input))
		return (EXIT_SUCCESS);
	tmp.setNickname(input);
	std::cout << "Phone number: ";
	if (!std::getline(std::cin, input))
		return (EXIT_SUCCESS);
	tmp.setPhoneNumber(input);
	std::cout << "Darkest secret: ";
	if (!std::getline(std::cin, input))
		return (EXIT_SUCCESS);
	tmp.setDarkestSecret(input);
	if (tmp.isFilled())
		this->_contacts[i++ % 8] = tmp;
	return (EXIT_SUCCESS);
}

int	PhoneBook::searchContact(void)
{
	std::string					input;
	std::string::const_iterator	iter;
	int							idx;

	if (DEBUG)
		std::cout
		<< "Calling PhoneBook::searchContact()"
		<< std::endl;
	idx = 0;
	printBook();
	std::cout << "Index: ";
	if (!std::getline(std::cin, input))
		return (EXIT_SUCCESS);
	if (input.find_first_not_of("0123456789-+\f\t\n\r\v ") != input.npos
		|| input.empty())
		idx = -1;
	else
		idx = atoi(input.c_str());
	if (idx < 0 || 7 < idx || this->_contacts[idx].getFirstName().empty())
	{
		std::cerr << RED << "Error 404" << RESET << std::endl;
		return EXIT_SUCCESS;
	}
	this->_contacts[idx].print();
	return EXIT_SUCCESS;
}

// ************************************************************************** //
//                          Private Member Functions                          //
// ************************************************************************** //

void	PhoneBook::printBook(void)
{
	Contact	curr;
	int		i;

	if (DEBUG)
		std::cout
		<< "Calling PhoneBook::printBook()"
		<< std::endl;
	std::cout << std::setw(WIDTH) << "Index" << "|";
	std::cout << std::setw(WIDTH) << "First Name" << "|";
	std::cout << std::setw(WIDTH) << "Last Name" << "|";
	std::cout << std::setw(WIDTH) << "Nickname" << std::endl;
	std::cout << std::setfill('-');
	std::cout << std::setw(4 * (WIDTH + 1)) << "" << std::endl;
	std::cout << std::setfill(' ');
	for (i = 0 ; i < 8 ; ++i)
	{
		if (!this->_contacts[i].isFilled())
			break ;
		curr.setFirstName(truncate(this->_contacts[i].getFirstName(), WIDTH));
		curr.setLastName(truncate(this->_contacts[i].getLastName(), WIDTH));
		curr.setNickname(truncate(this->_contacts[i].getNickname(), WIDTH));
		std::cout << std::setw(WIDTH) << i << "|";
		std::cout << std::setw(WIDTH) << curr.getFirstName() << "|";
		std::cout << std::setw(WIDTH) << curr.getLastName() << "|";
		std::cout << std::setw(WIDTH) << curr.getNickname() << std::endl;
	}
}

std::string	PhoneBook::truncate(std::string str, std::size_t width)
{
	if (DEBUG)
		std::cout
		<< "Calling PhoneBook::truncate()"
		<< std::endl;
	if (str.length() > width)
	{
		str[WIDTH - 1] = '.';
		return str.substr(0, WIDTH);
	}
	return str;
}
