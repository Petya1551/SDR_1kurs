#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <windows.h>

using namespace std;

//Структура с информация за студентите
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
		double avarageScore; //допълнение второ
	};

//Дизайн на главното меню
void Menu()
{
	cout << setw(42) << "МЕНЮ ЗА ИЗБОР НА КОМАНДИ" << endl;
	cout << setfill('-') << setw(60) << "" << endl;
	cout << setfill(' ');
	cout << "1. ДОБАВИ СТУДЕНТ В ГРУПА \n"
		<< "2. ПОКАЖИ ВСИЧКИ СТУДЕНТИ \n"
		<< "3. ТЪРСЕНЕ И ИЗВЕЖДАНЕ НА СТУДЕНТИ С ОЦЕНКА ПО БП И С МИНИМУМ 1 ДИСЦИПЛИНА С ОЦЕНКА СЛАБ 2 \n"
		<< "4. СОРТИРАНЕ И ИЗВЕЖДАНЕ НА СТУДЕНТИ \n"
		<< "5. РАБОТА С ВЪНШЕН ФАЙЛ \n"
		<< "6. ДОПЪЛНИТЕЛНИ КОМАНДИ \n"
		<< "7. ИЗХОД ОТ ПРОГРАМАТА" << endl;
	cout << setfill('-') << setw(60) << "" << endl;
	cout << setfill(' ');
}

//Дизайн на подменюто
void SubMenu()
{
	cout << setw(42) << "ПОДМЕНЮ ЗА ИЗБОР НА КОМАНДИ" << endl;
	cout << setfill('-') << setw(60) << "" << endl;
	cout << setfill(' ');
	cout << "1. ОТДЕЛЯНЕ НА СТУДЕНТИ ПО СТАТУТ И ТЪРСЕНЕ НА УСПЕХ ПО ДАДЕН ИНТЕРВАЛ\n"
		<< "2. ВЪВЕЖДАНЕ/АКТУАЛИЗАЦИЯ НА ОЦЕНКИ ЗА СТУДЕНТ \n"
		<< "3. ИЗЧИСЛЯВАНЕ НА СРЕДЕН УСПЕХ НА СТУДЕНТ \n"
		<< "4. СМЯНА НА СТАТУТ НА СТУДЕНТ \n"
		<< "5. ИЗЛЕЗ ОТ ПОДМЕНЮТО \n";
	cout << setfill('-') << setw(60) << "" << endl;
	cout << setfill(' ');
}


