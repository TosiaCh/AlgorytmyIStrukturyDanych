#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Proces {
    string id;
    int priority;
    Proces(string id, int priority) : id(id), priority(priority) {}
};

class KolejkaPriorytetowa {
private:
    vector<Proces*> kopiec;

    void podnies(int index) {
        while (index > 0 && kopiec[(index - 1) / 2]->priority < kopiec[index]->priority) {
            swap(kopiec[index], kopiec[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void opusc(int index) {
        int najwiekszy = index;
        int leweDziecko = 2 * index + 1;
        int praweDziecko = 2 * index + 2;

        if (leweDziecko < kopiec.size() && kopiec[leweDziecko]->priority > kopiec[najwiekszy]->priority)
            najwiekszy = leweDziecko;

        if (praweDziecko < kopiec.size() && kopiec[praweDziecko]->priority > kopiec[najwiekszy]->priority)
            najwiekszy = praweDziecko;

        if (najwiekszy != index) {
            swap(kopiec[index], kopiec[najwiekszy]);
            opusc(najwiekszy);
        }
    }

public:
    
    void dodaj(Proces* proces) {
        kopiec.push_back(proces);
        podnies(kopiec.size() - 1);
    }

    Proces* usun() {
        if (kopiec.empty()) {
            return nullptr;
        }

        Proces* pierwszy = kopiec[0];
        kopiec[0] = kopiec.back();
        kopiec.pop_back();
        opusc(0);
        return pierwszy;
    }

    Proces* podglad() {
        if (kopiec.empty()) {
            return nullptr;
        }
        return kopiec[0];
    }

    bool czyPusta() {
        return kopiec.empty();
    }
};

int main() {
    string polecenie;
    KolejkaPriorytetowa kp;

    while (cin >> polecenie) {
        if (polecenie == "ADD") {
            string id;
            int priorytet;
            cin >> id >> priorytet;
            Proces* nowyProces = new Proces(id, priorytet);
            kp.dodaj(nowyProces);
        } else if (polecenie == "REMOVE") {
            if (kp.czyPusta()) {
                cout << "EMPTY" << endl;
            } else {
                Proces* pierwszy = kp.usun();
                cout << pierwszy->id << endl;
                delete pierwszy;
            }
        } else if (polecenie == "PEEK") {
            if (kp.czyPusta()) {
                cout << "EMPTY" << endl;
            } else {
                Proces* pierwszy = kp.podglad();
                cout << pierwszy->id << endl;
            }
        }
    }

    return 0;
}
