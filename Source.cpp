#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <windows.h>

using namespace std;

//��������� � ���������� �� ����������
	struct Students
	{
		string fakNomer;
		string egn;
		string firstName;
		string secondName;
		string thirdName;
		string discipline[5];
		string gender;
		int age = 0;
		string statut;
		int grades[5];
		double avarageScore; //���������� �����
	};

//������ �� �������� ����
void Menu()
{
	cout << setw(42) << "���� �� ����� �� �������" << endl;
	cout << setfill('-') << setw(60) << "" << endl;
	cout << setfill(' ');
	cout << "1. ������ ������� � ����� \n"
		<< "2. ������ ������ �������� \n"
		<< "3. ������� � ��������� �� �������� � ������ �� �� � � ������� 1 ���������� � ������ ���� 2 \n"
		<< "4. ��������� � ��������� �� �������� \n"
		<< "5. ������ � ������ ���� \n"
		<< "6. ������������ ������� \n"
		<< "7. ����� �� ����������" << endl;
	cout << setfill('-') << setw(60) << "" << endl;
	cout << setfill(' ');
}

//������ �� ���������
void SubMenu()
{
	cout << setw(42) << "������� �� ����� �� �������" << endl;
	cout << setfill('-') << setw(60) << "" << endl;
	cout << setfill(' ');
	cout << "1. �������� �� �������� �� ������ � ������� �� ����� �� ����� ��������\n"
		<< "2. ���������/������������ �� ������ �� ������� \n"
		<< "3. ����������� �� ������ ����� �� ������� \n"
		<< "4. ����� �� ������ �� ������� \n"
		<< "5. ����� �� ��������� \n";
	cout << setfill('-') << setw(60) << "" << endl;
	cout << setfill(' ');
}


//������� �� �������� �� ��������
void addStudents(Students mass[], int N, int& countAddedStudents)
{
	//� ���� ��� ���������� �� ������� ���� ����������, ����� ��� ���������, � �� ��������� �������� �����
	int disciplina;
	int grade;
	int allGrades = 0;
	//���� ���������� �� �������� �� �����, ����� ����� ��� �� ��������� � 1, ������ �� ������ ��� ������� 
	int currentCount = countAddedStudents;

	//for-�����, ����� ����� �� ��������� �� ����������� ���� �������� ��������. ���� ���� �� �������� ������� �� ����� �������
	for (int i = countAddedStudents; i < N + countAddedStudents; i++)
	{
		cout << "������ ���������� �����, ���, ����� �����, ����������, ������, ���, ������� � ������ �� ������� ����� " << i + 1 << endl;
		cout << "���������� �����: \n";
		getline(cin, mass[i].fakNomer);
		cin.clear();
		while (mass[i].fakNomer.length() != 8)
		{
			cout << "�� ��� ������ �������� �����. ������������ ����� ������ �� ������� 8 �����. �������� ���������� �����: \n";
			getline(cin, mass[i].fakNomer);
			cin.clear();
		}
		cout << "���: \n";
		getline(cin, mass[i].egn);
		cin.clear();
		while (mass[i].egn.length() != 10)
		{
			cout << "�� ��� ������ �������� �����. ���-�� ������ �� ������� 10 �����. �������� ���: \n";
			getline(cin, mass[i].egn);
			cin.clear();
		}
		cout << "���: \n";
		getline(cin, mass[i].firstName);
		cin.clear();
		cout << "�������: \n";
		getline(cin, mass[i].secondName);
		cin.clear();
		cout << "�������: \n";
		getline(cin, mass[i].thirdName);
		cin.clear();
		cout << "������ ���� ����������: \n";
		cin >> disciplina;
		cin.ignore();
		string listDisciplini[5];
		while (disciplina == 0 || disciplina > 5)
		{
			cout << "�� ��� ������ �������� �����. �������� ���� �� ���������� �� 1 �� 5: \n";
			cin >> disciplina;
			cin.ignore();
		}
		//����� ����� for, � ����� ��������� ������ ���������� � �������� ��� ���
		for (int j = 0; j < disciplina; j++)
		{
			cout << "��� �� ������������ (�������� �� ����������: ��(BP), ��(WD), ��(EL), ��(SP), ��(MT)): \n";
			getline(cin, listDisciplini[j]);
			mass[i].discipline[j] = listDisciplini[j];
			cin.clear();
			cout << "������ ������ �� ������������ (0(���� �����a) ��� �� 2 �� 6): \n";
			cin >> grade;
			allGrades += grade;
			while (grade < 0 || grade > 6 || grade == 1)
			{
				cout << "�� ��� ������ �������� �����. �������� ������ 0(���� �����a) ��� �� 2 �� 6: \n";
				cin >> grade;
			}
			mass[i].grades[j] = grade;
			cin.ignore();
		}
		mass[i].avarageScore = allGrades / disciplina;
		cout << "��� (male/female): \n";
		getline(cin, mass[i].gender);
		cin.clear();
		while (mass[i].gender != "male" && mass[i].gender != "female")
		{
			cout << "�� ��� ������ �������� �����. �������� ��� male ��� female: \n";
			getline(cin, mass[i].gender);
			cin.clear();
		}
		cout << "�������: \n";
		cin >> mass[i].age;
		cin.ignore();
		cout << "������ (active/dropped out/graduated): \n";
		getline(cin, mass[i].statut);
		cin.clear();
		while (mass[i].statut != "active" && mass[i].statut != "dropped out" && mass[i].statut != "graduated")
		{
			cout << "�� ��� ������ �������� ������. �������� ������: \n";
			getline(cin, mass[i].statut);
			cin.clear();
		}
		cin.clear();
		currentCount++;
	}
	//����������� ���������� �� currentCount �� countAddedStudents, �� �� ����� ������� ������ � ������� �� ���������� ����� � �������
	//�������� ��� countAddedStudents �� ����� ��� ���������, �� �� ���� ���������� � �� �� ������.
	countAddedStudents = currentCount;
}

