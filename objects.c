#pragma once
#include "oz.h"

GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat red[] = { 1.0, 0.1, 0.1, 1.0 };
GLfloat green[] = { 0.0, 0.6, 0.2, 1.0 };
GLfloat blue[] = { 0.1, 0.1, 1.0, 1.0 };
GLfloat skyblue[] = { 0.5, 1.0, 1.0, 1.0 };
GLfloat orange[] = { 0.8, 0.4, 0.0, 1.0 };
GLfloat purple[] = { 0.4, 0.0, 0.6, 1.0 };
GLfloat pink[] = { 0.8, 0.0, 0.6, 1.0 };
GLfloat yellow[] = { 1.0, 1.0, 0.2, 1.0 };
GLfloat yellowgreen[] = { 0.0, 1.0, 0.2, 1.0 };


double norm(double *vec, int n) {
    int i;
    double s = 0.0;

    for ( i = 0; i < n; i++ ) {
        s += vec[i] * vec[i];
	printf("vec = %d  nijou = %f \n",vec[i],s);
    }

    return sqrt(s);
}

double inner_product(double *vec1, double *vec2, int n) {
    int i;
    double s = 0.0;

    for ( i = 0; i < n; i++ ) {
        s += vec1[i] * vec2[i];
    }

    return s;
}

double included_angle(double *vec1, double *vec2, int n) {
    return acos(inner_product(vec1, vec2, n) / 
        (norm(vec1, n) * norm(vec2, n)));
}

double to_deg(double r) {
    return r * 180.0 / (atan(1.0) * 4.0);
}


void booksrainbow(int booknum, double d, int R,double interval){
  int i,j=0;
  double r = to_deg(acos(1 - interval*interval/(2*d*d)));
  double rrad = acos(1 - interval*interval/(2*d*d));
  GLfloat bookcolor[booknum][4];
  GLfloat color[8][4] = {{ 1.0, 0.1, 0.1, 1.0 }, /*red*/
			{ 0.8, 0.0, 0.6, 1.0 }, /*pink*/
			{ 0.1, 0.1, 1.0, 1.0 }, /*blue*/
			{ 0.5, 1.0, 1.0, 1.0 }, /*skyblue*/
			{ 0.1, 1.0, 0.1, 1.0 }, /*green*/
			{ 0.0, 1.0, 0.2, 1.0 }, /*yellowgreen*/
			 { 1.0, 1.0, 0.2, 1.0 },/*yellow*/
			 { 1.0, 0.1, 0.1, 1.0 }}; /*red*/

  double y0 = 7.0;

  glRotated(R, 0.0, 1.0, 0.0);   
  for(i=0;i<booknum;i++){

    if(0 < i && i < booknum/14 || 7*booknum/14 < i && i < 8*booknum/14) j = 0;
    else if((booknum/14 < i && i< 2*booknum/14) || (8*booknum/14 < i && i < 9*booknum/14)) j = 1;
    else if((2*booknum/14 < i && i< 3*booknum/14) || (9*booknum/14 < i && i < 10*booknum/14)) j = 2;
    else if((3*booknum/14 < i && i< 4*booknum/14) || (10*booknum/14 < i && i < 11*booknum/14)) j = 3;
    else if((4*booknum/14 < i && i< 5*booknum/14) || (11*booknum/14 < i && i < 12*booknum/14)) j = 4;
    else if((5*booknum/14 < i && i< 6*booknum/14) || (12*booknum/14 < i && i < 13*booknum/14)) j = 5;
    else if((6*booknum/14 < i && i< 7*booknum/14) || (13*booknum/14 < i && i < 14*booknum/14)) j = 6;
    
    //if(*booknum/14 < i && i< *booknum/14 || *booknum/14 < i && i < *booknum/14) j = 0;
    /*
    if(i == 7*booknum/14) j = 0;
    else if(i == booknum/14 || i ==  8*booknum/14 ) j = 1;
    else if(i == 2*booknum/14 || i == 9*booknum/14 ) j = 2;
    else if(i == 3*booknum/14 || i == 10*booknum/14 ) j = 3;
    else if(i == 4*booknum/14 || i == 11*booknum/14 ) j = 4;
    else if(i == 5*booknum/14 || i == 12*booknum/14 ) j = 5;
    else if(i == 6*booknum/14 || i == 13*booknum/14 ) j = 6;
    */

    if(i < booknum/2){
      bookcolor[i][0] = color[j][0] + ( color[j+1][0] - color[j][0] )* (i - j*booknum/14)/ (booknum/14);
      bookcolor[i][1] = color[j][1] + ( color[j+1][1] - color[j][1] )* (i - j*booknum/14)/ (booknum/14);
      bookcolor[i][2] = color[j][2] + ( color[j+1][2] - color[j][2] )* (i - j*booknum/14)/ (booknum/14);
      bookcolor[i][3] = color[j][3] + ( color[j+1][3] - color[j][3] )* (i - j*booknum/14)/ (booknum/14);
    }else{
      bookcolor[i][0] = color[j][0] + ( color[j+1][0] - color[j][0] )* (i - (j+7)*booknum/14)/ (booknum/14);
      bookcolor[i][1] = color[j][1] + ( color[j+1][1] - color[j][1] )* (i - (j+7)*booknum/14)/ (booknum/14);
      bookcolor[i][2] = color[j][2] + ( color[j+1][2] - color[j][2] )* (i - (j+7)*booknum/14)/ (booknum/14);
      bookcolor[i][3] = color[j][3] + ( color[j+1][3] - color[j][3] )* (i - (j+7)*booknum/14)/ (booknum/14);
    }

    glRotated(r, 0.0, 1.0, 0.0);   
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, bookcolor[i]);
    book(d,y0,0.0);
    book(d,y0+1.0,0.0);
    book(d,y0+2.0,0.0);
    glPopMatrix();
    glPopAttrib();
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
    stand(d,y0,0,rrad);
    stand(d,y0+1.0,0.0,rrad);
    stand(d,y0+2.0,0.0,rrad);
    stand(d,y0+3.0,0.0,rrad);
    glPopMatrix();
    glPopAttrib();

  }

}

