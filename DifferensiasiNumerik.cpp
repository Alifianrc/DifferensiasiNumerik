#include "DifferensiasiNumerik.h"

// f'(x) = (f(x + h) - f(x)) / h 
double Differensiasi::Maju(double x, double h, std::function<double(double)> function) {
	double result = (function(x + h) - function(x)) / h;
	return result;
}
// f'(X) = (f(x) - f(x - h)) / h
double Differensiasi::Mundur(double x, double h, std::function<double(double)> function) {
	double result = (function(x) - function(x - h)) / h;
	return result;
}
// f'(x) = (f(x + h) - f(x - h)) / 2h
double Differensiasi::Tengahan(double x, double h, std::function<double(double)> function) {
	double result = (function(x + h) - function(x - h)) / (2*h);
	return result;
}


double Differensiasi::Error(double x, double h, std::function<double(double)> function) {
	double result = -0.5 * h * function(x);
	return result;
}
double  Differensiasi::AverageError() {
	double result = 0;

	for (int i = 0; i < iterasiCount; i++) {
		result = result + error[i];
	}
	result = result/iterasiCount;

	return result;
}


void Differensiasi::GetInput() {
	std::cout << "Masukkan Batas Bawah (a)   : "; std::cin >> a;
	std::cout << "Masukkan Batas Atas (b)    : "; std::cin >> b;
	std::cout << "Masukkan Step h            : "; std::cin >> h;
	std::cout << std::endl;
}
void Differensiasi::RunMethod(std::function<double(double)> function, std::function<double(double)> functionEksak, std::function<double(double)> functionEksakDua) {
	bool condition = true;
	int iterasi = 0;

	while (condition) {
		x[iterasi] = a + (h * iterasi);
		fX[iterasi] = function(x[iterasi]);
		fTurunan[iterasi] = Maju(x[iterasi], (h * iterasi), function);
		fTurunanEksak[iterasi] = functionEksak(x[iterasi]);
		error[iterasi] = Error(x[iterasi], (h * iterasi), functionEksakDua);

		if (x[iterasi] > b) {
			condition = false;
		}
		else {
			iterasi++;
		}
	}

	iterasiCount = iterasi;
}
void Differensiasi::ShowTable() {
	std::cout << "                        Tabel Iterasi\n";
	std::cout << "Iterasi     x               f(x)               f'(x)              f'eksak(x)         Error\n";

	std::cout << std::fixed << std::setprecision(9);
	for (int i = 0; i < iterasiCount; i++) {
		std::cout << i + 1 << "           " << x[i] << "     " << fX[i] << "        " << fTurunan[i] << "        " << fTurunanEksak[i] << "        " << error[i] << std::endl;
	}
	std::cout << "\n Rata-rata Error : " << AverageError() << std::endl;
}