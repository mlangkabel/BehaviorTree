#include "behavior_tree/task/ActionEvaluateTree.h"

#include "behavior_tree/factory/TreeFactory.h"
#include "utility/logging/logging.h"

namespace BehaviorTree
{
	ActionEvaluateTree::ActionEvaluateTree(std::string name)
		: m_name(name)
	{
	}

	void ActionEvaluateTree::setTreeFactory(std::shared_ptr<const TreeFactory> treeFactory)
	{
		m_treeFactory = treeFactory;
	}

	Task::StatusType ActionEvaluateTree::evaluate(std::shared_ptr<Blackboard> blackboard)
	{
		if (m_treeFactory)
		{
			std::shared_ptr<Task> treeRoot = m_treeFactory->createBehaviorTree(m_name);
			return treeRoot->evaluate(blackboard);
		}

		LOG_ERROR("No TreeFactory available.");
		return STATUS_FAILURE;
	}
}
