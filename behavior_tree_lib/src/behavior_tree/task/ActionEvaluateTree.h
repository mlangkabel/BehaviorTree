#ifndef ACTION_EVALUATE_TREE_H
#define ACTION_EVALUATE_TREE_H

#include "behavior_tree/factory/TaskFactory.h"
#include "behavior_tree/task/Task.h"

class ActionEvaluateTree;
class TreeFactory;

class ActionFactoryEvaluateTree : public TaskFactory<ActionEvaluateTree, std::string>
{
public:
	ActionFactoryEvaluateTree()
		: TaskFactory<ActionEvaluateTree, std::string>("EVALUATE_TREE", "name")
	{}
};

class ActionEvaluateTree : public Task
{
public:
	ActionEvaluateTree(std::string name);
	virtual ~ActionEvaluateTree();

	void setTreeFactory(std::shared_ptr<const TreeFactory> treeFactory);

	virtual StatusType evaluate(std::shared_ptr<Blackboard> blackboard);

private:
	std::string m_name;
	std::shared_ptr<const TreeFactory> m_treeFactory;
};

#endif // ACTION_EVALUATE_TREE_H
