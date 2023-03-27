#include <iostream>
#include <fstream>
#include <sstream>
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
		std::cout << "Error: bad input => " << date << '\n';
        return false;
    }

    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
		std::cout << "Error: bad input => " << date << '\n';
        return false;
    }

    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "Error: Invalid number of arguments.\n";
        return 1;
    }

    std::ifstream price_db;
	price_db.open("data.csv");
    if (!price_db.is_open()) {
        std::cerr << "Error: could not open input.csv file.\n";
	return 1;
	std::map<std::string, float> exchange_rate;
	std::string date;
	float price;
	while (price_db >> date >> price) {
		exchange_rate[date] = price;
	}
	price_db.close();

	std::ifstream input;
	input.open(argv[1]);
	if (!input.is_open()) {
		std::cerr << "Error: could not open input file.\n";
		return 1;
	}

	std::string line;
	std::getline(input, line);
	std::cout << line << '\n';

	while (std::getline(input, line)) {
		std::cout << line << '\n';
		std::istringstream line_stream(line);
		std::string date, delimiter;
		float value;

		line_stream >> date >> delimiter >> value;
		if (delimiter != "|") {
			std::cerr << "Error: bad input => " << line << '\n';
			continue;
		}

		if (!is_valid_date(date)) {
			std::cerr << "Error: bad input => " << date << '\n';
			continue;
		}
		if (value < 0 || value > 1000) {
			std::cerr << "Error: ";
			if (value < 0) {
				std::cerr << "not a positive number.\n";
			} else {
				std::cerr << "too large a number.\n";
			}
			continue;
		}

		std::map<std::string, float>::iterator it = exchange_rate.lower_bound(date);
		if (it == exchange_rate.begin()) {
			std::cerr << "Error: date not in range.\n";
			continue;
		}
		if (it == exchange_rate.end() || it->first != date) {
			it--;
		}
		float result = value * it->second;
		std::cout << date << " => " << value << " = " << result << '\n';
	}
		input.close();
		return 0;
	}
}

