#include <iostream>
#include "Serializer.h"

int main()
{
	std::cout << "testing serialize and deserialized class methods" << std::endl;

	std::cout << "------------------------------------" <<  std::endl;

	/* creating a Data object */
	Data	originalData(42, "Hello, World!");

	/* Serialization: converting a pointer struct Data into a uintptr_t type */
	uintptr_t raw;
	
	raw = Serializer::serialize(&originalData);

	std::cout << "Serialized pointer: Data* converted into raw uintptr_t" << std::endl;

	std::cout << "raw uintptr_t: " << raw << std::endl;

	std::cout << "------------------------------------" <<  std::endl;

	/* Deserialization: converting a uintptr_t type into a Data pointer struct */
	std::cout << "Deserialized pointer: raw uintptr converted into Data pointer" << std::endl;
	Data* deserializedData;
	
	deserializedData = Serializer::deserialize(raw);
	std::cout << "Deserialized Data pointer: " << deserializedData << std::endl;

	std::cout << "------------------------------------" <<  std::endl;

	/* verify that the original Data pointer and the Deserialized Data pointer are the same */

	std::cout << "Verify that the original data pointer and the deserialized data pointer are the same" << std::endl;

	std::cout << "Original Data pointer: " << &originalData << std::endl;
	std::cout << "Deserialized Data pointer: " << deserializedData << std::endl;

	/* verify that the value of the original Data struct and the deserialized Data are the same */
	std::cout << "Original Data content: number = " << originalData.number 
			<< ", text = \"" << originalData.text << "\"" << std::endl;
	std::cout << "Deserialized Data content: number = " << deserializedData->number 
			<< ", text = \"" << deserializedData->text << "\"" << std::endl;

	std::cout << "------------------------------------" <<  std::endl;

	if (deserializedData == &originalData)
		std::cout << "Test passed: Deserialized pointer matches the original!" << std::endl;
	else
		std::cout << "Test failed: Deserialized pointer does not match the original!" << std::endl;

	return 0;
}
