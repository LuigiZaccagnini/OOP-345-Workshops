#pragma once
#include <iostream>

namespace sdds
{

	template<typename K, typename V>

	class Pair
	{

		K m_key;
		V m_value;

	public:
		Pair(){};

		Pair(const K& key, const V& value)
		{
			m_key = key;
			m_value = value;
		};

		const K& key() const
		{
			return m_key;
		};

		const V& value() const
		{
			return m_value;
		};

		void display(std::ostream& os) const
		{
			os << m_key << " : " << m_value << std::endl;
		};

		friend std::ostream& operator<<(std::ostream& os, const Pair<K, V>& pair)
		{
			pair.display(os);
			return os;
		};
	};

}
