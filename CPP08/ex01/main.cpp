#include "Span.hpp"
#include <iostream>
#include <vector>

int main() {
	// Test the basic functionality
	Span sp = Span(5);

	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		
		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test with range insertion
	std::vector<int> nums;
	nums.push_back(2);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(7);
	nums.push_back(10);

	Span sp2(10);
	
	try {
		sp2.addNumber(nums.begin(), nums.end());
		std::cout << "Shortest Span after range insert: " << sp2.shortestSpan() << std::endl;
		std::cout << "Longest Span after range insert: " << sp2.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	return 0;
}
