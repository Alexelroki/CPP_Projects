#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	// Create an instance of Data on the stack and initialize its members
	Data	data;

	data.s = "Module 06 C++ - Serialization";
	data.n = 42;

	// Store the original memory address
	Data*	originalPtr = &data;

	std::cout << "--- SERIALIZATION TEST ---\n";
	std::cout << "Original Pointer (Data*):  " << originalPtr << "\n";
	std::cout << "  -> Member .s: " << originalPtr->s << "\n";
	std::cout << "  -> Member .n: " << originalPtr->n << "\n\n";

	// 1. Serialize: Convert Data* pointer to uintptr_t integer
	uintptr_t	rawBits = Serializer::serialize(originalPtr);
	std::cout << "Serialized Value (uintptr_t Dec): " << rawBits << "\n";
	std::cout << "Serialized Value (uintptr_t Hex): 0x" << std::hex << rawBits << std::dec << "\n\n";

	// 2. Deserialize: Convert uintptr_t integer back to Data* pointer
	Data*	deserializedPtr = Serializer::deserialize(rawBits);
	std::cout << "Deserialized Pointer (Data*): " << deserializedPtr << "\n";

	// 3. Verification
	if (deserializedPtr == originalPtr)
	{
		std::cout << "\n[SUCCESS] Both pointers are strictly equal!\n";
		std::cout << "  -> Recovered .s: " << deserializedPtr->s << "\n";
		std::cout << "  -> Recovered .n: " << deserializedPtr->n << "\n";
	}
	else
	{
		std::cout << "\n[ERROR] Pointers do not match.\n";
	}

	return (0);
}
