#pragma once

class ISplitter
{
public:
	virtual void split() = 0;
	virtual ~ISplitter() {}
};

class BinarySplitter : public ISplitter
{
public:
	virtual void split() override {}

};

class TxtSplitter : public ISplitter
{
public:
	virtual void split() override {}

};

class SplitterFactory
{
public:
	virtual ISplitter* CreateSplitter() = 0;
	virtual ~SplitterFactory() {}
};

class BinarySplitterFactory : public SplitterFactory
{
public:
	virtual ISplitter* CreateSplitter() override
	{
		return new BinarySplitter();
	}
};

class TxtSplitterFactory : public SplitterFactory
{
public:
	virtual ISplitter* CreateSplitter() override
	{
		return new TxtSplitter();
	}
};