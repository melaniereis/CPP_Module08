/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:33:55 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/30 17:36:59 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/MutantStack.hpp"
#include "../inc/ansi.h"
#include <iostream>

#define SEPARATOR(txt) std::cout << "\n"                                              \
								<< BWHT "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"     \
								<< "📄 " << BBLU << txt << BWHT "\n"                 \
								<< "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" RESET "\n" \
								<< std::endl;

// Forward declarations of test functions
void SubjectTest();
void ConstIteratorTest();
void ReverseIteratorTest();
void CopyAndAssignTest();
void DifferentTypeTest();

// ─────────────────────────────────────────────────────────────
// 🚀 main()
// ─────────────────────────────────────────────────────────────
int main()
{
	std::cout << BGRN "\n\n📋===== MUTANTSTACK SIMULATION =====📋\n\n" RESET;

	SubjectTest();
	ConstIteratorTest();
	ReverseIteratorTest();
	CopyAndAssignTest();
	DifferentTypeTest();

	std::cout << BGRN "\n\n✅ All tests complete!\n\n" RESET;
	return 0;
}

// Test function definitions
void SubjectTest()
{
	SEPARATOR("Subject Test");

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
}


void ConstIteratorTest()
{
	SEPARATOR("Const Iterator Test");

	MutantStack<int> mstack;
	for (int i = 1; i <= 5; ++i)
		mstack.push(i * 10);

	const MutantStack<int> &constStack = mstack;

	MutantStack<int>::const_iterator cit = constStack.begin();
	MutantStack<int>::const_iterator cite = constStack.end();

	std::cout << "Elements via const_iterator:" << std::endl;
	for (; cit != cite; ++cit)
		std::cout << BGRN << *cit << RESET << " ";
	std::cout << std::endl;
}

void ReverseIteratorTest()
{
	SEPARATOR("Reverse Iterator Test");

	MutantStack<int> mstack;
	for (int i = 1; i <= 5; ++i)
		mstack.push(i);

	MutantStack<int>::reverse_iterator rit = mstack.rbegin();
	MutantStack<int>::reverse_iterator rite = mstack.rend();

	std::cout << "Elements in reverse:" << std::endl;
	for (; rit != rite; ++rit)
		std::cout << BYEL << *rit << RESET << " ";
	std::cout << std::endl;

	const MutantStack<int> &constStack = mstack;
	MutantStack<int>::const_reverse_iterator crit = constStack.rbegin();
	MutantStack<int>::const_reverse_iterator crite = constStack.rend();

	std::cout << "Const reverse iteration:" << std::endl;
	for (; crit != crite; ++crit)
		std::cout << BMAG << *crit << RESET << " ";
	std::cout << std::endl;
}

void CopyAndAssignTest()
{
	SEPARATOR("Copy Constructor and Assignment Operator Test");

	MutantStack<int> original;
	for (int i = 0; i < 3; ++i)
		original.push(i * 100);

	// Copy constructor
	MutantStack<int> copyConstructed(original);

	std::cout << BBLU "Copy constructed stack elements:" RESET << std::endl;
	MutantStack<int>::iterator it = copyConstructed.begin();
	MutantStack<int>::iterator ite = copyConstructed.end();
	for (; it != ite; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;

	// Assignment operator
	MutantStack<int> assigned;
	assigned = original;

	std::cout << BBLU "Assigned stack elements:" RESET << std::endl;
	it = assigned.begin();
	ite = assigned.end();
	for (; it != ite; ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void DifferentTypeTest()
{
	SEPARATOR("Test with std::string Type");

	MutantStack<std::string> mstack;

	mstack.push("Hello");
	mstack.push("Mutant");
	mstack.push("Stack");
	mstack.push("42");

	std::cout << "Stack contents:" << std::endl;
	MutantStack<std::string>::iterator it = mstack.begin();
	MutantStack<std::string>::iterator ite = mstack.end();
	for (; it != ite; ++it)
		std::cout << BCYN << *it << RESET << std::endl;
}
