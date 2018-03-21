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

	void insertPointInPos(int pos, double xpos, double ypos) {
		setjA(getjA() + 1);

		double **newArray;
		newArray = new double*[getiA()];
		for (int i = 0; i < getiA(); i++) {
			newArray[i] = new double[getjA()];
		}
		for (int i = 1; i < pos; i++) {
			newArray[0][i - 1] = getX(i);
			newArray[1][i - 1] = getY(i);
		}

		for (int i = getjA(); i > pos; i--) {
			newArray[0][i-1] = getX(i-1);
			newArray[1][i-1] = getY(i-1);
		}

		setNMA(newArray);
		setX(pos, xpos);
		setY(pos, ypos);
	}
	void insertPoint(double xpos, double ypos) {
		setjA(getjA() + 1);

		double **newArray;
		newArray = new double*[getiA()];
		for (int i = 0; i < getiA(); i++) {
			newArray[i] = new double[getjA()];
		}

		int needI = 1;
		while ((xpos > getX(needI))&&(needI<getjA())) { needI++; }
		for (int i = 1; i < needI; i++) {
			newArray[0][i - 1] = getX(i);
			newArray[1][i - 1] = getY(i);
		}

		int lastelement = getjA();
		if (lastelement == needI) lastelement--;

		for (int i = lastelement; i > needI; i--) {
			newArray[0][i - 1] = getX(i - 1);
			newArray[1][i - 1] = getY(i - 1);
		}

		setNMA(newArray);
		setX(needI, xpos);
		setY(needI, ypos);
	}

	~nm_Points() {}
};

#endif NM_POINTS_CLASS_H
