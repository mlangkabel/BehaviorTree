#ifndef BLACKBOARD_H
#define BLACKBOARD_H

#include <map>
#include <memory>
#include <string>
#include <iostream>

#include "utility/UtilityString.h"

class Blackboard
{
public: 
	Blackboard();
	Blackboard(std::shared_ptr<Blackboard> parent);
	~Blackboard();

	template <typename T>
	void set(const std::string& key, const T& value);

	template <typename T>
	bool get(const std::string& key, T& value);

	bool getAsString(const std::string& key, std::string& value);
	bool exists(const std::string& key);
	bool clear(const std::string& key);

private:
	struct BlackboardData
	{
		virtual ~BlackboardData()
		{}

		virtual std::string getAsString() = 0;
	};

	template <typename T>
	struct BlackboardDataConcrete : public BlackboardData
	{
		BlackboardDataConcrete(const T &v)
			: value(v)
		{}

		virtual ~BlackboardDataConcrete()
		{}

		virtual std::string getAsString()
		{
			return Utility::toString(value);
		}

		T value;
	};

	typedef std::map<std::string, std::shared_ptr<BlackboardData>> ValueMap;

	std::shared_ptr<Blackboard> m_parent;
	ValueMap m_values;
};


template <typename T>
void Blackboard::set(const std::string& key, const T& value)
{
	m_values[key] = std::make_shared<BlackboardDataConcrete<T>>(value);
}

template <typename T>
bool Blackboard::get(const std::string& key, T& value)
{
	ValueMap::const_iterator it = m_values.find(key);
	if (it != m_values.end())
	{
		std::shared_ptr<BlackboardDataConcrete<T>> slot = std::dynamic_pointer_cast<BlackboardDataConcrete<T>>(it->second);
		if (slot)
		{
			value = slot->value;
			return true;
		}
	}
	if (m_parent)
	{
		return m_parent->get(key, value);
	}
	std::cout << "Variable \"" + key + "\" not found on blackboard." << std::endl;
	return false;
}

#endif // BLACKBOARD_H