//Функция за добавяне на студенти
void addStudents(Students mass[], int N, int& countAddedStudents)
{
	//С тези три променливи се запазва броя дисциплини, които има студентът, и се изчислява средният успех
	int disciplina;
	int grade;
	int allGrades = 0;
	//Тази променлива се използва за брояч, който всеки път се увеличава с 1, когато се добави нов студент 
	int currentCount = countAddedStudents;

	//for-цикъл, който върти до посочения от потребителя брой добавени студенти. Чрез него се въвеждат данните за всеки студент
	for (int i = countAddedStudents; i < N + countAddedStudents; i++)
	{
		cout << "Въведи факултетен номер, ЕГН, трите имена, дисциплини, оценки, пол, възраст и статут на студент номер " << i + 1 << endl;
		cout << "Факултетен номер: \n";
		getline(cin, mass[i].fakNomer);
		cin.clear();
		while (mass[i].fakNomer.length() != 8)
		{
			cout << "Не сте въвели коректни данни. Факултетният номер трябва да съдържа 8 цифри. Въведете факултетен номер: \n";
			getline(cin, mass[i].fakNomer);
			cin.clear();
		}
		cout << "ЕГН: \n";
		getline(cin, mass[i].egn);
		cin.clear();
		while (mass[i].egn.length() != 10)
		{
			cout << "Не сте въвели коректни данни. ЕГН-то трябва да съдържа 10 цифри. Въведете ЕГН: \n";
			getline(cin, mass[i].egn);
			cin.clear();
		}
		cout << "Име: \n";
		getline(cin, mass[i].firstName);
		cin.clear();
		cout << "Презиме: \n";
		getline(cin, mass[i].secondName);
		cin.clear();
		cout << "Фамилия: \n";
		getline(cin, mass[i].thirdName);
		cin.clear();
		cout << "Въведи брой дисциплини: \n";
		cin >> disciplina;
		cin.ignore();
		string listDisciplini[5];
		while (disciplina == 0 || disciplina > 5)
		{
			cout << "Не сте въвели коректни данни. Въведете брой на дисциплине от 1 до 5: \n";
			cin >> disciplina;
			cin.ignore();
		}
		//Втори цикъл for, с който записваме всички дисциплини и оценките към тях
		for (int j = 0; j < disciplina; j++)
		{
			cout << "Име на дисциплината (Изберете от изброените: БП(BP), УД(WD), ЕЛ(EL), СП(SP), МТ(MT)): \n";
			getline(cin, listDisciplini[j]);
			mass[i].discipline[j] = listDisciplini[j];
			cin.clear();
			cout << "Въведи оценка по дисциплината (0(Няма оценкa) или от 2 до 6): \n";
			cin >> grade;
			allGrades += grade;
			while (grade < 0 || grade > 6 || grade == 1)
			{
				cout << "Не сте въвели коректни данни. Въведете оценка 0(Няма оценкa) или от 2 до 6: \n";
				cin >> grade;
			}
			mass[i].grades[j] = grade;
			cin.ignore();
		}
		mass[i].avarageScore = allGrades / disciplina;
		cout << "Пол (male/female): \n";
		getline(cin, mass[i].gender);
		cin.clear();
		while (mass[i].gender != "male" && mass[i].gender != "female")
		{
			cout << "Не сте въвели коректни данни. Въведете пол male или female: \n";
			getline(cin, mass[i].gender);
			cin.clear();
		}
		cout << "Възраст: \n";
		cin >> mass[i].age;
		cin.ignore();
		cout << "Статут (active/dropped out/graduated): \n";
		getline(cin, mass[i].statut);
		cin.clear();
		while (mass[i].statut != "active" && mass[i].statut != "dropped out" && mass[i].statut != "graduated")
		{
			cout << "Не сте въвели правилен статус. Въведете отново: \n";
			getline(cin, mass[i].statut);
			cin.clear();
		}
		cin.clear();
		currentCount++;
	}
	//Присвояваме стойността на currentCount на countAddedStudents, за да имаме точната бройка в момента на студентите вътре в групата
	//Извикали сме countAddedStudents по адрес във функцията, за да може стойността и да се запази.
	countAddedStudents = currentCount;
}

//Дизайн на таблицата с информация за всички студенти
void tableDesign()
{
	const int width = 170;
	const int columnWidth = 20;

	cout << endl << setw(width) << setfill('-') << "" << setfill(' ');
	cout << endl << "|"
		<< setw(columnWidth) << left << "ФАК. NO" << "|"
		<< setw(columnWidth) << left << "ЕГН" << "|"
		<< setw(columnWidth) << right << "ИМЕ" << "|"
		<< setw(columnWidth) << right << "ПРЕЗИМЕ" << "|"
		<< setw(columnWidth) << right << "ФАМИЛИЯ" << "|"
		<< setw(columnWidth) << right << "ПОЛ" << "|"
		<< setw(columnWidth) << right << "ВЪЗРАСТ" << "|"
		<< setw(columnWidth) << right << "СТАТУТ" << "|";
	cout << endl << setw(width) << setfill('-') << "" << setfill(' ') << endl;
}