void books3c(int booknum, double d, int R,double interval,GLfloat color1[4],GLfloat color2[4],GLfloat color3[4]){
  int i;
  double y0 = 7.0;
  double r = to_deg(acos(1 - interval*interval/(2*d*d)));
  double rrad = acos(1 - interval*interval/(2*d*d));
  GLfloat colors[booknum][4];

  //R = to_deg(included_angle(xunivec,vec,2));
  //printf("R = %d r = %f xunivec norm = %f,vec norm =  %f,naiseki =  %f    \n",R,r,norm(xunivec,2),norm(vec,2),inner_product(vec,xunivec,2));

  glRotated(R, 0.0, 1.0, 0.0);   
  for(i=0;i<booknum;i++){
    if(i<booknum/2){
      colors[i][0] = color1[0] + ( color2[0] - color1[0] )* i / (booknum/2);
      colors[i][1] = color1[1] + ( color2[1] - color1[1] )* i / (booknum/2);
      colors[i][2] = color1[2] + ( color2[2] - color1[2] )* i / (booknum/2);
      colors[i][3] = color1[3] + ( color2[3] - color1[3] )* i / (booknum/2);
    }else{
      colors[i][0] = color2[0] + ( color3[0] - color2[0] )* (i - booknum/2) / (booknum/2);
      colors[i][1] = color2[1] + ( color3[1] - color2[1] )* (i - booknum/2) / (booknum/2);
      colors[i][2] = color2[2] + ( color3[2] - color2[2] )* (i - booknum/2) / (booknum/2);
      colors[i][3] = color2[3] + ( color3[3] - color2[3] )* (i - booknum/2) / (booknum/2);
    }
    
    glRotated(r, 0.0, 1.0, 0.0);   
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colors[i]);
    book(d,y0,0.0);
    book(d,y0+1.0,0.0);
    book(d,y0+2.0,0.0);
    glPopMatrix();
    glPopAttrib();
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
    stand(d,y0,0,rrad);
    stand(d,y0+1.0,0.0,rrad);
    stand(d,y0+2.0,0.0,rrad);
    stand(d,y0+3.0,0.0,rrad);
    glPopMatrix();
    glPopAttrib();

  }

}



