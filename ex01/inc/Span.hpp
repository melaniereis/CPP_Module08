/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 16:24:54 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/28 16:15:24 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <algorithm>
#include <exception>
#include <stdexcept>
#include <iterator>
#include <iostream>
#include <iomanip>
#include "ansi.h"


class Span
{
	public:
		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void addNumber(int number);

		void addRangeNumbers(std::vector<int>::iterator begin,
								std::vector<int>::iterator end);

		size_t shortestSpan();
		size_t longestSpan();

		class FullException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NotEnoughNumbersException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		unsigned int getSize() const;
		std::vector<int> getNumbers() const;

	private:
		unsigned int _size;
		std::vector<int> _numbers;

		Span();
};

std::ostream &operator<<(std::ostream &os, const Span &span);
