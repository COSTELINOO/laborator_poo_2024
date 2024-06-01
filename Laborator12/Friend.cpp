#include "Friend.h"


Friend::Friend(const std::string& name, const std::string& dateOfBirth,
    const std::string& phoneNumber, const std::string& address)
    : Contact(name), dateOfBirth(dateOfBirth), phoneNumber(phoneNumber), address(address) {}


std::string Friend::getDateOfBirth() const {
    return dateOfBirth;
}


std::string Friend::getPhoneNumber() const {
    return phoneNumber;
}


std::string Friend::getAddress() const {
    return address;
}


std::string Friend::getDetails() const {
    return "Nume: " + getName() + ", Data nasterii: " + dateOfBirth +
        ", Telefon: " + phoneNumber + ", Adresa: " + address;
}
