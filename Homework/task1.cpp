#include <iostream>

int main() {

// Declaration

        char name[3];
        unsigned int day = 0, month = 0, year = 0;
        unsigned long long int flightDate = 0;
        int destination = 0;

// input
        std::cout << "Enter a name! \n";
        std::cin >> name[0] >> name[1] >> name[2];
        if((name[0] < 'A' || name[0] > 'Z') ||
           (name[1] < 'A' || name[1] > 'Z') ||
           (name[2] < 'A' || name[2] > 'Z')) {
                std::cout << "Invalid name \n";
                return 1;
        }

        std::cout << "Enter a birthdate: \n";
        std::cin >> day >> month >> year;
        bool isLeapYear = year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
        if ((month < 1 || month > 12) ||
            (isLeapYear && month == 2 && (day < 1 && day > 29)) ||
            ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
             && (day < 1 || day > 31)) ||
            ((month == 4 || month == 6 || month == 9 || month == 11)
             && (day < 1 || day > 30)) ||
            (month == 2 && (day < 1 || day > 28))) {
                std::cout << "Invalid birthdate \n";
                return 2;
        }


        std::cout << "Enter Flight Date: \n";
        std::cin >> flightDate;
        unsigned int flightTime = flightDate % 10000;
        flightDate /= 10000;
        int flightYear = flightDate % 10000;
        flightDate /= 10000;
        int flightMonth = flightDate % 100;
        int flightDay = flightDate / 100;
        isLeapYear = flightYear % 4 == 0 && (flightYear % 100 != 0 || flightYear % 400 == 0);
        if ((flightMonth < 1 || flightMonth > 12) ||
            (isLeapYear && flightMonth == 2 && (flightDay < 1 || flightDay > 29)) ||
            ((flightMonth == 1 || flightMonth == 3 || flightMonth == 5 ||
              flightMonth == 7 || flightMonth == 8 || flightMonth == 10 || flightMonth == 12) &&
             (flightDay < 1 || flightDay > 31)) ||
            ((flightMonth == 4 || flightMonth == 6 || flightMonth == 9 ||
              flightMonth == 11) && (flightDay < 1 || flightDay > 30)) ||
            (flightMonth == 2 && (flightDay < 1 || flightDay > 28)) ||
            (flightYear < year) || (flightYear == year &&
                                    (flightMonth < month || (flightMonth == month && flightDay < day))) ||
            (flightYear < 1000 || flightYear > 9999)) {
                std::cout << "Invalid flight date \n";
                return 3;
        }

        int flightTimeMinutes = flightTime % 100;
        int flightTimeHours = flightTime / 100;
        if (flightTimeHours < 0 || flightTimeHours >= 24) {
                std::cout << "Invalid time of the flight \n";
                return 4;
        }
        if (flightTimeMinutes < 0 || flightTimeMinutes >= 59) {
                std::cout << "Invalid time of the flight \n";
                return 5;
        }

        std::cout << "Enter your destination (Number between 0 and 5): \n";
        std::cin >> destination;
        // Validation for destination code
        if (destination < 0 || destination > 5) {
                std::cout << "Invalid destination code \n";
                return 6;
        }

        int age = 0;
        if (flightMonth > month) {
                age = flightYear - year;
        } else if (flightMonth == month) {
                if (flightDay >= day) {
                        age = flightYear - year;
                } else {
                        age = flightYear - year - 1;
                }
        } else {
                age = flightYear - year - 1;
        }

        int discount = 0;
        if (flightTimeHours >= 0 && flightTimeHours < 12 || flightTimeHours == 12 && flightTimeMinutes == 0) {
                discount = 10;
        } else {
                discount = 5;
        }

        if(age == 0) age = 1;

        double ticketPrice = 0.0;
        if (destination == 0) {
                ticketPrice = 200;
                ticketPrice *= age;
                ticketPrice -= discount;
        } else if (destination == 1) {
                ticketPrice = 300;
                ticketPrice *= age;
                ticketPrice -= discount;
        } else if (destination == 2) {
                ticketPrice = 400;
                ticketPrice *= age;
                ticketPrice -= discount;
        } else if (destination == 3) {
                ticketPrice = 500;
                ticketPrice *= age;
                ticketPrice -= discount;
        } else if (destination == 4) {
                ticketPrice = 600;
                ticketPrice *= age;
                ticketPrice -= discount;
        } else if (destination == 5) {
                ticketPrice = 700;
                ticketPrice *= age;
                ticketPrice -= discount;
        }
        std::cout << "\n";

        std::cout << name[0] << name[1] << name[2];
        std::cout << "|";
        day < 10 ? std::cout << "0" << day : std::cout << day;
        std::cout << ".";
        month < 10 ? std::cout << "0" << month : std::cout << month;
        std::cout << "." << year;
        std::cout << "|";
        flightDay < 10 ? std::cout << "0" << flightDay : std::cout << flightDay;
        std::cout << ".";
        flightMonth < 10 ? std::cout << "0" << flightMonth : std::cout << flightMonth;
        std::cout << "." << flightYear;
        std::cout << "|";
        flightTimeHours < 10 ? std::cout << "0" << flightTimeHours : std::cout << flightTimeHours;
        std::cout << ":";
        flightTimeMinutes < 10 ? std::cout << "0" << flightTimeMinutes : std::cout << flightTimeMinutes;
        std::cout << "|";
        std::cout << destination;
        std::cout << "|";
        std::cout << ticketPrice;
        return 0;
}
