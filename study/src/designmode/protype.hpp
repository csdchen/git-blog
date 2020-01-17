
class IPrototype
{
public:
	virtual IPrototype* clone() = 0;
	virtual ~IPrototype() {}
};

class ChildrenPrototype : public IPrototype
{
public:
	virtual IPrototype* clone()
	{
		return new ChildrenPrototype(*this);
	}

};
