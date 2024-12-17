/*
ВБУДУВАННЯ. ПЕРЕВАНТАЖЕННЯ. ШАБЛОНИ ФУНКЦІЙ. РЕКУРСІЯ.
======================================================


Навчальний матеріал:
 https://fsx1.itstep.org/api/v1/files/v7HPgHcT8eeoPIvbWucTtQpus5dPKcvr?inline
 https://fsx1.itstep.org/api/v1/files/48F0HqTXVLmCZP1g0Gv94w2yoO--VSeC?inline

 https://fsx1.itstep.org/api/v1/files/DJZxVIiKxkKNN3j5bhOHFFTcBRwpjUQR?inline
 https://fsx1.itstep.org/api/v1/files/yhNVl_l024dxxlo_kk72Tg0AUAX9AmQV?inline
*/

/*
№1
 Напишіть програму, яка обмежує кількість викликів певної функції. Якщо кількість викликів перевищує ліміт, функція повинна повідомити про це.
 Використовувати статично локальну змінну у функції. Приклад:

  Тест функції з лімітом 3:
  Виклик №1: Функція виконана успішно.
  Виклик №2: Функція виконана успішно.
  Виклик №3: Функція виконана успішно.
  Перевищено ліміт викликів!

  Скидання лічильника: Лічильник скинуто.

  Повторний тест після скидання:
  Тест функції з лімітом 3:
  Виклик №1: Функція виконана успішно.
  Виклик №2: Функція виконана успішно.
*/
/*
#include <iostream>
#include <locale>

#define SQRT (X) ((X)*(X); // тренировка використання #define з прикладу 

const int AMOUNT_OF_VALIDATIONS = 3;

using namespace std;

inline void counterReset(short& value) {
	value = 0;
	cout << "\nСкидання лічильника: Лічильник скинуто.\n" << endl;
}

void func(int reset = 0) {
	static short n = 0;
	static long counterOfTriggers = 0;

	if (reset == 1) {
		counterReset(n);
		return;
	}

	int limit = AMOUNT_OF_VALIDATIONS - n;

	n++;

	if (limit != 0 && n < 4) {
		cout << "\n\033[035mТест функції. Поточний ліміт: " << limit << "\033[0m \n";
		counterOfTriggers++;
	}
	if (n < 4) cout << "\n\033[032mВиклик №" << counterOfTriggers << ": Функція виконана успішно.\033[0m\n" << endl;
	else cout << "\n\033[031mПеревищено ліміт викликів!\033[0m\n" << endl;

	if (n == 3) cout << "\n\033[031m УВАГА! На разі ваш ліміт становить 0\033[0m\n" << endl;
}

int main() {
	setlocale(LC_ALL, "ukr");
	system("chcp 1251>null");

	cout << "\t\t\t\t\033[033mMEНЮ\033[0m" << endl << "\n";

#pragma region Implementation Of Menu Setup
	int user_choice;
	while (true) {
		cout << "\033[033m"
			"Введіть 1 для виконання функції;\n"
			"Введіть 2 для скидання лічильника;\n"
			"Введіть 3 для виходу;"
			"\033[0m"
			<< endl;

		cout << "Введіть ваш вибір: ";
		cin >> user_choice;

		if (cin.fail()) {
			cout << "\033[031m Помилка! Будь ласка, введіть число.\033[0m\n";
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}

		if (user_choice != 1 && user_choice != 2 && user_choice != 3) {
			cout << "\033[031m Помилка! Будь ласка, введіть числа 1, 2 або 3.\033[0m\n";
			continue;
		}

		switch (user_choice) {

		case 1:
			func();
			break;

		case 2:
			func(1);
			break;
		}

		if (user_choice == 3) {
			cout << "\033[032mВи успішно вийшли з програми.\033[0m" << endl;
			break;
		}


	}

#pragma endregion

	return 0;

}
*/

