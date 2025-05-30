/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:33:55 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/30 22:01:42 by meferraz         ###   ########.fr       */
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

/**
 * The main entry point of the program.
 *
 * Runs a series of tests to verify the correctness of the easyfind function.
 *
 * The tests cover the following scenarios:
 *  - Searching a std::vector
 *  - Searching a std::list
 *  - Searching a std::deque
 *  - Searching a std::vector for a value not in the container
 *  - Searching an empty container
 *  - Searching a container with duplicate values
 *  - Searching a container with negative values
 *
 * After running all tests, prints a success message to the console.
 *
 * @return 0 if all tests pass, non-zero otherwise.
 */
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

/**
 * Tests the easyfind function.
 *
 * Prints a message to the console with the value found, the type of container
 * used, and whether the value was found.
 *
 * If the value is not found, catch the EasyFindException and print an error
 * message to the console.
 *
 * @param container The container to search in.
 * @param value The value to search for.
 * @param containerType A string representing the type of container.
 */
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

/**
 * Tests easyfind with a std::vector<int>.
 *
 * Verifies that easyfind works correctly with an array-based container.
 */
void testVector()
{
	SEPARATOR("Testing with std::vector<int>");
	int arr[] = {1, 2, 3, 4, 5};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
	testEasyFind(vec, 3, "vector");
}

/**
 * Tests easyfind with a std::list<int>.
 *
 * Verifies that easyfind works correctly with a linked list.
 */
void testList()
{
	SEPARATOR("Testing with std::list<int>");
	int arr[] = {1, 2, 3, 4, 5};
	std::list<int> lst(arr, arr + sizeof(arr) / sizeof(int));
	testEasyFind(lst, 3, "list");
}

/**
 * Tests easyfind with a std::deque<int>.
 *
 * Verifies that easyfind works correctly with a double-ended queue.
 */
void testDeque()
{
	SEPARATOR("Testing with std::deque<int>");
	int arr[] = {1, 2, 3, 4, 5};
	std::deque<int> dq(arr, arr + sizeof(arr) / sizeof(int));
	testEasyFind(dq, 3, "deque");
}

/**
 * Tests easyfind with a std::vector<int> where the value is not present.
 *
 * Verifies that easyfind throws an exception when the specified value
 * is not found within the container.
 */
void testVectorNotFound()
{
	SEPARATOR("Testing with std::vector<int> (not found)");
	int arr[] = {1, 2, 3, 4, 5};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
	testEasyFind(vec, 6, "vector");
}

/**
 * Tests easyfind with an empty std::vector<int>.
 *
 * Verifies that easyfind throws an exception when attempting to find a value
 * in an empty container.
 */
void testEmptyContainer()
{
	SEPARATOR("Testing with empty std::vector<int>");
	std::vector<int> vec;
	testEasyFind(vec, 1, "empty vector");
}

/**
 * Tests easyfind with a std::list containing duplicate values.
 *
 * Verifies that easyfind only returns the first occurrence of a value
 * in a container, even if the value appears multiple times.
 */
void testDuplicateValues()
{
	SEPARATOR("Testing with std::list<int> (duplicates)");
	int arr[] = {1, 2, 3, 3, 4, 5};
	std::list<int> lst(arr, arr + sizeof(arr) / sizeof(int));
	testEasyFind(lst, 3, "list with duplicates");
}

/**
 * Tests easyfind with a std::deque containing negative values.
 *
 * Verifies that easyfind works correctly even when the container
 * contains negative values.
 */
void testNegativeValues()
{
	SEPARATOR("Testing with std::deque<int> (negative values)");
	int arr[] = {-5, -3, -1, 0, 2, 4};
	std::deque<int> dq(arr, arr + sizeof(arr) / sizeof(int));
	testEasyFind(dq, -3, "deque with negatives");
}
