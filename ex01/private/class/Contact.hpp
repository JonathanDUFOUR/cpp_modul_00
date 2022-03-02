/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 13:08:09 by jodufour          #+#    #+#             */
/*   Updated: 2022/03/02 17:05:37 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

# ifndef DEBUG
#  define DEBUG 0
# endif

class Contact
{
private:
	// Attributes
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_phoneNumber;
	std::string	_darkestSecret;

public:
	// Constructors
	Contact(
		std::string const &firstName = std::string(""),
		std::string const &lastName = std::string(""),
		std::string const &nickname = std::string(""),
		std::string const &phoneNumber = std::string(""),
		std::string const &darkestSecret = std::string(""));
	Contact(Contact const &src);

	// Destructors
	~Contact(void);

	// Accessors
	std::string const	&getFirstName(void) const;
	std::string const	&getLastName(void) const;
	std::string const	&getNickname(void) const;
	std::string const	&getPhoneNumber(void) const;
	std::string const	&getDarkestSecret(void) const;

	void				setFirstName(std::string const &firstName);
	void				setLastName(std::string const &lastName);
	void				setNickname(std::string const &nickname);
	void				setPhoneNumber(std::string const &phoneNumber);
	void				setDarkestSecret(std::string const &darkestSecret);

	// Member functions
	void	printFirstName(void) const;
	void	printLastName(void) const;
	void	printNickname(void) const;
	void	printPhoneNumber(void) const;
	void	printDarkestSecret(void) const;
	void	print(void) const;

	bool	isFilled(void) const;
};

#endif

