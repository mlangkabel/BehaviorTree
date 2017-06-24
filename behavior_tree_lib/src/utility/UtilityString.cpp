#include "utility/UtilityString.h"

namespace utility
{
	template <>
	std::string stringTo<std::string>(std::string s)
	{
		return s;
	}

	template <>
	char stringTo<char>(std::string s)
	{
		return s[0];
	}
}
