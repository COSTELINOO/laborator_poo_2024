#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
private:
    std::string name;

public:
    Contact(const std::string& name) : name(name) {}
    virtual ~Contact() {}

    std::string getName() const { return name; }

    
    virtual std::string getDetails() const = 0;
};

#endif // CONTACT_H
