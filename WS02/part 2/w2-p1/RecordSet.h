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

		RecordSet(const RecordSet& copy);
		RecordSet& operator=(const RecordSet& copy);
		RecordSet(RecordSet&& copy) noexcept;
		RecordSet& operator=(RecordSet&& copy) noexcept;

		size_t size();
		std::string getRecord(size_t index);
	};

}