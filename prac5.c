//#pragma once
#include "oz.h"
#include "glm.h"

GLuint objects;

int clickx,clicky;
double abv = 0.0;
double a = 0.0;
double v[] = { 0.0, 0.0 };
double t = 0.0;
double pi = 3.141592;
int ww,hh;

double ex = 0.0, ez = 150.0, ey = 30.0;
double r = 0.0;

double bwidth = 0.2;
double bheight = 0.8;
double bdepth =0.6;

GLuint texID[100];
int ID_KEY = 0;

int i;
int goaheadflg = 0;
int gobackflg = 0;
int goleftflg = 0;
int gorightflg = 0;
int goupflg = 0;
int godownflg = 0;
double mv=1.0;

double wwidth = 1.0;
double wheight = 6.0;
double wdepth1 = 2.4;
double wdepth2 = 0.5;

//---------- 各種外部変数 ----------//
GLMmodel *Model;
char *modelname = "ozmain.obj";
GLfloat scale;

GLMmodel *Model2;
char *modelname2 = "karikenji.obj";
GLfloat scale2;


//--------- プロトタイプ宣言 -----------//
void display();
void reshape(int w, int h);


//--------- モデルロード処理 -------------//
void load_model()
{
        Model = glmReadOBJ(modelname);//モデルを読み込む
	scale = glmUnitize(Model);
        glmFacetNormals(Model);//面の法線データを計算
        glmVertexNormals(Model, 90);
        glmUnitize(Model);//単位化

	glmScale(Model,110.0);
}

void load_model2()
{
        Model2 = glmReadOBJ(modelname2);//モデルを読み込む
	scale2 = glmUnitize(Model2);
        glmFacetNormals(Model2);//面の法線データを計算
        glmVertexNormals(Model2, 90);
        glmUnitize(Model2);//単位化

	glmScale(Model2,1.0);
}


 

void idle(void)
{
  t += 0.1;
  if(goaheadflg == 1){
    for(i=0;i<1000000;i++){
      ez += -0.0000005*mv;
      glutPostRedisplay();
    }      
    goaheadflg = 0;
  }
  if(gobackflg == 1){
    for(i=0;i<1000000;i++){
      ez += 0.0000005*mv;
      glutPostRedisplay();
    }      
    gobackflg = 0;
  }
  if(goleftflg == 1){
    for(i=0;i<1000000;i++){
      ex += -0.0000005*mv;
      glutPostRedisplay();
    }      
    goleftflg = 0;
  }
  if(gorightflg == 1){
    for(i=0;i<1000000;i++){
      ex += 0.0000005*mv;
      glutPostRedisplay();
    }      
    gorightflg = 0;
  }
  if(goupflg == 1){
    for(i=0;i<1000000;i++){
      ey += 0.0000005*mv;
      glutPostRedisplay();
    }      
    goupflg = 0;
  }
  if(godownflg == 1){
    for(i=0;i<1000000;i++){
      ey += -0.0000005*mv;
      glutPostRedisplay();
    }      
    godownflg = 0;
  }
  glutPostRedisplay();
}


void display(void)
{
  static GLfloat lightpos[] = { 3.0, 4.0, 5.0, 0.0 };

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  glLoadIdentity();

  
  r = a * t + r;
  if(r > 360) r -= 360;
  if(r < -360) r += 360;
  v[0] = abv * sin(r*pi/180);
  v[1] = -abv * cos(r*pi/180);

  ex = ex + v[0] * t;
  ez = ez + v[1] * t;
  
  glRotated(r, 0.0, 1.0, 0.0);
  

  glTranslated(-ex, -ey, -ez);

  
  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  glmDraw(Model,GLM_SMOOTH | GLM_COLOR);
  glPopMatrix();
  glPopAttrib();
  
  
  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  glTranslated(ex, ey-0.5, ez-8);  
  glRotated(180, 0.0, 1.0, 0.0);
  glmDraw(Model2,GLM_SMOOTH | GLM_COLOR);
  glPopMatrix();
  glPopAttrib();
  
  
  glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
  glPushMatrix();
  glPushAttrib(GL_LIGHTING_BIT);
  glCallList(objects);
  glPopMatrix();
  glPopAttrib();
  

  //glPushMatrix();
  //glPushAttrib(GL_LIGHTING_BIT);
  //glTranslated(3.0, 0.0, 0.0);
  //map_to_square(0.0,0.0,0.0,0.0,0.0,1.0,1,1,&texID[ID_KEY]);
  //map_to_body(-1.0, 0.1, 0.0, 0.0, 50, 50, &texID[ID_KEY],1.0);

  //glTranslated(0.0, 0.5, 1.0);
  //map_to_ellipsoid(&texID[ID_KEY],1.0,0.3,0.5,0.3,0.0,0.0,0.0);

  //map_to_book(1.0,0.1,0.0,&texID[ID_KEY]);
  //glPopMatrix();
  //glPopAttrib();
  

  glFlush();
}

