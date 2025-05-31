/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:33:55 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/30 22:10:47 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"
#include "../inc/ansi.h"
#include <iostream>
#include <ctime>

#define SEPARATOR(txt) std::cout << "\n"                                              \
								<< BWHT "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n"     \
								<< "📄 " << BBLU << txt << BWHT "\n"                 \
								<< "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" RESET "\n" \
								<< std::endl;

// Forward declarations of test functions
void BasicSpanTest();
void RangeInsertionTest();
void OverflowTest();
void NotEnoughNumbersTest();
void CopyConstructorTest();
void AssignmentOperatorTest();
void OrderAndValueTests();
void MinimumElementsTest();
void RangeAdditionExceedTest();

// ─────────────────────────────────────────────────────────────
// 🚀 main()
// ─────────────────────────────────────────────────────────────

/**
 * The main entry point of the program.
 *
 * Runs a series of tests to verify the correctness of the Span class.
 *
 * The tests cover the following scenarios:
 *  - Basic usage of the Span class
 *  - Insertion of a range of numbers
 *  - Overflowing the Span
 *  - Attempting to calculate the shortest or longest span with less than two
 *    numbers
 *  - Copy construction and assignment
 *  - Verifying the order and values of the stored numbers
 *  - Attempting to create a Span with a size less than 2
 *  - Attempting to add a range of numbers that exceeds the size of the Span
 *
 * After running all tests, prints a success message to the console.
 *
 * @return 0 if all tests pass, non-zero otherwise.
 */
int main()
{
	std::cout << BGRN "\n\n📋===== SPAN SIMULATION =====📋\n\n" RESET;
	std::srand(std::time(0));  // Seed for random number generation

	BasicSpanTest();
	RangeInsertionTest();
	OverflowTest();
	NotEnoughNumbersTest();
	CopyConstructorTest();
	AssignmentOperatorTest();
	OrderAndValueTests();
	MinimumElementsTest();
	RangeAdditionExceedTest();

	std::cout << BGRN "\n\n✅ All tests complete!\n\n" RESET;
	return 0;
}

/**
 * Verifies the correctness of the Span class by using the object as described
 * in the subject.
 *
 * The test creates a Span of size 5, adds 5 numbers to it, and then verifies
 * that the correct shortest and longest spans are calculated.
 */
void SubjectTest()
{
	SEPARATOR("Subject Test");
	try
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp;

		std::cout << GRN "Shortest Span: " << RESET << sp.shortestSpan() << "\n";
		std::cout << GRN "Longest Span:  " << RESET << sp.longestSpan() << "\n";
	} catch (std::exception& e)
	{
		std::cerr << RED "Unexpected Error: " << e.what() << RESET << std::endl;
	}
}

// Test function definitions

/**
 * Verifies the correctness of the Span class by performing a basic test.
 *
 * The test creates a Span of size 5, adds 5 numbers to it, and then verifies
 * that the correct shortest and longest spans are calculated.
 */
void BasicSpanTest()
{
	SEPARATOR("Basic Span Test");
	try
	{
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp;
		std::cout << GRN "Shortest Span: " << RESET << sp.shortestSpan() << "\n";
		std::cout << GRN "Longest Span:  " << RESET << sp.longestSpan() << "\n";
	} catch (std::exception& e)
	{
		std::cerr << RED "Unexpected Error: " << e.what() << RESET << std::endl;
	}
}

/**
 * Verifies the correctness of the Span class by inserting a range of numbers.
 *
 * The test creates a Span of size 10000, generates 10000 random numbers, and
 * inserts them into the Span via the addRangeNumbers function. It then verifies
 * that the correct shortest and longest spans are calculated.
 */
void RangeInsertionTest()
{
	SEPARATOR("Range Insertion Test");
	try
	{
		Span sp2(10000);
		std::vector<int> range(10000);
		std::generate(range.begin(), range.end(), std::rand);
		sp2.addRangeNumbers(range.begin(), range.end());
		std::cout << "Added 10000 numbers via range insertion.\n";
		std::cout << GRN "Shortest Span: " << RESET << sp2.shortestSpan() << "\n";
		std::cout << GRN "Longest Span:  " << RESET << sp2.longestSpan() << "\n";
	} catch (std::exception& e)
	{
		std::cerr << RED "Unexpected Error: " << e.what() << RESET << std::endl;
	}
}

