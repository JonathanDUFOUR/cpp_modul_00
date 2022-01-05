/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhoneBook.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:40:56 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/05 07:22:19 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSPHONEBOOK_HPP
# define CLASSPHONEBOOK_HPP

# include "class/ClassContact.hpp"

# ifndef WIDTH
#  define WIDTH	10
# endif

class PhoneBook
{
private:
	Contact contacts[8];

	// Methods
	int			stoi(std::string str);

	void		printBook(void);

	std::string	truncate(std::string str, std::size_t width);

public:
	// Constructors
	PhoneBook(void);

	// Destructors
	~PhoneBook(void);

	// Methods
	int			addContact(void);
	int			searchContact(void);
};

#endif
