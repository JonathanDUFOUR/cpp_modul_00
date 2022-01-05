/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhoneBook.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:41:16 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/05 07:24:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <string>
#include <iomanip>
#include "colors.hpp"
#include "class/ClassPhoneBook.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

PhoneBook::PhoneBook(void) {}

// ************************************************************************* //
//                                Destructors                                //
// ************************************************************************* //

PhoneBook::~PhoneBook(void) {}

// ************************************************************************** //
//                               Public Methods                               //
// ************************************************************************** //

int	PhoneBook::addContact(void)
{
	static int	i = 0;
	std::string	input;
	Contact		tmp;

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
		this->contacts[i++ % 8] = tmp;
	return (EXIT_SUCCESS);
}

int	PhoneBook::searchContact(void)
{
	std::string					input;
	std::string::const_iterator	iter;
	int							idx;

	idx = 0;
	printBook();
	std::cout << "Index: ";
	if (!std::getline(std::cin, input))
		return (EXIT_SUCCESS);
	if (input.find_first_not_of("0123456789-+\f\t\n\r\v ") != input.npos
		|| input.empty())
		idx = -1;
	else
		idx = stoi(input);
	if (idx < 0 || 7 < idx || this->contacts[idx].getFirstName().empty())
	{
		std::cerr << RED << "Error 404" << RESET << std::endl;
		return EXIT_SUCCESS;
	}
	this->contacts[idx].print();
	return EXIT_SUCCESS;
}

// ************************************************************************* //
//                              Private Methods                              //
// ************************************************************************* //

int		PhoneBook::stoi(std::string str)
{
	std::string::const_iterator	iter = str.begin();
	int							output;
	int							sign;

	output = 0;
	sign = 1;
	for (iter = str.begin() ; std::isspace(*iter) ; ++iter);
	if (*iter == '-' || *iter == '+')
		sign = (-(*iter++ == '-') | 1);
	for ( ; std::isdigit(*iter) ; ++iter)
		output = output * 10 + *iter - '0';
	return output * sign;
}

void	PhoneBook::printBook(void)
{
	Contact	curr;
	int		i;

	std::cout << std::setw(WIDTH) << "Index" << "|";
	std::cout << std::setw(WIDTH) << "First Name" << "|";
	std::cout << std::setw(WIDTH) << "Last Name" << "|";
	std::cout << std::setw(WIDTH) << "Nickname" << std::endl;
	std::cout << std::setfill('-');
	std::cout << std::setw(4 * (WIDTH + 1)) << "" << std::endl;
	std::cout << std::setfill(' ');
	for (i = 0 ; i < 8 ; ++i)
	{
		if (!this->contacts[i].isFilled())
			break ;
		curr.setFirstName(truncate(this->contacts[i].getFirstName(), WIDTH));
		curr.setLastName(truncate(this->contacts[i].getLastName(), WIDTH));
		curr.setNickname(truncate(this->contacts[i].getNickname(), WIDTH));
		std::cout << std::setw(WIDTH) << i << "|";
		std::cout << std::setw(WIDTH) << curr.getFirstName() << "|";
		std::cout << std::setw(WIDTH) << curr.getLastName() << "|";
		std::cout << std::setw(WIDTH) << curr.getNickname() << std::endl;
	}
}

std::string	PhoneBook::truncate(std::string str, std::size_t width)
{
	if (str.length() > width)
	{
		str[9] = '.';
		return str.substr(0, 10);
	}
	return str;
}