void books(int booknum, double d, int R,double interval,GLfloat color1[4],GLfloat color2[4]){
  int i;
  double y0 = 7.0;
  //int R;
  //static double xunivec[] = {1.0};  //staticとると内積計算みする
  //double vec[] = {x0,z0};
  //double d = sqrt(x0*x0 + z0*z0);
  double r = to_deg(acos(1 - interval*interval/(2*d*d)));
  double rrad = acos(1 - interval*interval/(2*d*d));
  GLfloat colors[booknum][4];

  //R = to_deg(included_angle(xunivec,vec,2));
  //printf("R = %d r = %f xunivec norm = %f,vec norm =  %f,naiseki =  %f    \n",R,r,norm(xunivec,2),norm(vec,2),inner_product(vec,xunivec,2));

  glRotated(R, 0.0, 1.0, 0.0);   
  for(i=0;i<booknum;i++){
    colors[i][0] = color1[0] + ( color2[0] - color1[0] )* i / booknum;
    colors[i][1] = color1[1] + ( color2[1] - color1[1] )* i / booknum;
    colors[i][2] = color1[2] + ( color2[2] - color1[2] )* i / booknum;
    colors[i][3] = color1[3] + ( color2[3] - color1[3] )* i / booknum;
    
    glRotated(r, 0.0, 1.0, 0.0);   
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, colors[i]);
    book(d,y0,0.0);
    book(d,y0+1.0,0.0);
    book(d,y0+2.0,0.0);
    glPopMatrix();
    glPopAttrib();
    glPushMatrix();
    glPushAttrib(GL_LIGHTING_BIT);
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
    stand(d,y0,0,rrad);
    stand(d,y0+1.0,0.0,rrad);
    stand(d,y0+2.0,0.0,rrad);
    stand(d,y0+3.0,0.0,rrad);
    glPopMatrix();
    glPopAttrib();

  }

}


void book(double x0, double y0, double z0)
{
  int i;
  int j;

  GLdouble normal[][3] = {
    { 0.0, 0.0,-1.0 },
    { 1.0, 0.0, 0.0 },
    { 0.0, 0.0, 1.0 },
    {-1.0, 0.0, 0.0 },
    { 0.0,-1.0, 0.0 },
    { 0.0, 1.0, 0.0 }
  };

  GLdouble vertex[][3] = {
    { x0, y0, z0-bwidth/2 },
    { x0, y0, z0+bwidth/2 },
    { x0, y0+bheight, z0+bwidth/2 },
    { x0, y0+bheight, z0-bwidth/2 },
    { x0+bdepth, y0, z0-bwidth/2 },
    { x0+bdepth, y0, z0+bwidth/2 },
    { x0+bdepth, y0+bheight, z0+bwidth/2 },
    { x0+bdepth, y0+bheight, z0-bwidth/2 }
  };

  int face[][4] = {
    { 0, 1, 2, 3 },
    { 1, 5, 6, 2 },
    { 5, 4, 7, 6 },
    { 4, 0, 3, 7 },
    { 4, 5, 1, 0 },
    { 3, 2, 6, 7 }
  };
  
  glBegin(GL_QUADS);
  for(j=0;j<6;++j){
    glNormal3dv(normal[j]);
    for(i=0;i<4;++i){
      glVertex3dv(vertex[face[j][i]]);
    }
  }
  glEnd();
}




void ellipsoidsmall(double scl,float R,float shpnessx,float shpnessz,double rx,double ry,double rz){
  
  const float PI=3.14159265;
  float dth,dph,th,ph,thp,php;
  int i,j,k;

  R = R * scl;
  shpnessx = shpnessx * scl;
  shpnessz = shpnessz * scl;

  dth=2*PI/10;
  dph=2*PI/10;

  glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
  //glEnable(GL_LIGHTING);
  glEnable( GL_BLEND );
  glRotated(rx, 1.0, 0.0, 0.0);
  glRotated(ry, 0.0, 1.0, 0.0);
  glRotated(rz, 0.0, 0.0, 1.0);
  //glColor3d(1.0, 1.0, 0.0);
  for(i=0;i<10;i++)    
    for(j=0;j<20;j++){
      th=-PI+dth*i;
      ph=-PI+dph*j;
      thp=PI+dth*(i+1);
      php=-PI+dph*(j+1);
	  
      glBegin(GL_QUADS);
      glNormal3f(shpnessx*sin(th)*cos(ph),sin(th)*sin(ph),shpnessz*cos(th));
      glVertex3f(shpnessx*R*sin(th)*cos(ph),R*sin(th)*sin(ph),shpnessz*R*cos(th));
      glNormal3f(shpnessx*sin(thp)*cos(ph),sin(thp)*sin(ph),shpnessz*cos(thp));
      glVertex3f(shpnessx*R*sin(thp)*cos(ph),R*sin(thp)*sin(ph),shpnessz*R*cos(thp));
      glNormal3f(shpnessx*sin(thp)*cos(php),sin(thp)*sin(php),shpnessz*cos(thp));
      glVertex3f(shpnessx*R*sin(thp)*cos(php),R*sin(thp)*sin(php),shpnessz*R*cos(thp));
      glNormal3f(shpnessx*sin(th)*cos(php),sin(th)*sin(php),shpnessz*cos(th));
      glVertex3f(shpnessx*R*sin(th)*cos(php),R*sin(th)*sin(php),shpnessz*R*cos(th));
      glEnd();
    }
  glDisable( GL_BLEND );
  //glDisable(GL_LIGHTING);

}