//������ �� ��������� � ���������� �� ������ ��������
void tableDesign()
{
	const int width = 170;
	const int columnWidth = 20;

	cout << endl << setw(width) << setfill('-') << "" << setfill(' ');
	cout << endl << "|"
		<< setw(columnWidth) << left << "���. NO" << "|"
		<< setw(columnWidth) << left << "���" << "|"
		<< setw(columnWidth) << right << "���" << "|"
		<< setw(columnWidth) << right << "�������" << "|"
		<< setw(columnWidth) << right << "�������" << "|"
		<< setw(columnWidth) << right << "���" << "|"
		<< setw(columnWidth) << right << "�������" << "|"
		<< setw(columnWidth) << right << "������" << "|";
	cout << endl << setw(width) << setfill('-') << "" << setfill(' ') << endl;
}

//��������� �� ������ �������� � �������
void print(Students mas[], int& countAddedStudents)
{
	const int columnWidth = 20;
	cout << "���������� � �������: \n";

	tableDesign();
	for (int i = 0; i < countAddedStudents; i++)
	{
		cout << endl << "|"
			<< setw(columnWidth) << left << mas[i].fakNomer << "|" << setfill(' ')
			<< setw(columnWidth) << left << mas[i].egn << "|"
			<< setw(columnWidth) << right << mas[i].firstName << "|"
			<< setw(columnWidth) << right << mas[i].secondName << "|"
			<< setw(columnWidth) << right << mas[i].thirdName << "|"
			<< setw(columnWidth) << right << mas[i].gender << "|"
			<< setw(columnWidth) << right << mas[i].age << "|"
			<< setw(columnWidth) << right << mas[i].statut << "|" << endl;
	}
}

//��������� �� �������� � ������ �� ����������
void printWithoutTable(Students mas[], int& countAddedStudents)
{
	for (int i = 0; i < countAddedStudents; i++)
	{
		//� arrayLength �� ��������� ����� �������� ��� � discipline, ���� ������� ���� ������� �� ����� ����� �� ��������� �� ���� ������� �� ������ � ����������
		int arrayLength = sizeof(mas[i].discipline) / sizeof(mas[0].discipline[0]);
		cout << mas[i].fakNomer << " " << mas[i].egn << " " << mas[i].firstName << " " << mas[i].secondName << " " << mas[i].thirdName << " ";
		for (int j = 0; j < arrayLength; j++)
		{
			if (mas[i].discipline[j] == "")
			{
				continue;
			}
			cout << mas[i].discipline[j] << " " << mas[i].grades[j] << " ";
		}

		cout << mas[i].gender << " " << mas[i].age << " " << mas[i].statut << endl;
	}
}

