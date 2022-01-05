/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassContact.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:07:11 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/05 07:24:19 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "class/ClassContact.hpp"

// ************************************************************************** //
//                                Constructors                                //
// ************************************************************************** //

Contact::Contact(void) {}

Contact::Contact(
	std::string firstName,
	std::string lastName,
	std::string nickname,
	std::string phoneNumber,
	std::string darkestSecret) :
		_firstName(firstName),
		_lastName(lastName),
		_nickname(nickname),
		_phoneNumber(phoneNumber),
		_darkestSecret(darkestSecret) {}

// ************************************************************************* //
//                                Destructors                                //
// ************************************************************************* //

Contact::~Contact(void) {}

// ************************************************************************* //
//                                 Accessors                                 //
// ************************************************************************* //

std::string	Contact::getFirstName() const
{
	return this->_firstName;
}

std::string	Contact::getLastName() const
{
	return this->_lastName;
}

std::string	Contact::getNickname() const
{
	return this->_nickname;
}

std::string	Contact::getPhoneNumber() const
{
	return this->_phoneNumber;
}

std::string	Contact::getDarkestSecret() const
{
	return this->_darkestSecret;
}

void	Contact::setFirstName(std::string firstName)
{
	this->_firstName = firstName;
}

void	Contact::setLastName(std::string lastName)
{
	this->_lastName = lastName;
}

void	Contact::setNickname(std::string nickname)
{
	this->_nickname = nickname;
}

void	Contact::setPhoneNumber(std::string phoneNumber)
{
	this->_phoneNumber = phoneNumber;
}

void	Contact::setDarkestSecret(std::string darkestSecret)
{
	this->_darkestSecret = darkestSecret;
}

// ************************************************************************** //
//                               Public Methods                               //
// ************************************************************************** //

void	Contact::printFirstName(void) const
{
	std::cout << "First name: " << this->_firstName << std::endl;
}

void	Contact::printLastName(void) const
{
	std::cout << "Last name: " << this->_lastName << std::endl;
}

void	Contact::printNickname(void) const
{
	std::cout << "Nickname: " << this->_nickname << std::endl;
}

void	Contact::printPhoneNumber(void) const
{
	std::cout << "Phone number: " << this->_phoneNumber << std::endl;
}

void	Contact::printDarkestSecret(void) const
{
	std::cout << "Darkest secret: " << this->_darkestSecret << std::endl;
}

void	Contact::print(void) const
{
	this->printFirstName();
	this->printLastName();
	this->printNickname();
	this->printPhoneNumber();
	this->printDarkestSecret();
}

bool	Contact::isFilled(void) const
{
	if (this->_firstName.empty()
		|| this->_lastName.empty()
		|| this->_nickname.empty()
		|| this->_phoneNumber.empty()
		|| this->_darkestSecret.empty())
		return false;
	return true;
}
