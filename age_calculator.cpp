#include <iostream>
#include <ctime>

int main(void) {
    time_t currentTime = time(nullptr);
    tm* localTime = localtime(&currentTime);

    std::cout << "Enter your birthdate (MM DD YYYY): ";
    int month, day, year;
    std::cin >> month >> day >> year;

    tm birthdate;
    birthdate.tm_mon = month - 1;
    birthdate.tm_mday = day;
    birthdate.tm_year = year - 1900;

    time_t birthdateTime = mktime(&birthdate);
    double diff = difftime(currentTime, birthdateTime);

    int ageInSeconds = (int) diff;
    int ageInMinutes = ageInSeconds / 60;
    int ageInHours = ageInMinutes / 60;
    int ageInDays = ageInHours / 24;
    int ageInWeeks = ageInDays / 7;
    int ageInMonths = (localTime->tm_year - birthdate.tm_year) * 12 + (localTime->tm_mon - birthdate.tm_mon);
    int ageInYears = ageInMonths / 12;

    std::cout << "Your age is: " << std::endl;

    switch (true) {
        case (ageInSeconds >= 60):
            std::cout << ageInSeconds / 60 << " minutes " << ageInSeconds % 60 << " seconds" << std::endl;
        case (ageInMinutes >= 60):
            std::cout << ageInMinutes / 60 << " hours " << ageInMinutes % 60 << " minutes" << std::endl;
        case (ageInHours >= 24):
            std::cout << ageInHours / 24 << " days " << ageInHours % 24 << " hours" << std::endl;
        case (ageInDays >= 7):
            std::cout << ageInWeeks << " weeks " << ageInDays % 7 << " days" << std::endl;
        case (ageInMonths >= 12):
            std::cout << ageInYears << " years " << ageInMonths % 12 << " months" << std::endl;
        default:
            std::cout << ageInMonths << " months " << ageInDays % 30 << " days" << std::endl;
    }
}
