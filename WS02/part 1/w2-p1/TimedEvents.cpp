#include <iostream>
#include <chrono>
#include <string>
#include "TimedEvents.h"

namespace sdds
{

	TimedEvents::TimedEvents()
	{
		m_storedRecords = 0;
	}

	void TimedEvents::startClock()
	{
		m_startTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::stopClock()
	{
		m_endTime = std::chrono::steady_clock::now();
	}

	void TimedEvents::recordEvent(const char* eventName)
	{
		if (eventName != nullptr && eventName[0] != '\0' && m_storedRecords < MAX_RECORDS)
		{
			this->Records[m_storedRecords].m_eventName = eventName;
			this->Records[m_storedRecords].m_time = "nanoseconds";
			this->Records[m_storedRecords].m_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(m_endTime - m_startTime);

			m_storedRecords++;
		}
	}

	std::ostream& operator<<(std::ostream& os, const TimedEvents& events)
	{
		os << "--------------------------\n";
		os << "Execution Times:" << std::endl;
		os << "--------------------------\n";

		for (int i = 0; i < events.m_storedRecords; i++)
		{
			os << events.Records[i].m_eventName << ' ' << std::right;
			os << events.Records[i].m_duration.count() << ' ';
			os << events.Records[i].m_time << std::endl;
		}

		os << "--------------------------" << std::endl;

		return os;
	}
}