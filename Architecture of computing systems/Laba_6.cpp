#include <iostream>
#include <cmath>

using namespace std;

void FullBranch(double x, double y)
{
	const double ten = 10, two = 2, three = 3, sfive = -5, one_third = 1.0 / 3.0; // объявляем и инициализируем константые переменные

	__asm
	{
		fld sfive		// скопировали -5 в st(0)
		fld x				// скопировали x в st(0), а -5 провалилось в st(1)
		fcomi st, st(1)		// сравниваем x с -5

		jb X_Less_s3		// если x < -5, то переходим на метку X_Less_s3
		jge X_Greater_s3	// если x >= -5, то переходим на метку X_Greater_s3

		X_Less_s3 :
		fld two					// st(0) = 2
			fld x				// st(0) = x, st(1) = 2
			fdiv				// st(0) = 2/x
			jmp finish			// переход к финишу

			X_Greater_s3 :	// x > -5
		fld two			// st(0) = 2, st(1) = x
			fxch			// st(0) = x, st(1) = 4 (st(0) <-> st(1))
			fcomi st, st(1)	// сравниваем x c 2
			jb X_Less_4		// если x < 2, то переходим на метку X_Less_4
			jge X_Greater_4 // если x >= 2, то переходим на метку X_Greater_4

			X_Less_4 :		// x < 2
		fsin 			// st(0) = sin(x)
			fld x // st(0) = x, st(1) = sin(x)
			fmul // st(0) = x * sin(x)
			jmp finish		// переход к финишу

			X_Greater_4 :	// x > 2
		fld three			// st(0) = 3, st(1) = x
			fxch			// st(0) <-> st(1)
			fcomi st, st(1)	// сравниваем x c 3
			jae X_Greater_6	// если x >= 3, то переходим на метку X_Greater_6
			// если x < 3, то продолжаем
			fadd ten // st(0) = x + 10
			fld x // st(0) = x, st(1) = x + 10
			fmul x // st(0) = x^2
			fadd two // st(0) = x^2 + 2
			fdivp st(1), st // (x+10)/(x^2+2)
			jmp finish		// переход к финишу

			X_Greater_6 : // x > 3



			finish : fstp y // поместили результат в y
	}

	cout << "Результаты вычислений на Assembler: " << y << endl;

	// -- здесь вычисление формулы на С++ -- 
	if (x < -5) y = 2 / x;
	else if (x >= -5 && x < 2) y = x * sin(x);
	else if (x >= 2 && x < 3) y = (x + 10) / (2 + x * x);
	else if (x >= 3) y = x + pow(x, 1.0 / 3);
	cout << "Результаты вычислений на C++: " << y << endl << endl;
}

//void UnfullBranch(double x, double y)
//{
//	const double ten = 10, two = 2, three = 3, sfive = -5; // объявляем и инициализируем константые переменные
//
//	__asm
//	{
//		fld sthree			// скопировали -3 в st(0)
//		fld x				// скопировали x в st(0), а -3 провалилось в st(1)
//		fcomi st, st(1)		// сравниваем x с -3
//
//		jb X_Less_s3		// если x < -3, то переходим на метку X_Less_s3
//
//		fld four			// st(0) = 4, st(1) = x
//		fxch				// st(0) = x, st(1) = 4 (st(0) <-> st(1))
//		fcomi st, st(1)		// сравниваем x c 4
//		jb X_Less_4			// если x < 4, то переходим на метку X_Less_4
//
//		fld six				// st(0) = 6, st(1) = x
//		fxch				// st(0) <-> st(1)
//		fcomi st, st(1)		// сравниваем x c 6
//		jae X_Greater_6		// если x >= 6, то переходим на метку X_Greater_6
//		// если x < 6, то продолжаем
//		fld1				// st(0) = 1, st(1) = x
//		fxch				// st(0) <-> st(1)
//		fyl2x				// st(1) = st(1) * log2(x) вместе с этим выгрузился st(0) (st(0) <- st(1))
//		fldl2t				// st(0) = log2(10)
//		fdivp st(1), st		// log2(x)/log2(10) = lg(x)
//		jmp finish			// переход к финишу
//
//		X_Greater_6 :		// x > 6
//		fsin				// st(0) = sin(x)
//			fld x			// st(0) = x, st(1) = sin(x)
//			fsin			// st(0) = sin(x)
//			fmul			// sin^2(x)
//			jmp finish		// переход к финишу
//
//			X_Less_4 :		// x < 4 
//		fmul p_one			// x * 0.1
//			fldl2e			// st(0) = log2(e), st(1) = x * 0.1
//			fmul			// st(0) = log2(e) * (x * 0.1)
//			fld st			// st(0) = st(1) = log2(e) * (x * 0.1)
//			frndint			// округлили st(0)		|	т.к. x * 0.1 в заданном диапазоне не может быть
//			fsub st(1), st	// st(1) -= st(0)		|	больше 1 или меньше -1, то эти 3 строчки можно
//			fxch			// st(0) <-> st(1)		|	не писать
//			f2xm1			// st(0) = 2^st(0) - 1	
//			fld1			// st(0) = 1, st(1) = 2^st(1) - 1, st(2) = log2(e) * (x * 0.1)
//			fadd			// st(0) = 2^st(0), st(1) = log2(e) * (x * 0.1)
//			fscale			// st(0) = 2^st(0) * 2^(log2(e) * (x * 0.1))
//			jmp finish		// переход к финишу
//
//			X_Less_s3 :		// x < -3
//		fcos				// st(0) = cos(x)
//			fld x			// st(0) = x, st(1) = cos(x)
//			fadd ten		// st(0) = x+10
//			fdiv			// st(0) = cos(x)/(x+10)
//
//			finish : fstp y // поместили результат в y
//	}
//
//	cout << "Результаты вычислений на Assembler: " << y << endl;
//
//	// -- здесь вычисление формулы на С++ -- 
//	if (x < -5) y = 2 / x;
//	if (x >= -5 && x < 2) y = x * sin(x);
//	if (x >= 2 && x < 3) y = (x + 10) / (2 + x * x);
//	if (x >= 3) y = x + pow(x, 1 / 3);
//
//	cout << "Результаты вычислений на C++: " << y << endl << endl;
//}

int main()
{
	setlocale(LC_ALL, "Russian");	// установка русского алфавита
	// если x < -5, то y = 2/x
	// если -5 <= x < 2, то y = x * sin(x)
	// если 2 <= x < 3, то y = (x + 10) / (2 + x * x)
	// если x >= 3, то y = x + x^(1/3)

	// -- тестовые значения --

	int choice; // объявляем переменную выбора решения
	double x = 0, y = 0; // объявляем переменные и инициализируем в ноль

	cout << "Яхьяев Данис. Лабораторная работа № 11-12. Вариант №18(3)." << endl;

	cout << "Введите способ решения:\n1.Полное ветвление\n2.Краткая форма ветвления\n\nВвод: ";
	cin >> choice;

	if (cin.good()) {
		cout << "Введите x: ";
		cin >> x;	//ввод значения x
	}

	switch (choice)
	{
	case 1:
		FullBranch(x, y);
		break;
	case 2:
		//UnfullBranch(x, y);
		break;
	default:
		break;
	}
	return 0;
}