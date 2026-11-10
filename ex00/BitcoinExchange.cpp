/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenrach <abenrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:51:33 by abenrach          #+#    #+#             */
/*   Updated: 2026/11/10 23:47:33 by abenrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

Database::Database(void) {}

std::string Database::take_str_data(std::string line)
{
    unsigned int    i = 0;
    while (i < line.length())
    {
        if (line[i] == ',')
            break;
        i++;
    }
    std::string date = line.substr(0, i);
    return (date);
}

double  Database::take_dbl_data(std::string line)
{
    unsigned int    i = 0;
    while (i < line.length())
    {
        if (line[i] == ',')
            break;
        i++;
    }
    std::string nb = line.substr(i + 1, line.length());
    return (std::atof(nb.c_str()));
}

void    Database::fill_csv(void)
{
    std::ifstream   file("data.csv");
    if (file.is_open())
    {
        std::string line;
        getline(file, line); // on souhaite sauter la premiere ligne qui contient pas quelque chose d'utile
        while (getline(file, line))
            this->_data[this->take_str_data(line)] = this->take_dbl_data(line);
        file.close();
    }
    else
        throw std::runtime_error("Error: ifstream fail to open data.csv");
    return ;
}

std::map<std::string, double>   &Database::getData(void)
{
    return (this->_data);
}

Database::Database(const Database &src): _data(src._data){}

Database    &Database::operator=(const Database &src)
{
    if (this != &src)
    {
        this->_data = src._data;
    }
    return (*this);
}

Database::~Database(void){}

std::string take_str_input(std::string line)
{
    size_t  pos = line.find('|');
    std::string date = line.substr(0, pos);
    // find if space at the last
    pos = date.find_last_not_of(" \n\t");
    if (pos != std::string::npos)
        date = date.substr(0, pos + 1);
    else
        return ("none");
    // find if space at the end
    pos = date.find_first_not_of(" \n\t");
    if (pos != std::string::npos)
        date = date.substr(pos);
    // parsing
    if (date.length() != 10)
        return ("none");
    return (date);
}

double  take_dbl_input(std::string line)
{
    size_t  pos = line.find('|');
    std::string nb = line.substr(pos + 1);
    // for space at the last
    pos = nb.find_last_not_of(" \n\t");
    if (pos == std::string::npos)
        return (-1);
    nb = nb.substr(0, pos + 1);
    // convert
    char    *ptr = NULL;
    double  value = std::strtod(nb.c_str(), &ptr);
    if (ptr == nb.c_str())  // si le strtod a fait aucune convertion et donc a renvoyer ptr tel que ptr = nb (sachant que ptr a la meme adresse memoire que nb.c_str)
        return (-1);
    for (size_t i = 0; ptr[i] != '\0'; i++)
    {
        if (std::isspace(ptr[i]))
            continue ;
        else
            return (-1);
    }
    return (value);
}

void    Database::find_line_in_csv(std::string line)
{
    size_t  pos = line.find('|');
    if (pos == std::string::npos)
        return ;
    std::string date = take_str_input(line);
    if (date == "none")
        throw std::invalid_argument("Error: Bad date input");
    double  nb = take_dbl_input(line);
    if (nb < 0)
        throw std::invalid_argument("Error: Not valid number");
    std::map<std::string, double>::iterator it = this->_data.find(date);
    if (it == this->_data.end())
    {
        std::cout << "Pas trouver" << std::endl;
    }
    else
    {
        std::cout << it->first << " => " << nb << " = " << (it->second * nb) << std::endl;
    }
}
