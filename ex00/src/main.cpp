/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:33:55 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/30 21:50:07 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/easyfind.hpp"
#include "../inc/ansi.h"
#include <vector>
#include <list>
#include <deque>

#define SEPARATOR(txt) std::cout << "\n"                                              \
								<< BWHT "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"     \
								<< "📄 " << BBLU << txt << BWHT "\n"                 \
								<< "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" RESET "\n" \
								<< std::endl;

// ─────────────────────────────────────────────────────────────
// 📌 Function Declarations
// ─────────────────────────────────────────────────────────────
void testVector();
void testList();
void testDeque();
void testVectorNotFound();
void testEmptyContainer();
void testDuplicateValues();
void testNegativeValues();

// ─────────────────────────────────────────────────────────────
// 🚀 main()
// ─────────────────────────────────────────────────────────────
int main()
{
	std::cout << BGRN "\n\n📋===== EASYFIND SIMULATION =====📋\n\n" RESET;

	testVector();
	testList();
	testDeque();
	testVectorNotFound();
	testEmptyContainer();
	testDuplicateValues();
	testNegativeValues();

	std::cout << BGRN "\n\n✅ All tests complete!\n\n" RESET;
	return 0;
}

// ─────────────────────────────────────────────────────────────
// 🔧 Template function implementations (C++98 compliant)
// ─────────────────────────────────────────────────────────────
template <typename Container>
void testEasyFind(const Container& container, int value, const std::string& containerType)
{
	try
	{
		typename Container::const_iterator it = easyfind(container, value);
		std::cout << GRN << "Found value: " << YELHB << *it << GRN << " in " << containerType << "." << RESET << std::endl;
	}
	catch (const EasyFindException& e)
	{
		std::cerr << RED << e.what() << RESET << std::endl;
	}
}

// ─────────────────────────────────────────────────────────────
// 🧪 Test Cases (C++98 syntax)
// ─────────────────────────────────────────────────────────────

void testVector()
{
	SEPARATOR("Testing with std::vector<int>");
	int arr[] = {1, 2, 3, 4, 5};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
	testEasyFind(vec, 3, "vector");
}

void testList()
{
	SEPARATOR("Testing with std::list<int>");
	int arr[] = {1, 2, 3, 4, 5};
	std::list<int> lst(arr, arr + sizeof(arr) / sizeof(int));
	testEasyFind(lst, 3, "list");
}

void testDeque()
{
	SEPARATOR("Testing with std::deque<int>");
	int arr[] = {1, 2, 3, 4, 5};
	std::deque<int> dq(arr, arr + sizeof(arr) / sizeof(int));
	testEasyFind(dq, 3, "deque");
}

void testVectorNotFound()
{
	SEPARATOR("Testing with std::vector<int> (not found)");
	int arr[] = {1, 2, 3, 4, 5};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
	testEasyFind(vec, 6, "vector");
}

void testEmptyContainer()
{
	SEPARATOR("Testing with empty std::vector<int>");
	std::vector<int> vec;
	testEasyFind(vec, 1, "empty vector");
}

void testDuplicateValues()
{
	SEPARATOR("Testing with std::list<int> (duplicates)");
	int arr[] = {1, 2, 3, 3, 4, 5};
	std::list<int> lst(arr, arr + sizeof(arr) / sizeof(int));
	testEasyFind(lst, 3, "list with duplicates");
}

void testNegativeValues()
{
	SEPARATOR("Testing with std::deque<int> (negative values)");
	int arr[] = {-5, -3, -1, 0, 2, 4};
	std::deque<int> dq(arr, arr + sizeof(arr) / sizeof(int));
	testEasyFind(dq, -3, "deque with negatives");
}
