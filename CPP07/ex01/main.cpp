# include "iter.h"

static void doubleElement( int& element );
template <typename T>
static void incrementElement( T& element );
template <typename T>
static void	printElement( const T& element );

int main()
{
	/* Test with integer array */
	std::cout << "Test with integer array:" << std::endl;
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intSize = sizeof(intArray) / sizeof(intArray[0]);

	std::cout << "Original array: ";
	iter(intArray, intSize, printElement<int>);
	std::cout << std::endl;

	iter(intArray, intSize, doubleElement);
	std::cout << "Doubled array: ";
	iter(intArray, intSize, printElement<int>);
	std::cout << std::endl;
	std::cout << "---------------------------" << std::endl;

	/* Test with float array */
	std::cout << "Test with float array:" << std::endl;
	float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
	size_t floatSize = sizeof(floatArray) / sizeof(floatArray[0]);

	std::cout << "Original array: ";
	iter(floatArray, floatSize, printElement<float>);
	std::cout << std::endl;

	iter(floatArray, floatSize, incrementElement<float>);
	std::cout << "Incremented array: ";
	iter(floatArray, floatSize, printElement<float>);
	std::cout << std::endl;
	std::cout << "---------------------------" << std::endl;

	/* Test with character array */
	std::cout << "Test with character array:" << std::endl;
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	size_t charSize = sizeof(charArray) / sizeof(charArray[0]);

	std::cout << "Original array: ";
	iter(charArray, charSize, printElement<char>);
	std::cout << std::endl;

	std::cout << "No modification for characters, still: ";
	iter(charArray, charSize, printElement<char>);
	std::cout << std::endl;

	std::cout << "incrementing char array: ";
	iter(charArray, charSize, incrementElement<char>);

	iter(charArray, charSize, printElement<char>);
	std::cout << std::endl;
	std::cout << "---------------------------" << std::endl;

	/* Test with an array of strings */
	std::cout << "Test with string array:" << std::endl;
	std::string stringArray[] = {"Hello", "World", "Template", "Functions"};
	size_t stringSize = sizeof(stringArray) / sizeof(stringArray[0]);

	std::cout << "Original array: ";
	iter(stringArray, stringSize, printElement<std::string>);
	std::cout << std::endl;

	std::cout << "No modification for strings, still: ";
	iter(stringArray, stringSize, printElement<std::string>);
	std::cout << std::endl;
	std::cout << "---------------------------" << std::endl;

	return 0;
}

/* Basic function to double an element */
static void doubleElement( int& element ) {
	element *= 2; // Modify the element
}

/* Template function to increment an element */
template <typename T>
static void incrementElement( T& element ) {
	element += 1; // Increment the element
}

/* generic print function template */
template <typename T>
static void	printElement( const T& element ) {
	std::cout << element << " ";
}