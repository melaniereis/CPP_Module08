/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meferraz <meferraz@student.42porto.pt>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:33:55 by meferraz          #+#    #+#             */
/*   Updated: 2025/05/27 16:22:46 by meferraz         ###   ########.fr       */
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
// 📌 Auxiliar Functions
// ─────────────────────────────────────────────────────────────

// ─────────────────────────────────────────────────────────────
// 🚀 main()
// ─────────────────────────────────────────────────────────────
int main()
{
	std::cout << BGRN "\n\n📋===== EASYFIND SIMULATION =====📋\n\n" RESET;

	SEPARATOR("Testing with std::vector<int>");
	int arr[] = {1, 2, 3, 4, 5};
	std::vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));
	try
	{
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << GRN << "Found value: " << YELHB << *it  << GRN << " in vector.\n" RESET;
	} catch (const EasyFindException &e)
	{
		std::cerr << e.what() << "\n";
	}

	SEPARATOR("Testing with std::list<int>");
	std::list<int> lst(arr, arr + sizeof(arr) / sizeof(arr[0]));
	try
	{
		std::list<int>::iterator it2 = easyfind(lst, 3);
		std::cout << GRN << "Found value: " << YELHB << *it2  << GRN << " in list.\n" RESET;
	} catch (const EasyFindException &e)
	{
		std::cerr << e.what() << "\n";
	}

	SEPARATOR("Testing with std::deque<int>");
	std::deque<int> dq(arr, arr + sizeof(arr) / sizeof(arr[0]));
	try
	{
		std::deque<int>::iterator it4 = easyfind(dq, 3);
		std::cout << GRN << "Found value: " << YELHB << *it4  << GRN << " in deque.\n" RESET;
	} catch (const EasyFindException &e)
	{
		std::cerr << RED << e.what() << "\n" << RESET;
	}

	SEPARATOR("Testing with std::vector<int> (not found)");
	std::vector<int> vec2(arr, arr + sizeof(arr) / sizeof(arr[0]));
	try
	{
		std::vector<int>::iterator it3 = easyfind(vec2, 6);
		std::cout << GRN << "Found value: " << YELHB << *it3  << GRN << " in vector.\n" RESET;
	} catch (const EasyFindException &e)
	{
		std::cerr << RED << e.what() << "\n" << RESET;
	}

	std::cout << BGRN "\n\n✅ All tests complete!\n\n" RESET;
	return 0;
}

// ─────────────────────────────────────────────────────────────
// 🔧 Auxilary functions implementations
// ─────────────────────────────────────────────────────────────
