/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 16:18:52 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/30 22:16:01 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"

/**
 * Default constructor for MutantStack.
 *
 * Initializes an empty MutantStack with an empty underlying container.
 *
 * @param T Type of the elements stored in the stack.
 * @param Container Container type used to store the elements.
 */
template <typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>()
{}

/**
 * Copy constructor for MutantStack.
 *
 * Creates a new MutantStack object with the same elements as the given other stack.
 *
 * @param other The other stack to copy.
 */
template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack &other) : std::stack<T, Container>(other)
{}

/**
 * Destructor for MutantStack.
 *
 * Destroys a MutantStack object, releasing all resources allocated by the stack.
 *
 * @param T Type of the elements stored in the stack.
 * @param Container Container type used to store the elements.
 */
template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{}

/**
 * Assignment operator for MutantStack.
 *
 * Assigns the contents of another MutantStack to this stack.
 *
 * @param other The other stack to assign from.
 * @return A reference to this MutantStack object.
 */
template <typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack &other)
{
	if (this != &other)
		std::stack<T, Container>::operator=(other);
	return *this;
}

/**
 * Returns an iterator pointing to the first element in the underlying container.
 *
 * @return An iterator pointing to the first element in the underlying container.
 */
template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::begin()
{
	return std::stack<T, Container>::c.begin();
}

/**
 * Returns an iterator pointing to the element after the last element in the underlying container.
 *
 * @return An iterator pointing to the element after the last element in the underlying container.
 */
template <typename T, typename Container>
typename MutantStack<T, Container>::iterator MutantStack<T, Container>::end()
{
	return std::stack<T, Container>::c.end();
}

/**
 * Returns a constant iterator pointing to the first element in the underlying container.
 *
 * @return A constant iterator pointing to the first element in the underlying container.
 */
template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::begin() const
{
	return std::stack<T, Container>::c.begin();
}

/**
 * Returns a constant iterator pointing to the element after the last element in the underlying container.
 *
 * @return A constant iterator pointing to the element after the last element in the underlying container.
 */
template <typename T, typename Container>
typename MutantStack<T, Container>::const_iterator MutantStack<T, Container>::end() const
{
	return std::stack<T, Container>::c.end();
}

/**
 * Returns a reverse iterator pointing to the last element in the underlying container.
 *
 * @return A reverse iterator pointing to the last element in the underlying container.
 */
template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rbegin()
{
	return std::stack<T, Container>::c.rbegin();
}

/**
 * Returns a reverse iterator pointing to the element before the first element in the underlying container.
 *
 * @return A reverse iterator pointing to the element before the first element in the underlying container.
 */
template <typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator MutantStack<T, Container>::rend()
{
	return std::stack<T, Container>::c.rend();
}

/**
 * Returns a constant reverse iterator pointing to the last element in the underlying container.
 *
 * @return A constant reverse iterator pointing to the last element in the underlying container.
 */
template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rbegin() const
{
	return std::stack<T, Container>::c.rbegin();
}

/**
 * Returns a constant reverse iterator pointing to the element before the first element in the underlying container.
 *
 * @return A constant reverse iterator pointing to the element before the first element in the underlying container.
 */
template <typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator MutantStack<T, Container>::rend() const
{
	return std::stack<T, Container>::c.rend();
}
