/*
	Name: Luigi Zaccagnini
	Seneca Email: lzaccagnini@myseneca.ca
	Seneca Student ID: 101423192
	I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#pragma once
#include "Set.h"

namespace sdds
{
	template<typename T, size_t N, typename K, typename V>

	class SetSummable : public sdds::Set<T, N>
	{

	public:

		V accumulate(const K& key) const
		{
			V sum = T::getInitialValue();

			for (size_t i = 0; i < Set<T, N>::size(); i++)
			{
				sum = (*this)[i].sum(key, sum);
			}

			return sum;
		}
	};

}