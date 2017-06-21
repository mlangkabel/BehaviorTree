#ifndef UTILITY_STRING_H
#define UTILITY_STRING_H

#include <string>
#include <sstream>

namespace Utility
{
	template <typename T>
	inline std::string toString(const T& t) {
		std::stringstream ss;
		ss << t;
		return ss.str();
	}

	template <typename T>
	T stringTo(std::string s)
	{
		std::stringstream buffer(s);
		T value;
		buffer >> value;
		return value;
	}

	template <>
	std::string stringTo<std::string>(std::string s);

	template <>
	char stringTo<char>(std::string s);
}

#endif // UTILITY_STRING_H