//��������� �� ������ ����� �� ����������� ��������
void printSorting(Students mas[], int& countAddedStudents)
{
	for (int i = 0; i < countAddedStudents; i++)
	{
		int arrayLength = sizeof(mas[i].discipline) / sizeof(mas[0].discipline[0]);
		cout << mas[i].fakNomer << " " << mas[i].egn << " " << mas[i].firstName << " " << mas[i].secondName << " " << mas[i].thirdName << " ";
		for (int j = 0; j < arrayLength; j++)
		{
			if (mas[i].discipline[j] == "")
			{
				continue;
			}
			cout << mas[i].discipline[j] << " " << mas[i].grades[j] << " ";
		}

		cout << mas[i].gender << " " << mas[i].age << " " << mas[i].statut << endl;
	}
}

//��������� �� ���������� �� ����� ��� ��� �������� ���
void sorting(Students mas[], int& countAddedStudents)
{
	//���������� �� ���� �� �����������, � ����� �������� �� ������������ �����
	Students temp;
	//��������� �� ��� �����, � ����� �� ������� ����������� ��������
	Students masCopy[30];
	for (int i = 0; i < countAddedStudents; i++)
	{
		masCopy[i] = mas[i];
	}

	//�������� ��������� �� ������ ���� ����� ��������� �� ����� ����� �� ��������� �� ���� �� ���������� � ����
	int arrayLength = sizeof(masCopy) / sizeof(masCopy[0]);
	//��������� ���� ����� �� ���������
	for (int i = 0; i < countAddedStudents; i++)
	{
		for (int j = countAddedStudents - 1; j > i; j--)
		{
			if (masCopy[j - 1].firstName > masCopy[j].firstName)
			{
				temp = masCopy[j - 1];
				masCopy[j - 1] = masCopy[j];
				masCopy[j] = temp;
			}
		}
	}
	cout << "����������� �������� �� ���: " << endl;
	printSorting(masCopy, countAddedStudents);
}

//��������� �� ���������� �� ���������� �����
void sortByFakNomer(Students mas[], int& countAddedStudents)
{
	//���������� �� ���� �� �����������, � ����� �������� �� ������������ �����
	Students temp;
	//��������� �� ��� �����, � ����� �� ������� ����������� ��������
	Students masCopy[30];
	for (int i = 0; i < countAddedStudents; i++)
	{
		masCopy[i] = mas[i];
	}

	//�������� ��������� �� ������ ���� ����� ��������� �� ����� ����� �� ��������� �� ���� �� ���������� � ����
	int arrayLength = sizeof(masCopy) / sizeof(masCopy[0]);

	for (int j = 0; j < countAddedStudents; j++)
	{
		if (masCopy[j].fakNomer > masCopy[j + 1].fakNomer && j + 1 < countAddedStudents)
		{
			temp = masCopy[j];
			masCopy[j] = masCopy[j + 1];
			masCopy[j + 1] = temp;
		}
	}
	printSorting(masCopy, countAddedStudents);
}

//��������� �� ���������� �� ���
void sortByEGN(Students mas[], int& countAddedStudents)
{
	//���������� �� ���� �� �����������, � ����� �������� �� ������������ �����
	Students temp;
	//��������� �� ��� �����, � ����� �� ������� ����������� ��������
	Students masCopy[30];
	for (int i = 0; i < countAddedStudents; i++)
	{
		masCopy[i] = mas[i];
	}

	//�������� ��������� �� ������ ���� ����� ��������� �� ����� ����� �� ��������� �� ���� �� ���������� � ����
	int arrayLength = sizeof(masCopy) / sizeof(masCopy[0]);

	for (int j = 0; j < countAddedStudents; j++)
	{
		if (masCopy[j].egn > masCopy[j + 1].egn && j + 1 < countAddedStudents)
		{
			temp = masCopy[j];
			masCopy[j] = masCopy[j + 1];
			masCopy[j + 1] = temp;
		}
	}
	printSorting(masCopy, countAddedStudents);
}

