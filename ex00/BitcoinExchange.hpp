/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenrach <abenrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:53:34 by abenrach          #+#    #+#             */
/*   Updated: 2026/11/10 23:46:12 by abenrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <exception>
# include <fstream>
# include <algorithm>
# include <map>

class   Database
{
    private:
        std::map<std::string, double>   _data;
    public:
        Database(void);
        Database(const Database &src);
        Database    &operator=(const Database &src);
        ~Database(void);
        double                          take_dbl_data(std::string line);
        std::string                     take_str_data(std::string line);
        void                            fill_csv(void);
        void                            find_line_in_csv(std::string line);
        std::map<std::string, double>   &getData(void);
};


#endif