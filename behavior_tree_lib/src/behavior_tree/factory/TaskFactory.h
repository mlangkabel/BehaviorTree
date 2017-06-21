#ifndef TASK_FACTORY_H
#define TASK_FACTORY_H

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "behavior_tree/task/Task.h"
#include "Utility/UtilityString.h"

class TaskFactoryBase
{
public:
	TaskFactoryBase(const std::string &taskName);
	virtual ~TaskFactoryBase();

	std::string getTaskName() const;
	std::vector<std::string> getParameterNames() const;

	virtual std::shared_ptr<Task> create(std::map<std::string, std::string> parameters) = 0;

protected:
	void addParameterName(const std::string &patameterName);

private:
	const std::string m_taskName;
	std::vector<std::string> m_parameterNames;
};


template <typename TaskType, typename T1 = void, typename T2 = void, typename T3 = void, typename T4 = void, typename T5 = void, typename T6 = void>
class TaskFactory : public TaskFactoryBase
{
public:
	TaskFactory(
		const std::string &taskName,
		const std::string &parameterName1, const std::string &parameterName2, const std::string &parameterName3,
		const std::string &parameterName4, const std::string &parameterName5, const std::string &parameterName6
	)
		: TaskFactoryBase(taskName)
	{
		addParameterName(parameterName1);
		addParameterName(parameterName2);
		addParameterName(parameterName3);
		addParameterName(parameterName4);
		addParameterName(parameterName5);
		addParameterName(parameterName6);
	}

	virtual std::shared_ptr<Task> create(std::map<std::string, std::string> parameters)
	{
		return std::shared_ptr<TaskType>(new TaskType(
			Utility::stringTo<T1>(parameters.find(getParameterNames()[0])->second),
			Utility::stringTo<T2>(parameters.find(getParameterNames()[1])->second),
			Utility::stringTo<T3>(parameters.find(getParameterNames()[2])->second),
			Utility::stringTo<T4>(parameters.find(getParameterNames()[3])->second),
			Utility::stringTo<T5>(parameters.find(getParameterNames()[4])->second),
			Utility::stringTo<T6>(parameters.find(getParameterNames()[5])->second)
		));
	}
};

template <typename TaskType, typename T1, typename T2, typename T3, typename T4, typename T5>
class TaskFactory<TaskType, T1, T2, T3, T4, T5, void> : public TaskFactoryBase
{
public:
	TaskFactory(
		const std::string &taskName,
		const std::string &parameterName1, const std::string &parameterName2, const std::string &parameterName3,
		const std::string &parameterName4, const std::string &parameterName5
	)
		: TaskFactoryBase(taskName)
	{
		addParameterName(parameterName1);
		addParameterName(parameterName2);
		addParameterName(parameterName3);
		addParameterName(parameterName4);
		addParameterName(parameterName5);
	}

	virtual std::shared_ptr<Task> create(std::map<std::string, std::string> parameters)
	{
		return std::shared_ptr<TaskType>(new TaskType(
			Utility::stringTo<T1>(parameters.find(getParameterNames()[0])->second),
			Utility::stringTo<T2>(parameters.find(getParameterNames()[1])->second),
			Utility::stringTo<T3>(parameters.find(getParameterNames()[2])->second),
			Utility::stringTo<T4>(parameters.find(getParameterNames()[3])->second),
			Utility::stringTo<T5>(parameters.find(getParameterNames()[4])->second)
		));
	}
};

template <typename TaskType, typename T1, typename T2, typename T3, typename T4>
class TaskFactory<TaskType, T1, T2, T3, T4, void, void> : public TaskFactoryBase
{
public:
	TaskFactory(
		const std::string &taskName,
		const std::string &parameterName1, const std::string &parameterName2, const std::string &parameterName3,
		const std::string &parameterName4
	)
		: TaskFactoryBase(taskName)
	{
		addParameterName(parameterName1);
		addParameterName(parameterName2);
		addParameterName(parameterName3);
		addParameterName(parameterName4);
	}

	virtual std::shared_ptr<Task> create(std::map<std::string, std::string> parameters)
	{
		return std::shared_ptr<TaskType>(new TaskType(
			Utility::stringTo<T1>(parameters.find(getParameterNames()[0])->second),
			Utility::stringTo<T2>(parameters.find(getParameterNames()[1])->second),
			Utility::stringTo<T3>(parameters.find(getParameterNames()[2])->second),
			Utility::stringTo<T4>(parameters.find(getParameterNames()[3])->second)
		));
	}
};

template <typename TaskType, typename T1, typename T2, typename T3>
class TaskFactory<TaskType, T1, T2, T3, void, void, void> : public TaskFactoryBase
{
public:
	TaskFactory(
		const std::string &taskName,
		const std::string &parameterName1, const std::string &parameterName2, const std::string &parameterName3
	)
		: TaskFactoryBase(taskName)
	{
		addParameterName(parameterName1);
		addParameterName(parameterName2);
		addParameterName(parameterName3);
	}

	virtual std::shared_ptr<Task> create(std::map<std::string, std::string> parameters)
	{
		return std::shared_ptr<TaskType>(new TaskType(
			Utility::stringTo<T1>(parameters.find(getParameterNames()[0])->second),
			Utility::stringTo<T2>(parameters.find(getParameterNames()[1])->second),
			Utility::stringTo<T3>(parameters.find(getParameterNames()[2])->second)
		));
	}
};

template <typename TaskType, typename T1, typename T2>
class TaskFactory<TaskType, T1, T2, void, void, void, void> : public TaskFactoryBase
{
public:
	TaskFactory(
		const std::string &taskName,
		const std::string &parameterName1, const std::string &parameterName2
	)
		: TaskFactoryBase(taskName)
	{
		addParameterName(parameterName1);
		addParameterName(parameterName2);
	}

	virtual std::shared_ptr<Task> create(std::map<std::string, std::string> parameters)
	{
		return std::shared_ptr<TaskType>(new TaskType(
			Utility::stringTo<T1>(parameters.find(getParameterNames()[0])->second),
			Utility::stringTo<T2>(parameters.find(getParameterNames()[1])->second)
		));
	}
};

template <typename TaskType, typename T1>
class TaskFactory<TaskType, T1, void, void, void, void, void> : public TaskFactoryBase
{
public:
	TaskFactory(const std::string &taskName, const std::string &parameterName1)
		: TaskFactoryBase(taskName)
	{
		addParameterName(parameterName1);
	}

	virtual std::shared_ptr<Task> create(std::map<std::string, std::string> parameters)
	{
		return std::make_shared<TaskType>(Utility::stringTo<T1>(parameters.find(getParameterNames()[0])->second));
	}
};

template <typename TaskType>
class TaskFactory<TaskType, void, void, void, void, void, void> : public TaskFactoryBase
{
public:
	TaskFactory(const std::string &taskName)
		: TaskFactoryBase(taskName)
	{
	}

	virtual std::shared_ptr<Task> create(std::map<std::string, std::string> parameters)
	{
		return std::make_shared<TaskType>();
	}
};

#endif // TASK_FACTORY_H
