/*
	Name: Luigi Zaccagnini
	Seneca Email: lzaccagnini@myseneca.ca
	Seneca Student ID: 101423192
	I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#pragma once

namespace sdds
{
	template<typename T, size_t N>

	class Set
	{
		T setArray[N];
		int currentSize = 0;

	public:
		size_t size() const { return currentSize; };

		const T& operator[](size_t idx) const { return setArray[idx]; };

		void operator+=(const T& item)
		{
			if (currentSize < N)
				setArray[currentSize] = item;

			currentSize++;
		};
	};
}

