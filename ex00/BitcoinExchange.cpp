/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenrach <abenrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:51:33 by abenrach          #+#    #+#             */
/*   Updated: 2026/11/09 19:47:28 by abenrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

std::map<std::string, float>    fill_csv(void)
{
    std::map<std::string, float>    data;
    std::ifstream   file("data.csv");
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            std::cout << line << "\n";
        }
        file.close();
    }
    else
        throw std::runtime_error("Error: ifstream fail to open input file");
    return (data);
}

// Database::Database(char *input_file)
// {
//     this->_dataCsv = fill_csv();
//     this->_dataInput = fill_input(input_file);
// }

// Database::~Database(void){}