void ellipsoid(double scl,float R,float shpnessx,float shpnessz,double rx,double ry,double rz){
  
  const float PI=3.14159265;
  float dth,dph,th,ph,thp,php;
  int i,j,k;

  R = R * scl;
  shpnessx = shpnessx * scl;
  shpnessz = shpnessz * scl;

  dth=2*PI/40;
  dph=2*PI/40;

  glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
  //glEnable(GL_LIGHTING);
  glEnable( GL_BLEND );
  glRotated(rx, 1.0, 0.0, 0.0);
  glRotated(ry, 0.0, 1.0, 0.0);
  glRotated(rz, 0.0, 0.0, 1.0);
  //glColor3d(1.0, 1.0, 0.0);
  for(i=0;i<40;i++)    
    for(j=0;j<40;j++){
      th=-PI+dth*i;
      ph=-PI+dph*j;
      thp=PI+dth*(i+1);
      php=-PI+dph*(j+1);
	  
      glBegin(GL_QUADS);
      glNormal3f(shpnessx*sin(th)*cos(ph),sin(th)*sin(ph),shpnessz*cos(th));
      glVertex3f(shpnessx*R*sin(th)*cos(ph),R*sin(th)*sin(ph),shpnessz*R*cos(th));
      glNormal3f(shpnessx*sin(thp)*cos(ph),sin(thp)*sin(ph),shpnessz*cos(thp));
      glVertex3f(shpnessx*R*sin(thp)*cos(ph),R*sin(thp)*sin(ph),shpnessz*R*cos(thp));
      glNormal3f(shpnessx*sin(thp)*cos(php),sin(thp)*sin(php),shpnessz*cos(thp));
      glVertex3f(shpnessx*R*sin(thp)*cos(php),R*sin(thp)*sin(php),shpnessz*R*cos(thp));
      glNormal3f(shpnessx*sin(th)*cos(php),sin(th)*sin(php),shpnessz*cos(th));
      glVertex3f(shpnessx*R*sin(th)*cos(php),R*sin(th)*sin(php),shpnessz*R*cos(th));
      glEnd();
    }
  glDisable( GL_BLEND );
  //glDisable(GL_LIGHTING);

}

void pillar(double scl,float R,float length,float shpnessx,float shpnessz,double rx,double ry,double rz){
  
  const float PI=3.14159265;
  float dth,dph,th,ph,thp,php;
  int i,j,k;

  R = R * scl;

  dth=length/40;
  dph=2*PI/40;

  glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
  //glEnable(GL_LIGHTING);
  glEnable( GL_BLEND );
  glRotated(rx, 1.0, 0.0, 0.0);
  glRotated(ry, 0.0, 1.0, 0.0);
  glRotated(rz, 0.0, 0.0, 1.0);
  //glColor3d(1.0, 1.0, 0.0);
  for(i=0;i<40;i++)    
    for(j=0;j<40;j++){
      th=dth*i;
      ph=-PI+dph*j;
      thp=dth*(i+1);
      php=-PI+dph*(j+1);
	  
      glBegin(GL_QUADS);
      glNormal3f(th,R*sin(ph),R*cos(ph));
      glVertex3f(th,R*sin(ph),R*cos(ph));
      glNormal3f(thp,R*sin(ph),R*cos(ph));
      glVertex3f(thp,R*sin(ph),R*cos(ph));
      glNormal3f(thp,R*sin(php),R*cos(php));
      glVertex3f(thp,R*sin(php),R*cos(php));
      glNormal3f(th,R*sin(php),R*cos(php));
      glVertex3f(th,R*sin(php),R*cos(php));
      glEnd();
    }
  glDisable( GL_BLEND );
  //glDisable(GL_LIGHTING);

}

