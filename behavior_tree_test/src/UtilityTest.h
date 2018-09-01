#include "CppUnitTest.h"

#include "behavior_tree/task/Task.h"

namespace Microsoft
{
	namespace VisualStudio
	{
		namespace CppUnitTestFramework
		{
			template<> static std::wstring ToString<BehaviorTree::Task::StatusType>(const BehaviorTree::Task::StatusType& t)
			{
				if (t == BehaviorTree::Task::STATUS_SUCCESS)
				{
					return L"STATUS_SUCCESS";
				}
				return L"STATUS_FAILURE";
			}
		}
	}
}