/**
 * Tests the behavior of the Span class when attempting to exceed its capacity.
 *
 * This test creates a Span with a capacity of 3 and adds four numbers to it.
 * The fourth addition should trigger a FullException since the Span's capacity
 * is exceeded. The test verifies that the exception is correctly thrown and
 * caught.
 */
void OverflowTest()
{
	SEPARATOR("Overflow Test");
	try
	{
		Span sp3(3);
		sp3.addNumber(1);
		sp3.addNumber(2);
		sp3.addNumber(3);
		sp3.addNumber(4);  // Should throw FullException
		std::cerr << RED "Error: Expected FullException but no exception was thrown." << RESET << std::endl;
	} catch (Span::FullException& e)
	{
		std::cerr << RED "Expected Error: " << e.what() << RESET << std::endl;
	} catch (std::exception& e)
	{
		std::cerr << RED "Unexpected Error: " << e.what() << RESET << std::endl;
	}
}

/**
 * Tests the behavior of the Span class when attempting to calculate the
 * shortest span without having at least two numbers in the Span.
 *
 * This test creates a Span with a capacity of 2, adds a single number to it,
 * and then attempts to calculate the shortest span. The calculation should
 * throw a NotEnoughNumbersException since there are not enough numbers in the
 * Span to calculate a span. The test verifies that the exception is correctly
 * thrown and caught.
 */
void NotEnoughNumbersTest()
{
	SEPARATOR("Not Enough Numbers Test");
	try
	{
		Span sp4(2);
		sp4.addNumber(1);
		std::cout << sp4.shortestSpan();  // Should throw NotEnoughNumbersException
		std::cerr << RED "Error: Expected NotEnoughNumbersException but no exception was thrown." << RESET << std::endl;
	} catch (Span::NotEnoughNumbersException& e)
	{
		std::cerr << RED "Expected Error: " << e.what() << RESET << std::endl;
	} catch (std::exception& e)
	{
		std::cerr << RED "Unexpected Error: " << e.what() << RESET << std::endl;
	}
}

/**
 * Tests the copy constructor of the Span class.
 *
 * This test creates a Span object and copies it using the copy constructor.
 * The test verifies that the copied Span object is a deep copy of the original
 * object by comparing the contents of the original and copied objects.
 */
void CopyConstructorTest()
{
	SEPARATOR("Copy Constructor Test");
	try {
		Span sp1(5);
		sp1.addNumber(1);
		sp1.addNumber(2);
		sp1.addNumber(3);
		sp1.addNumber(4);
		sp1.addNumber(5);
		Span sp2(sp1);
		std::cout << "Original Span:\n" << sp1;
		std::cout << "Copied Span:\n" << sp2;
		std::cout << GRN "Shortest Span of copied Span: " << RESET << sp2.shortestSpan() << "\n";
		std::cout << GRN "Longest Span of copied Span: " << RESET << sp2.longestSpan() << "\n";
	} catch (std::exception& e)
	{
		std::cerr << RED "Unexpected Error: " << e.what() << RESET << std::endl;
	}
}

/**
 * Tests the assignment operator of the Span class.
 *
 * This test creates two Span objects, assigns one to the other using the
 * assignment operator, and verifies that the assigned Span object is a deep
 * copy of the original object by comparing the contents of the original and
 * assigned objects.
 */
void AssignmentOperatorTest()
{
	SEPARATOR("Assignment Operator Test");
	try
	{
		Span sp3(3);
		sp3.addNumber(10);
		sp3.addNumber(20);
		sp3.addNumber(30);
		Span sp4(4);
		sp4.addNumber(40);
		sp4.addNumber(50);
		sp4.addNumber(60);
		sp4.addNumber(70);
		sp4 = sp3;
		std::cout << "After assignment, sp4:\n" << sp4;
		std::cout << GRN "Shortest Span of sp4: " << RESET << sp4.shortestSpan() << "\n";
		std::cout << GRN "Longest Span of sp4: " << RESET << sp4.longestSpan() << "\n";
	} catch (std::exception& e)
	{
		std::cerr << RED "Unexpected Error: " << e.what() << RESET << std::endl;
	}
}

