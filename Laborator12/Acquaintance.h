#ifndef ACQUAINTANCE_H
#define ACQUAINTANCE_H

#include "Contact.h"
#include <string>

class Acquaintance : public Contact {
private:
    std::string phoneNumber;

public:
    Acquaintance(const std::string& name, const std::string& phoneNumber)
        : Contact(name), phoneNumber(phoneNumber) {}

    std::string getPhoneNumber() const { return phoneNumber; }
    std::string getDetails() const override {
        return "Nume: " + getName() + ", Telefon: " + phoneNumber;
    }
};

#endif // ACQUAINTANCE_H