//�������� �� ���������� �� ��������� ������, ������� �� ����������� � ��������� �� ���. �����
void separateStudents(Students mas[], int size, int& countAddedStudents)
{
	//��������� ���������� �� ��� string, � ����� ����������� �� �������� ������� �� ���� ������, �� ����� �� �� ������
	string statut2 = "";
	cout << "�������� ������(active, dropped out, graduated): ";
	getline(cin, statut2);

	//��� �����, � ����� �� �� ����������
	Students masCopy[30];

	//��������� �� �������
	while (statut2 != "active" && statut2 != "dropped out" && statut2 != "graduated")
	{
		cout << "�� ��� ������ ���� ���� �� ����� �������. �������� ������� ������: ";
		cin >> statut2;
		cin.clear();
	}

	for (int i = 0; i < countAddedStudents; i++)
	{
		//�������� ���� ����������� � ������ ������� ������ � ���� ������� ��� ������� �� ��������� � ������� �� ���������� �� ������
		if (statut2 == "active" && mas[i].statut == "active")
		{
			for (int j = 0; j < 30; j++)
			{
				//��������� ���� � ������� �� ���������� ���� ������� �������. ��� firstName � ������ ������ - ����� ������� ������� �����
				if (masCopy[j].firstName == "")
				{
					masCopy[j] = mas[i];
					break;
				}
			}
			//������� size ����� �� �������� �� ����������, ����� �� � ��������� �� ����������� ������
			size++;
		}

		else if (statut2 == "dropped out" && mas[i].statut == "dropped out")
		{
			for (int j = 0; j < 30; j++)
			{
				if (masCopy[j].firstName == "")
				{
					masCopy[j] = mas[i];
					break;
				}
			}
			size++;
		}

		else if (statut2 == "graduated" && mas[i].statut == "graduated")
		{
			for (int j = 0; j < 30; j++)
			{
				if (masCopy[j].firstName == "")
				{
					masCopy[j] = mas[i];
					break;
				}
			}
			size++;
		}
	}

	//��������� ���� ������� � ������ - ��� � ������, ������� �������� ���������
	if (masCopy[0].firstName == "")
	{
		cout << "���� �������� ��� ���������� ������. \n";
	}
	else
	{
		cout << "���������� ��� ������ " << statut2 << ": " << endl;
		sortByFakNomer(masCopy, size);
	}
}

//�������� �� �������� � ����� � �������� (��� -����) � ��������� �� ���.
void separateStudentsByScore(Students mas[], int size, int& countAddedStudents)
{
	int firstInterval(0), secondInterval(0), score(0), count(0);
	cout << "������ ������� ������ �� ��������� �� �����: \n";
	cin >> firstInterval;
	cout << "������ ������� ������ �� ��������� �� �����: \n";
	cin >> secondInterval;

	Students masCopy[30];

	for (int i = 0; i < countAddedStudents; i++)
	{
		//���������� ������ � ������ ���� ����� �������� �� ������
		score = 0;
		count = 0;

		int arrayLength = sizeof(mas[i].discipline) / sizeof(mas[0].discipline[0]);
		for (int j = 0; j < arrayLength; j++)
		{
			//�������� ���� ��� �������� ����������, ��� ���� ���������� �� ����������
			if (mas[i].discipline[j] == "")
			{
				continue;
			}

			//��� ��� �������� ����������, ������ ���1���� �� ������ � �� ��������� count
			score += mas[i].grades[j];
			count++;
		}

		//�������� ���� ������ �� ������� � ����� ���������
		if (score / count >= firstInterval && score / count <= secondInterval)
		{
			for (int k = 0; k < 30; k++)
			{
				if (masCopy[k].firstName == "")
				{
					masCopy[k] = mas[i];
					size++;
					break;
				}
			}
		}
	}

	//��������� ���� ������� � ������ - ��� � ������, ������� �������� ���������
	if (masCopy[0].firstName == "")
	{
		cout << "���� �������� � ����� � ������� ��������. \n";
	}
	else
	{
		cout << "���������� � ����� � ������� ��������: \n";
		sortByEGN(masCopy, size);
	}
}

