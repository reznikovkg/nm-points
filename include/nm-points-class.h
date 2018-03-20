#ifndef NM_POINTS_CLASS_H

/*
	Author: reznikovkg
	GitHub: https://github.com/reznikovkg
	Email: kosrez1@yandex.ru

	File: include/nm-points-class.h
	GitHub Repository: https://github.com/reznikovkg/nm-points
*/

#define NM_POINTS_CLASS_H

// class interpolation polinom by Newton
class nm_Points : public nm_Array
{
private:

public:
	nm_Points() : nm_Array() {}
	nm_Points(int pN) : nm_Array(2, pN) {};

	double getX(int i) { return getNMA(0, i - 1); } void setX(int i, double k) { setNMA(0, i - 1, k); }
	double getY(int i) { return getNMA(1, i - 1); } void setY(int i, double k) { setNMA(1, i - 1, k); }
	int getN() { return getjA(); }

	~nm_Points() {}
};

#endif NM_POINTS_CLASS_H
