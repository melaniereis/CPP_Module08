/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:07:25 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/28 16:19:17 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

Span::Span(unsigned int N) : _size(N)
{}

Span::Span(const Span &other)
{
	*this = other;
}

Span &Span::operator=(const Span &other)
{
	if (this != &other) {
		_size = other._size;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span()
{}

void Span::addNumber(int number)
{
	if (_numbers.size() == _size) {
		throw FullException();
	}
	_numbers.push_back(number);
}

void Span::addRangeNumbers(std::vector<int>::iterator begin,
							std::vector<int>::iterator end)
{
	unsigned int distance = 0;
	for (std::vector<int>::iterator it = begin; it != end; ++it)
		distance++;
	if (_numbers.size() + distance > _size)
		throw FullException();
	_numbers.insert(_numbers.end(), begin, end);
}

size_t Span::shortestSpan()
{
	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();

	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	size_t minSpan = std::numeric_limits<size_t>::max();
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		size_t span = std::abs(sorted[i] - sorted[i - 1]);
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

size_t Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();

	std::pair
	<std::vector<int>::iterator,
	std::vector<int>::iterator>
	minmax
	= std::minmax_element(_numbers.begin(), _numbers.end());
	return *minmax.second - *minmax.first;
}

unsigned int Span::getSize() const
{
	return _size;
}

std::vector<int> Span::getNumbers() const
{
	return _numbers;
}

const char* Span::FullException::what() const throw()
{
	return "Span is full, cannot add more numbers.";
}

const char* Span::NotEnoughNumbersException::what() const throw()
{
	return "Not enough numbers to calculate span.";
}

std::ostream &operator<<(std::ostream &os, const Span &span)
{
	std::vector<int> numbers = span.getNumbers();
	os << MAG "📊 "
		<< std::left << std::setw(10) << "Span"
		<< " | Size: " << std::setw(3) << YEL << numbers.size()
		<< MAG " | Max Size: " << std::setw(3) << YEL << span.getSize()
		<< MAG << " | Numbers: ";
	for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it)
		os << std::setw(3) << YEL << *it << " ";
	os << RESET << std::endl;
	return os;
}
