/*
	Name: Luigi Zaccagnini
	Seneca Email: lzaccagnini@myseneca.ca
	Seneca Student ID: 101423192
	I have done all the coding by myselfand only copied the code that my professor provided to complete my workshopsand assignments.
*/

#pragma once
#include <iostream>
#include <string>
#include "Pair.h"

namespace sdds
{
	template<typename K, typename V>

	class PairSummable : public sdds::Pair<K, V>
	{
		static V m_initialValue;
		static size_t m_minCharacters;

	public:
		static const V& getInitialValue() { return m_initialValue; };

		PairSummable() {};

		PairSummable(const K& key, const V& value) : Pair<K, V>(key, value)
		{

			if (key.size() > m_minCharacters)
				m_minCharacters = key.size();

		}

		V sum(const K& key, const V& val) const {

			V result;

			if (Pair<K, V>::key() == key)
				result = Pair<K, V>::value() + val;

			else
				result = val;


			return result;
		}


		void display(std::ostream& os) const {
			std::os.width(m_minCharacters) << std::left;
			Pair<K, V>::display(os);
			std::os.setf(std::ios::right);
		}
	};

	template<> std::string PairSummable<std::string, std::string>::sum(const std::string& key, const std::string& value) const
	{
		std::string result;

		if (Pair::key() != key)
			result = value;

		else {

			if (value[0] == '\0')
				result = Pair::value() + value;

			else
				result = value + ", " + Pair::value();
		}

		return result;
	};

	template<> int PairSummable<std::string, int>::m_initialValue = 0;
	template<> std::string PairSummable<std::string, std::string>::m_initialValue = "";

	template<typename K, typename V>
	size_t PairSummable<K, V>::m_minCharacters = 0;
}