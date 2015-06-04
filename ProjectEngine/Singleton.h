#pragma once

template <class T>
class Singleton
{
public:

	static T *getInstance()
	{
		static T instance;
		return &instance;
	}

protected:

	/// Hide all methods of copying.
	Singleton(){};
	~Singleton(){};
	Singleton(const Singleton &);
	Singleton &operator=(const Singleton &);
};

