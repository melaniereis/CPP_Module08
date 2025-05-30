/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:12:24 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/30 21:52:00 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <iterator>

class EasyFindException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return "EasyFindException: Value not found in the container";
		}
};

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = find(container.begin(), container.end(), value);
	if (it == container.end())
		throw EasyFindException();
	return it;
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int value)
{
	typename T::const_iterator it = find(container.begin(), container.end(), value);
	if (it == container.end())
		throw EasyFindException();
	return it;
}
