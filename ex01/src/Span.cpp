/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 17:07:25 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/30 22:06:04 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"

/**
 * Constructs a Span with a given size.
 *
 * @param N The size of the Span.
 */
Span::Span(unsigned int N) : _size(N)
{}

/**
 * Copy constructor for the Span class.
 *
 * @param other The Span object to copy from.
 */
Span::Span(const Span &other)
{
	*this = other;
}

/**
 * Assignment operator for the Span class.
 *
 * @param other The Span object to assign from.
 * @return A reference to this Span object.
 */
Span &Span::operator=(const Span &other)
{
	if (this != &other) {
		_size = other._size;
		_numbers = other._numbers;
	}
	return *this;
}

/**
 * Destructor for the Span class.
 *
 * This destructor cleans up the Span object.
 */
Span::~Span()
{}

/**
 * Adds a single number to the Span.
 *
 * This function adds a single number to the Span.  If the Span is full (i.e., its size has been exceeded),
 * it throws a FullException.
 *
 * @param number The number to add to the Span.
 */
void Span::addNumber(int number)
{
	if (_numbers.size() == _size) {
		throw FullException();
	}
	_numbers.push_back(number);
}

/**
 * Adds a range of numbers to the Span.
 *
 * This function adds a range of numbers from a source container to the Span.
 * If the Span is full (i.e., its size has been exceeded), it throws a FullException.
 *
 * @param begin The beginning iterator of the range of numbers to add.
 * @param end The ending iterator of the range of numbers to add.
 */
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

/**
 * Calculates the shortest span of numbers in the Span.
 *
 * The shortest span of numbers in the Span is the smallest difference between two numbers in the Span.
 * If the Span has less than two numbers, this function throws a NotEnoughNumbersException.
 *
 * @return The shortest span of numbers in the Span.
 */
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

/**
 * Calculates the longest span of numbers in the Span.
 *
 * The longest span of numbers in the Span is the largest difference between two numbers in the Span.
 * If the Span has less than two numbers, this function throws a NotEnoughNumbersException.
 *
 * @return The longest span of numbers in the Span.
 */
size_t Span::longestSpan()
{
	if (_numbers.size() < 2)
		throw NotEnoughNumbersException();

	std::vector<int>::iterator minIt = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::iterator maxIt = std::max_element(_numbers.begin(), _numbers.end());
	return *maxIt - *minIt;
}

/**
 * Gets the size of the Span.
 *
 * The size of the Span is the maximum number of integers that can be stored in it.
 *
 * @return The size of the Span.
 */
unsigned int Span::getSize() const
{
	return _size;
}

/**
 * Retrieves the numbers currently stored in the Span.
 *
 * @return A vector containing all the numbers in the Span.
 */
std::vector<int> Span::getNumbers() const
{
	return _numbers;
}

/**
 * \brief Provides a description of the FullException error.
 *
 * \return A C-style string describing that the Span is full and cannot accept more numbers.
 */
const char* Span::FullException::what() const throw()
{
	return "Span is full, cannot add more numbers.";
}

/**
 * \brief Provides a description of the NotEnoughNumbersException error.
 *
 * \return A C-style string describing that there are not enough numbers
 *         in the Span to calculate a span.
 */
const char* Span::NotEnoughNumbersException::what() const throw()
{
	return "Not enough numbers to calculate span.";
}

/**
 * Overloads the output stream operator for the Span class.
 *
 * This function allows printing the Span object to an output stream in a formatted way.
 *
 * @param os The output stream to write to.
 * @param span The Span object to print.
 * @return The output stream after writing the Span object.
 */
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
