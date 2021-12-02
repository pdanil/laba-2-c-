/*�������� ����� Fraction ��� ������������� ������������ ������ (��� ��������� ���� ����� ����� x/y). 
����������� ��������� +, -, *, / ��� ������. ����������� ����� void reduce() ��� ���������� �����, � ����� ����������� ������:
- int gcd(int n, int m) ������� ��� ���������� ����������� ������ �������� ����� n � m;
- void printAsFraction(double decimal_fraction)
- void printAsFraction(char* decimal_fraction)
������������� ������ ������ ���������� ����� � ���� ������������ 
(��������, ��� �������� decimal_fraction = 0.43 �� ������ ������ ��������� 43/100, ��� 0.25 � 1/4 � �.�.).
����� ����������� � ���� ������������ ����� ������ ������� ���� ��������� �� ������ ������ � ��������� ����������� ������.
������������������ ������ ���������� ������. ������� ��������� �������� ������. 
���������� �������� ��������, ���������, ��������� � ������� ������. 
������� �� ����� ����������. �������� ����� ���������� ������ ����������� ������� ������.
*/

#include <iostream>
#include "Fraction.h"
using namespace std;
#include <conio.h> // for using getch()


int main() {
	Fraction fract;

	//�������� ������� Enter(��� - 13), Space(��� - 32), 1(��� - 49), 2(��� - 50)
	while (true) {
		cout << " Press 1 to do ordinary fraction, reduce it and count GCD\n";
		cout << " Press 2 to transform decimal fraction to ordinary by DOUBLE\n";
		cout << " Press 3 to transform decimal fraction to ordinary by CHAR*\n";
		cout << " Press 4 to show mathematical operations on fractions\n";
		cout << " Press 'ENTER' to EXIT, press ANY KEY to continue\n\n";
		int x = _getch();
		if (x == 49) {
			cout << " You pressed 1\n\n";

			cout << "\tEnter X = ";
			cin >> fract.x;
			cout << "\tEnter Y = ";
			cin >> fract.y;

			cout <<"\n\tNumber of the created fraction - " << fract.s_counter();

			cout << "\n\n\tOrdinary fraction: " << fract.x << " / " << fract.y << "\n";
			fract.reduce(); 
			cout << "\tReduced fraction: " << fract.x << " / " << fract.y << "\n";
			cout << "\tGCD: " << fract.gcd() << "\n\n"; //���������� ����� �������� ����� n � m
			fract.gcdNull();
		}

		if (x == 50) {
			cout << " You pressed 2\n\n";

			double decimal_fraction;
			cout << "\tEnter a decimal fraction: ";
			cin >> decimal_fraction;
			cout << "\n\tNumber of the created fraction - " << fract.s_counter();
			fract.printAsFraction(decimal_fraction);
		}

		if (x == 51) {
			cout << " You pressed 3\n\n";

			char decimal_fraction[255];
			cout << "\tEnter a decimal fraction: ";
			cin >> decimal_fraction;
			cout << "\n\tNumber of the created fraction - " << fract.s_counter();
			fract.printAsFraction(decimal_fraction);
		}

		if (x == 52) {
			cout << " You pressed 4\n\n";

			Fraction fr;
			cout << "\tEnter data for first fraction:\n";
			cout << "\tEnter X = ";
			cin >> fr.x;
			cout << "\tEnter Y = ";
			cin >> fr.y;
			cout << "\n\tNumber of the created fraction - " << fr.s_counter();
			cout << "\n\tFirst fraction: " << fr.x << " / " << fr.y << "\n\n\n";
			
			cout << "\tEnter data for second fraction:\n";
			cout << "\tEnter X = ";
			cin >> fr.x1;
			cout << "\tEnter Y = ";
			cin >> fr.y1;
			cout << "\n\tNumber of the created fraction - " << fr.s_counter();
			cout << "\n\tSecond fraction: " << fr.x1 << " / " << fr.y1 << "\n\n\n";

			cout << "\tOperator + : "; 
			fr.operator+(); 
			cout << "\tOperator - : "; 
			fr.operator-();
			cout << "\tOperator * : ";
			fr.operator*();
			cout << "\tOperator / : ";
			fr.operator/(1);

			cout << "\n\n";
		}

		if (x == 13) {
			exit(0);
		}
	}

	system("pause");
	return 0;
}