double talextoy(double x,double y0){
  double a1 =1.0;
  double a2 =1.5;
  //return a1*x*sin(x);
    if(y0>=0)
      return a1*x;//*sin(x);
  else if(y0<0)
    return a1*x;//*sin(x);
  
}

double talextoz(double x,double z0){
  double a =0.5;
  //double b =;
  if(z0>=0)
    return a*x;
  else if(z0<0)
    return -a*x;

}

void pillarcurved(double scl,float R,float length,float shpnessx,float shpnessz,double rx,double ry,double rz,double (*f)(double,double),double (*g)(double,double)){
  
  const float PI=3.14159265;
  float dth,dph,th,ph,thp,php;
  int i,j,k;

  R = R * scl;

  dth=length/40;
  dph=2*PI/40;

  glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
  //glEnable(GL_LIGHTING);
  glEnable( GL_BLEND );
  glRotated(rx, 1.0, 0.0, 0.0);
  glRotated(ry, 0.0, 1.0, 0.0);
  glRotated(rz, 0.0, 0.0, 1.0);
  //glColor3d(1.0, 1.0, 0.0);
  for(i=0;i<40;i++)    
    for(j=0;j<40;j++){
      th=dth*i;
      ph=-PI+dph*j;
      thp=dth*(i+1);
      php=-PI+dph*(j+1);
	  
      glBegin(GL_QUADS);
      glNormal3f(th,R*sin(ph)*f(th,ph),R*cos(ph)*g(th,ph));
      glVertex3f(th,R*sin(ph)*f(th,ph),R*cos(ph)*g(th,ph));
      glNormal3f(thp,R*sin(ph)*f(thp,ph),R*cos(ph)*g(thp,ph));
      glVertex3f(thp,R*sin(ph)*f(thp,ph),R*cos(ph)*g(thp,ph));
      glNormal3f(thp,R*sin(php)*f(thp,php),R*cos(php)*g(thp,php));
      glVertex3f(thp,R*sin(php)*f(thp,php),R*cos(php)*g(thp,php));
      glNormal3f(th,R*sin(php)*f(th,php),R*cos(php)*g(th,php));
      glVertex3f(th,R*sin(php)*f(th,php),R*cos(php)*g(th,php));
      glEnd();
    }
  glDisable( GL_BLEND );
  //glDisable(GL_LIGHTING);

}


