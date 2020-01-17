#pragma once

class Stream
{
public:
	virtual ~Stream() {}
	virtual void Read() = 0;
	virtual void Seek() = 0;
	virtual void Write() = 0;
};

class FileStream
{
public:
	virtual void Read() {
		//读文件流
	}
	virtual void Seek() {
		//定位文件流
	}
	virtual void Write() {
		//写文件流
	}
};

//扩展操作
class FileBufferStream : FileStream
{
	virtual void Read()
	{
		// 缓冲
		// ...
		FileStream::Read();
	}

	virtual void Seek()
	{
		// 缓冲
		// ...
		FileStream::Seek();
	}

	virtual void Write()
	{
		// 缓冲
		// ...
		FileStream::Write();
	}
};

class CryptoFileStream :public FileStream {
public:
	virtual void Read() 
	{
		//额外的加密操作...
		FileStream::Read();
	}
	virtual void Seek() {
		//额外的加密操作...
		FileStream::Seek();
	}
	virtual void Write() {
		//额外的加密操作...
		FileStream::Write();
	}
};

class DecoratorStream
{
protected:
	DecoratorStream(Stream* stream) :m_stream(stream) {}

protected:
	Stream* m_stream;
};

class BufferStream : DecoratorStream
{
public:
	BufferStream(Stream* stream) :DecoratorStream(stream) {}

	virtual void Read()
	{
		// 缓冲
		// ...
		m_stream->Read();
	}

	virtual void Seek()
	{
		// 缓冲
		// ...
		m_stream->Seek();
	}

	virtual void Write()
	{
		// 缓冲
		// ...
		m_stream->Read();
	}
};

class CryptoStream : public DecoratorStream
{
public:
	CryptoStream(Stream* stream) :DecoratorStream(stream)
	{

	}

	virtual char Read() {

		//额外的加密操作...
		m_stream->Read();
	}
	virtual void Seek() {
		//额外的加密操作...
		m_stream->Seek();
	}
	virtual void Write() {
		//额外的加密操作...
		m_stream->Write();
	}
};
