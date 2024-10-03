#include <iostream>
#include "Array.hpp"

#define SEPARATOR std::cout << "-----------------------------" << std::endl;

struct Point
{
	int x, y;
	Point() : x(0), y(0) {}
	Point(int xVal, int yVal) : x(xVal), y(yVal) {}
};

std::ostream& operator<<(std::ostream& os, const Point& p)
{
	os << "(" << p.x << ", " << p.y << ")";
	return os;
}

int main()
{
	// Test 1: Creating an empty array
	SEPARATOR
	std::cout << "Test 1: Creating an empty array" << std::endl;
	Array<int> emptyArray;
	std::cout << "Size of emptyArray: " << emptyArray.size() << std::endl;

	// Test 2: Creating an array of integers
	SEPARATOR
	std::cout << "Test 2: Creating an array of integers" << std::endl;
	Array<int> intArray(5);
	for (unsigned int i = 0; i < intArray.size(); ++i)
		intArray[i] = i * 2;
	for (unsigned int i = 0; i < intArray.size(); ++i)
		std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;

	// Test 3: Creating an array of strings
	SEPARATOR
	std::cout << "Test 3: Creating an array of strings" << std::endl;
	Array<std::string> stringArray(3);
	stringArray[0] = "Hello";
	stringArray[1] = "Array";
	stringArray[2] = "Test";
	for (unsigned int i = 0; i < stringArray.size(); ++i)
		std::cout << "stringArray[" << i << "] = " << stringArray[i] << std::endl;

	// Test 4: Testing copy constructor
	SEPARATOR
	std::cout << "Test 4: Testing copy constructor" << std::endl;
	Array<int> copiedArray(intArray);
	std::cout << "Copied Array: ";
	for (unsigned int i = 0; i < copiedArray.size(); ++i)
		std::cout << copiedArray[i] << " ";
	std::cout << std::endl;

	// Test 5: Testing assignment operator
	SEPARATOR
	std::cout << "Test 5: Testing assignment operator" << std::endl;
	Array<std::string> assignedArray;
	assignedArray = stringArray;
	std::cout << "Assigned Array: ";
	for (unsigned int i = 0; i < assignedArray.size(); ++i)
		std::cout << assignedArray[i] << " ";
	std::cout << std::endl;

	// Test 6: Modifying the original array after copy/assignment
	SEPARATOR
	std::cout << "Test 6: Modifying original array after copy/assignment" << std::endl;
	intArray[0] = 100;
	stringArray[0] = "Modified";
	std::cout << "Modified Original intArray: ";
	for (unsigned int i = 0; i < intArray.size(); ++i)
		std::cout << intArray[i] << " ";
	std::cout << std::endl;
	std::cout << "Copied intArray (should be unchanged): ";
	for (unsigned int i = 0; i < copiedArray.size(); ++i)
		std::cout << copiedArray[i] << " ";
	std::cout << std::endl;
	std::cout << "Modified Original stringArray: ";
	for (unsigned int i = 0; i < stringArray.size(); ++i)
		std::cout << stringArray[i] << " ";
	std::cout << std::endl;
	std::cout << "Assigned stringArray (should be unchanged): ";
	for (unsigned int i = 0; i < assignedArray.size(); ++i)
		std::cout << assignedArray[i] << " ";
	std::cout << std::endl;

	// Test 7: Creating an array of doubles
	SEPARATOR
	std::cout << "Test 7: Creating an array of doubles" << std::endl;
	Array<double> doubleArray(4);
	for (unsigned int i = 0; i < doubleArray.size(); ++i)
		doubleArray[i] = 1.1 * (i + 1);
	for (unsigned int i = 0; i < doubleArray.size(); ++i)
		std::cout << "doubleArray[" << i << "] = " << doubleArray[i] << std::endl;

	// Test 8: Checking out-of-bounds access
	SEPARATOR
	std::cout << "Test 8: Checking out-of-bounds access" << std::endl;
	try
	{
		std::cout << intArray[10] << std::endl;  // This should throw an exception
	}
	catch (const std::exception& e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// Test 9: Creating a zero-sized array
	SEPARATOR
	std::cout << "Test 9: Creating a zero-sized array" << std::endl;
	Array<char> charArray(0);
	std::cout << "Size of zero-sized charArray: " << charArray.size() << std::endl;

	// Test 10: Creating an array of custom objects
	SEPARATOR
	std::cout << "Test 10: Creating an array of custom objects (Point)" << std::endl;

	Array<Point> pointArray(3);
	pointArray[0] = Point(1, 2);
	pointArray[1] = Point(3, 4);
	pointArray[2] = Point(5, 6);
	for (unsigned int i = 0; i < pointArray.size(); ++i)
		std::cout << "pointArray[" << i << "] = " << pointArray[i] << std::endl;

	SEPARATOR
	return 0;
}
