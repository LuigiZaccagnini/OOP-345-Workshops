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
			{
				memcpy(&setArray[currentSize], &item, sizeof(item));
				currentSize++;
			}
		};
	};
}