//������� � ��������� �� �������� � ������ �� �� � ��������� � �������� [min � max]
void studentsInInterval(Students mas[], int& countAddedStudents)
{
	int firstInterval(0), secondInterval(0), count(0);
	cout << "����� �� ����� �������� ���������� � ������ �� �� � ����� ��������, ���� ���� ������ �������� � ���� ���� ������ ���� 2 �� ����� ���������� \n";
	cout << "������ ������� ������ �� �� �� ���������: \n";
	cin >> firstInterval;
	cout << "������ ������� ������ �� �� �� ���������: \n";
	cin >> secondInterval;

	Students masCopy[30];

	for (int i = 0; i < countAddedStudents; i++)
	{
		int arrayLength = sizeof(mas[i].discipline) / sizeof(mas[0].discipline[0]);
		for (int j = 0; j < arrayLength; j++)
		{
			//�������� ���� � �������� �������� ��� �������� ����������
			if (mas[i].discipline[j] == "")
			{
				continue;
			}
			//�������� ���� �������� ���������� � ��
			if (mas[i].discipline[j] == "BP")
			{
				//�������� ���� �������� ������ � ������� ��������
				if (mas[i].grades[j] >= firstInterval && mas[i].grades[j] <= secondInterval)
				{
					for (int k = 0; k < 30; k++)
					{
						if (masCopy[k].firstName == "")
						{
							masCopy[k] = mas[i];
							count++;
							break;
						}
					}
				}
			}
			else
			{
				continue;
			}
		}
	}

	if (masCopy[0].firstName == "")
	{
		cout << "���� �������� � ������ �� �� � ������� ��������. \n";
	}
	else
	{
		cout << "���������� � ������ �� �� � ������� �������� ��: \n";
		printWithoutTable(masCopy, count);
	}
}

//������� � ��������� �� �������� � ������� ���� �������, � ������ ���� 2
void studentsWithFailDiscipline(Students mas[], int& countAddedStudents)
{
	int countStudent(0), count(0);

	Students masCopy[30];

	for (int i = 0; i < countAddedStudents; i++)
	{
		//���������� countStudent �� ����� �������� �� ������
		countStudent = 0;

		int arrayLength = sizeof(mas[i].discipline) / sizeof(mas[0].discipline[0]);
		for (int j = 0; j < arrayLength; j++)
		{
			//�������� ���� �������� � �������� �� 2
			if (mas[i].grades[j] != 2)
			{
				continue;
			}
			else
			{
				for (int k = 0; k < 30; k++)
				{
					//�������� ���� firstName � ������ � ���� ���� ���� ������� �� � ������� � ������
					if (masCopy[k].firstName == "" && countStudent == 0)
					{
						masCopy[k] = mas[i];
						count++;
						countStudent++;
						break;
					}
				}
			}
		}
	}

	if (masCopy[0].firstName == "")
	{
		cout << "���� �������� � ������ ���� 2. \n";
	}
	else
	{
		cout << "���������� � ������ ���� 2: \n";
		printWithoutTable(masCopy, count);
	}
}

//����� �� ������ �� �������
void newStatut(Students mas[], int& countAddedStudents)
{
	cout << "������ ���������� �����, �� ����� ������� ������ �� ��������� �������: \n";
	string fakNomerStudent, newStatut;
	//��������� ������ ����������, � ����� �� ������ �������� �� ����������� �����
	bool fakNomerExists = false;
	getline(cin, fakNomerStudent);
	cin.clear();

	for (int i = 0; i < countAddedStudents; i++)
	{
		//�������� ���� ���������� ������� � ��������� ���������� �����
		if (mas[i].fakNomer == fakNomerStudent)
		{
			fakNomerExists = true;
			break;
		}
	}

	//������� � ������, ��� ���������� ������� � ����� ���������� �����
	if (fakNomerExists)
	{
		for (int i = 0; i < countAddedStudents; i++)
		{
			//�������� ���� ���. ����� �� �������� � ���� ������ ������� � ��������� �� �����������
			if (fakNomerStudent != mas[i].fakNomer)
			{
				continue;
			}

			if (mas[i].statut == "active" || mas[i].statut == "dropped out")
			{
				cout << "������ ����� ������: \n";
				getline(cin, newStatut);
				mas[i].statut = newStatut;
				cout << "������� ���������� ������� �� ��������! \n";
			}
			else
			{
				cout << "��������� � ���� ��������. �� ���� �� ��������� ������� ������. \n";
			}
		}
	}
	else
	{
		cout << "���� �������� � ���� ���������� �����. \n";
	}
}

