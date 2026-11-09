/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenrach <abenrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 15:53:34 by abenrach          #+#    #+#             */
/*   Updated: 2026/11/09 19:43:53 by abenrach         ###   ########.fr       */
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

// class   Database
// {
//     private:
//         std::map<std::string, float>    _dataInput;
//         std::map<std::string, float>    _dataCsv;
//     public:
//         Database(void);
//         Database(const Database &src);
//         Database    &operator=(const Database &src);
//         ~Database(void);
// };

std::map<std::string, float>    fill_csv(void);

#endif