#ifndef ACTION_H
#define ACTION_H

#include "behavior_tree/task/Task.h"

class Action: public Task
{
public:
	Action();
	virtual ~Action();
};

#endif // ACTION_H
