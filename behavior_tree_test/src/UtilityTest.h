#include "CppUnitTest.h"

#include "behavior_tree/task/Task.h"

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<> static std::wstring ToString<Task::StatusType>(const Task::StatusType& t)
			{
				if (t == Task::STATUS_SUCCESS)
				{
					return L"STATUS_SUCCESS";
				}
				return L"STATUS_FAILURE";
			}
		}
	}
}
