#include "array.h"
int main() {
    try {
       
        Array<int> arr(10);
        arr += 5;
        arr += 2;
        arr += 9;
        arr += 1;
        arr += 7;

        // Afișăm elementele inițiale
        cout << "Elementele initiale: ";
        for (int i = 0; i < arr.GetSize(); ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // Sortăm array-ul
        arr.Sort();
        cout << "Elementele dupa sortare: ";
        for (int i = 0; i < arr.GetSize(); ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // Inserăm un element la o poziție specifică
        arr.Insert(2, 3);
        cout << "Elementele dupa inserare: ";
        for (int i = 0; i < arr.GetSize(); ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // Ștergem un element la o poziție specifică
        arr.Delete(4);
        cout << "Elementele dupa stergere: ";
        for (int i = 0; i < arr.GetSize(); ++i) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // Căutare binară
        int index = arr.BinarySearch(3);
        if (index != -1)
            cout << "Elementul 3 gasit la indexul " << index << endl;
        else
            cout << "Elementul 3 nu a fost gasit" << endl;

        // Căutare liniară
        index = arr.Find(7);
        if (index != -1)
            cout << "Elementul 7 gasit la indexul " << index << endl;
        else
            cout << "Elementul 7 nu a fost gasit" << endl;

        // Utilizare iteratori
        cout << "Elementele folosind iteratori: ";
       
        for (auto it = arr.GetBeginIterator(); it != arr.GetEndIterator(); ++it) {
            cout << *(it.GetElement()) << " ";
       }

        cout << endl;

    }
    catch (const exception& e) {
        cout << "Exceptie: " << e.what() << endl;
    }

    return 0;
}
