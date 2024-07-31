/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snegi <snegi@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 12:49:54 by snegi             #+#    #+#             */
/*   Updated: 2024/06/12 12:49:57 by snegi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <cstring>

int main(int argc, char *argv[]) 
{
	if (argc > 1) 
	{
		for (int i = 1; i < argc; i++) 
		{
			for (int j = 0; j < strlen(argv[i]); j++)
				std::cout << static_cast<char>(std::toupper(argv[i][j]));
			std::cout << ' ';
		} 
		std::cout << std::endl;
	}
	else 
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	return 0;
}
