#include <iostream>
#include <string>
#include <vector>
#include <functional>

class Patient;
class Doctor {
private:

	std::string m_name{};
	std::vector<std::reference_wrapper<const Patient>> m_patients{};

public:

	Doctor(const std::string& name) : m_name{ name }
	{
		std::cout << "Doctor constructor has been used.\n";
	}

	void addPatient(Patient& patient);

	friend std::ostream& operator<<(std::ostream& out, const Doctor& doctor);

	const std::string &getName() const
	{
		return m_name;
	}
};

class Patient {
private:

	std::string m_name{};
	std::vector<std::reference_wrapper<const Doctor>> m_doctors{};

	void addDoctor(Doctor& doctor)
	{
		m_doctors.push_back(doctor);
	}

public:
	Patient(const std::string& name) : m_name{ name }
	{
		std::cout << "Patient constructor has been used.\n";
	}

	friend void Doctor::addPatient(Patient& patient);

	friend std::ostream& operator<<(std::ostream& out, const Patient& patient);

	const std::string& getName() const
	{
		return m_name;
	}

};

void Doctor::addPatient(Patient& patient)
{
	m_patients.push_back(patient);
	patient.addDoctor(*this);
}

std::ostream& operator<<(std::ostream& out, const Patient& patient)
{
	if (patient.m_doctors.empty())
	{
		out << patient.getName() << " has no doctors right now.\n";
	}
	else
	{
		out << patient.getName() << " is seeing doctors: ";
		for (auto &doctor : patient.m_doctors)
		{
			out << doctor.get().getName() << ' ';
		}
		out << '\n';
	}
	return out;
}
std::ostream& operator<< (std::ostream& out, const Doctor& doctor)
{
	if (doctor.m_patients.empty())
	{
		out << doctor.getName() << " has no patients right now.\n";
	}
	else
	{
		out << doctor.getName() << " is seeing patients: ";
		for (auto& patient : doctor.m_patients)
		{
			out << patient.get().getName() << ' ';
		}
		out << '\n';
	}
	return out;
}

int main() {
	Patient bob{ "Bob" };
	Patient sam{ "Sam" };
	Doctor who{ "Who" };
	std::cout << "First test:\n";
	std::cout << bob;
	std::cout << who;
	
	who.addPatient(bob);
	std::cout << "Second test:\n";
	std::cout << bob;
	std::cout << who;

	return 0;
}