void scene(void)
{
  /* 物体の色 */
  static GLfloat red[] = { 0.8, 0.2, 0.2, 1.0 };
  static GLfloat green[] = { 0.2, 0.8, 0.2, 1.0 };
  static GLfloat blue[] = { 0.2, 0.2, 0.8, 1.0 };
  static GLfloat yellow[] = { 0.8, 0.8, 0.2, 1.0 };
  static GLfloat player[] = { 0.9, 0.8, 0.2, 1.0 };
  static GLfloat ground[][4] = {
    { 0.6, 0.6, 0.6, 1.0 },
    { 0.3, 0.3, 0.3, 1.0 }
  };

  double chscl = 1.0;

  int i, j;
  static int rball = 0;

  objects = glGenLists(1);
  glNewList(objects, GL_COMPILE);


  /*複数の本*/
  
  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  booksrainbow(840,40.0,150,0.3);
  glPopMatrix();
  glPopAttrib();
  
  
  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  books(250,50.0,15,0.3,blue,red);
  glPopMatrix();
  glPopAttrib();
  
  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  books(200,50.0,155,0.3,skyblue,yellowgreen);
  glPopMatrix();
  glPopAttrib();
  
  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  books3c(170,50.0,250,0.3,yellowgreen,yellow,orange);
  glPopMatrix();
  glPopAttrib();

  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  books(130,50.0,320,0.3,red,purple);
  glPopMatrix();
  glPopAttrib();  
  
  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  books(150,60.0,35,0.3,purple,skyblue);
  glPopMatrix();
  glPopAttrib();
  
  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  books(150,60.0,95,0.3,yellowgreen,red);
  glPopMatrix();
  glPopAttrib();
  
  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  books(250,60.0,160,0.3,red,blue);
  glPopMatrix();
  glPopAttrib();
  
  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  books(150,60.0,260,0.3,green,yellow);
  glPopMatrix();
  glPopAttrib();
 
  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  books(150,60.0,320,0.3,yellow,red);
  glPopMatrix();
  glPopAttrib();
  
  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  books3c(250,70.0,10,0.3,red,yellow,yellowgreen);
  glPopMatrix();
  glPopAttrib();
  
  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  books(100,70.0,80,0.3,green,orange);
  glPopMatrix();
  glPopAttrib();
  
  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  books(150,70.0,120,0.3,red,pink);
  glPopMatrix();
  glPopAttrib();
  
  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  books(200,70.0,170,0.3,pink,blue);
  glPopMatrix();
  glPopAttrib();
  
  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  books3c(180,70.0,240,0.3,blue,skyblue,green);
  glPopMatrix();
  glPopAttrib();
  
  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  books3c(250,70.0,295,0.3,yellowgreen,yellow,red);
  glPopMatrix();
  glPopAttrib();
  

  /* 地面 */
  glPushAttrib(GL_LIGHTING_BIT);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glBegin(GL_QUADS);
  glNormal3d(0.0, 1.0, 0.0);
  for (j = -5; j < 5; ++j) {
    for (i = -5; i < 5; ++i) {
      glMaterialfv(GL_FRONT, GL_DIFFUSE, ground[(i + j) & 1]);
      glVertex3d((GLdouble)i, -0.5, (GLdouble)j);
      glVertex3d((GLdouble)i, -0.5, (GLdouble)(j + 1));
      glVertex3d((GLdouble)(i + 1), -0.5, (GLdouble)(j + 1));
      glVertex3d((GLdouble)(i + 1), -0.5, (GLdouble)j);
    }
  }
  glEnd();
  glDisable(GL_LIGHTING);
  glPopAttrib();

  glEndList();
}

void stand(double x0, double y0, double z0,double r){
  int i,j;
  double standroom = 0.2;
  double d1 = x0 - standroom;
  double d2 = x0 + bdepth + standroom;
  double sheight = 0.1;

  //glColor3d(1.0, 1.0, 1.0);

  GLdouble normal[][3] = {
    { 0.0, 0.0,-1.0 },
    { 1.0, 0.0, 0.0 },
    { 0.0, 0.0, 1.0 },
    {-1.0, 0.0, 0.0 },
    { 0.0,-1.0, 0.0 },
    { 0.0, 1.0, 0.0 }
  };

  GLdouble vertex[][3] = {
    { d1,y0,-d1*tan(r/2) },
    { d1,y0,d1*tan(r/2) },
    { d1,y0-sheight,d1*tan(r/2) },
    { d1,y0-sheight,-d1*tan(r/2) },
    { d2,y0,-d2*tan(r/2) },
    { d2,y0,d2*tan(r/2) },
    { d2,y0-sheight,d2*tan(r/2) },
    { d2,y0-sheight,-d2*tan(r/2) },
  };

  int face[][4] = {
    { 0, 1, 2, 3 },
    { 1, 5, 6, 2 },
    { 5, 4, 7, 6 },
    { 4, 0, 3, 7 },
    { 4, 5, 1, 0 },
    { 3, 2, 6, 7 }
  };
  
  glBegin(GL_QUADS);
  for(j=0;j<6;++j){
    glNormal3dv(normal[j]);
    for(i=0;i<4;++i){
      glVertex3dv(vertex[face[j][i]]);
    }
  }
  glEnd();

}


