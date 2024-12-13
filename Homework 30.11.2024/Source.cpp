/*
ВБУДУВАННЯ. ПЕРЕВАНТАЖЕННЯ. ШАБЛОНИ ФУНКЦІЙ. РЕКУРСІЯ.
======================================================

№2
 Написати шаблонні функції і протестувати їх в основній програмі:
 ■ Знаходження максимального значення в одновимірному масиві;
 ■ Знаходження максимального значення у двовимірному масиві;

№3
 Реалізуйте перевантажені функції для
 ■ Знаходження максимального значення двох цілих;
 ■ Знаходження максимального значення трьох цілих


№4
 Напишіть рекурсивну функцію, яка приймає одновимірний масив зі 100 цілих чисел,
 заповнених випадковим чином, і знаходить позицію, з якої починається послідовність з 10 чисел, сума яких мінімальна.
 Вивести масив у вигляды таблиці (10х10)

№5
 Створіть функцію з необмеженою кількістю параметрів для об'єднання масивів у один.




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