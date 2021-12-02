#include "Student.h"
#include <iostream>
#include <fstream> // for using file input/output
using namespace std;

static char numOfStudent = 49; // code 49 = '1'
static char numOfStudentRead = 49;

const size_t S = 3; // ���-�� ������ (s -> sessions)
const size_t M = 4; // ���-�� ������� �� ������ ������ (m -> marks)
const size_t COM = M * S; // com - common


//����������� ��� ����������
Student::Student() {
	fio_ = "";
	gender_ = "";
	yearOfBirth_ = 0;
	yearOfEntrance_ = 0;
	numOfCreditBook_ = 0;
	avarageMark_ = 0;
}

//����������� � �����������
Student::Student(string fullName, string gender, size_t yearOfBirth,
	size_t yearOfEntrance, long numOfCreditBook, double avarageMark) {
	fio_ = fullName;
	gender_ = gender;
	yearOfBirth_ = yearOfBirth;
	yearOfEntrance_ = yearOfEntrance;
	numOfCreditBook_ = numOfCreditBook;
	avarageMark_ = avarageMark;
}


//�������
void Student::setFio(const string& fio) {
	fio_ = fio;
}
void Student::setGender(const string& gender) {
	gender_ = gender;
}
void Student::setYearOfBirth(const size_t& yearOfBirth){
	yearOfBirth_ = yearOfBirth;
}
void Student::setYearOfEntrance(const size_t& yearOfEntrance){
	yearOfEntrance_ = yearOfEntrance;
}
void Student::setNumOfCreditBook(const long& numOfCreditBook){
	numOfCreditBook_ = numOfCreditBook;
}
void Student::setAvarageMark(const double& avarageMark){
	avarageMark_ = avarageMark;
}


//�������
string Student::getFio() const{
	return fio_;
}
string Student::getGender() const {
	return gender_;
}
size_t Student::getYearOfBirth() const {
	return yearOfBirth_;
}
size_t Student::getYearOfEntrance() const {
	return yearOfEntrance_;
}
long Student::getNumOfCreditBook() const {
	return numOfCreditBook_;
}
double Student::getAvarageMark() const {
	return avarageMark_;
}


//lab's metods
void Student::serialize() { //���������� ������ ������ � txt-����
	string txt = ".txt";
	string filename = numOfStudent + txt;

	ofstream outf(filename); // ����� ofstream ������������ ��� ������ ������ � ����.
	outf << "  ���:  " << getFio() << endl;
	outf << "  ���: " << getGender() << endl;
	outf << "  ��� ��������: " << getYearOfBirth() << endl;
	outf << "  ��� �����������: " << getYearOfEntrance() << endl;
	outf << "  ����� �������: " << getNumOfCreditBook() << endl;
	outf << "  ������� ����: " << getAvarageMark() << endl;

	numOfStudent++; 
}

void Student::serialize(const string& filename) { // ���� �����, ��� ����, �� �����
	ofstream outf(filename); // ����� ofstream ������������ ��� ������ ������ � ����.
	outf << "  ���:  " << getFio() << endl;
	outf << "  ���: " << getGender() << endl;
	outf << "  ��� ��������: " << getYearOfBirth() << endl;
	outf << "  ��� �����������: " << getYearOfEntrance() << endl;
	outf << "  ����� �������: " << getNumOfCreditBook() << endl;
	outf << "  ������� ����: " << getAvarageMark() << endl;
}

void Student::deserialize() {
	string txt = ".txt";
	string filename = numOfStudentRead + txt;

	ifstream inf(filename); // ifstream ������������ ��� ������ ����������� �����.

	while (inf) { // ���� ���� ������, ������� �� ����� ���������, �� ���������� ��, 
		// ��� ����� ���������, � ������, � ����� ������� ��� ������ �� �����
		string strInput;
		getline(inf, strInput);
		cout << strInput << endl;
	}

	numOfStudentRead++;
}

void Student::deserialize(const string& filename) {
	ifstream inf(filename); // ifstream ������������ ��� ������ ����������� �����.
	
	while (inf) { // ���� ���� ������, ������� �� ����� ���������, �� ���������� ��, 
		// ��� ����� ���������, � ������, � ����� ������� ��� ������ �� �����
		string strInput;
		getline(inf, strInput);
		cout << strInput << endl;
	}
}

//my metods
double Student::sessionSimulation() {
	size_t min = 1, max = 5;
	double arr[COM];
	double sumMarks = 0;

	for (size_t i = 0; i < COM; i++) {
		arr[i] = (size_t)((rand() % (max - min + 1)) + min);
		sumMarks += arr[i];
	}

	return sumMarks;
}

double Student::calculAvarageMark() {
	avarageMark_ = sessionSimulation() / COM;
	return getAvarageMark();
}

void Student::printInfo() {
	cout << "  " << getFio() << " - " << getAvarageMark() << endl;
}