//���������/������������� �� ������
void newGrade(Students mas[], int& countAddedStudents)
{
	cout << "������ ���������� �����, �� ����� ������� ������ �� ��������� ��������: \n";
	int allGrades = 0;
	int count = 0;
	string fakNomerStudent;
	string disciplineGrade;
	bool fakNomerExists = false;
	getline(cin, fakNomerStudent);
	cin.clear();

	for (int i = 0; i < countAddedStudents; i++)
	{
		//�������� ���� ���������� ������� � ��������� ���������� �����
		if (mas[i].fakNomer == fakNomerStudent)
		{
			fakNomerExists = true;
			break;
		}
	}

	if (fakNomerExists)
	{
		for (int i = 0; i < countAddedStudents; i++)
		{
			int arrayLength = sizeof(mas[i].discipline) / sizeof(mas[0].discipline[0]);

			//�������� ���� ���. ����� �� �������� � ���� ������ ������� � ��������� �� �����������
			if (fakNomerStudent != mas[i].fakNomer)
			{
				continue;
			}

			//��� ��������� � �������
			if (mas[i].statut == "active")
			{
				//������ ����������, � ����� �� �������� ���� � �������� ����������, ����� ��������� �������
				bool disciplineExists = true;
				cout << "�������� ����������, ����� ������ �� ���������: \n";
				getline(cin, disciplineGrade);
				cin.clear();

				for (int j = 0; j < arrayLength; j++)
				{
					if (mas[i].discipline[j] == disciplineGrade)
					{
						disciplineExists = true;
						//������ �������� � �������� �� 0(����� ���� ������)
						if (mas[i].grades[j] != 0)
						{
							cout << "������� �� ���, �� ������ �� ��������� �������� �� ��������?(yes/no) \n";
							string check;
							getline(cin, check);
							cin.clear();
							if (check == "yes")
							{
								int newGrade = 0;
								cout << "������ ������ ������: \n";
								cin >> newGrade;
								mas[i].grades[j] = newGrade;
								break;
							}
							else if (check == "no")
							{
								cout << "��� ��������� �� ��������� �������� �� ��������." << endl;
								break;
							}
						}
						else if (mas[i].grades[j] == 0)
						{
							int newGrade = 0;
							cout << "������ ������ ������: \n";
							cin >> newGrade;
							mas[i].grades[j] = newGrade;
							break;
						}
					}
					else
					{
						disciplineExists = false;
					}
				}
				if (disciplineExists == false)
				{
					cout << "�� ��� ������ ����������, ����� ��������� �������. \n";
				}
				//for-�����, � ����� �� ������� ������ ������ �� ��������, ���� ��������� �� ���
				for (int j = 0; j < arrayLength; j++)
				{
					//�������� ���� ��������, ����� � ����� �������� - ���, ������ ���� �������� ������, �� �������� ����������� �����
					if (mas[i].grades[j] < 0)
					{
						break;
					}
					allGrades += mas[i].grades[j];
					count++;
				}
			}
			else
			{
				cout << "��������� � ���� ��������� ��� ��������. �� ���� �� ��������� �������� ������. \n";
				break;
			}
			//���������� ����� ������ �����
			mas[i].avarageScore = allGrades / count;
		}
	}
	else
	{
		cout << "���� �������� � ���� ���������� �����. \n";
	}

}

