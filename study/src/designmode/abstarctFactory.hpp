#pragma once

class IDBConnection
{

};

class IDBCommand
{

};

class IDBDataReader
{

};

class SqlDBConnection : public IDBConnection
{
public:

};

class SqlDBCommand : public IDBCommand
{
public:

};

class SqlDBDataReader : public IDBDataReader
{
public:

};

class IDBFactory
{
public:
	virtual IDBConnection *CreateDBConnection() = 0;
	virtual IDBCommand *CreateDBCommand() = 0;
	virtual IDBDataReader *CreateDBDataReader() = 0;
};

class SqlDBFactory :public IDBFactory
{
public:
	virtual IDBConnection *CreateDBConnection() abstract
	{
		return new SqlDBConnection();
	}

	virtual IDBCommand *CreateDBCommand()abstract
	{
		return new SqlDBCommand();
	}

	virtual IDBDataReader *CreateDBDataReader()abstract
	{
		return new SqlDBDataReader();
	}
};