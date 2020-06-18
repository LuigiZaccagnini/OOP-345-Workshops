/*
	Name: Luigi Zaccagnini
	Seneca Email: lzaccagnini@myseneca.ca
	Seneca Student ID: 101423192
	I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#include "Event.h"
#include<iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iomanip>

size_t g_sysClock = 0;

namespace sdds
{
	Event::Event()
	{
		m_eventStart = 0;
		m_description = nullptr;
	}

	Event::Event(const Event& copy)
	{
		if (copy.m_description != nullptr && copy.m_description[0] != '\0')
		{
			if (m_description != nullptr)
			{
				delete[] m_description;
				m_description = nullptr;
			}

			m_description = new char[strlen(copy.m_description) + 1];

			//Copy string to description
			strcpy(m_description, copy.m_description);

			//Set current time to start time of event
			m_eventStart = copy.m_eventStart;
		}

		else
		{
			if (m_description != nullptr)
				delete[] m_description;

			//set empty
			m_description = nullptr;
			m_eventStart = 0;
		}
	}

	Event& Event::operator=(const Event& copy)
	{
		if (copy.m_description != nullptr && copy.m_description[0] != '\0')
		{
			if (m_description != nullptr)
			{
				delete[] m_description;
				m_description = nullptr;
			}

			m_description = new char[strlen(copy.m_description) + 1];

			//Copy string to description
			strcpy(m_description, copy.m_description);

			//Set current time to start time of event
			m_eventStart = copy.m_eventStart;
		}

		else
		{
			if (m_description != nullptr)
				delete[] m_description;

			//set empty
			m_description = nullptr;
			m_eventStart = 0;
		}

		return *this;
	}

	Event::~Event()
	{
		m_eventStart = 0;

		if (m_description != nullptr)
			delete[] m_description;

		m_description = nullptr;
	}

	void Event::display()
	{
		static short counter; //Counts how many times function is called.
		double hour, min, sec;

		counter++;

		if (m_description != nullptr && m_description[0] != '\0')
		{
			//Setting up the time for display.
			hour = (m_eventStart / 60) / 60;
			min = (((m_eventStart / 60) / 60) - floor(((m_eventStart / 60) / 60))) * 60;
			sec = (((((m_eventStart / 60) / 60) - floor(((m_eventStart / 60) / 60))) * 60) - floor(min)) * 60;

			//Display event information
			std::cout << std::setw(2) << std::setfill(' ') << counter;
			std::cout << ". " << std::setw(2) << std::setfill('0') << floor(hour);
			std::cout << ":" << std::setw(2) << std::setfill('0') << floor(min);
			std::cout << ":" << std::setw(2) << std::setfill('0') << floor(sec);
			std::cout << " -> " << m_description << std::endl;
		}

		else
		{
			std::cout << std::setw(2) << std::setfill(' ') << counter << ". " << "[ No Event ]" << std::endl;
		}
	}

	void Event::setDescription(const char* description)
	{
		if (description != nullptr && description[0] != '\0')
		{
			if (m_description != nullptr)
			{
				delete[] m_description;
				m_description = nullptr;
			}

			m_description = new char[strlen(description) + 1];

			//Copy string to description
			strcpy(m_description, description);

			//Set current time to start time of event
			m_eventStart = g_sysClock;
		}

		else
		{
			if (m_description != nullptr)
				delete[] m_description;

			//set empty
			m_description = nullptr;
			m_eventStart = 0;
		}
	}
}
