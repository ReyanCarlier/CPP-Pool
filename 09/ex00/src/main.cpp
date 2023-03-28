#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <string>
#include <map>
#include <cmath>
#include <limits>

bool is_valid_date(const std::string &date) {
    int year, month, day;
    char delimiter1, delimiter2;

    std::istringstream date_stream(date);
    date_stream >> year >> delimiter1 >> month >> delimiter2 >> day;

    if (date_stream.fail() || delimiter1 != '-' || delimiter2 != '-') {
		std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
		std::cout << "Error: bad input => " << date << std::endl;
        return false;
    }

	if (month == 2) {
		if (day > 29) {
			std::cout << "Error: bad input => " << date << std::endl;
			return false;
		}
		if (day == 29) {
			if (year % 4 != 0) {
				std::cout << "Error: bad input => " << date << std::endl;
				return false;
			}
			if (year % 100 == 0 && year % 400 != 0) {
				std::cout << "Error: bad input => " << date << std::endl;
				return false;
			}
		}
	} else if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day > 30) {
			std::cout << "Error: bad input => " << date << std::endl;
			return false;
		}
	}
	

    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        return 1;
    }

    std::ifstream price_db;
	price_db.open("data.csv");
    if (!price_db.is_open()) {
        std::cerr << "Error: could not open data file." << std::endl;
		return 1;
	}
	std::map<std::string, float> exchange_rate;
	std::string date;
	std::string line;
	float price;
	while (std::getline(price_db, line)) {
		std::istringstream line_stream(line);
		date = line.substr(0, 10);
		price = atof(line.substr(11, 6).c_str());
		exchange_rate[date] = price;
	}
	
	price_db.close();

	std::ifstream input;
	input.open(argv[1]);
	if (!input.is_open()) {
		std::cerr << "Error: could not open " << argv[1] <<".\n";
		return 1;
	}
	std::getline(input, line);

	while (std::getline(input, line)) {
		std::istringstream line_stream(line);
		std::string date, delimiter;
		float value;

		line_stream >> date >> delimiter >> value;
		if (delimiter != "|") {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		if (!is_valid_date(date)) {
			std::cerr << "Error: invalid date => " << date << std::endl;
			continue;
		}
		if (value < 0 || value > 1000) {
			std::cerr << "Error: ";
			if (value < 0) {
				std::cerr << "not a positive number." << std::endl;
			} else {
				std::cerr << "too large number." << std::endl;
			}
			continue;
		}

		std::map<std::string, float>::iterator it = exchange_rate.lower_bound(date);
		if (it == exchange_rate.begin()) {
			std::cerr << "Error: date not in range." << std::endl;
			continue;
		}
		if (it == exchange_rate.end() || it->first != date) {
			it--;
		}
		float result = it->second * value;
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
	input.close();
	return 0;
}

