/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenrach <abenrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 17:36:01 by abenrach          #+#    #+#             */
/*   Updated: 2026/11/13 17:36:01 by abenrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <exception>
# include <iomanip>
# include <stack>

void    do_operation(std::stack<long> &pile, char c);
void    do_add(std::stack<long> &pile);
void    do_sub(std::stack<long> &pile);
void    do_mult(std::stack<long> &pile);
void    do_div(std::stack<long> &pile);

#endif