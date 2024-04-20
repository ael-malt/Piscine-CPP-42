#include "Serializer.hpp"

int main(void) {
	Data data;
	uintptr_t	u1 = 0;
	Data*		u2;

	data.setNb(42);
	cout << "data before Serialization - pointer: " << &data << " nb: " << data.getNb() << endl;

	u1 = Serializer::serialize(&data);
	cout << "u1 (data after Serialization) " << u1 << endl;

	u2 = Serializer::deserialize(u1);
	cout << "u2 (data after Deserialization) - pointer: " << u2 << " nb: " << u2->getNb() << endl;
	
	if (u2 == &data)
		cout << "Serialization->Deserialization: OK" << endl;
	else 
		cout << "Serialization->Deserialization: NOT OK" << endl;
};