void resize(int w, int h)
{
  ww = w;
  hh = h;
  
  glViewport(0, 0, w, h);

  /* 透視変換行列の設定 */
  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();
  gluPerspective(30.0, (double)w/(double)h, 1.0, 1000.0);

  /* モデルビュー変換行列の設定 */
  glMatrixMode(GL_MODELVIEW);
}

void specialkeydown(int key, int x, int y)
{
     if( key == GLUT_KEY_UP )//矢印「上」
       goaheadflg = 1;
     idle();
     {
       
     }

     if( key == GLUT_KEY_DOWN )//矢印「下」
     {
       gobackflg = 1;
     idle();
     }

     if( key == GLUT_KEY_LEFT )
     {
       goleftflg = 1;
     idle();
     }

     if( key == GLUT_KEY_RIGHT )
     {
       gorightflg = 1;
     idle();
     }

}


void keyboard(unsigned char key, int x, int y)
{
  /* ESC か q をタイプしたら終了 */
  if (key == '\033' || key == 'q') {
    exit(0);
  }
  // u
  if(key == 'u'){
       goupflg = 1;
     idle();
  }
  // d
  if(key == 'd'){
       godownflg = 1;
     idle();
  }
  // r
  if(key == 'r'){
    r+=1;
     idle();
  }
  if(key == 'e'){
    r-=1;
     idle();
  }
  if(key == 's'){
    mv+=5;
     idle();
  }
  if(key == 'a'){
    mv-=5;
     idle();
  }

}

void motion(int x, int y)
{
      /* 速度ベクトル等計算エリア */

      
      t = 0.0;

      abv = sqrt((ww/2 - (double)x)*(ww/2 - (double)x) + (hh/2 - (double)y)*(hh/2 - (double)y)) / 5000;
      if(x > ww/2)
	a = 1.0;
      else
	a = -1.0;
      
      if(y > hh/2)
	abv *= -10.0;
      else
	abv *= 10.0;

      //glutIdleFunc(idle);
      


  /*
      abv = sqrt((ww/2 - (double)x)*(ww/2 - (double)x) + (hh/2 - (double)y)*(hh/2 - (double)y)) / 5000;
      if(x > ww/2)
	a = 1.0;
      else
	a = -1.0;
      
      if(y > hh/2)
	abv *= -1.0;
      else
	abv *= 1.0;
  */  
}

void mouse(int button, int state, int x, int y)
{
  switch (button) {
  case GLUT_LEFT_BUTTON:
    if (state == GLUT_DOWN) { 
      /*
      t = 0.0;

      abv = sqrt((ww/2 - (double)x)*(ww/2 - (double)x) + (hh/2 - (double)y)*(hh/2 - (double)y)) / 5000;
      if(x > ww/2)
	a = 1.0;
      else
	a = -1.0;
      
      if(y > hh/2)
	abv *= -100.0;
      else
	abv *= 100.0;

      glutIdleFunc(idle);
      */
    }
    else {
      glutIdleFunc(0);
    }
    break;
  default:
    break;
  }
}



void initLighting(void)
{
  //float diffuse[] = {1.0, 0.2, 0.2, 1.0};
  //float specular[] = {0.5, 0.5, 1.0, 1.0};
  float ambient[] = {0.5, 0.5, 0.5, 1.0};

  //glLightfv(GL_LIGHT0, GL_DIFFUSE,diffuse);
  //glLightfv(GL_LIGHT0, GL_SPECULAR,specular);
  glLightfv(GL_LIGHT0, GL_AMBIENT,ambient);
  glEnable(GL_LIGHT0);
}

void load_them()
{
  //load_raw3("mc04.raw" , 1200, 1600, &texID[0]);
}

void init(void)
{
  /* 初期設定 */
  glClearColor(0.8, 0.8, 1.0, 0.0);
  glEnable(GL_DEPTH_TEST);
  //glEnable(GL_CULL_FACE);
  glEnable(GL_LIGHTING);
  //glEnable(GL_LIGHT0);
  
  initLighting();

  glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
  glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
  glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
  glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);
  glTexGeni(GL_Q, GL_TEXTURE_GEN_MODE, GL_OBJECT_LINEAR);

  load_them();
  load_model();
  load_model2();

}

int main(int argc, char *argv[])
{
  glutInitWindowPosition(100,100);
  glutInitWindowSize(960,480);
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH);
  glutCreateWindow(argv[0]);
  glutDisplayFunc(display);
  glutReshapeFunc(resize);
   glutMouseFunc(mouse);
  //glutIdleFunc(idle);
  glutMotionFunc(motion);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(specialkeydown);
  scene();
  init();
  glutMainLoop();
  return 0;
}
