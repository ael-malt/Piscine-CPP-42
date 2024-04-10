#include "Serializer.hpp"

int main(void) {
	Data object;
	uintptr_t	u1;
	Data*		u2;

	u1 = Serializer::serialize(&object);
	u2 = Serializer::deserialize(u1);
	if (u2 == &object)
		cout << "Serialization->Deserialization: OK" << endl;
	else 
		cout << "Serialization->Deserialization: NOT OK" << endl;
};