/*
№2
 Написати шаблонні функції і протестувати їх в основній програмі:
 ■ Знаходження максимального значення в одновимірному масиві;
 ■ Знаходження максимального значення у двовимірному масиві;
*/

/*
#include <iostream>
#include <ctime>
#include <locale>
#include <limits>
#include <iomanip>
#include <random>
#include <utility> // Для std::pair
#include <tuple> // for tuple



#define OUTPUT_FOR_ONE_DIMENSION_ARRAY(X) \
    std::cout << "\n\033[032mНайбільше значення масиву становить: " << (X).first<< "\n" \
              << "Його позиція: " << (X).second << "\033[0m" << std::endl;

#define  OUTPUT_FOR_TWO_DIMENSION_ARRAY(X) \
	std::cout << "\n\033[032mНайбільше значення масиву становить: " << std::get<0>(X) << "\n" \
			  << "Його позиція: \033[035mгоризонталь: " << std::get<1>(X) << "  \033[035mвертикаль: " <<std::get<2>(X) << "\033[0m" << std::endl;


using namespace std;

char generateRandomCharFromSet() {
	const string charset = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	static random_device rd;
	static mt19937 generator(rd());
	uniform_int_distribution<int> distribution(0, charset.size() - 1);

	return charset[distribution(generator)];
}

template  <typename T>
pair <T, int> maxInOneDimensionalArray(T* arr, int length);

template <typename T1>
tuple <T1, int, int> maxInTwoDimensionalArray(T1** arr, int rows, int columns);

template <typename TYPE>
void fillOneDimensionalAndOutput(int length, TYPE* arr, int SWITCH = 0);

template <typename TYPE>
void fillTwoDimensionalAndOutput(TYPE** arr, int rows, int columns, int SWITCH = 0);


// --------------------------------------------  MAIN function --------------------------------------------------------- //

int main() 
{
	void OneDimensionalArrayGeneration();
	void TwoDimensionalArrayGeneration();

	setlocale(LC_ALL, "ukr");
	system("chcp 1251>null");
	srand(time(NULL));

	// 
	OneDimensionalArrayGeneration();

	//
	
	TwoDimensionalArrayGeneration();

	return 0;
}

// ------------------------------------------------------------------------------------------------------------------------- //
template  <typename T> 
pair <T, int> maxInOneDimensionalArray(T* arr, int length)
{
	T max = numeric_limits<T>::min();

	int maxPosition = 0;

	for (int i = 0; i <= length; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			maxPosition = i;
		}
	}

	return { max, maxPosition };
}

template <typename T1>
tuple <T1, int, int> maxInTwoDimensionalArray(T1** arr, int rows, int columns) 
{
	T1 max = numeric_limits<T1>::min();

	int maxPositionI = 0;
	int maxPositionJ = 0;

	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < columns; j++) 
		{
			if (arr[i][j] > max) 
			{
				max = arr[i][j];
				maxPositionI = i;
				maxPositionJ = j;
			}
		}	
	}

	return { max, maxPositionI, maxPositionJ};
}

template <typename TYPE>
void fillOneDimensionalAndOutput(int length, TYPE* arr, int SWITCH)
{
	cout << "\033[033mМасив: \033[0m" << endl;

	switch (SWITCH)
	{
	case 1:
		for (int i = 0; i < length; i++)
		{
			arr[i] = generateRandomCharFromSet();

			cout << setw(4) << arr[i];
		}
		cout << endl;
		break;
	case 2:
		for (int i = 0; i < length; i++)
		{
			arr[i] = -100 + rand() % 201;

			cout << setw(4) << arr[i];
		}
		cout << endl;
		break;

	default:
	break;
	}
	
}

template <typename TYPE>
void fillTwoDimensionalAndOutput(TYPE** arr, int rows, int columns, int SWITCH) 
{
	cout << "\033[033mРандомно-сгенерований двовимірний масив: \033[0m" << endl;

	switch (SWITCH) 
	{
	
		case 1:
		{

			for (int i = 0; i < rows; i++)
			{
			
				for (int j = 0; j < columns; j++)
				{
					arr[i][j] = generateRandomCharFromSet();
					cout << setw(5) << arr[i][j];
				}
				cout << endl;
			}
			cout << endl;
			break;

		}
		case 2:
		{
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < columns; j++)
				{
					arr[i][j] = -100 + rand() % 201;
					cout << setw(5) << arr[i][j];
				}
				cout << endl;
			}
			cout << endl;
			break;


		}

	}

}

void OneDimensionalArrayGeneration() 
{
	const int LENGTH_1 = 5 + rand() % 16;

	int userChoice_1;
	while (true) {
		cout << "\033[033m\t\t\t\tГенерація одновимірного масиву" << endl;
		cout << "1 - сгенерувати для типу char;\n"
			"2 - сгенерувати для типу int;\n\033[0m"
			"Ваш вибір: ";
		cin >> userChoice_1;

		if (cin.fail()) {
			cout << "\033[031m Помилка! Будь ласка, введіть число.\033[0m\n" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		if (userChoice_1 != 1 && userChoice_1 != 2) {
			cout << "\033[031m Помилка! Будь ласка, введіть число 1 або 2.\033[0m\n" << endl;
			continue;
		}

		break;

	}

	switch (userChoice_1)
	{
		case 1: {
			char* OneDimensionalArray = new char[LENGTH_1];

			fillOneDimensionalAndOutput(LENGTH_1, OneDimensionalArray, 1);

			auto result = maxInOneDimensionalArray(OneDimensionalArray, LENGTH_1);

			OUTPUT_FOR_ONE_DIMENSION_ARRAY(result);

			delete[] OneDimensionalArray;
			break;
		}

		case 2: {
			int* OneDimensionalArray2 = new int[LENGTH_1];

			fillOneDimensionalAndOutput(LENGTH_1, OneDimensionalArray2, 2);

			auto result = maxInOneDimensionalArray(OneDimensionalArray2, LENGTH_1);

			OUTPUT_FOR_ONE_DIMENSION_ARRAY(result);

			delete[] OneDimensionalArray2;
			break;
		}
	}
}

void TwoDimensionalArrayGeneration() 
{
	const int ROWS = 5 + rand() % 16;
	const int COLUMNS = 5 + rand() % 16;

	int userChoice_2;
	while (true) {
		cout << "\033[033m\t\t\t\tГенерація двовимірного масиву" << endl;
		cout << "1 - сгенерувати для типу char;\n"
			"2 - сгенерувати для типу int;\n\033[0m"
			"Ваш вибір: ";
		cin >> userChoice_2;

		if (cin.fail()) {
			cout << "\033[031m Помилка! Будь ласка, введіть число.\033[0m\n" << endl;
			cin.clear();
			cin.ignore(1000, '\n');
			continue;
		}
		if (userChoice_2 != 1 && userChoice_2 != 2) {
			cout << "\033[031m Помилка! Будь ласка, введіть число 1 або 2.\033[0m\n" << endl;
			continue;
		}

		break;

	}

	switch (userChoice_2)
	{
		case 1: {


			char** TwoDimensionalArray = new char* [ROWS];
			for (int i = 0; i < ROWS; i++) {
				TwoDimensionalArray[i] = new char[COLUMNS];
			}


			fillTwoDimensionalAndOutput(TwoDimensionalArray, ROWS, COLUMNS, 1);

			auto result = maxInTwoDimensionalArray(TwoDimensionalArray, ROWS, COLUMNS);

			OUTPUT_FOR_TWO_DIMENSION_ARRAY(result);

			for (int i = 0; i < ROWS; i++) {
				delete[] TwoDimensionalArray[i];
			}
			delete[] TwoDimensionalArray;

			break;
		}

		case 2: {
			int** TwoDimensionalArray2 = new int* [ROWS];
			for (int i = 0; i < ROWS; i++)  
			{
				TwoDimensionalArray2[i] = new int[COLUMNS];
			}



			fillTwoDimensionalAndOutput(TwoDimensionalArray2, ROWS, COLUMNS, 2);

			auto result = maxInTwoDimensionalArray(TwoDimensionalArray2, ROWS, COLUMNS);

			OUTPUT_FOR_TWO_DIMENSION_ARRAY(result);

			for (int i = 0; i < ROWS; i++) {
				delete[] TwoDimensionalArray2[i];
			}
			delete[] TwoDimensionalArray2;
			break;
		}

	}
}
*/

