#pragma once
#include <map>
#include <iostream>
using namespace std;

class Font
{
public:
	std::string key;

	Font(std::string _key) :key(_key) {}
};

class FontFactory
{
private:
	std::map<std::string, Font*> fontPool;

public:
	Font* GetFont(std::string& key)
	{
		auto iter = fontPool.find(key);
		if (iter == fontPool.end())
		{
			Font* font = new Font(key);
			fontPool[key] = font;
			return font;
		}

		return iter->second;
	}

};