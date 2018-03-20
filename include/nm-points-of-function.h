#ifndef NM_POINTS_OF_FUNCTION_H

/*
	Author: reznikovkg
	GitHub: https://github.com/reznikovkg
	Email: kosrez1@yandex.ru

	File: include/nm-points-class.h
	GitHub Repository: https://github.com/reznikovkg/nm-points
*/

#define NM_POINTS_OF_FUNCTION_H

// class interpolation polinom by Newton
class nm_PointsOfFunction
{
private:
	typedef double(*Func)(double);
	Func ipnF;
	double a; double b;
	int n; double h;
	nm_Points points;

public:

	nm_PointsOfFunction() {}

	nm_PointsOfFunction(Func ff, double fa, double fb, char typeParam, double fparam) {
		ipnF = ff; a = fa; b = fb;
		switch (typeParam)
		{
		case 'h': {
			n = (int)((b - a) / fparam) + 1;
			points = nm_Points(n);
			break;
		}
		case 'n': {
			h = (b - a) / (fparam - 1);
			points = nm_Points(fparam);
			break;
		}
		default:
			break;
		}
		setPoints();
	};

	double f(double x) { return this->ipnF(x); }

	double getA() { return this->a; } void setA(double fa) { a = fa; }
	double getB() { return this->b; } void setB(double fb) { b = fb; }
	double getH() { return this->h; } void setH(double fh) { h = fh; }
	double getN() { return this->n; } void setN(int fn) { n = fn; }

	nm_Points getPoints() { return this->points; }
	void setPoints() {
		for (int i = 1; i <= points.getN(); i++) {
			points.setX(i, a + h * (i - 1));
			points.setY(i, f(a + h * (i - 1)));
		}
	}
	void printPoints() { points.printNMA(); }

	double getPointX(int i) { return this->points.getX(i); }
	double getPointY(int i) { return this->points.getY(i); }

	~nm_PointsOfFunction() {}
};

#endif NM_POINTS_OF_FUNCTION_H
