#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "Contact.h"
#include "Friend.h"
#include <vector>
#include <algorithm>

class AddressBook {
private:
    std::vector<Contact*> contacts;

public:
    AddressBook();
    ~AddressBook();

    void addContact(Contact* contact);
    void deleteContact(const std::string& name);
    Contact* searchContact(const std::string& name) const;
    std::vector<Friend*> getFriends() const;
};

#endif // ADDRESSBOOK_H
