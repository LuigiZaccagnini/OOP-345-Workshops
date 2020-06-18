#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm>
#include <locale>

namespace sdds
{
	class Reservation
	{
		std::string reservationId;
		std::string reservationName;
		std::string reservationEmail;

		size_t numberOfPeopleInParty;
		size_t dateOfParty;
		size_t hourOfParty;

	public:

		Reservation()
		{
			setEmpty();
		}

		Reservation(const std::string& res)
		{
			setEmpty();

			size_t start = 0;
			size_t end = res.find(":");
			size_t counter = 0;

			//http://www.cplusplus.com/reference/string/string/npos/
			while (end != std::string::npos)
			{
				std::string info = res.substr(start, end - start);

				switch (counter)
				{

				case 0:

					reservationId = info;
					start = end + 1;
					end = res.find(",", start);

					//https://en.cppreference.com/w/cpp/algorithm/remove https://en.cppreference.com/w/cpp/algorithm/remove
					//http://www.cplusplus.com/reference/cctype/isspace/
					//https://www.geeksforgeeks.org/lambda-expression-in-c/
					reservationId.erase(std::remove_if(reservationId.begin(), reservationId.end(), [](unsigned char x) {return std::isspace(x); }), reservationId.end());

					counter++;
					break;

				case 1:

					reservationName = info;
					start = end + 1;
					end = res.find(",", start);

					//https://en.cppreference.com/w/cpp/algorithm/remove https://en.cppreference.com/w/cpp/algorithm/remove
					//http://www.cplusplus.com/reference/cctype/isspace/
					//https://www.geeksforgeeks.org/lambda-expression-in-c/
					reservationName.erase(std::remove_if(reservationName.begin(), reservationName.end(), [](unsigned char x) {return std::isspace(x); }), reservationName.end());

					counter++;
					break;

				case 2:
					reservationEmail = info;
					start = end + 1;
					end = res.find(",", start);

					//https://en.cppreference.com/w/cpp/algorithm/remove https://en.cppreference.com/w/cpp/algorithm/remove
					//http://www.cplusplus.com/reference/cctype/isspace/
					//https://www.geeksforgeeks.org/lambda-expression-in-c/
					reservationEmail.erase(std::remove_if(reservationEmail.begin(), reservationEmail.end(), [](unsigned char x) {return std::isspace(x); }), reservationEmail.end());

					counter++;
					break;

				case 3:
					numberOfPeopleInParty = std::stoi(info);
					start = end + 1;
					end = res.find(",", start);

					counter++;
					break;

				case 4:
					dateOfParty = std::stoi(info);
					start = end + 1;

					hourOfParty = std::stoi(res.substr(start, res.length()));
					end = res.find(",", start);

					counter++;
					break;

				default:
					break;
				}
			}
		}

		friend std::ostream& operator<<(std::ostream& os, Reservation& reservation)
		{
			std::string email = "<" + reservation.reservationEmail + ">";

			if (reservation.hourOfParty >= 6 && reservation.hourOfParty <= 9)
			{

				os << "Reservation " << reservation.reservationId << ": ";


				os.width(10);
				os << std::right << reservation.reservationName << "  ";

				os.width(23);
				os << std::left << email;

				os << " Breakfast on day " << reservation.dateOfParty << " @ " << reservation.hourOfParty << ":00 for " << reservation.numberOfPeopleInParty << " people." << std::endl;
			}

			else if (reservation.hourOfParty >= 11 && reservation.hourOfParty <= 15)
			{
				
				os << "Reservation " << reservation.reservationId << ": ";

				os.width(10);
				os << std::right << reservation.reservationName << "  ";

				os.width(23);
				os << std::left << email;

				os << " Lunch on day " << reservation.dateOfParty << " @ " << reservation.hourOfParty << ":00 for " << reservation.numberOfPeopleInParty << " people." << std::endl;
			}

			else if (reservation.hourOfParty >= 17 && reservation.hourOfParty <= 21)
			{
				os << "Reservation " << reservation.reservationId << ": ";

				os.width(10);
				os << std::right << reservation.reservationName << "  ";

				os.width(23);
				os << std::left << email;

				os << " Dinner on day " << reservation.dateOfParty << " @ " << reservation.hourOfParty << ":00 for " << reservation.numberOfPeopleInParty << " people." << std::endl;
			}

			else
			{
				os << "Reservation " << reservation.reservationId << ": ";

				os.width(10);
				os << std::right << reservation.reservationName << "  ";

				os.width(23);
				os << std::left << email;

				os << " Drinks on day " << reservation.dateOfParty << " @ " << reservation.hourOfParty << ":00 for " << reservation.numberOfPeopleInParty << " people." << std::endl;
			}

			return os;
		}

		void setEmpty()
		{
			reservationId = "";
			reservationName = "";
			reservationEmail = "";

			numberOfPeopleInParty = 0;
			dateOfParty = 0;
			hourOfParty = 0;
		}

	};
}