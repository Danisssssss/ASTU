#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    float zero = 0;
    float x1, x2, y1, x3, x4, y2, y3, y4;
    float s;
    // cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    // 2 4 12 0 10 6 14 0
    x1 = 2; y1 = 4; x2 = 12; y2 = 0; x3 = 10; y3 = 6; x4 = 14; y4 = 0;

    __asm {
        // Сравнение x2 и x3
        fld x2 // Загрузка значения x2 в st(0)
        fld x3 // Загрузка значения x3 в st(0), st(1) = x2
        fcomi st, st(1)
        jae zero_area // если x3 >= x2, то переходим на метку zero_area

        // Сравнение x4 и x1
        fld x4 // Загрузка значения x4 в st(0)
        fld x1 // Загрузка значения x1 в st(0), st(1) = x4
        fcomi st, st(1) // сравнение
        jae zero_area // если x1 >= x4, то переходим на метку zero_area

        // Сравнение y1 и y3
        fld y3 // Загрузка значения y3 в st(0)
        fld y1 // Загрузка значения y1 в st(0), st(1) = y3
        fcomi st, st(1) // сравнение

        jb y1_less_y3 // если y1 < y3, то переходим на метку y1_less_y3
        jae y1_more_y3 // если y1 >= y3, то переходимна метку y1_more_y3

        y1_less_y3 :
        fld x1 // Загрузка значения x1 в st(0)
            fld x3 // Загрузка значения x3 в st(0), st(1) = x1
            fcomi st, st(1) // сравнение
            jae y1_less_y3_x3_more_x1 // если x3 >= x1, то переходим на метку y1_less_y3_x3_more_x1
            jbe y1_less_y3_x3_less_x1 // если x3 <= x1, то переходим на метку y1_less_y3_x3_less_x1

            y1_less_y3_x3_more_x1 :
        fld x2 // Загрузка значения x4 в st(0), st(1) = x2
            fld x4 // Загрузка значения x2 в st(0)
            fcomi st, st(1) // сравнение

            jae y1_less_y3_x3_more_x1_and_x4_more_x2 // если x4 >= x2, то переходим на метку y1_less_y3_x3_more_x1_and_x4_more_x2
            
            y1_less_y3_x3_more_x1_and_x4_more_x2 :
        fld x2 // Загрузка значения x2 в st(0)
            fsub x3 // st(0) = x2 - x3
            fabs // st(0) = abs(x2-x3)
            fld y1 // st(0) = y1, st(1) = abs(x2-x3)
            fmul // abs(x2-x3) * y1
            jmp finish // переход к финишу

            jbe y1_less_y3_x3_more_x1_and_x4_less_x2 // если x4 <= x2, то переходим на метку y1_less_y3_x3_more_x1_and_x4_less_x2

            y1_less_y3_x3_more_x1_and_x4_less_x2 :
        fld x4 // Загрузка значения x4 в st(0)
            fsub x3 // st(0) = x4 - x3
            fabs // st(0) = abs(x4-x3)
            fchs
            fmul y1 // st(0) = abs(x4-x3) * y1
            jmp finish // переход к финишу

            y1_less_y3_x3_less_x1 :
        fld x2 // Загрузка значения x2 в st(0)
            fld x4 // Загрузка значения x4 в st(0), st(1) = x2
            fcomi st, st(1) // сравнение
            jae y1_less_y3_x3_less_x1_and_x4_more_x2 // если x4 >= x2, то переходим на метку y1_less_y3_x3_less_x1_and_x4_more_x2
            jbe y1_less_y3_x3_less_x1_and_x4_less_x2 // если x4 <= x2, то переходим на метку y1_less_y3_x3_less_x1_and_x4_less_x2

            y1_less_y3_x3_less_x1_and_x4_less_x2 :
        fld x4 // Загрузка значения x4 в st(0)
            fsub x1 // st(0) = x4 - x1
            fabs // st(0) = abs(x4-x1)
            fmul y1 // st(0) = abs(x4-x1) * y1
            jmp finish // переход к финишу

            y1_less_y3_x3_less_x1_and_x4_more_x2 :
        fld x2 // Загрузка значения x2 в st(0)
            fsub x1 // st(0) = x2 - x1
            fabs // st(0) = abs(x2-x1)
            fmul y1 // st(0) = abs(x2-x1) * y1
            jmp finish // переход к финишу


        y1_more_y3 :
        fld x1 // Загрузка значения x1 в st(0)
            fld x3 // Загрузка значения x3 в st(0), st(1) = x1
            fcomi st, st(1) // сравнение
            jae y1_more_x1_x3_more_x1 // если x3 >= x1, то переходим на метку y1_more_x1_x3_more_x1
            jbe y1_more_x1_x3_less_x1 // если x3 <= x1, то переходим на метку y1_more_x1_x3_less_x1

            y1_more_x1_x3_more_x1 :
        fld x2 // Загрузка значения x2 в st(0)
            fld x4 // Загрузка значения x4 в st(0), st(1) = x2
            fcomi st, st(1) // сравнение
            jbe y1_more_x1_x3_more_x1_and_x4_less_x2 // если x4 <= x2, то переходим на метку y1_more_x1_x3_more_x1_and_x4_less_x2
            jae y1_more_x1_x3_more_x1_and_x4_more_x2 // если x4 >= x2, то переходим на метку y1_more_x1_x3_more_x1_and_x4_more_x2

            y1_more_x1_x3_more_x1_and_x4_less_x2 :
        fld x4 // Загрузка значения x4 в st(0)
            fsub x3 // st(0) = x4 - x3
            fabs // st(0) = abs(x4-x3)
            fmul y3 // st(0) = abs(x4-x3) * y3
            jmp finish // переход к финишу
           
            y1_more_x1_x3_more_x1_and_x4_more_x2 :
        fld x2 // Загрузка значения x2 в st(0)
            fsub x3 // st(0) = x2 - x3
            fabs // st(0) = abs(x2-x3)
            fmul y3 // st(0) = abs(x2-x3) * y3
            jmp finish // переход к финишу

            y1_more_x1_x3_less_x1 :
        fld x2 // Загрузка значения x2 в st(0)
            fld x4 // Загрузка значения x4 в st(0), st(1) = x2
            fcomi st, st(1) // сравнение
            jbe y1_more_x1_x3_less_x1_and_x4_less_x2 // если x4 <= x2, то переходим на метку y1_more_x1_x3_less_x1_and_x4_less_x2
            jae y1_more_x1_x3_less_x1_and_x4_more_x2 // если x4 >= x2, то переходим на метку y1_more_x1_x3_less_x1_and_x4_more_x2

            y1_more_x1_x3_less_x1_and_x4_more_x2 :
        fld x2 // Загрузка значения x2 в st(0)
            fsub x1 // st(0) = x2 - x1
            fabs // st(0) = abs(x2-x1)
            fmul y3 // st(0) = abs(x2-x1) * y3
            jmp finish // переход к финишу

            y1_more_x1_x3_less_x1_and_x4_less_x2 :
        fld x4 // Загрузка значения x4 в st(0)
            fsub x1 // st(0) = x4 - x1
            fabs // st(0) = abs(x4-x1)
            fmul y3 // st(0) = abs(x4-x1) * y3
            jmp finish // переход к финишу

            zero_area :
        fld zero // Загрузка нуля в st(0)
            jmp finish // переход к финишу

            finish : fstp s // поместили результат в s
    }

    cout << "Площадь пересечения: " << s << endl;

    // Проверка на C++
    if (x3 >= x2 || x4 <= x1)
        s = 0;
    else {
        if (y1 >= y3) {
            if (x3 >= x1 && x4 <= x2) s = (x4 - x3) * y3;
            else if (x3 >= x1 && x4 >= x2) s = abs((x2 - x3)) * y3;
            else if (x3 <= x1 && x4 >= x2) s = abs((x2 - x1)) * y3;
            else if (x3 <= x1 && x4 <= x2) s = abs((x4 - x1)) * y3;
        }
        else {
            if (x3 >= x1 && x4 <= x2)
                s = abs((x4 - x3)) * y1;
            else if (x3 >= x1 && x4 >= x2)
                s = abs((x2 - x3)) * y1;
            else if (x3 <= x1 && x4 >= x2)
                s = abs((x2 - x1)) * y1;
            else if (x3 <= x1 && x4 <= x2)
                s = abs((x4 - x1)) * y1;
        }
    }
    cout << "Проверка на C++: " << s;

    return 0;
}