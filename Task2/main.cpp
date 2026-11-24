#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>


using namespace std;
class Person {
private:
    std::string name;

public:
    explicit Person(std::string name) {
		if (name.empty()) {
			throw std::invalid_argument("Name cannot be empty.");
		}
		this->name = name;
	}

    virtual ~Person() = default;

	const std::string& getName() const {
		return name;
	}

	virtual std::string role() const {
		return "Person";

    }

    virtual std::string status() const {
		return "N/A";

    }
};

class Student : public Person {
private:
	int course;
	double grade;
public:
	Student(const std::string& name, int course, double grade)
		: Person(name) {
		if (course < 1 || course > 6) {
			throw std::invalid_argument("Course must be between 1 and 6.");
		}

		if (grade < 0.0 || grade > 100.0) {
			throw std::invalid_argument("Grade must be between 0.0 and 100.0.");
		}

		this->course = course;
		this->grade = grade;
	}

	int getCourse() const {
		return course;
	}

	double getGrade() const {
		return grade;
	}

	std::string role() const override {
		return "Student";
	}

	std::string status() const override {
		return (grade >= 60.0) ? "PASS" : "FAIL";
	}
};

class GraduateStudent : public Student {
public:
	GraduateStudent(const std::string& name, int course, double grade)
		: Student(name, course, grade) {
	}
	std::string role() const override {
		return "Graduate Student";
	}
};
class Teacher : public Person {

private:
	string subject;
	string degree;
public:
	explicit Teacher(const std::string& name)
		: Person(name) {}
	std::string role() const override {
		return "Teacher";
	}

	std::string status() const override {
		return "N/A";
	}
};

int main() {
	try {
		std::vector<std::unique_ptr<Person>> people;

		people.push_back(std::make_unique<Student>("Alice", 2, 85.5));
		people.push_back(std::make_unique<GraduateStudent>("Bob", 3, 92.0));
		people.push_back(std::make_unique<Teacher>("Dr. Smith"));
		people.push_back(std::make_unique<Student>("Charlie", 1, 55.0));
		people.push_back(std::make_unique<Student>("Diana", 4, 78.0));

		std::stable_sort(people.begin(), people.end(),
			[](const std::unique_ptr<Person>& a, const std::unique_ptr<Person>& b) {
			return a->getName() < b->getName();
			});

		for (const auto& person : people) {
		cout << "Name: " << person->getName() << ", Role: " << person->role() << ", Status: " << person->status() << endl;
		}
	}
	catch (const std::invalid_argument& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}