/*
№3
 Реалізуйте перевантажені функції для
 ■ Знаходження максимального значення двох цілих;
 ■ Знаходження максимального значення трьох цілих
*/
/*
#include <iostream>
#include <locale>

using namespace std;

int main() {
	int findMax(int a, int b);
	int findMax(int a, int b, int c);

	short findMax(short a, short b);
	short findMax(short a, short b, short c);

	long findMax(long a, long b);
	long findMax(long a, long b, long c);

	long long findMax(long long a, long long b);
	long long findMax(long long a, long long b, long long c);

	system("chcp 1251>null");
	setlocale(LC_ALL, "ukr");


	short shortArray[] = { 2, 8, -3};

	int intArray[] = { 3, 7, -1};

	long longArray[] = {-4L, 30L, 25L };

	long long longLongArray[] = { 100LL, 999999999LL, -500LL};


	cout << "\033[032m=== Тестування для типу short ===\033[0m" << endl;
	cout << "Максимальне значення серед short: ";
	short shortResult = findMax(shortArray[0], shortArray[1], shortArray[2]);
	cout << shortResult << endl;

	cout << "\n\033[032m=== Тестування для типу int ===\033[0m" << endl;
	cout << "Максимальне значення серед int: ";
	int intResult = findMax(intArray[0], intArray[2], intArray[2]);
	cout << intResult << endl;

	cout << "\n\033[032m=== Тестування для типу long ===\033[0m" << endl;
	cout << "Максимальне значення серед long: ";
	long longResult = findMax(longArray[1], longArray[2], longArray[2]);
	cout << longResult << endl;

	cout << "\n\033[032m=== Тестування для типу long long ===\033[0m" << endl;
	cout << "Максимальне значення серед long long: ";
	long long longLongResult = findMax(longLongArray[0], longLongArray[1], longLongArray[2]);
	cout << longLongResult << endl;

	return 0;
}

// Для int
int findMax(int a, int b) 
{
	return (a > b) ? a : b;
}

int findMax(int a, int b, int c)
{
	return findMax(findMax(a, b), c);
}

// Для short
short findMax(short a, short b)
{
	return (a > b) ? a : b;
}

short findMax(short a, short b, short c)
{
	return findMax(findMax(a, b), c);
}

// Для long
long findMax(long a, long b)
{
	return (a > b) ? a : b;
}

long findMax(long a, long b, long c)
{
	return findMax(findMax(a, b), c);
}

// Для long long
long long findMax(long long a, long long b)
{
	return (a > b) ? a : b;
}

long long findMax(long long a, long long b, long long c)
{
	return findMax(findMax(a, b), c);
}
*/

