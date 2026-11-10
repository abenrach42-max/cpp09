/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenrach <abenrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 19:16:19 by abenrach          #+#    #+#             */
/*   Updated: 2026/11/10 23:46:28 by abenrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: You must put 1 argument after executable file" << std::endl;
        return (1);
    }
    Database    data;
    data.fill_csv();
    std::ifstream   file(av[1]);
    if (!file.is_open())
    {
        std::cout << "Error: File in argument cant be open" << std::endl;
        return (1);
    }
    std::string line;
    getline(file, line);
    while (getline(file, line))
    {
        try
        {
            data.find_line_in_csv(line);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
        }
    }
    file.close();
    return (0);
}