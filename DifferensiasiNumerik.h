#pragma once
#include <iostream>
#include <functional>
#include <iomanip>

class Differensiasi {
private:
	int iterasiCount;
	double a, b, h;
	double x[10000], fX[10000], fTurunan[10000], fTurunanEksak[10000], error[10000];

	double Maju(double x, double h, std::function<double(double)> function);
	double Mundur(double x, double h, std::function<double(double)> function);
	double Tengahan(double x, double h, std::function<double(double)> function);
	
	double Error(double x, double h, std::function<double(double)> function);
	double AverageError();

public:
	Differensiasi() = default;

	void GetInput();
	void RunMethod(std::function<double(double)> function, std::function<double(double)> functionEksak, std::function<double(double)> functionEksakDua);
	void ShowTable();
};