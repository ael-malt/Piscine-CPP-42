#include "easyFind.hpp"

template <typename T>
typename T::iterator easyfind(T& container, int nb) {
	

	for (T::iterator it = container.begin(), int i = 0; it != container.end() && i < nb ; i++, it++) {}
	if (it != it.end())
		return (it);
	throw (NotFound());
}