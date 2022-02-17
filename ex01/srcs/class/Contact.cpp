/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:07:11 by jodufour          #+#    #+#             */
/*   Updated: 2022/02/17 02:46:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/Contact.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Contact::Contact(
	std::string const &firstName,
	std::string const &lastName,
	std::string const &nickname,
	std::string const &phoneNumber,
	std::string const &darkestSecret) :
		_firstName(firstName),
		_lastName(lastName),
		_nickname(nickname),
		_phoneNumber(phoneNumber),
		_darkestSecret(darkestSecret)
{
	if (DEBUG)
		std::cout
		<< "Creating Contact"
		<< " (" << this->_firstName << ")"
		<< " (" << this->_lastName << ")"
		<< " (" << this->_nickname << ")"
		<< " (" << this->_phoneNumber << ")"
		<< " (" << this->_darkestSecret << ")"
		<< std::endl;
}

// ************************************************************************* //
//                                Destructors                                //
// ************************************************************************* //

Contact::~Contact(void)
{
	if (DEBUG)
		std::cout
		<< "Destroying Contact"
		<< std::endl;
}

// ************************************************************************* //
//                                 Accessors                                 //
// ************************************************************************* //

std::string const	&Contact::getFirstName(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Contact::getFirstName()"
		<< std::endl;
	return this->_firstName;
}

std::string const	&Contact::getLastName(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Contact::getLastName()"
		<< std::endl;
	return this->_lastName;
}

std::string const	&Contact::getNickname(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Contact::getNickname()"
		<< std::endl;
	return this->_nickname;
}

std::string const	&Contact::getPhoneNumber(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Contact::getPhoneNumber()"
		<< std::endl;
	return this->_phoneNumber;
}

std::string const	&Contact::getDarkestSecret(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Contact::getDarkestSecret()"
		<< std::endl;
	return this->_darkestSecret;
}

void	Contact::setFirstName(std::string const &firstName)
{
	if (DEBUG)
		std::cout
		<< "Calling Contact::setFirstName()"
		<< std::endl;
	this->_firstName = firstName;
}

void	Contact::setLastName(std::string const &lastName)
{
	if (DEBUG)
		std::cout
		<< "Calling Contact::setLastName()"
		<< std::endl;
	this->_lastName = lastName;
}

void	Contact::setNickname(std::string const &nickname)
{
	if (DEBUG)
		std::cout
		<< "Calling Contact::setNickname()"
		<< std::endl;
	this->_nickname = nickname;
}

void	Contact::setPhoneNumber(std::string const &phoneNumber)
{
	if (DEBUG)
		std::cout
		<< "Calling Contact::setPhoneNumber()"
		<< std::endl;
	this->_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string const &darkestSecret)
{
	if (DEBUG)
		std::cout
		<< "Calling Contact::setDarkestSecret()"
		<< std::endl;
	this->_darkestSecret = darkestSecret;
}

// ************************************************************************* //
//                          Public Member Functions                          //
// ************************************************************************* //

void	Contact::printFirstName(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Contact::printFirstName()"
		<< std::endl;
	std::cout << "First name: " << this->_firstName << std::endl;
}

void	Contact::printLastName(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Contact::printLastName()"
		<< std::endl;
	std::cout << "Last name: " << this->_lastName << std::endl;
}

void	Contact::printNickname(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Contact::printNickname()"
		<< std::endl;
	std::cout << "Nickname: " << this->_nickname << std::endl;
}

void	Contact::printPhoneNumber(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Contact::printPhoneNumber()"
		<< std::endl;
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
}

void	Contact::printDarkestSecret(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Contact::printDarkestSecret()"
		<< std::endl;
	std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
}

void	Contact::print(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Contact::print()"
		<< std::endl;
	this->printFirstName();
	this->printLastName();
	this->printNickname();
	this->printPhoneNumber();
	this->printDarkestSecret();
}

bool	Contact::isFilled(void) const
{
	if (DEBUG)
		std::cout
		<< "Calling Contact::isFilled()"
		<< std::endl;
	if (this->_firstName.empty()
		|| this->_lastName.empty()
		|| this->_nickname.empty()
		|| this->_phoneNumber.empty()
		|| this->_darkestSecret.empty())
		return false;
	return true;
}
