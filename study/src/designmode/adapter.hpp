#pragma once
#include <cstdio>

// 新目标
class ITarget
{
public:
	virtual void process() = 0;
};

// 旧目标
class IAdaptee
{
public:
	virtual void foo() = 0;
};

class oldClass : IAdaptee
{
public:
	virtual void foo() { printf("oldClass::foo()\r\n"); }
};

class AdapterA : public ITarget
{
protected:
	IAdaptee* pAdaptee;
public:
	AdapterA(IAdaptee* _pAdaptee) :pAdaptee(_pAdaptee) {}

	virtual void process()
	{
		if(pAdaptee != nullptr)
			pAdaptee->foo();
	}
};

// 类 - 适配器
class AdapterClass : public ITarget, protected oldClass
{
public:
	void process()
	{
		oldClass::foo();
	}
};

// 对象 - 适配器
class AdapterObject : public ITarget
{
public:
	AdapterObject(IAdaptee* _pAdaptee) :m_pAdaptee(_pAdaptee) {}

	~AdapterObject()
	{
		if (m_pAdaptee != nullptr)
		{
			delete m_pAdaptee;
			m_pAdaptee = nullptr;
		}
	}

	void Request()
	{
		if (m_pAdaptee != nullptr)
			m_pAdaptee->foo();
	}

private:
	IAdaptee* m_pAdaptee;
};