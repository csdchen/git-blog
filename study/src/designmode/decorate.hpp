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
		//���ļ���
	}
	virtual void Seek() {
		//��λ�ļ���
	}
	virtual void Write() {
		//д�ļ���
	}
};

//��չ����
class FileBufferStream : FileStream
{
	virtual void Read()
	{
		// ����
		// ...
		FileStream::Read();
	}

	virtual void Seek()
	{
		// ����
		// ...
		FileStream::Seek();
	}

	virtual void Write()
	{
		// ����
		// ...
		FileStream::Write();
	}
};

class CryptoFileStream :public FileStream {
public:
	virtual void Read() 
	{
		//����ļ��ܲ���...
		FileStream::Read();
	}
	virtual void Seek() {
		//����ļ��ܲ���...
		FileStream::Seek();
	}
	virtual void Write() {
		//����ļ��ܲ���...
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
		// ����
		// ...
		m_stream->Read();
	}

	virtual void Seek()
	{
		// ����
		// ...
		m_stream->Seek();
	}

	virtual void Write()
	{
		// ����
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

		//����ļ��ܲ���...
		m_stream->Read();
	}
	virtual void Seek() {
		//����ļ��ܲ���...
		m_stream->Seek();
	}
	virtual void Write() {
		//����ļ��ܲ���...
		m_stream->Write();
	}
};
