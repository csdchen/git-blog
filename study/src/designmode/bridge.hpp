#pragma once
#include <iostream>
using namespace std;

// 变化方向 业务与平台

class Image {};

class MessagerImp
{
public:
    virtual void PlaySound() = 0;
    virtual void DrawShape() = 0;
    virtual void WriteText() = 0;
    virtual void Connect() = 0;

    virtual ~MessagerImp() {}
};

class Messager 
{
protected:
    MessagerImp* messagerImp;

public:
    virtual void Login(string username, string password) = 0;
    virtual void SendMessage(string message) = 0;
    virtual void SendPicture(Image image) = 0;

    Messager(MessagerImp* imp) : messagerImp(imp) {}
    virtual ~Messager() {}
};

//平台实现 n
class PCMessagerImp : public MessagerImp 
{
public:

    virtual void PlaySound() 
    {
        //**********
    }

    virtual void DrawShape() 
    {
        //**********
    }

    virtual void WriteText() 
    {
        //**********
    }

    virtual void Connect() 
    {
        //**********
    }
};

class MobileMessagerImp : public MessagerImp 
{
public:

    virtual void PlaySound() 
    {
        //==========
    }

    virtual void DrawShape() 
    {
        //==========
    }

    virtual void WriteText() 
    {
        //==========
    }

    virtual void Connect() 
    {
        //==========
    }
};

//ҵ����� m
class MessagerLite :public Messager
{
public:
    MessagerLite(MessagerImp* imp) : Messager(imp) {}

    virtual void Login(string username, string password) 
    {
        messagerImp->Connect();
        //........
    }

    virtual void SendMessage(string message) 
    {
        messagerImp->WriteText();
        //........
    }

    virtual void SendPicture(Image image)
    {
        messagerImp->DrawShape();
        //........
    }
};

class MessagerPerfect :public Messager 
{
public:
    MessagerPerfect(MessagerImp* imp) : Messager(imp) {}

    virtual void Login(string username, string password) 
    {
        messagerImp->PlaySound();
        //********
        messagerImp->Connect();
        //........
    }

    virtual void SendMessage(string message) 
    {
        messagerImp->PlaySound();
        //********
        messagerImp->WriteText();
        //........
    }

    virtual void SendPicture(Image image)
    {
        messagerImp->PlaySound();
        //********
        messagerImp->DrawShape();
        //........
    }
};