/*
№4
 Напишіть рекурсивну функцію, яка приймає одновимірний масив зі 100 цілих чисел,
 заповнених випадковим чином, і знаходить позицію, з якої починається послідовність з 10 чисел, сума яких мінімальна.
 Вивести масив у вигляды таблиці (10х10)
*/


//#include <iostream>
//#include <ctime>
//#include <iomanip>
//#include <limits>
//#include <utility>
//#include <string>
//
//using namespace std;
//
//void autoFillArray(int length, int* arr);
//void outputArray(int startPos, int endPos, int* arr, bool forSum = false, bool withColor = false, char SEPARATION = ',', int withColorStart = -1, int withColorEnd = -1);
//pair <int, int> returningIndexOFMinSUM(int length, int range, int* arr);
//
//int main()
//{
//	system("chcp 1251>null");
//	setlocale(LC_ALL, "ukr");
//	srand(time(NULL));
//
//	const int LENGTH = 100;
//
//	int myArray[LENGTH];
//
//	cout << "\t\t\t\t\033[033m Виведення масиву 10х10 \033[0m" << endl << endl;
//
//	autoFillArray(LENGTH, myArray);
//	outputArray(0, LENGTH-1, myArray);
//	cout << endl;
//
//
//	cout << endl << "\t\t\t\t\033[033m Виведення найменшої суми \033[0m" << endl << endl;
//
//	auto result = returningIndexOFMinSUM(LENGTH, 10, myArray);
//
//	cout << "\033[033m Найменша сума: \033[0m";
//	outputArray(result.first, (result.first + 10), myArray, /* forSum = */ true, /* withColor = */ false, /* SEPARATION = */ '+',/*withColorStart*/ -1,/*withColorEnd*/ -1);
//	cout << " = ";
//	cout << "\033[035m" << result.second << "\033[0m" << endl; 
//
//	cout << "\033[033mПочатковий індекс становить: \033[0m\033[035m" << result.first << "\033[0m" << endl;
//
//	outputArray(0, LENGTH-1, myArray, /* forSum = */ false, /* withColor = */ true, /* SEPARATION = */ ',', /*withColorStart*/ result.first,/*withColorEnd*/ (result.first + 10));
//
//	return 0;
//}
//
//void autoFillArray(int length, int *arr)
//{
//	for (int i = 0; i < length; i++)
//	{
//		arr[i] = -100 + rand() % 201;
//	}
//}
//
//void outputArray(int startPos, int endPos, int* arr, bool forSum, bool withColor, char SEPARATION, int withColorStart, int withColorEnd)
//{
//	for (int i = startPos; i <= endPos; i++)
//	{
//		if (!forSum) 
//		{
//			if (withColor) 
//			{
//				string coloredValue = "\033[035m" + to_string(arr[i]) + "\033[0m";
//
//				string valueWithoutColor = to_string(arr[i]);
//				size_t valueLength = valueWithoutColor.length();
//
//				if (withColorStart == -1 && withColorEnd == -1)
//				{
//					cout << "\033[031mУВАГА! Ви не вказали параметри withColorStart та withColorEnd для функції outputArray\033[0m" << endl;
//					return;
//				}
//
//				else if (withColorStart <= i && i <= withColorEnd)
//				{
//					if (i % 10 == 0) cout << endl << endl;
//
//					if (arr[i] < 0)
//					{
//						if (i != endPos) cout << setw(5+ (coloredValue.length() - valueLength)) << coloredValue;
//						else cout << setw(5 + (coloredValue.length() - valueLength)) << coloredValue;
//					}
//					else
//					{
//						if (i != endPos) cout << setw(5 + (coloredValue.length() - valueLength)) << coloredValue;
//						else cout << setw(5 + (coloredValue.length() - valueLength)) << coloredValue;
//					}
//				}
//				else if (withColorStart > i || i > withColorEnd )
//				{
//					if (i % 10 == 0) cout << endl << endl;
//
//					if (arr[i] < 0)
//					{
//						if (i != endPos) cout << setw(5) << arr[i];
//						else cout << setw(5) << arr[i];
//					}
//					else
//					{
//						if (i != endPos) cout << setw(5) << arr[i];
//						else cout << setw(5) << arr[i];
//					}
//				}
//				
//
//			}
//			else
//			{
//				if (i % 10 == 0) cout << endl << endl;
//
//				if (arr[i] < 0)
//				{
//					if (i != endPos) cout << setw(5) << arr[i];
//					else cout << setw(5) << arr[i];
//				}
//				else
//				{
//					if (i != endPos) cout << setw(5) << arr[i];
//					else cout << setw(5) << arr[i];
//				}
//			}
//		}
//
//		else
//		{
//			if (arr[i] < 0)
//			{
//				if (i != endPos) cout  << "(" << arr[i] << ")" << " " << SEPARATION << " ";
//				else cout << setw(5) << arr[i];
//			}
//			else
//			{
//				if (i != endPos) cout << arr[i] << " " << SEPARATION << " ";
//				else cout << arr[i];
//			}
//		}
//
//	
//	}
//}
//
//
//pair <int, int> returningIndexOFMinSUM(int length, int range ,int* arr) 
//{
//	long long minSum = numeric_limits<long long>::max();
//
//	int index = -1;
//	if (length < range)
//	{
//		cout << "Помилка: range не може бути більше за length!" << endl;
//		return { -1, -1 };
//	}
//
//	for (int i = 0; i < (length - range); i++)
//	{
//		int Sum = 0;
//		for (int j = i; j < i + 10; j++) {
//			Sum += arr[j];
//		}
//
//		if (Sum < minSum) 
//		{
//			minSum = Sum;
//			index = i;
//		}
//	}
//
//	return { index, minSum };
//}

