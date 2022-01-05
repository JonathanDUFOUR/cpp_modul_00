/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 19:32:09 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/05 07:10:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "colors.hpp"
#include "class/ClassPhoneBook.hpp"

int	main(void)
{
	std::string	cmd;
	PhoneBook	book;

	std::cout << "> ";
	while (std::getline(std::cin, cmd))
	{
		if (cmd == "EXIT")
			break ;
		else if (cmd == "ADD" && book.addContact())
			break ;
		else if (cmd == "SEARCH" && book.searchContact())
			break ;
		std::cout << "> ";
	}
	return EXIT_SUCCESS;
}
