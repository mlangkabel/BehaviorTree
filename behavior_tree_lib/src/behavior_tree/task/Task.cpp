#include "behavior_tree/task/Task.h"

Task::Task(int allowedChildCount)
	: m_allowedChildCount(allowedChildCount)
{
}

Task::~Task()
{
}
		
int Task::getAllowedChildCount() const
{
	return m_allowedChildCount;
}
