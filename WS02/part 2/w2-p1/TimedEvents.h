#pragma once
#include <iostream>
#include <chrono>
#include <string>

namespace sdds
{
	const int MAX_RECORDS = 7;

	class TimedEvents
	{

		int m_storedRecords;
		std::chrono::steady_clock::time_point m_startTime;
		std::chrono::steady_clock::time_point m_endTime;

		struct {
			std::string m_eventName;
			std::string m_time;
			std::chrono::steady_clock::duration m_duration;
		} Records[MAX_RECORDS];

	public:
		TimedEvents();
		void startClock();
		void stopClock();
		void recordEvent(const char* eventName);
		friend std::ostream& operator<<(std::ostream& os, const TimedEvents& events);
	};
}

