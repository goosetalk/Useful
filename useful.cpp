#include "useful.h"
#include <iostream>
using namespace std;
const float hollyst = 0.017453292519943295769236907684886;

const float sin_table[] = {
    0.0,                                    //sin(0)
    0.17364817766693034885171662676931 ,    //sin(10)
    0.34202014332566873304409961468226 ,    //sin(20)
    0.5 ,                                   //sin(30)
    0.64278760968653932632264340990726 ,    //sin(40)
    0.76604444311897803520239265055542 ,    //sin(50)
    0.86602540378443864676372317075294 ,    //sin(60)
    0.93969262078590838405410927732473 ,    //sin(70)
    0.98480775301220805936674302458952 ,    //sin(80)
    1.0                                     //sin(90)
};

const float cos_table[] = {
    1.0 ,                                   //cos(0)
    0.99984769515639123915701155881391 ,    //cos(1)
    0.99939082701909573000624344004393 ,    //cos(2)
    0.99862953475457387378449205843944 ,    //cos(3)
    0.99756405025982424761316268064426 ,    //cos(4)
    0.99619469809174553229501040247389 ,    //cos(5)
    0.99452189536827333692269194498057 ,    //cos(6)
    0.99254615164132203498006158933058 ,    //cos(7)
    0.99026806874157031508377486734485 ,    //cos(8)
    0.98768834059513772619004024769344      //cos(9)
};
unsigned int __abs(int value)
{
	unsigned int copyed_value = value;
	return (copyed_value > 0x80000000) ? -value : copyed_value;
}
double Newton_sqrt(double n) {
	double x0, x1;
	x0 = n / 2;
	x1 = x0 - (x0 * x0 - n) / (2 * x0);
	while (__abs(x0 - x1) >= 1e-9)
	{
		x0 = x1;
		x1 = x0 - (x0 * x0 - n) / (2 * x0);
	}
    return x1;
}
const double PI = 3.14159265358979323846;
double f(double x) {
    // 定义被积函数
    return qfsind(x);
}
double integrate(double a, double b, int n) {
    double h = (b - a) / n;  // 计算每个小区间的宽度
    double sum = 0.0;

    // 使用梯形法则进行数值积分
    for (int i = 0; i <= n; i++) {
        double x = a + i * h;
        if (i == 0 || i == n) {
            sum += f(x);
        }
        else {
            sum += 2 * f(x);
        }
    }
    sum *= h / 2;

    return sum;
}
float qfsind(float x)
{
    int sig = 0;

    if (x > 0.0) {
        while (x >= 360.0) {
            x = x - 360.0;
        }
    }
    else {
        while (x < 0.0) {
            x = x + 360.0;
        }
    }

    if (x >= 180.0) {
        sig = 1;
        x = x - 180.0;
    }

    x = (x > 90.0) ? (180.0 - x) : x;

    int a = x * 0.1;
    float b = x - 10 * a;

    float y = sin_table[a] * cos_table[(int)b] + b * hollyst * sin_table[9 - a];

    return (sig > 0) ? -y : y;
}
float qfcosd(float a)
{
    float a_sin = a + 90;
    a_sin = a_sin > 360 ? a_sin - 360 : a_sin;
    return qfsind(a_sin);
}
int info() {
    cout << "Chinese:" << endl;
    cout << "这个DLL只是随手瞎做的，不要过度(喷)评论(我)" << endl;
    cout << "不会引用上网查" << endl;
    cout << "Engish:" << endl;
    cout << "This DLL is just done blindly, don't scold me." << endl;
    cout << "If you don't know how to import DLLs, look them up online." << endl;
    cout << "The English part is translated from Bing, if there are grammatical errors, please understand." << endl;
    cout << "Help? (If you want to get help,type 1,otherwise type 0 to exit)" << endl;
    int a;
    cin >> a;
    switch(a) {
        case 1:
            cout << "The \"__abs\" functions the same as the \"abs\" method in cmath" << endl;
            cout << "The \"Newton_sqrt\" method makes squaring even faster" << endl;
            cout << "Don't care method \"f\"" << endl;
            cout << "Method \"integrate\" can calculate definite integrals" << endl;
            cout << "\"qfsind\" is a quick version of \"sin\" in cmath" << endl;
            cout << "\"qfcosd\" is a quick version of \"cos\" in cmath too" << endl;
            cout << "And,the method \"info \" is the method that is working right now" << endl;
            return 1;
        case 0:
            return 0;
    }
}