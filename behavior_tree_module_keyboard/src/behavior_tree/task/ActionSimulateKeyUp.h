#ifndef ACTION_SIMULATE_KEY_UP_H
#define ACTION_SIMULATE_KEY_UP_H

#include "behavior_tree/factory/TaskFactory.h"
#include "behavior_tree/task/Action.h"

namespace BehaviorTree
{
	class ActionSimulateKeyUp;

	class ActionFactorySimulateKeyUp : public TaskFactory<ActionSimulateKeyUp, int>
	{
	public:
		ActionFactorySimulateKeyUp()
			: TaskFactory<ActionSimulateKeyUp, int>("SIMULATE_KEY_UP", "keycode")
		{}
	};

	/*
	keycodes map according to this table: https://msdn.microsoft.com/en-us/library/windows/desktop/dd375731(v=vs.85).aspx
	*/
	class ActionSimulateKeyUp : public Action
	{
	public:
		ActionSimulateKeyUp(const int keycode);

		virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard);

	private:
		const int m_keycode;
	};
}

#endif // ACTION_SIMULATE_KEY_UP_H
