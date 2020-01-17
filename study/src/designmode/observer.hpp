#pragma once

/// ����: roleLogicItem ʵ��ͨ�õĽӿ�
/// rolelogic �����ע�� �̳�roleLogicItem������
/// ��role��ͨ���¼�����, rolelogic��������ע���ʵ��

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
