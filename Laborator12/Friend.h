#ifndef FRIEND_H
#define FRIEND_H

#include "Contact.h"
#include <string>

class Friend : public Contact {
private:
    std::string dateOfBirth;
    std::string phoneNumber;
    std::string address;

public:
    Friend(const std::string& name, const std::string& dateOfBirth,
        const std::string& phoneNumber, const std::string& address);

    std::string getDateOfBirth() const;
    std::string getPhoneNumber() const;
    std::string getAddress() const;
    std::string getDetails() const override;
};

#endif // FRIEND_H
