#include"Txt.h"
#include <fstream>
#include<string>
#include<iostream>

l1::Txt::Txt()
{
}

l1::Txt::Txt(const std::string& path)
{
	std::ifstream file;
	file.open(path);
	if (!file.is_open())
	{
		std::cout << "Mistake ! File don't find :( ";
		//return;
	}
	else
	{
		std::string information;
		while (std::getline(file, information))
		{
			m_arr_size++;
		}
		this->m_arr = new std::string[m_arr_size];
		
		for (int i = 0; i < m_arr_size; i++)
		{
			std::getline(file, m_arr[i]);
		}
		
	}
	file.close();
}

size_t l1::Txt::size() const
{
	return m_arr_size;
}

l1::Txt::Txt(const Txt &txt)
{
	this->m_arr_size = txt.m_arr_size;
	this->m_arr = new std::string[txt.m_arr_size];
	for (int i = 0; i < m_arr_size; i++)
	{
		this->m_arr[i] = txt.m_arr[i];
	}
}

l1::Txt& l1::Txt::operator=(const Txt& txt)
{
	this->m_arr_size = txt.m_arr_size;
	this->m_arr = new std::string[txt.m_arr_size];
	for (int i = 0; i < m_arr_size; i++)
	{
		this->m_arr[i] = txt.m_arr[i];
	}
	return *this;
}

l1::Txt::Txt(Txt&& txt)	
{
	this->m_arr_size = txt.m_arr_size;
	this->m_arr = txt.m_arr;
	txt.m_arr = nullptr;
	txt.m_arr_size = 0;
}

l1::Txt& l1::Txt::operator=(Txt&& txt)
{
	this->m_arr_size = txt.m_arr_size;
	this->m_arr = txt.m_arr;
	txt.m_arr = nullptr;
	txt.m_arr_size = 0;
	return *this;
}

l1::Txt::~Txt()
{
	delete[] m_arr;
	m_arr = nullptr;
}