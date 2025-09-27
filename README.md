# CPP Module 08 - Templated Containers, Iterators and Algorithms

[![42 School Badge](https://img.shields.io/badge/42-School-000000?style=flat-square&logo=42&logoColor=white)](https://42.fr)
[![C++ Badge](https://img.shields.io/badge/C++-11-00599C?style=flat-square&logo=c%2B%2B&logoColor=white)](https://isocpp.org)
[![STL Badge](https://img.shields.io/badge/STL-Standard%20Template%20Library-blue?style=flat-square)](https://en.cppreference.com/w/cpp/header)

## 📚 Module Overview

Module 08 dives deep into the **Standard Template Library (STL)**, focusing on templated containers, iterators, and algorithms. This module teaches how to leverage C++'s powerful template system to create flexible, reusable code while mastering the STL's core components.

### 🎯 Learning Objectives

- Master **STL containers** (vector, list, deque, stack)
- Understand **iterators** and their categories
- Implement **template functions** with STL algorithms
- Create **custom containers** with iterator support
- Learn **algorithm complexity** and performance considerations
- Practice **exception handling** in template contexts

---

## 📋 Exercise Overview

| Exercise | Name | Key Concepts | Difficulty |
|----------|------|--------------|------------|
| **ex00** | [easyfind](#-ex00---easyfind) | Template Functions, STL Algorithms | ⭐⭐ |
| **ex01** | [Span](#-ex01---span) | Custom Containers, Iterator Ranges | ⭐⭐⭐ |
| **ex02** | [MutantStack](#-ex02---mutantstack) | Container Adapters, Iterator Implementation | ⭐⭐⭐⭐ |

---

## 🔍 Ex00 - easyfind

### 📖 Description

Implement a template function `easyfind` that searches for the first occurrence of an integer in any STL container using iterators.

### 🎯 Key Concepts
- **Template Functions**: Generic programming with type parameters
- **STL Algorithms**: Using `std::find()` for container-agnostic searches
- **Iterator Concepts**: Understanding forward iterators and container compatibility
- **Exception Handling**: Managing search failures with exceptions

### 🚀 Implementation

```cpp
#include <algorithm>
#include <iterator>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end())
        throw std::runtime_error("Value not found in container");
    return it;
}
```

### 💡 Usage Examples

```cpp
#include <vector>
#include <list>
#include <deque>

int main()
{
    // Vector example
    std::vector<int> vec;
    vec.push_back(42);
    vec.push_back(21);
    vec.push_back(84);

    try {
        std::vector<int>::iterator it = easyfind(vec, 42);
        std::cout << "Found " << *it << " at position "
                  << std::distance(vec.begin(), it) << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // List example
    std::list<int> lst(vec.begin(), vec.end());
    try {
        easyfind(lst, 999); // Will throw exception
    }
    catch (const std::exception& e) {
        std::cout << "Expected: " << e.what() << std::endl;
    }

    return 0;
}
```

### 🔧 Technical Notes
- Works with any container supporting **forward iterators**
- Compatible with `vector`, `list`, `deque`, `set`, etc.
- Uses **SFINAE** principles for template specialization
- **O(n)** time complexity for linear search

---

## 📊 Ex01 - Span

### 📖 Description

Create a `Span` class that stores integers and can find the shortest and longest "span" (distance) between stored numbers using STL algorithms.

### 🎯 Key Concepts
- **Custom Container Design**: Implementing container-like behavior
- **STL Algorithm Integration**: Using `std::min_element` and `std::max_element`
- **Iterator Ranges**: Supporting range-based insertion
- **Exception Safety**: Proper error handling for edge cases

### 🏗️ Class Structure

```cpp
class Span
{
private:
    std::vector<int>    _numbers;
    unsigned int        _maxSize;

public:
    Span(unsigned int N);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    void addRange(std::vector<int>::iterator begin,
                  std::vector<int>::iterator end);

    int shortestSpan() const;
    int longestSpan() const;

    // Exception classes
    class SpanFullException : public std::exception;
    class NoSpanException : public std::exception;
};
```

### 🚀 Key Methods Implementation

```cpp
int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw NoSpanException();

    std::vector<int> sorted(_numbers);
    std::sort(sorted.begin(), sorted.end());

    int minSpan = INT_MAX;
    for (size_t i = 1; i < sorted.size(); ++i)
    {
        int span = sorted[i] - sorted[i - 1];
        if (span < minSpan)
            minSpan = span;
    }
    return minSpan;
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw NoSpanException();

    std::vector<int>::const_iterator min =
        std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator max =
        std::max_element(_numbers.begin(), _numbers.end());

    return *max - *min;
}
```

### 💡 Advanced Usage

```cpp
int main()
{
    Span sp(10000);

    // Range insertion with random numbers
    std::vector<int> randomNumbers(10000);
    std::srand(time(NULL));
    std::generate(randomNumbers.begin(), randomNumbers.end(),
                  []() { return rand() % 100000; });

    sp.addRange(randomNumbers.begin(), randomNumbers.end());

    std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "Longest span: " << sp.longestSpan() << std::endl;

    return 0;
}
```

### 📈 Performance Analysis
- **addNumber()**: O(1) amortized
- **addRange()**: O(n) where n is range size
- **shortestSpan()**: O(n log n) due to sorting
- **longestSpan()**: O(n) linear scan

---

## 🧬 Ex02 - MutantStack

### 📖 Description

Create a `MutantStack` class that extends `std::stack` functionality by adding **iterator support**, making it compatible with STL algorithms.

### 🎯 Key Concepts
- **Container Adapters**: Understanding stack's underlying container
- **Iterator Implementation**: Adding iteration to non-iterable containers
- **Template Inheritance**: Inheriting from templated standard containers
- **STL Compatibility**: Making custom containers work with algorithms

### 🏗️ Class Design

```cpp
#include <stack>
#include <deque>

template <typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container>
{
public:
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

    // Constructors
    MutantStack() : std::stack<T, Container>() {}
    MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}
    MutantStack& operator=(const MutantStack& other);
    ~MutantStack() {}

    // Iterator access
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }

    reverse_iterator rbegin() { return this->c.rbegin(); }
    reverse_iterator rend() { return this->c.rend(); }
    const_reverse_iterator rbegin() const { return this->c.rbegin(); }
    const_reverse_iterator rend() const { return this->c.rend(); }
};
```

### 🚀 Advanced Features

```cpp
int main()
{
    MutantStack<int> mstack;

    // Standard stack operations
    mstack.push(5);
    mstack.push(17);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    // Iterator functionality (not available in std::stack)
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    std::cout << "Stack contents: ";
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    // Use with STL algorithms
    std::cout << "Sum: " << std::accumulate(mstack.begin(), mstack.end(), 0) << std::endl;
    std::cout << "Max: " << *std::max_element(mstack.begin(), mstack.end()) << std::endl;

    // Range-based for loop support
    std::cout << "Range-based loop: ";
    for (const auto& value : mstack)
        std::cout << value << " ";
    std::cout << std::endl;

    return 0;
}
```

### 🔄 Comparison with Standard Containers

```cpp
void compareWithDeque()
{
    std::deque<int> deq;
    MutantStack<int> mstack;

    // Same operations, different syntax
    deq.push_back(21);
    mstack.push(21);

    deq.push_back(42);
    mstack.push(42);

    // Both support iteration
    std::for_each(deq.begin(), deq.end(),
                  [](int n) { std::cout << n << " "; });
    std::cout << std::endl;

    std::for_each(mstack.begin(), mstack.end(),
                  [](int n) { std::cout << n << " "; });
    std::cout << std::endl;
}
```

---

## 🧪 Testing Strategies

### Unit Testing Approach

```cpp
void testEasyFind()
{
    std::vector<int> vec = {1, 2, 3, 4, 5};

    assert(easyfind(vec, 3) != vec.end());
    try {
        easyfind(vec, 99);
        assert(false); // Should not reach here
    } catch (const std::exception&) {
        // Expected behavior
    }
}

void testSpan()
{
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    assert(sp.shortestSpan() == 2);  // 9-11 or 6-9
    assert(sp.longestSpan() == 14);  // 17-3
}
```

---

## 🎓 Key Learning Outcomes

### Template Mastery
- **Generic Programming**: Writing code that works with multiple types
- **Template Specialization**: Customizing behavior for specific types
- **SFINAE**: Substitution Failure Is Not An Error principles

### STL Proficiency
- **Container Categories**: Sequential, associative, and adapter containers
- **Iterator Categories**: Input, output, forward, bidirectional, random access
- **Algorithm Library**: Search, sort, transform, and numeric algorithms

### Advanced C++ Concepts
- **Container Design**: Creating STL-compatible custom containers
- **Iterator Implementation**: Adding iteration support to existing classes
- **Exception Safety**: Proper error handling in generic code

---

## 🏆 Skills Developed

- ✅ **STL Algorithm Integration**
- ✅ **Template Function Design**
- ✅ **Custom Container Creation**
- ✅ **Iterator Implementation**
- ✅ **Exception Handling in Templates**
- ✅ **Performance Analysis**
- ✅ **Generic Programming Patterns**

---

## 📚 Additional Resources

- [C++ Reference - STL Containers](https://en.cppreference.com/w/cpp/container)
- [C++ Reference - STL Algorithms](https://en.cppreference.com/w/cpp/algorithm)
- [Iterator Categories](https://en.cppreference.com/w/cpp/iterator)
- [Template Specialization](https://en.cppreference.com/w/cpp/language/template_specialization)

---

*Module 08 successfully bridges the gap between basic C++ knowledge and professional-level template programming, providing the foundation for advanced STL usage and generic programming techniques.*
