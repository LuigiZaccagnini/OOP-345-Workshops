#include <iostream>
#include <chrono>
#include <string>
#include <fstream>
#include "RecordSet.h"

namespace sdds
{
	RecordSet::RecordSet()
	{
		m_stringsStored = nullptr;
		m_storedSize = 0;
	}

	RecordSet::RecordSet(const char* fileName)
	{
		std::string fileInfo;


		std::ifstream file;
		file.open(fileName);

		m_stringsStored = nullptr;
		m_storedSize = 0;

		if (!file.fail())
		{


			while (getline(file, fileInfo, ' '))
			{
				m_storedSize++;
			}

			file.close();



			file.open(fileName);

			m_stringsStored = new std::string[m_storedSize];

			for (size_t i = 0; i < m_storedSize; i++)
			{
				getline(file, m_stringsStored[i], ' ');
			};

			file.close();
		}
	}

	RecordSet::~RecordSet()
	{
		if (m_stringsStored != nullptr)
			delete[] m_stringsStored;

		m_stringsStored = nullptr;
	}

	RecordSet::RecordSet(const RecordSet& copy)
	{
		m_storedSize = 0;
		m_stringsStored = nullptr;

		if (copy.m_stringsStored != nullptr)
		{
			m_storedSize = copy.m_storedSize;

			if (m_stringsStored != nullptr)
				delete[] m_stringsStored;

			m_stringsStored = nullptr;

			m_stringsStored = new std::string[copy.m_storedSize + 1];

			for (size_t i = 0; i < copy.m_storedSize; i++)
			{
				m_stringsStored[i] = copy.m_stringsStored[i];
			}
		}
	}

	RecordSet& RecordSet::operator=(const RecordSet& copy)
	{
		if (copy.m_stringsStored != nullptr)
		{
			m_storedSize = copy.m_storedSize;

			if (m_stringsStored != nullptr)
				delete[] m_stringsStored;

			m_stringsStored = nullptr;

			m_stringsStored = new std::string[copy.m_storedSize + 1];

			for (size_t i = 0; i < copy.m_storedSize; i++)
			{
				m_stringsStored[i] = copy.m_stringsStored[i];
			}

		}

		return *this;
	}

	RecordSet::RecordSet(RecordSet&& copy) noexcept
	{
		if (copy.m_stringsStored != nullptr) {

			m_storedSize = copy.m_storedSize;
			m_stringsStored = copy.m_stringsStored;

			copy.m_stringsStored = nullptr;
		}
	}

	RecordSet& RecordSet::operator=(RecordSet&& copy) noexcept
	{
		if (copy.m_stringsStored != nullptr) {
			m_storedSize = copy.m_storedSize;
			m_stringsStored = copy.m_stringsStored;
			copy.m_stringsStored = nullptr;
		}

		return *this;
	}

	size_t RecordSet::size()
	{
		return m_storedSize;
	}

	std::string RecordSet::getRecord(size_t index)
	{
		std::string result;

		if (m_stringsStored != nullptr)
		{
			result = m_stringsStored[index];
		}

		return result;
	}
}