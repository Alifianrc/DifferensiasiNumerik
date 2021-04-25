#include "DifferensiasiNumerik.h"

// f(x) = (e^-x) * sin(2X) + 1
double functionX(double x) {
	double result = (pow(exp(1), -x) * sin(2 * x)) + 1;
	return result;
}
// f'(x) = (2(e^-x) * cos (2x)) - ((e^-x) * sin(2x))
double functionEksak(double x) {
	double result = (2 * pow(exp(1), -x) * cos(2 * x)) - (pow(exp(1), -x) * sin(2 * x));
	return result;
}
// f''(x) = (-3 * (e^-x) * sin(2x)) - (4 * (e^-x) cos(2x))
double functionEksakDua(double x) {
	double result = (-3 * pow(exp(1), -x) * sin(2 * x)) - (4 * pow(exp(1), -x) * cos(2 * x));
	return result;
}

int main() {
	Differensiasi numerik;
	numerik.GetInput();
	numerik.RunMethod(functionX, functionEksak, functionEksakDua);
	numerik.ShowTable();

	return 0;
}