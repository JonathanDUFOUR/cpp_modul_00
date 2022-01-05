/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:48:52 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/05 00:15:52 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

static std::string	str_toupper(std::string str)
{
	std::string::iterator	iter;

	for (iter = str.begin() ; *iter ; ++iter)
		*iter = toupper(*iter);
	return (str);
}

int main(int const ac, char const **av)
{
	int	i;

	if (ac > 1)
		for (i = 1 ; av[i] ; ++i)
			std::cout << str_toupper(std::string(av[i]));
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return (0);
}