//Извеждане на всички студенти в таблица
void print(Students mas[], int& countAddedStudents)
{
	const int columnWidth = 20;
	cout << "Студентите в групата: \n";

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

//Извеждане на студенти с цялата им информация
void printWithoutTable(Students mas[], int& countAddedStudents)
{
	for (int i = 0; i < countAddedStudents; i++)
	{
		//В arrayLength се изчислява колко елемента има в discipline, като разделя броя байтове от общия масив на байтовете на един елемент от масива с дисциплини
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

//Извеждане на всички данни на сортираните студенти
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

//Сортиране на студентите до първо име във възходящ ред
void sorting(Students mas[], int& countAddedStudents)
{
	//Променлива от типа на структурата, в която временно да запаметяване данни
	Students temp;
	//Създаване на нов масив, в който да запазим сортираните студенти
	Students masCopy[30];
	for (int i = 0; i < countAddedStudents; i++)
	{
		masCopy[i] = mas[i];
	}

	//Намираме дължината на масива като делим байтовете от целия масив на байтовете на един от елементите в него
	int arrayLength = sizeof(masCopy) / sizeof(masCopy[0]);
	//Сортиране чрез метод на мехурчето
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
	cout << "Сортираните студенти по име: " << endl;
	printSorting(masCopy, countAddedStudents);
}

//Сортиране на студентите по факултетен номер
void sortByFakNomer(Students mas[], int& countAddedStudents)
{
	//Променлива от типа на структурата, в която временно да запаметяване данни
	Students temp;
	//Създаване на нов масив, в който да запазим сортираните студенти
	Students masCopy[30];
	for (int i = 0; i < countAddedStudents; i++)
	{
		masCopy[i] = mas[i];
	}

	//Намираме дължината на масива като делим байтовете от целия масив на байтовете на един от елементите в него
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

//Сортиране на студентите по ЕГН
void sortByEGN(Students mas[], int& countAddedStudents)
{
	//Променлива от типа на структурата, в която временно да запаметяване данни
	Students temp;
	//Създаване на нов масив, в който да запазим сортираните студенти
	Students masCopy[30];
	for (int i = 0; i < countAddedStudents; i++)
	{
		masCopy[i] = mas[i];
	}

	//Намираме дължината на масива като делим байтовете от целия масив на байтовете на един от елементите в него
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

//Отделяне на студентите по определен статут, въведен от потребителя и сортиране по фак. номер
void separateStudents(Students mas[], int size, int& countAddedStudents)
{
	//Създаваме променлива от тип string, с която потребителя ще въведете желания от него статут, по който да ги отдели
	string statut2 = "";
	cout << "Въведете статут(active, dropped out, graduated): ";
	getline(cin, statut2);

	//Нов масив, в който да ги запаметява
	Students masCopy[30];

	//Валидация на статута
	while (statut2 != "active" && statut2 != "dropped out" && statut2 != "graduated")
	{
		cout << "Не сте въвели нито един от трите статута. Въведете валиден статут: ";
		cin >> statut2;
		cin.clear();
	}

	for (int i = 0; i < countAddedStudents; i++)
	{
		//Проверка дали потребителя е избрал активен статут и дали съвпада със статута на студентът в момента на итерацията на цикъла
		if (statut2 == "active" && mas[i].statut == "active")
		{
			for (int j = 0; j < 30; j++)
			{
				//Проверява дали в момента на итерацията няма записан студент. Ако firstName е празен стринг - вътре записва дадения човек
				if (masCopy[j].firstName == "")
				{
					masCopy[j] = mas[i];
					break;
				}
			}
			//Броячът size следи за бройката на студентите, които са с въведения от потребителя статут
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

	//Проверява дали масивът е празен - ако е празен, извежда даденото съобщение
	if (masCopy[0].firstName == "")
	{
		cout << "Няма студенти със съответния статут. \n";
	}
	else
	{
		cout << "Студентите със статут " << statut2 << ": " << endl;
		sortByFakNomer(masCopy, size);
	}
}

//Отделяне на студенти с успех в интервал (мин -макс) и сортиране по ЕГН.
void separateStudentsByScore(Students mas[], int size, int& countAddedStudents)
{
	int firstInterval(0), secondInterval(0), score(0), count(0);
	cout << "Въведи първата оценка от интервала за успех: \n";
	cin >> firstInterval;
	cout << "Въведи втората оценка от интервала за успех: \n";
	cin >> secondInterval;

	Students masCopy[30];

	for (int i = 0; i < countAddedStudents; i++)
	{
		//Зануляваме успеха и брояча след всяка итерация на цикъла
		score = 0;
		count = 0;

		int arrayLength = sizeof(mas[i].discipline) / sizeof(mas[0].discipline[0]);
		for (int j = 0; j < arrayLength; j++)
		{
			//Проверка дали има въведена дисциплина, ако няма продължава за следващата
			if (mas[i].discipline[j] == "")
			{
				continue;
			}

			//Ако има записана дисциплина, събира вси1ките му оценки и се увеличава count
			score += mas[i].grades[j];
			count++;
		}

		//Проверка дали успеха му съвпада с двата интервала
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

	//Проверява дали масивът е празен - ако е празен, извежда даденото съобщение
	if (masCopy[0].firstName == "")
	{
		cout << "Няма студенти с успех в дадения интервал. \n";
	}
	else
	{
		cout << "Студентите с успех в дадения интервал: \n";
		sortByEGN(masCopy, size);
	}
}

//Търсене и извеждане на студенти с оценка по БП в определен в интервал [min – max]
void studentsInInterval(Students mas[], int& countAddedStudents)
{
	int firstInterval(0), secondInterval(0), count(0);
	cout << "Първо ще бъдат показани студентите с оценка по БП в даден интервал, след това всички студенти с поне една оценка Слаб 2 по някоя дисциплина \n";
	cout << "Въведи първата оценка по БП от интервала: \n";
	cin >> firstInterval;
	cout << "Въведи втората оценка по БП от интервала: \n";
	cin >> secondInterval;

	Students masCopy[30];

	for (int i = 0; i < countAddedStudents; i++)
	{
		int arrayLength = sizeof(mas[i].discipline) / sizeof(mas[0].discipline[0]);
		for (int j = 0; j < arrayLength; j++)
		{
			//Проверка дали в дадената итерация има въведена дисциплина
			if (mas[i].discipline[j] == "")
			{
				continue;
			}
			//Проверка дали текущата дисциплина е БП
			if (mas[i].discipline[j] == "BP")
			{
				//Проверка дали оценката попада в дадения интервал
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
		cout << "Няма студенти с оценки по БП в дадения интервал. \n";
	}
	else
	{
		cout << "Студентите с оценки по БП в дадения интервал са: \n";
		printWithoutTable(masCopy, count);
	}
}

//Търсене и извеждане на студенти с минимум един предмет, с оценка Слаб 2
void studentsWithFailDiscipline(Students mas[], int& countAddedStudents)
{
	int countStudent(0), count(0);

	Students masCopy[30];

	for (int i = 0; i < countAddedStudents; i++)
	{
		//Зануляваме countStudent за всяка итерация на цикъла
		countStudent = 0;

		int arrayLength = sizeof(mas[i].discipline) / sizeof(mas[0].discipline[0]);
		for (int j = 0; j < arrayLength; j++)
		{
			//Проверка дали оценката е различна от 2
			if (mas[i].grades[j] != 2)
			{
				continue;
			}
			else
			{
				for (int k = 0; k < 30; k++)
				{
					//Проверка дали firstName е празно и дали вече този студент не е запазен в масива
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
		cout << "Няма студенти с оценка Слаб 2. \n";
	}
	else
	{
		cout << "Студентите с оценка Слаб 2: \n";
		printWithoutTable(masCopy, count);
	}
}

//Смяна на статут на студент
void newStatut(Students mas[], int& countAddedStudents)
{
	cout << "Въведи факултетен номер, на чийто студент искате да промените статута: \n";
	string fakNomerStudent, newStatut;
	//Създаваме булева променлива, с която ще правим проверка за факултетния номер
	bool fakNomerExists = false;
	getline(cin, fakNomerStudent);
	cin.clear();

	for (int i = 0; i < countAddedStudents; i++)
	{
		//Проверка дали съществува студент с въведения факултетен номер
		if (mas[i].fakNomer == fakNomerStudent)
		{
			fakNomerExists = true;
			break;
		}
	}

	//Влизаме в цикъла, ако съществува студент с такъв факултетен номер
	if (fakNomerExists)
	{
		for (int i = 0; i < countAddedStudents; i++)
		{
			//Проверка дали фак. номер на студента в този момент съвпада с въведения от потребителя
			if (fakNomerStudent != mas[i].fakNomer)
			{
				continue;
			}

			if (mas[i].statut == "active" || mas[i].statut == "dropped out")
			{
				cout << "Въведи новия статут: \n";
				getline(cin, newStatut);
				mas[i].statut = newStatut;
				cout << "Успешно променихте статута на студента! \n";
			}
			else
			{
				cout << "Студентът е вече завършил. Не може да променяте неговия статут. \n";
			}
		}
	}
	else
	{
		cout << "Няма студенти с този факултетен номер. \n";
	}
}

//Въвеждане/Актуализиране на оценка
void newGrade(Students mas[], int& countAddedStudents)
{
	cout << "Въведи факултетен номер, на чийто студент искате да промените оценката: \n";
	int allGrades = 0;
	int count = 0;
	string fakNomerStudent;
	string disciplineGrade;
	bool fakNomerExists = false;
	getline(cin, fakNomerStudent);
	cin.clear();

	for (int i = 0; i < countAddedStudents; i++)
	{
		//Проверка дали съществува студент с въведения факултетен номер
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

			//Проверка дали фак. номер на студента в този момент съвпада с въведения от потребителя
			if (fakNomerStudent != mas[i].fakNomer)
			{
				continue;
			}

			//Ако студентът е активен
			if (mas[i].statut == "active")
			{
				//Булева променлива, с която ще проверим дали е въведена дисциплина, която студентът изучава
				bool disciplineExists = true;
				cout << "Изберете дисциплина, чиято оценка да промените: \n";
				getline(cin, disciplineGrade);
				cin.clear();

				for (int j = 0; j < arrayLength; j++)
				{
					if (mas[i].discipline[j] == disciplineGrade)
					{
						disciplineExists = true;
						//Когато оценката е различна от 0(Тоест няма оценка)
						if (mas[i].grades[j] != 0)
						{
							cout << "Сигурни ли сте, че искате да промените оценката на студента?(yes/no) \n";
							string check;
							getline(cin, check);
							cin.clear();
							if (check == "yes")
							{
								int newGrade = 0;
								cout << "Въведи новата оценка: \n";
								cin >> newGrade;
								mas[i].grades[j] = newGrade;
								break;
							}
							else if (check == "no")
							{
								cout << "Вие отказахте да промените оценката на студента." << endl;
								break;
							}
						}
						else if (mas[i].grades[j] == 0)
						{
							int newGrade = 0;
							cout << "Въведи новата оценка: \n";
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
					cout << "Не сте въвели дисциплина, която студентът изучава. \n";
				}
				//for-цикъл, с който да съберем всички оценки на студента, след промените по тях
				for (int j = 0; j < arrayLength; j++)
				{
					//Отделяме само оценките, които е въвел студента - там, където няма въведена оценка, се запазват отрицателни числа
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
				cout << "Студентът е вече прекъснал или завършил. Не може да променяте неговите оценки. \n";
				break;
			}
			//Пресмятаме новия среден успех
			mas[i].avarageScore = allGrades / count;
		}
	}
	else
	{
		cout << "Няма студенти с този факултетен номер. \n";
	}

}

//Извеждане на средния успех на студент
void avarageGrades(Students mas[], int& countAddedStudents)
{
	cout << "Въведи факултетен номер, на чийто студент искате да видите средния успех: \n";
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
				cout << "Средният успех на студента е: " << mas[i].avarageScore << endl;
			}
		}
	}
	else
	{
		cout << "Няма студенти с този факултетен номер. \n";
	}
}

//Записване на информация във файл
void SaveStudentsToFile(Students mas[], int& countAddedStudents)
{
	const string FILE_NAME = "Students.txt";
	ofstream fp(FILE_NAME, ios::out);
	fp << countAddedStudents << endl;

	if (fp.fail())
	{
		cout << "Грешка!" << endl;
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
	cout << "Всичко е запазено във файл с име: " << FILE_NAME << endl;
	fp.close();
}

//Четене на информация от файл
void ReadStudentsFromFile(Students mas[], int& countAddedStudents)
{
	int allGrades = 0;
	const string FILE_NAME = "Students.txt";

	ifstream fp(FILE_NAME, ios::in);

	if (fp.fail())
	{
		cout << "Грешка!" << endl;
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
	cout << "Информацията е обновена от файл с име: " << FILE_NAME << endl;
	fp.close();
}

//Функция за изтриване на текст след всяка изпълнена команда
void nextCommand()
{
	string next = "";
	cout << "\nНатиснете произволен бутон от клавиатурата, за да продължите...\n";
	cin.ignore();
	getline(cin, next);
	system("CLS");
}

int main()
{	//Изпълнение на конзолната програма на цял екран
	::SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

	//Изпълнение на конзолната програма на цял екран с бутони за затваряне и минимизиране
	//ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	setlocale(LC_ALL, "");

	int choice, secondChoice, N(0), size(0), countAddedStudents(0);
	string next = "";

	Students student[30];

	//Четене на файл с данни
	ReadStudentsFromFile(student, countAddedStudents);
	do
	{
		Menu();
		cout << "Въведи твоя избор: ";
		cin >> choice;
		cin.clear();
		cin.ignore(1000, '\n');

		//Валидация за входа
		while (choice < 1 || choice > 7)
		{
			cout << endl << "Не сте избрали нито едно от дадените числа. Изберете от показаните в менюто." << endl;
			cout << "\nВъведи твоя избор: ";
			cin >> choice;
			cin.clear();
			cin.ignore(1000, '\n');
		}

		switch (choice)
		{
		case 1:
			cout << "Въведете броя студенти в групата: ";
			while (N <= 0 || N + countAddedStudents > 30) //Валидира броят добавяни книги
			{
				cin >> N;
				if (N <= 0) //за отрицателни числа
				{
					cout << endl << "Моля въведете положително цяло число!" << endl
						<< "\nВъведете броя студенти в групата: ";
				}
				if (N + countAddedStudents > 30) //за числа препълващи масива
				{
					cout << endl << "Броят, който искате да въведете, надвишава максималната стойност на групата. ("
						<< countAddedStudents << "+" << N
						<< ")/30" << endl
						<< endl << "Моля въведете по-малко число, така че групата да не надвишава 30 студенти: ";
				}
			}
			cin.ignore();
			addStudents(student, N, countAddedStudents);
			cout << "Добавихте успешно нов студент в групата. Натиснете произволен бутон от клавиатурата... \n";
			cin.ignore();
			getline(cin, next);
			system("CLS");

			break;
		case 2:
			if (countAddedStudents == 0)
			{
				cout << "Не сте добавили никакви студенти в групата.";
				nextCommand();
				break;
			}
			print(student, countAddedStudents);
			nextCommand();
			break;
		case 3:
			if (countAddedStudents == 0)
			{
				cout << "Не сте добавили никакви студенти в групата.";
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
				cout << "Не сте добавили никакви студенти в групата.";
				nextCommand();
				break;
			}
			sorting(student, countAddedStudents);
			nextCommand();
			break;
		case 5:
			if (countAddedStudents == 0)
			{
				cout << "Не сте добавили никакви студенти в групата.";
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

			//Подменю
			do
			{
				cout << "Въведи твоя избор: ";
				cin.clear();
				cin >> secondChoice;
				cin.clear();
				cin.ignore(1000, '\n');

				while (secondChoice < 1 || secondChoice > 5)
				{
					cout << endl << "Не сте избрали нито едно от дадените числа. Изберете от показаните в подменюто." << endl;
					cout << "\nВъведи твоя избор: ";
					cin >> secondChoice;
					cin.clear();
					cin.ignore(1000, '\n');
				}

				switch (secondChoice)
				{
				case 1:
					if (countAddedStudents == 0)
					{
						cout << "Не сте добавили никакви студенти в групата.";
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
						cout << "Не сте добавили никакви студенти в групата.";
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
						cout << "Не сте добавили никакви студенти в групата.";
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
						cout << "Не сте добавили никакви студенти в групата.";
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