//��������� �� ������� ����� �� �������
void avarageGrades(Students mas[], int& countAddedStudents)
{
	cout << "������ ���������� �����, �� ����� ������� ������ �� ������ ������� �����: \n";
	string fakNomerStudent;
	bool fakNomerExists = false;
	getline(cin, fakNomerStudent);
	cin.clear();

	for (int i = 0; i < countAddedStudents; i++)
	{
		if (mas[i].fakNomer == fakNomerStudent)
		{
			fakNomerExists = true;
			break;
		}
	}

	if (fakNomerExists)
	{
		for (int i = 0; i < countAddedStudents; i++)
		{
			int arrayLength = sizeof(mas[i].discipline) / sizeof(mas[0].discipline[0]);

			if (fakNomerStudent != mas[i].fakNomer)
			{
				continue;
			}
			else
			{
				cout << "�������� ����� �� �������� �: " << mas[i].avarageScore << endl;
			}
		}
	}
	else
	{
		cout << "���� �������� � ���� ���������� �����. \n";
	}
}

//��������� �� ���������� ��� ����
void SaveStudentsToFile(Students mas[], int& countAddedStudents)
{
	const string FILE_NAME = "Students.txt";
	ofstream fp(FILE_NAME, ios::out);
	fp << countAddedStudents << endl;

	if (fp.fail())
	{
		cout << "������!" << endl;
		exit(1);
	}

	for (int i = 0; i < countAddedStudents; i++)
	{
		int arrayLength = 0;
		fp << mas[i].fakNomer << endl << mas[i].egn << endl << mas[i].firstName << endl << mas[i].secondName << endl << mas[i].thirdName << endl;
		for (int j = 0; j < 5; j++)
		{
			if (mas[i].discipline[j] != "")
			{
				arrayLength++;
			}
		}
		fp << arrayLength << endl;
		for (int j = 0; j < arrayLength; j++)
		{
			fp << mas[i].discipline[j] << endl << mas[i].grades[j] << endl;
		}
		fp << mas[i].gender << endl << mas[i].age << endl << mas[i].statut << endl;
	}
	cout << "������ � �������� ��� ���� � ���: " << FILE_NAME << endl;
	fp.close();
}

//������ �� ���������� �� ����
void ReadStudentsFromFile(Students mas[], int& countAddedStudents)
{
	int allGrades = 0;
	const string FILE_NAME = "Students.txt";

	ifstream fp(FILE_NAME, ios::in);

	if (fp.fail())
	{
		cout << "������!" << endl;
		exit(1);
	}

	fp >> countAddedStudents;
	fp.ignore();
	for (int i = 0; i < countAddedStudents; i++)
	{
		allGrades = 0;
		int arrayLength = 0;
		getline(fp, mas[i].fakNomer);
		getline(fp, mas[i].egn);
		getline(fp, mas[i].firstName);
		getline(fp, mas[i].secondName);
		getline(fp, mas[i].thirdName);
		fp >> arrayLength;
		fp.ignore();
		for (int j = 0; j < arrayLength; j++)
		{
			getline(fp, mas[i].discipline[j]);
			fp >> mas[i].grades[j];
			fp.ignore();
			allGrades += mas[i].grades[j];
		}
		mas[i].avarageScore = allGrades / arrayLength;
		getline(fp, mas[i].gender);
		fp >> mas[i].age;
		fp.ignore();
		getline(fp, mas[i].statut);
	}
	cout << "������������ � �������� �� ���� � ���: " << FILE_NAME << endl;
	fp.close();
}

//������� �� ��������� �� ����� ���� ����� ��������� �������
void nextCommand()
{
	string next = "";
	cout << "\n��������� ���������� ����� �� ������������, �� �� ����������...\n";
	cin.ignore();
	getline(cin, next);
	system("CLS");
}

