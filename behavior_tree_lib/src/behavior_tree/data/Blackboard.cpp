#include "behavior_tree/data/Blackboard.h"

Blackboard::Blackboard()
{
}

Blackboard::Blackboard(std::shared_ptr<Blackboard> parent)
	: m_parent(parent)
{
}

bool Blackboard::getAsString(const std::string& key, std::string& value)
{
	ValueMap::const_iterator it = m_values.find(key);
	if (it != m_values.end())
	{
		value = it->second->getAsString();
		return true;
	}
	if (m_parent)
	{
		return m_parent->getAsString(key, value);
	}
	return false;
}

bool Blackboard::exists(const std::string& key)
{
	ValueMap::const_iterator it = m_values.find(key);
	return (it != m_values.end());
}

bool Blackboard::clear(const std::string& key)
{
	ValueMap::const_iterator it = m_values.find(key);
	if (it != m_values.end())
	{
		m_values.erase(it);
		return true;
	}
	return false;
}

std::vector<std::string> Blackboard::getKeys() const
{
	std::vector<std::string> keys;
	for (ValueMap::const_iterator it = m_values.begin(); it != m_values.end(); it++)
	{
		keys.push_back(it->first);
	}
	if (m_parent)
	{
		const std::vector<std::string> parentKeys = m_parent->getKeys();
		keys.insert(keys.end(), parentKeys.begin(), parentKeys.end());
	}
	return keys;
}
