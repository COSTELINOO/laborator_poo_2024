#include "AddressBook.h"
#include "Friend.h"
#include "Acquaintance.h"
#include "Colleague.h"
#include <iostream>
#include <algorithm>

AddressBook::AddressBook() {
    std::cout << "Constructor AddressBook" << std::endl;
}

AddressBook::~AddressBook() {
    std::cout << "Destructor AddressBook" << std::endl;
    for (Contact* contact : contacts) {
        std::cout << "Stergerea contactului: " << contact->getName() << std::endl;
        delete contact;
    }
}

void AddressBook::addContact(Contact* contact) {
    std::cout << "Adaugare contact: " << contact->getName() << std::endl;
    contacts.push_back(contact);
}

void AddressBook::deleteContact(const std::string& name) {
    std::cout << "Stergere contact: " << name << std::endl;

    for (auto it = contacts.begin(); it != contacts.end(); ) {
        if ((*it)->getName() == name) {
            std::cout << "Stergerea contactului: " << (*it)->getName() << std::endl;
            delete* it; 
            it = contacts.erase(it); 
            std::cout << "Contact sters cu succes: " << name << std::endl;
        }
        else {
            ++it; 
        }
    }
}

Contact* AddressBook::searchContact(const std::string& name) const {
    std::cout << "Cautare contact: " << name << std::endl;
    for (Contact* contact : contacts) {
        if (contact->getName() == name) {
            std::cout << "Contact gasit: " << name << std::endl;
            return contact;
        }
    }
    std::cout << "Contactul nu a fost găsit: " << name << std::endl;
    return nullptr;
}

std::vector<Friend*> AddressBook::getFriends() const {
    std::cout << "Obtinerea listei de prieteni" << std::endl;
    std::vector<Friend*> friends;
    for (Contact* contact : contacts) {
        if (Friend* friendContact = dynamic_cast<Friend*>(contact)) {
            std::cout << "Prieten gasit: " << friendContact->getName() << std::endl;
            friends.push_back(friendContact);
        }
    }
    return friends;
}