int main()
{	//���������� �� ���������� �������� �� ��� �����
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

	//���������� �� ���������� �������� �� ��� ����� � ������ �� ��������� � ������������
	//ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	setlocale(LC_ALL, "");

	int choice, secondChoice, N(0), size(0), countAddedStudents(0);
	string next = "";

	Students student[30];

	//������ �� ���� � �����
	ReadStudentsFromFile(student, countAddedStudents);
	do
	{
		Menu();
		cout << "������ ���� �����: ";
		cin >> choice;
		cin.clear();
		cin.ignore(1000, '\n');

		//��������� �� �����
		while (choice < 1 || choice > 7)
		{
			cout << endl << "�� ��� ������� ���� ���� �� �������� �����. �������� �� ���������� � ������." << endl;
			cout << "\n������ ���� �����: ";
			cin >> choice;
			cin.clear();
			cin.ignore(1000, '\n');
		}

		switch (choice)
		{
		case 1:
			cout << "�������� ���� �������� � �������: ";
			while (N <= 0 || N + countAddedStudents > 30) //�������� ����� �������� �����
			{
				cin >> N;
				if (N <= 0) //�� ����������� �����
				{
					cout << endl << "���� �������� ����������� ���� �����!" << endl
						<< "\n�������� ���� �������� � �������: ";
				}
				if (N + countAddedStudents > 30) //�� ����� ���������� ������
				{
					cout << endl << "�����, ����� ������ �� ��������, ��������� ������������ �������� �� �������. ("
						<< countAddedStudents << "+" << N
						<< ")/30" << endl
						<< endl << "���� �������� ��-����� �����, ���� �� ������� �� �� ��������� 30 ��������: ";
				}
			}
			cin.ignore();
			addStudents(student, N, countAddedStudents);
			cout << "��������� ������� ��� ������� � �������. ��������� ���������� ����� �� ������������... \n";
			cin.ignore();
			getline(cin, next);
			system("CLS");

			break;
		case 2:
			if (countAddedStudents == 0)
			{
				cout << "�� ��� �������� ������� �������� � �������.";
				nextCommand();
				break;
			}
			print(student, countAddedStudents);
			nextCommand();
			break;
		case 3:
			if (countAddedStudents == 0)
			{
				cout << "�� ��� �������� ������� �������� � �������.";
				nextCommand();
				break;
			}
			studentsInInterval(student, countAddedStudents);
			studentsWithFailDiscipline(student, countAddedStudents);
			nextCommand();
			break;
		case 4:
			if (countAddedStudents == 0)
			{
				cout << "�� ��� �������� ������� �������� � �������.";
				nextCommand();
				break;
			}
			sorting(student, countAddedStudents);
			nextCommand();
			break;
		case 5:
			if (countAddedStudents == 0)
			{
				cout << "�� ��� �������� ������� �������� � �������.";
				nextCommand();
				break;
			}
			SaveStudentsToFile(student, countAddedStudents);
			ReadStudentsFromFile(student, countAddedStudents);
			nextCommand();
			break;
		case 6:
			system("CLS");
			SubMenu();

			//�������
			do
			{
				cout << "������ ���� �����: ";
				cin.clear();
				cin >> secondChoice;
				cin.clear();
				cin.ignore(1000, '\n');

				while (secondChoice < 1 || secondChoice > 5)
				{
					cout << endl << "�� ��� ������� ���� ���� �� �������� �����. �������� �� ���������� � ���������." << endl;
					cout << "\n������ ���� �����: ";
					cin >> secondChoice;
					cin.clear();
					cin.ignore(1000, '\n');
				}

				switch (secondChoice)
				{
				case 1:
					if (countAddedStudents == 0)
					{
						cout << "�� ��� �������� ������� �������� � �������.";
						nextCommand();
						SubMenu();
						break;
					}
					separateStudents(student, size, countAddedStudents);
					separateStudentsByScore(student, size, countAddedStudents);
					nextCommand();
					SubMenu();
					break;
				case 2:
					if (countAddedStudents == 0)
					{
						cout << "�� ��� �������� ������� �������� � �������.";
						nextCommand();
						SubMenu();
						break;
					}
					newGrade(student, countAddedStudents);
					nextCommand();
					SubMenu();
					break;
				case 3:
					if (countAddedStudents == 0)
					{
						cout << "�� ��� �������� ������� �������� � �������.";
						nextCommand();
						SubMenu();
						break;
					}
					avarageGrades(student, countAddedStudents);
					nextCommand();
					SubMenu();
					break;
				case 4:
					if (countAddedStudents == 0)
					{
						cout << "�� ��� �������� ������� �������� � �������.";
						nextCommand();
						SubMenu();
						break;
					}
					newStatut(student, countAddedStudents);
					nextCommand();
					SubMenu();
					break;
				case 5:
					break;
				}
			} while (secondChoice != 5);

			system("CLS");

			choice = 0;
			break;

		case 7:
			break;
		}
	} while (choice != 7);

	return 0;
}
