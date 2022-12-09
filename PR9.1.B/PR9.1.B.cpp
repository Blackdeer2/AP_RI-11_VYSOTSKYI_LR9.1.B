#include <iostream> 
#include <string>
#include <iomanip>

using namespace std;


enum Kurs { I, II, III, IV, V, VI };
string kursStr[] = { "I","II","III","IV","V","VI" };

enum Spec { IT, CS, SA, SE };
string specStr[] = { "Inform sys and tec","Computer Science ","System analysis  ","Softwar enginering" };

struct Student
{
	string   prizv;
	Kurs     kurs;
	Spec     spec;
	struct
	{
		double physic;
		double math;
	};
	union
	{
		double prog;
		double ped;
		double num;
	};

};

void Create(Student* s, int N) {
	int kurs;
	int spec;
	for (int i = 0; i < N; i++) {
		cout << "Student number " << i + 1 << " : " << endl;
		cin.get();
		cin.sync();

		cout << "    Surname: "; getline(cin, s[i].prizv);
		cout << "    Course (0 - I, 1 - II, 2 - III, 3 - IV, 4 - V, 5 - VI): ";
		cin >> kurs;

		cout << " Specialty (0 - Information systems and technologies, 1 - Computer Science, 2 - System analysis, 3 - Software engineering): ";
		cin >> spec;

		cout << " Assessment in physics : "; cin >> s[i].physic;
		cout << " Assessment in math : "; cin >> s[i].math;
		//cout << " Assessment in programmingі : "; cin >> s[i].prog;
		//cout << " Assessment in pedagogyі : "; cin >> s[i].ped;
		//cout << " Assessment in numerical methodsі : "; cin >> s[i].num;

		s[i].kurs = (Kurs)kurs;
		s[i].spec = (Spec)spec;
		switch (s[i].spec) {
		case IT:
			cout << " Assessment in programmingі : "; cin >> s[i].prog;
			break;
		case CS:
			cout << " Assessment in pedagogyі : "; cin >> s[i].ped;
			break;
		case SA:
		case SE:
			cout << " Assessment in numerical methodsі : "; cin >> s[i].num;
			break;
		}
	}
}

void Print(Student* s, int N) {

	cout << "======================================================================================================================================="
		<< endl;
	cout << "|  №  |   Surname   |   Course   |        Specialty         |   Physics   |   Math   |   Programming   |   Pedagogy   |   Numerical   |"
		<< endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------"
		<< endl;

	for (int i = 0; i < N; i++) {
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(13) << left << s[i].prizv
			<< "| " << setw(11) << left << kursStr[s[i].kurs]
			<< "|    " << setw(4) << right << specStr[s[i].spec] << "    "
			<< "| " << setw(11) << s[i].physic
			<< "| " << setw(10) << s[i].math;
		/*<< "| " << setw(16) << s[i].prog << "|"
		<< "| " << setw(16) << s[i].ped << "|"
		<< "| " << setw(16) << s[i].num << "|";*/
		switch (s[i].spec) {
		case IT:
			cout << "| " << setw(16) << s[i].prog << "|" << setw(14) << "|" << setw(15) << "|";
			break;
		case CS:
			cout << "| " << setw(17) << "|" << setw(15) << s[i].ped << "|" << setw(15) << "|";
			break;
		case SA:
		case SE:
			cout << "| " << setw(17) << "|" << setw(15) << "|" << setw(15) << s[i].num << "|";
			break;
		}
		cout << endl;
	}
	cout << "======================================================================================================================================="
		<< endl;
	cout << endl;
}
void Excellent(Student* s, int N) {
	for (int i = 0; i < N; i++)
	{
		//if (s[i].spec == IT || s[i].spec == CS || s[i].spec == SA || s[i].spec == SE) {
		if (s[i].physic == 5 && s[i].math == 5 && s[i].prog == 5) {
			cout << " " << s[i].prizv << ",";
		}
		//}
	}

}
double Average(Student* s, int N) {
	double aver = 0;
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		aver = (s[i].physic + s[i].math + s[i].prog) / 3.;
		if (aver >= 4.5) {
			k++;
		}
		aver = 0;
	}
	return 100. * k / N;
}
int main() {
	int N;
	cout << "Input count of student N: "; cin >> N;
	Student* s = new Student[N];
	Create(s, N);
	Print(s, N);
	cout << "Names of students who are excellent students :";
	Excellent(s, N); cout << endl;
	cout << "Percentage of students with an average score greater than 4.5 = " << Average(s, N) << "%";

	return 0;
}