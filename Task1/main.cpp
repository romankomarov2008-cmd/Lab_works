#include <iostream>
#include <string>

//об'єктно-орієнтоване програмування:
// інкапсуляція - об'єднання всіх полів і методів та робота з ними в одному об'єкті.
// Абстракція - виділення суттєвих характреристик і поведінки об'єкта, приховування деталей
// Наслідування - створення нових класів на основі існуючих для повторного використання коду
using namespace std;
class Person {
protected:
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {}

    virtual ~Person() = default;

    virtual void printInfo() const {
        cout << "Name: " << name << ", Age: " << age;
    }
};

class Student : public Person {
protected:
    string group;
    double grade;
public:
    Student(std::string name, int age, string group, double grade)
        : Person(name, age), group(group), grade(grade) {
    }

    void printInfo() const override {
        cout << "[Student] ";
        cout << " Group: " << group << ", Average grade: " << grade << endl;
    }

};

class Teacher : public Person {
private:
	string subject;
	string degree;
public:
	Teacher(std::string name, int age, string subject, string degree)
		: Person(name, age), subject(subject), degree(degree) {
	}
	void printInfo() const override {
		cout << "[Teacher] ";
		cout << " Subject: " << subject << ", Degree: " << degree << endl;
	}
};

class Postgraduate : public Student {
private:
    string researchTopic;

public:
    Postgraduate(string name, int age, string group, double grade, string researchTopic)
        : Student(name, age, group, grade), researchTopic(researchTopic) {
    }

    void printInfo() const override {
        cout << "[Postgraduate] ";
        Person::printInfo();
        cout << ", Group: " << group << ", Average grade: " << grade
            << ", Research Topic: " << researchTopic << endl;
    }
};

int main() {
    Student s("Олена", 19, "КН-21", 95.5);
    Teacher t("Іван Петрович", 45, "Програмування", "Доцент");
    Postgraduate p("Максим", 24, "АСП-1", 98.0, "Штучний інтелект");

    s.printInfo();
    t.printInfo();
    p.printInfo();

	return 0;
}
