#include "AddressBook.h"
#include "Friend.h"
#include "Acquaintance.h"
#include "Colleague.h"
#include <iostream>

int main() {
    AddressBook agenda;

    Friend* ion = new Friend("Ion Popescu", "12/05/1985", "0722-123-456", "Strada Lalelelor, nr. 10, București");
    Acquaintance* maria = new Acquaintance("Maria Ionescu", "0744-654-321");
    Colleague* george = new Colleague("George Enescu", "0733-555-555", "SoftCorp", "Strada Trandafirilor, nr. 20, Cluj-Napoca");

    agenda.addContact(ion);
    agenda.addContact(maria);
    agenda.addContact(george);


    Contact* rezultatCautare = agenda.searchContact("Maria Ionescu");
    if (rezultatCautare) {
        std::cout << "Contact gasit: " << rezultatCautare->getDetails() << std::endl;
    }
    else {
        std::cout << "Contactul nu a fost gasit." << std::endl;
    }

   
    agenda.deleteContact("Ion Popescu");

    
   std::vector<Friend*> prieteni = agenda.getFriends();
    for (Friend* prieten : prieteni) {
        std::cout << "Prieten: " << prieten->getDetails() << std::endl;
    }

    return 0;
}
