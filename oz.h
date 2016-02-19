#ifndef OZ_H
#define OZ_H

#include<stdio.h>
#include<stdlib.h>
#include<GLUT/glut.h>
#include<math.h>

extern GLuint objects;

extern int clickx,clicky;
extern double abv;
extern double a;
extern double v[];
extern double t;
extern double pi;
extern int ww,hh;

extern double ex , ez, ey ;
extern double r;

extern double bwidth;
extern double bheight;
extern double bdepth;

extern GLuint texID[100];
extern int ID_KEY;

extern int i;
extern int goaheadflg;
extern int gobackflg;
extern int goleftflg;
extern int gorightflg;
extern int goupflg;
extern int godownflg;
extern double mv;

extern GLfloat white[];

extern double wwidth;
extern double wheight;
extern double wdepth1;
extern double wdepth2;


extern void ellipsoid(double scl,float R,float shpnessx,float shpnessz,double rx,double ry,double rz);
extern void book(double x0, double y0, double z0);
extern double norm(double *vec, int n);
extern double inner_product(double *vec1, double *vec2, int n);
extern double included_angle(double *vec1, double *vec2, int n);
extern double to_deg(double r);
extern void booksrainbow(int booknum, double d, int R,double interval);
extern void books3c(int booknum, double d, int R,double interval,GLfloat color1[4],GLfloat color2[4],GLfloat color3[4]);
extern void books(int booknum, double d, int r,double interval,GLfloat color1[4],GLfloat color2[4]);
extern void ellipsoidsmall(double scl,float R,float shpnessx,float shpnessz,double rx,double ry,double rz);
extern void ellipsoid(double scl,float R,float shpnessx,float shpnessz,double rx,double ry,double rz);
extern void pillar(double scl,float R,float length,float shpnessx,float shpnessz,double rx,double ry,double rz);
extern void scene(void);
extern double talextoy(double x,double y0);
  extern double talextoz(double x,double z0);
extern void stand(double x0, double y0, double z0,double r);



#endif
