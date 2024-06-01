#ifndef COLLEAGUE_H
#define COLLEAGUE_H

#include "Contact.h"
#include <string>

class Colleague : public Contact {
private:
    std::string phoneNumber;
    std::string company;
    std::string address;

public:
    Colleague(const std::string& name, const std::string& phoneNumber,
        const std::string& company, const std::string& address)
        : Contact(name), phoneNumber(phoneNumber), company(company), address(address) {}

    std::string getPhoneNumber() const { return phoneNumber; }
    std::string getCompany() const { return company; }
    std::string getAddress() const { return address; }
    std::string getDetails() const override {
        return "Nume: " + getName() + ", Telefon: " + phoneNumber +
            ", Companie: " + company + ", Adresa: " + address;
    }
};

#endif // COLLEAGUE_H