void feather(double wgap, double x0, double y0, double z0,double rx,double ry,double rz)
{
  int i;
  int j;

  GLdouble normal[][3] = {
    { x0, y0, z0-wwidth/2 },
    { x0, y0, z0+wwidth/2 },
    { x0+wdepth2+wgap, y0-wheight, z0+wwidth/2 },
    { x0+wdepth2+wgap, y0-wheight, z0-wwidth/2 },
    { x0+wdepth1, y0, z0-wwidth/2 },
    { x0+wdepth1, y0, z0+wwidth/2 },
    { x0+wdepth1-wdepth2+wgap, y0-wheight, z0+wwidth/2 },
    { x0+wdepth1-wdepth2+wgap, y0-wheight, z0-wwidth/2 }
  };

  GLdouble vertex[][3] = {
    { x0, y0, z0-wwidth/2 },
    { x0, y0, z0+wwidth/2 },
    { x0+wdepth2+wgap, y0-wheight, z0+wwidth/2 },
    { x0+wdepth2+wgap, y0-wheight, z0-wwidth/2 },
    { x0+wdepth1, y0, z0-wwidth/2 },
    { x0+wdepth1, y0, z0+wwidth/2 },
    { x0+wdepth1-wdepth2+wgap, y0-wheight, z0+wwidth/2 },
    { x0+wdepth1-wdepth2+wgap, y0-wheight, z0-wwidth/2 }
  };

  int face[][4] = {
    { 0, 1, 2, 3 },
    { 1, 5, 6, 2 },
    { 5, 4, 7, 6 },
    { 4, 0, 3, 7 },
    { 4, 5, 1, 0 },
    { 3, 2, 6, 7 }
  };
  
  glRotated(rx, 1.0, 0.0, 0.0);
  glRotated(ry, 0.0, 1.0, 0.0);
  glRotated(rz, 0.0, 0.0, 1.0);
  glBegin(GL_QUADS);
  for(j=0;j<6;++j){
    glNormal3dv(normal[j]);
    for(i=0;i<4;++i){
      glVertex3dv(vertex[face[j][i]]);
    }
  }
  glEnd();
}

void wind(double x0, double y0, double z0){
  int feathernum = 10;
  double wdistance = 1.9;
  double wdisth = 3.0;

  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  glTranslated(6.0, 24.3, 0.0);
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
  feather(0.0,0.0,0.0,0.0,60.0,0.0,6.0);
  glPopMatrix();
  glPopAttrib();

  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  glTranslated(5.6, 24.15, -0.35);
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
  feather(0.0,wdistance,0.0,0.0,60.0,0.0,12.0);
  glPopMatrix();
  glPopAttrib();

  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  glTranslated(5.6, 24.12, -0.42);
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
  feather(0.0,wdistance*2,0.0,0.0,60.0,0.0,13.0);
  glPopMatrix();
  glPopAttrib();

  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  glTranslated(5.6, 24.07, -0.5);
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
  feather(0.0,wdistance*3,0.0,0.0,60.0,0.0,14.0);
  glPopMatrix();
  glPopAttrib();

  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  glTranslated(5.6, 23.93, -0.68);
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
  feather(0.0,wdistance*4,0.0,0.0,60.0,0.0,16.0);
  glPopMatrix();
  glPopAttrib();

  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  glTranslated(5.6, 23.86, -0.80);
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, red);
  feather(0.0,wdistance*5,0.0,0.0,60.0,0.0,19.0);
  glPopMatrix();
  glPopAttrib();

  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  glTranslated(6.0, 24.3, 0.0);
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
  feather(0.0,wdistance*6,0.0,0.0,60.0,0.0,45.0);
  glPopMatrix();
  glPopAttrib();

  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  glTranslated(6.0, 24.3, 0.0);
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, green);
  feather(0.0,wdistance*7,0.0,0.0,0.0,45.0,0.0);
  glPopMatrix();
  glPopAttrib();

  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  glTranslated(6.0, 24.3, 0.0);
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue);
  feather(0.0,wdistance*8,0.0,0.0,0.0,0.0,45.0);
  glPopMatrix();
  glPopAttrib();

  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  glTranslated(6.0, 24.3, 0.0);
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
  feather(0.0,wdistance*9,0.0,0.0,60.0,0.0,30.0);
  glPopMatrix();
  glPopAttrib();

  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  glTranslated(6.0, 24.3, 0.0);
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
  feather(0.0,wdistance*10,0.0,0.0,60.0,0.0,33.0);
  glPopMatrix();
  glPopAttrib();

  /*  
  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  glTranslated(6.0, 24.3, 0.0);
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
  feather(0.0,0.7,0.0,0.0,0.0,0.0,0.0);
  glPopMatrix();
  glPopAttrib();
  
  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  glTranslated(6.0, 24.3, 0.0);
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
  feather(0.0,1.4,0.0,0.0,0.0,0.0,0.0);
  glPopMatrix();
  glPopAttrib();

  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  glTranslated(6.0, 24.3, 0.0);
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, white);
  feather(0.0,2.1,0.0,0.0,0.0,0.0,0.0);
  glPopMatrix();
  glPopAttrib();
  */

}

