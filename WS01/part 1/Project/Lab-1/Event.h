/*
	Name: Luigi Zaccagnini
	Seneca Email: lzaccagnini@myseneca.ca
	Seneca Student ID: 101423192
	I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#ifndef EVENT_H
#define EVENT_H

#define _CRT_SECURE_NO_WARNINGS
#include <cstddef>

extern size_t g_sysClock;

namespace sdds
{
	class Event
	{
		char* m_description = nullptr;
		double m_eventStart = 0; //Only stores positive integers

	public:
		//Default Constructor 
		Event();

		//Copy Constructor 
		Event(const Event& copy);
		Event& operator=(const Event& copy);

		//Deconstructor
		~Event();

		//Display 
		void display();

		//set the description of the event 
		void setDescription(const char* description);
	};
}

#endif