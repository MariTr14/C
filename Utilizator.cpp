#include <iostream>
#include <string>
#include <map>
using namespace std;
class User {
private:
    string location;
    map<string, int> skills;
public:
    string username;
    string email;

    User() {
        this->location = "unset";
        this->username = "";
        this->email = "";
    }
    User(string username, string email) {
        this->username = username;
        this->email = email;
        this->location = "unset";
    }

    string getLocation() {
        return this->location;
    }

    void setLocation(string location) {
        this->location = location;
    }

    void info() {
        cout << "Utilizator: " << this->username << endl;
        cout << "Email: " << this->email << endl;
        cout << "Locatie: " << this->location << endl;
    }

    void learn(string skill) {
        skills[skill]++;
    }
    void showSkills() {
        for (auto skill : skills) {
            cout << skill.first << ": " << skill.second << endl;
        }
    }
    void clearSkill(string existingSkill) {
        skills.erase(existingSkill);
    }

    int calculateSalary() {
        int sum_levels = 0;
        for (auto skill : skills) {
            sum_levels += skill.second;
        }
        return sum_levels * 100;
    }
};

int main() {
    cout << "===========Utilizatori===============" << endl;

    User u1("Maria", "maria@mail.ro");
    u1.setLocation("Romania");
    u1.info();
    cout << endl;

    u1.learn("C++");
    u1.learn("C++");
    u1.learn("C++");
    u1.learn("C++");

    u1.learn("C#");
    u1.learn("C#");

    u1.learn("Python");

    u1.learn("Java");

    cout << "Competente: " << endl;
    u1.showSkills();

    cout << "Salariul: " << u1.calculateSalary() << endl;
    cout << endl;
    cout << "=========================" << endl;

    User u2("Ana", "ana@mail.es");

    u2.info();
    cout << endl;

    cout << "Adaugare tara: " << endl;
    u2.setLocation("Spania");
    cout << "Locatie noua: " << u2.getLocation() << endl;
    cout << endl;

    u2.learn("Python");
    u2.learn("Python");
    u2.learn("Python");

    u2.learn("C++");

    u2.learn("HTML");
    u2.learn("HTML");
    u2.learn("HTML");
    u2.learn("HTML");

    cout << "Skills:" << endl;
    u2.showSkills();

    cout << "Salary: " << u2.calculateSalary() << endl;
    cout << endl;

    cout << "Exemplu stergere competente: " << endl;
    u2.clearSkill("Python");
    cout << "Skills dupa stergere:" << endl;
    u2.showSkills();
}