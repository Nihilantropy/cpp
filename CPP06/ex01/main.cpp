#include <iostream>
#include "Serializer.h"

int main()
{
	std::cout << "testing serialize and deserialized class methods" << std::endl;

	std::cout << "------------------------------------" <<  std::endl;

	/* creating a Data object */
	Data originalData(42, "Hello, World!");

	/* Serialization: converting a pointer struct Data into a unsigned long type */
	unsigned long raw;
	
	raw = Serializer::serialize(&originalData);

	std::cout << "Serialized pointer: Data* converted into raw unsigned long" << std::endl;

	std::cout << "raw unsigned long: " << raw << std::endl;

	std::cout << "------------------------------------" <<  std::endl;

	/* Deserialization: converting a unsigned long type into a Data pointer struct */
	Data* deserializedData;
	
	deserializedData = Serializer::deserialize(raw);

	/* verify that the original Data pointer and the Deserialized Data pointer are the same */
	std::cout << "Original Data pointer: " << &originalData << std::endl;
	std::cout << "Deserialized Data pointer: " << deserializedData << std::endl;

	/* verify that the value of the original Data struct and the deserialized Data are the same */
	std::cout << "Original Data content: number = " << originalData.number 
			<< ", text = \"" << originalData.text << "\"" << std::endl;
	std::cout << "Deserialized Data content: number = " << deserializedData->number 
			<< ", text = \"" << deserializedData->text << "\"" << std::endl;

	if (deserializedData == &originalData)
		std::cout << "Test passed: Deserialized pointer matches the original!" << std::endl;
	else
		std::cout << "Test failed: Deserialized pointer does not match the original!" << std::endl;

	return 0;
}
