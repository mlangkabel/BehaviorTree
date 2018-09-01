#ifndef SINGLETON_H
#define SINGLETON_H

#include <string>

class Singleton
{
public:
	virtual ~Singleton() = default;
	virtual std::string getSingletonName() = 0;
};

#endif // SINGLETON_H
