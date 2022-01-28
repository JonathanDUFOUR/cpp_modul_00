/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassPhoneBook.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:40:56 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/28 19:30:49 by jodufour         ###   ########.fr       */
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

	// Member functions
	int			stoi(std::string str);

	void		printBook(void);

	std::string	truncate(std::string str, std::size_t width);

public:
	// Constructors
	PhoneBook(void);

	// Destructors
	~PhoneBook(void);

	// Member functions
	int	addContact(void);
	int	searchContact(void);
};

#endif
