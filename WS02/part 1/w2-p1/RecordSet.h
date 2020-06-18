#pragma once
#include <iostream>
#include <chrono>
#include <string>
#include <fstream>

namespace sdds
{
	class RecordSet
	{

		std::string* m_stringsStored;
		size_t m_storedSize;

	public:
		RecordSet();
		RecordSet(const char* fileName);
		~RecordSet();

		RecordSet(RecordSet& copy);
		RecordSet& operator=(RecordSet& copy);
		RecordSet(RecordSet&& copy);
		RecordSet& operator=(RecordSet&& copy);

		size_t size();
		std::string getRecord(size_t index);
	};

}