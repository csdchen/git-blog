#pragma once

/// 例如: roleLogicItem 实现通用的接口
/// rolelogic 管理和注册 继承roleLogicItem的子类
/// 当role的通用事件触发, rolelogic遍历所有注册的实例

class RoleLogicItem
{
public:
	virtual void OnDayChange() = 0;
};

class RoleLogic
{
public:
	void Register() {};
	void OnDayChange()
	{
		for (int i = 0; i < 666; i++)
		{
			item[i]->OnDayChange();
		}
	}

	RoleLogicItem* item[666];
};

class Role
{
public:
	void OnDayChange() { logic->OnDayChange(); }
	RoleLogic* logic;
};
