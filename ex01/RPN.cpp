/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenrach <abenrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 17:35:58 by abenrach          #+#    #+#             */
/*   Updated: 2026/11/13 17:35:58 by abenrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void    do_add(std::stack<long> &pile)
{
    if (pile.size() <= 1)
        throw std::invalid_argument("Error: We can't perform addition");
    long tmp = pile.top();
    pile.pop();
    tmp += pile.top();
    pile.pop();
    pile.push(tmp);
    return ;
}

void    do_sub(std::stack<long> &pile)
{
    if (pile.size() <= 1)
        throw std::invalid_argument("Error: We can't perform subtraction");
    long tmp1 = pile.top();
    pile.pop();
    long tmp2 = pile.top();
    pile.pop();
    pile.push((tmp2 - tmp1));
    return ;
}

void    do_mult(std::stack<long> &pile)
{
    if (pile.size() <= 1)
        throw std::invalid_argument("Error: We can't perform multiplication");
    long tmp = pile.top();
    pile.pop();
    tmp *= pile.top();
    pile.pop();
    pile.push(tmp);
    return ;
}

void    do_div(std::stack<long> &pile)
{
    if (pile.size() <= 1)
        throw std::invalid_argument("Error: We can't perform division");
    long tmp1 = pile.top();
    pile.pop();
    long tmp2 = pile.top();
    pile.pop();
    pile.push((tmp2 / tmp1));
    return ;
}

void    do_operation(std::stack<long> &pile, char c)
{
    if (c == '+')
        do_add(pile);
    else if (c == '-')
        do_sub(pile);
    else if (c == '*')
        do_mult(pile);
    else if (c == '/')
        do_div(pile);
    else if (std::isdigit(c))
        pile.push(static_cast<long>(c - '0'));
    else
        throw std::invalid_argument("Error: Not valid element in operation (valid element = ' ', 1-9, +, -, /, *)");
}