/*
№5
 Створіть функцію з необмеженою кількістю параметрів для об'єднання масивів у один.
*/

#include <iostream>
#include <ctime>
#include <iomanip>
#include <type_traits>
#include <cstdarg>
#include <vector>


using namespace std;

void autoFillArray(int length, int* arr);
void outputArray(int length, int number, int* arr);

template <typename type, typename ... Args>
void ConjugationOfArrays(vector<type>arrayResult);

template <typename type, typename ... Args>
void ConjugationOfArrays(vector<type>& arrayResult, type* arr, int length, const Args&... args);

int main()
{


	system("chcp 1251>null");
	setlocale(LC_ALL, "ukr");
	srand(time(NULL));



	const int LENGTH_1 = 5 + rand() % 16;

	const int LENGTH_2 = 5 + rand() % 16;

	int* myArray_1 = new int[LENGTH_1];

	int* myArray_2 = new int[LENGTH_2];


	autoFillArray(LENGTH_1, myArray_1);
	autoFillArray(LENGTH_2, myArray_2);

	outputArray(LENGTH_1, 1, myArray_1);
	outputArray(LENGTH_2, 2, myArray_2);

	vector<int>resArr;

	ConjugationOfArrays(resArr, myArray_1, LENGTH_1, myArray_2, LENGTH_2);

	cout << "\t\t\t\t\033[033mОб'єднаний масивів\033[0m" << endl << endl;
	cout << endl;
	for (auto const& num : resArr)
	{
		cout << setw(5) << num;
	}


	delete[] myArray_1;
	delete[] myArray_2;
	return 0;
}





void autoFillArray(int length, int *arr)
{
	for (int i = 0; i < length; i++)
	{
		arr[i] = -100 + rand() % 201;
	}
}

void outputArray(int length, int number, int* arr)
{
	cout << "\t\t\t\t\033[033m Виведення масиву " << number << " \033[0m" << endl << endl;
	for (int i = 0; i < length; i++)
	{
		cout << setw(5) << arr[i];
	}
	cout << endl;
}

template <typename type, typename ... Args>
void ConjugationOfArrays(vector<type>arrayResult)
{

}
template <typename Type, typename... Args>
void ConjugationOfArrays(vector<Type>& arrayResult, Type* arr, int length, const Args&... args) {


	for (int i = 0; i < length; i++) {
		arrayResult.push_back(arr[i]);
	}

	if constexpr (sizeof...(args) > 0) {
		ConjugationOfArrays(arrayResult, args...);
	}
}

		/*for (int i = 0; i < lengthOfArray1; i++)
		{
			array3[i] = arr1[i];
		}

		int count = 0;

		for (int i = lengthOfArray1; i < lengthOfNewArray; i++)
		{
			array3[i] = arr2[count];
			count++;
		}
		count = 0;*/




