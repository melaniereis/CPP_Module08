/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 21:12:24 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/30 21:58:06 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <algorithm>
#include <iostream>
#include <iterator>

class EasyFindException : public std::exception
{
	public:

		/**
		 * \brief Provides a description of the EasyFindException error.
		 *
		 * \return A C-style string describing that the value was not found
		 *         in the container.
		 */
		virtual const char *what() const throw()
		{
			return "EasyFindException: Value not found in the container";
		}
};

/**
 * \brief Finds the first occurrence of a given value in a container.
 *
 * \param container the container to search in
 * \param value the value to search for
 *
 * \return an iterator pointing to the found value
 *
 * \throws EasyFindException if the value is not found in the container
 */
template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator it = find(container.begin(), container.end(), value);
	if (it == container.end())
		throw EasyFindException();
	return it;
}

/**
 * \brief Finds the first occurrence of a given value in a container.
 *
 * \param container the container to search in
 * \param value the value to search for
 *
 * \return an iterator pointing to the found value
 *
 * \throws EasyFindException if the value is not found in the container
 */
template <typename T>
typename T::const_iterator easyfind(const T &container, int value)
{
	typename T::const_iterator it = find(container.begin(), container.end(), value);
	if (it == container.end())
		throw EasyFindException();
	return it;
}
