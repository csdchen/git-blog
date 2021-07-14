### 正确管理动态内存
- 提供静态调用方法, 由scene统一管理
```
static Monster* MonsterPool::CreaterMonster(...)
{
	Monster* monster = new Monster(...);
	...
	scene.Addobj(monster);
}

{
	RoleShadow *shadow = new RoleShadow(...)
	...
	scene.Addobj(shadow);
}
```

### 重载与复用
- 避免写出类似的代码
```
Knaspace::HasItem(ItemID id, bool is_bind);
Knaspace::HasItem(int id, int count);
```

- 尽量消除重复的代码
- 避免修改业务,导致大量的重复代码都要修改
```
void product(ClassA a)
{
	// 重复代码
	...
}

void product(ClassB b)
{
	// 重复代码
	...
}
```

### 判断比较
```
if(nullptr == role)
{
}

if(role != nullptr) < > ...
```

### 重载虚函数
- 增加 override 关键字

### 关于map
- 不要做重复的查询工作
```
int GetValue(int key)
{
	auto iter = _map.find(key)
	if(_map.end() != iter)
	{
		return _map[key];
		return iter->second;
	}

	return 0;
}
```

### 尽量不要使用会create a new param的接口
```
使用这种接口容易忘记手动free内存, 导致大量的内存碎片
```

### 迭代器
```
迭代器溢出
迭代器失效
```