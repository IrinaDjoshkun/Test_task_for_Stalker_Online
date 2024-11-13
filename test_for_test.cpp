#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Contact {
public:
    std::string firstName;
    std::string lastName;
    std::string phoneNumber;

    Contact(const std::string& f_Name, const std::string& l_Name, const std::string& _phone)
        : firstName(f_Name), lastName(l_Name), phoneNumber(_phone) {}

    // Отображение контактов
    void display() const {
        std::cout << firstName << " " << lastName << ": " << phoneNumber << std::endl;
    }
};

class ContactSorting {
private:
    std::vector<Contact> contacts;

public:
    void addContact(const std::string& firstName, const std::string& lastName, const std::string& phoneNumber) {
        contacts.push_back(Contact(firstName, lastName, phoneNumber));
    }

    void sortContacts(int option) {
        switch (option) {
        case 1:  // Если пользователь выбрал сортировку по имени
            std::sort(contacts.begin(), contacts.end(), CompareByFirstName);
            break;
        case 2:  // Если пользователь выбрал сортировку по фамилии
            std::sort(contacts.begin(), contacts.end(), CompareByLastName);
            break;
        case 3:  // Если пользователь выбрал сортировку по номеру телефона
            std::sort(contacts.begin(), contacts.end(), CompareByPhoneNumber);
            break;
        default:
            std::cout << "Invalid sorting option." << std::endl;
        }
    }

    // Сравнение по имени
    static bool CompareByFirstName(const Contact& a, const Contact& b) {
        if (a.firstName != b.firstName) return a.firstName < b.firstName;
        if (a.lastName != b.lastName) return a.lastName < b.lastName;
        return a.phoneNumber < b.phoneNumber;
    }

    // Сравнение по фамилии
    static bool CompareByLastName(const Contact& a, const Contact& b) {
        if (a.lastName != b.lastName) return a.lastName < b.lastName;
        if (a.firstName != b.firstName) return a.firstName < b.firstName;
        return a.phoneNumber < b.phoneNumber;
    }

    // Сравнение по номеру телефона
    static bool CompareByPhoneNumber(const Contact& a, const Contact& b) {
        if (a.phoneNumber != b.phoneNumber) return a.phoneNumber < b.phoneNumber;
        if (a.lastName != b.lastName) return a.lastName < b.lastName;
        return a.firstName < b.firstName;
    }

    // вывод результата на экран
    void displayContacts(int option) const {
        for (const auto& contact : contacts) {
            if (option == 3) {
                std::cout << contact.phoneNumber << ": " << contact.lastName << " " << contact.firstName << std::endl;
            }
            else {
                contact.display();
            }
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    ContactSorting S;

    // Добавление контактов
    S.addContact("Иван", "Иванов", "3515454");
    S.addContact("Иван", "Сидоров", "3515422");
    S.addContact("Олег", "Сидоров", "23515423");
    S.addContact("Иван", "Петров", "3515455");

    // Выбор сортировки пользователем
    int SortOption;
    std::cout << "Чтобы отсортировать по имени выберите - 1, по фамилии - 2, по номеру телефона - 3: ";
    std::cin >> SortOption;

    // Сортировка и отображение результатов
    S.sortContacts(SortOption);
    S.displayContacts(SortOption);

    return 0;
}
