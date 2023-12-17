#pragma once
#ifdef Useful_API
#define Useful_API __declspec(dllexport)
#else
#define Useful_API __declspec(dllimport)
#endif // Useful_API

Useful_API double Newton_sqrt(double n);
Useful_API unsigned int __abs(int value);
Useful_API double integrate(double a, double b, int n);
Useful_API float qfsind(float x);
Useful_API float qfcosd(float a);
Useful_API int info();
class Useful_API Useful {
public:
	//TODO
};