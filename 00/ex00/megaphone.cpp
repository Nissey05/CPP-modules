/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhendrik <nhendrik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:41:18 by nhendrik          #+#    #+#             */
/*   Updated: 2025/11/19 17:47:57 by nhendrik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; argv[i]; i++)
	{
		std::string str = argv[i];
		std::string::iterator it;
		for (it = str.begin(); it < str.end(); it++)
			std::cout << (char)std::toupper((unsigned char)*it);
	}
	std::cout << std::endl;
}