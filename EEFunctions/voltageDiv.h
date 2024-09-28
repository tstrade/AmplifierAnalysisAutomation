#ifndef VOLTAGEDIV_H
#define VOLTAGEDIV_H

double findVS(double Vi, double Rs, double Ri);
double findVI(double Vs, double Rs, double Ri);
double findRS(double Vs, double Vi, double Ri);
double findRI(double Vs, double Vi, double Rs);
double findVIVS(double *);
double (*vFuncs[4])(double, double, double);

#endif