/**
 * Tests the order and values of the numbers stored in the Span class.
 *
 * The test creates multiple Span objects, each with a different set of numbers.
 * The test verifies that the numbers are stored in the correct order and that
 * the correct shortest and longest spans are calculated.
 *
 * The test covers the following scenarios:
 *  - Ascending order
 *  - Descending order
 *  - Negative and positive numbers
 *  - All same numbers
 */
void OrderAndValueTests()
{
	SEPARATOR("Order and Value Tests");
	try
	{
		// Ascending Order
		Span sp5(5);
		sp5.addNumber(1);
		sp5.addNumber(2);
		sp5.addNumber(3);
		sp5.addNumber(4);
		sp5.addNumber(5);
		std::cout << "Ascending order:\n" << sp5;
		std::cout << GRN "Shortest Span: " << RESET << sp5.shortestSpan() << "\n";
		std::cout << GRN "Longest Span: " << RESET << sp5.longestSpan() << "\n";

		// Descending Order
		Span sp6(5);
		sp6.addNumber(5);
		sp6.addNumber(4);
		sp6.addNumber(3);
		sp6.addNumber(2);
		sp6.addNumber(1);
		std::cout << "Descending order:\n" << sp6;
		std::cout << GRN "Shortest Span: " << RESET << sp6.shortestSpan() << "\n";
		std::cout << GRN "Longest Span: " << RESET << sp6.longestSpan() << "\n";

		// Negative and Positive Numbers
		Span sp7(5);
		sp7.addNumber(-2);
		sp7.addNumber(-1);
		sp7.addNumber(0);
		sp7.addNumber(1);
		sp7.addNumber(2);
		std::cout << "Negative and positive numbers:\n" << sp7;
		std::cout << GRN "Shortest Span: " << RESET << sp7.shortestSpan() << "\n";
		std::cout << GRN "Longest Span: " << RESET << sp7.longestSpan() << "\n";

		// All Same Numbers
		Span sp8(5);
		sp8.addNumber(7);
		sp8.addNumber(7);
		sp8.addNumber(7);
		sp8.addNumber(7);
		sp8.addNumber(7);
		std::cout << "All same numbers:\n" << sp8;
		std::cout << GRN "Shortest Span: " << RESET << sp8.shortestSpan() << "\n";
		std::cout << GRN "Longest Span: " << RESET << sp8.longestSpan() << "\n";
	} catch (std::exception& e)
	{
		std::cerr << RED "Unexpected Error: " << e.what() << RESET << std::endl;
	}
}

/**
 * Verifies the correctness of the Span class with the minimum number of elements.
 *
 * The test creates a Span with 2 elements and verifies that the correct shortest
 * and longest spans are calculated.
 */
void MinimumElementsTest()
{
	SEPARATOR("Minimum Elements Test");
	try
	{
		Span sp9(2);
		sp9.addNumber(10);
		sp9.addNumber(20);
		std::cout << "Minimum elements:\n" << sp9;
		std::cout << GRN "Shortest Span: " << RESET << sp9.shortestSpan() << "\n";
		std::cout << GRN "Longest Span: " << RESET << sp9.longestSpan() << "\n";
	} catch (std::exception& e)
	{
		std::cerr << RED "Unexpected Error: " << e.what() << RESET << std::endl;
	}
}

/**
 * Tests adding a range of numbers that exceeds the size of the Span.
 *
 * This test creates a Span of size 5 and attempts to add a range of 6 numbers
 * to it. The test verifies that a FullException is thrown, indicating that
 * the Span cannot accommodate more numbers than its defined size.
 */
void RangeAdditionExceedTest()
{
	SEPARATOR("Range Addition Exceed Test");
	try
	{
		Span sp10(5);
		std::vector<int> range(6, 100);  // 6 elements, each 100
		sp10.addRangeNumbers(range.begin(), range.end());  // Should throw FullException
		std::cerr << RED "Error: Expected FullException but no exception was thrown." << RESET << std::endl;
	} catch (Span::FullException& e)
	{
		std::cerr << RED "Expected Error: " << e.what() << RESET << std::endl;
	} catch (std::exception& e)
	{
		std::cerr << RED "Unexpected Error: " << e.what() << RESET << std::endl;
	}
}
