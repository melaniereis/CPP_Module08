/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:33:55 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/29 15:35:17 by meferraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"
#include "../inc/ansi.h"
#include <iostream>

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

void SubjectTest()
{
	SEPARATOR("Subject Test");
	try {
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp;

		std::cout << GRN "Shortest Span: " << RESET << sp.shortestSpan() << "\n";
		std::cout << GRN "Longest Span:  " << RESET << sp.longestSpan() << "\n";
	} catch (std::exception& e) {
		std::cerr << RED "Unexpected Error: " << e.what() << RESET << std::endl;
	}
}

// Test function definitions
void BasicSpanTest()
{
	SEPARATOR("Basic Span Test");
	try {
		Span sp(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp;
		std::cout << GRN "Shortest Span: " << RESET << sp.shortestSpan() << "\n";
		std::cout << GRN "Longest Span:  " << RESET << sp.longestSpan() << "\n";
	} catch (std::exception& e) {
		std::cerr << RED "Unexpected Error: " << e.what() << RESET << std::endl;
	}
}

void RangeInsertionTest()
{
	SEPARATOR("Range Insertion Test");
	try {
		Span sp2(10000);
		std::vector<int> range(10000);
		std::generate(range.begin(), range.end(), std::rand);
		sp2.addRangeNumbers(range.begin(), range.end());
		std::cout << "Added 10000 numbers via range insertion.\n";
		std::cout << GRN "Shortest Span: " << RESET << sp2.shortestSpan() << "\n";
		std::cout << GRN "Longest Span:  " << RESET << sp2.longestSpan() << "\n";
	} catch (std::exception& e) {
		std::cerr << RED "Unexpected Error: " << e.what() << RESET << std::endl;
	}
}

void OverflowTest()
{
	SEPARATOR("Overflow Test");
	try {
		Span sp3(3);
		sp3.addNumber(1);
		sp3.addNumber(2);
		sp3.addNumber(3);
		sp3.addNumber(4);  // Should throw FullException
		std::cerr << RED "Error: Expected FullException but no exception was thrown." << RESET << std::endl;
	} catch (Span::FullException& e) {
		std::cerr << RED "Expected Error: " << e.what() << RESET << std::endl;
	} catch (std::exception& e) {
		std::cerr << RED "Unexpected Error: " << e.what() << RESET << std::endl;
	}
}

void NotEnoughNumbersTest()
{
	SEPARATOR("Not Enough Numbers Test");
	try {
		Span sp4(2);
		sp4.addNumber(1);
		std::cout << sp4.shortestSpan();  // Should throw NotEnoughNumbersException
		std::cerr << RED "Error: Expected NotEnoughNumbersException but no exception was thrown." << RESET << std::endl;
	} catch (Span::NotEnoughNumbersException& e) {
		std::cerr << RED "Expected Error: " << e.what() << RESET << std::endl;
	} catch (std::exception& e) {
		std::cerr << RED "Unexpected Error: " << e.what() << RESET << std::endl;
	}
}

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
	} catch (std::exception& e) {
		std::cerr << RED "Unexpected Error: " << e.what() << RESET << std::endl;
	}
}

void AssignmentOperatorTest()
{
	SEPARATOR("Assignment Operator Test");
	try {
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
	} catch (std::exception& e) {
		std::cerr << RED "Unexpected Error: " << e.what() << RESET << std::endl;
	}
}

void OrderAndValueTests()
{
	SEPARATOR("Order and Value Tests");
	try {
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
	} catch (std::exception& e) {
		std::cerr << RED "Unexpected Error: " << e.what() << RESET << std::endl;
	}
}

void MinimumElementsTest()
{
	SEPARATOR("Minimum Elements Test");
	try {
		Span sp9(2);
		sp9.addNumber(10);
		sp9.addNumber(20);
		std::cout << "Minimum elements:\n" << sp9;
		std::cout << GRN "Shortest Span: " << RESET << sp9.shortestSpan() << "\n";
		std::cout << GRN "Longest Span: " << RESET << sp9.longestSpan() << "\n";
	} catch (std::exception& e) {
		std::cerr << RED "Unexpected Error: " << e.what() << RESET << std::endl;
	}
}

void RangeAdditionExceedTest()
{
	SEPARATOR("Range Addition Exceed Test");
	try {
		Span sp10(5);
		std::vector<int> range(6, 100);  // 6 elements, each 100
		sp10.addRangeNumbers(range.begin(), range.end());  // Should throw FullException
		std::cerr << RED "Error: Expected FullException but no exception was thrown." << RESET << std::endl;
	} catch (Span::FullException& e) {
		std::cerr << RED "Expected Error: " << e.what() << RESET << std::endl;
	} catch (std::exception& e) {
		std::cerr << RED "Unexpected Error: " << e.what() << RESET << std::endl;
	}
}
