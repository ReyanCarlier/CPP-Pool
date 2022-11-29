#include "Data.hpp"
#include "Deserialize.hpp"
#include "Serialize.hpp"
#include <iostream>

int main()
{
	Data data;
	data.s1 = "Hello";
	data.n = 42;
	data.s2 = "World";

	uintptr_t raw = serialize(&data);
	Data *data2 = deserialize(raw);

	std::cout << "data: " << &data << std::endl;
	std::cout << "raw: " << raw << std::endl;

	std::cout << "s1: " << data2->s1 << std::endl;
	std::cout << "n: " << data2->n << std::endl;
	std::cout << "s2: " << data2->s2 << std::endl;

	return (0);
}