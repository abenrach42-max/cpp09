/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenrach <abenrach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 17:37:11 by abenrach          #+#    #+#             */
/*   Updated: 2026/11/13 17:37:11 by abenrach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: Please follow this model: ./RNP <inverted_polish_mathematical>" << std::endl;
        return (1);
    }
    std::stack<long>    pile;
    size_t  i = 0;
    while (av[1][i] && av[1][i] == ' ')
        i++;
    if (av[1][i] == '\0')
    {
        std::cout << "Error: Argument string is empty" << std::endl;
        return (1);
    }
    try
    {
        while (av[1][i])
        {
            do_operation(pile, av[1][i]);
            i++;
            while (av[1][i] && av[1][i] == ' ')
                i++;
        }
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return (1);
    }
    if (pile.size() > 1)
    {
        std::cout << "Error: Invalid size stack" << std::endl;
        return (1);
    }
    std::cout << pile.top() << std::endl;
    return (0);
}