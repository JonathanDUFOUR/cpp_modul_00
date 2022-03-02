/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 18:48:52 by jodufour          #+#    #+#             */
/*   Updated: 2022/03/01 18:32:30 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>

typedef unsigned int	uint;

int main(int const ac, char const **av)
{
	uint	idx0;
	uint	idx1;

	if (ac > 1)
		for (idx0 = 1 ; av[idx0] ; ++idx0)
			for (idx1 = 0 ; av[idx0][idx1] ; ++idx1)
				std::cout << static_cast<char>(std::toupper(av[idx0][idx1]));
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << std::endl;
	return EXIT_SUCCESS;
}
