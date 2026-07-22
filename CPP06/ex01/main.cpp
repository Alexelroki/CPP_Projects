#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	// 1. Instanciamos la estructura Data (en el Stack)
	Data data;
	data.s = "Modulo 06 C++ - Serialization";
	data.n = 42;

	// Guardamos la dirección de memoria original
	Data* originalPtr = &data;

	std::cout << "--- PRUEBA DE SERIALIZACIÓN ---\n";
	std::cout << "Puntero original (Data*):   " << originalPtr << "\n";
	std::cout << "  -> Contenido.s: " << originalPtr->s << "\n";
	std::cout << "  -> Contenido.n: " << originalPtr->n << "\n\n";

	// 2. Serializar: Data* -> uintptr_t
	uintptr_t rawBits = Serializer::serialize(originalPtr);
	std::cout << "Valor serializado (uintptr_t Hex): 0x" << std::hex << rawBits << std::dec << "\n";
	std::cout << "Valor serializado (uintptr_t Dec): " << rawBits << "\n\n";

	// 3. Deserializar: uintptr_t -> Data*
	Data* deserializedPtr = Serializer::deserialize(rawBits);
	std::cout << "Puntero deserializado (Data*): " << deserializedPtr << "\n";

	// 4. Verificación
	if (deserializedPtr == originalPtr)
	{
		std::cout << "\n[ÉXITO] ¡Los punteros coinciden exactos!\n";
		std::cout << "  -> Recobrado.s: " << deserializedPtr->s << "\n";
		std::cout << "  -> Recobrado.n: " << deserializedPtr->n << "\n";
	}
	else
	{
		std::cout << "\n[ERROR] Los punteros NO coinciden.\n";
	}

	return 0;
}