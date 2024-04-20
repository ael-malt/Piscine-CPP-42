#include "easyFind.hpp"

template <typename T>
typename T::iterator easyfind(T& container, int nb) {
	typename T::iterator it = container.begin();
	for (; it != container.end() && *it != nb ;it++) {}
	if (it != container.end())
		return (it);
	throw (NotFound());
}