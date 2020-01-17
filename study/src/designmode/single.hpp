#pragma once
#include <mutex>
#include <atomic>

class SingleA
{
public:
	static SingleA& GetInstance() { static SingleA single; return single; }	// ע����̲߳����Ķ�γ�ʼ������

private:
	SingleA() {}
};

/// 线程安全
std::mutex g_single_mutex;
class SingleB
{
public:
	static SingleB& GetInstance()
	{
		std::lock_guard <std::mutex> _(g_single_mutex);
		static SingleB single;
		return single;
	}

private:
	SingleB() {}
};

class SingleC
{
public:
	static SingleC& GetInstance()
	{
		return SingleC::single;
	}

private:
	static SingleC single;
	SingleC() {}
};

class SingleD
{
public:
	static SingleD* GetInstance()
	{
		// 由于内存读写reorder不安全
		if(nullptr == m_instance)
		{
			std::lock_guard <std::mutex> _(g_single_mutex);
			if(nullptr == m_instance)
			{
				m_instance = new SingleD;
			}
		}

		// 正常new: 分配内存 构造 返回指针
		// reorder: 分配内存 返回指针 构造
		// 缺点: 没有执行构造 就返回 m_instance
		// 解决: c++11 实现 volatile

		return m_instance;
	}

private:
	SingleD() {}
	static SingleD *m_instance;
};


class SingleE
{
public:
	
	static SingleE* GetInstance()
	{
		SingleE *tmp = m_instance.load(std::memory_order_relaxed);
		// 获取内存fence
		std::atomic_thread_fence(std::memory_order_acquire);
		if(nullptr == m_instance)
		{
			std::lock_guard <std::mutex> _(m_mutex);
			tmp = m_instance.load(std::memory_order_relaxed);
			if(nullptr == m_instance)
			{
				tmp = new SingleE;
				// 释放内存fence
				std::atomic_thread_fence(std::memory_order_release);
				m_instance.store(tmp, std::memory_order_relaxed);
			}
		}

		return tmp;
	}

private:
	SingleE() {}
	static std::atomic<SingleE*> m_instance;
	static std::mutex m_mutex;
};
std::atomic<SingleE*> SingleE::m_instance;
std::mutex SingleE::m_mutex;
