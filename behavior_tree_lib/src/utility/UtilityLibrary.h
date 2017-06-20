#ifndef UTILITY_LIBRARY_H
#define UTILITY_LIBRARY_H

#include <string>
#include <windows.h>

#include "utility/logging/logging.h"

namespace Utility
{
	template <typename R, typename P0>
	std::function<R(P0)> loadFunctionFromDynamicLibrary(const std::string& libraryFilePath, const std::string& functionName)
	{
		HINSTANCE handle = LoadLibrary(libraryFilePath.c_str());

		if (!handle)
		{
			LOG_ERROR("Could not load the dynamic library from \"" + libraryFilePath + "\".");
			return nullptr;
		}

		typedef R(*functionTypes)(P0);

		std::function<R(P0)> function = (functionTypes)GetProcAddress(handle, functionName.c_str());
		if (!function)
		{
			LOG_ERROR("Could not locate the function \"" + functionName + "\" in dynamic library \"" + libraryFilePath + "\".");
			return nullptr;
		}

		return function;
	}
};

#endif // UTILITY_LIBRARY_H
