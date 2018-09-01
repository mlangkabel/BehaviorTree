#ifndef ACTION_SIMULATE_MOUSE_BUTTON_UP_H
#define ACTION_SIMULATE_MOUSE_BUTTON_UP_H

#include "behavior_tree/factory/TaskFactory.h"
#include "behavior_tree/task/Action.h"

namespace BehaviorTree
{
	class ActionSimulateMouseButtonUp;

	class ActionFactorySimulateMouseButtonUp : public TaskFactory<ActionSimulateMouseButtonUp, int>
	{
	public:
		ActionFactorySimulateMouseButtonUp()
			: TaskFactory<ActionSimulateMouseButtonUp, int>("SIMULATE_MOUSE_BUTTON_UP", "button_id")
		{}
	};

	class ActionSimulateMouseButtonUp : public Action
	{
	public:
		ActionSimulateMouseButtonUp(const int buttonId);

		virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard);

	private:
		const int m_buttonId;
	};
}

#endif // ACTION_SIMULATE_MOUSE_BUTTON_UP_H
