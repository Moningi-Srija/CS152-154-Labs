 // header files
 #include <FL/Fl.H> 
 #include <FL/Fl_Window.H>
 #include <FL/Fl_Box.H>
 #include <iostream>
 #include <string>
 #include <fstream>
 #include <math.h>
 #include <cstdlib>
 #include <FL/Fl_Int_Input.H>
 
 using namespace std;
 
 //global variable
 int m;
 float pi2 = 6.28318; //represents 2*pi
 
 //label 4//
 void drawbox(float x,float y,float w,float h,Fl_Box *box,int colour)
 {
   box = new Fl_Box ( x, y, w, h, "");
   box->box(FL_UP_BOX);
   box->box(FL_FLAT_BOX);
   box->color(colour);
 }
 
 void electrons(float &j,float &t,float &x,int &y,int color,Fl_Box *b1)
 {
   while(j <= pi2)
   {
     for(int i=4;i>0;i-=0.05)
     { 
       for(x=-i;x<=i;x+=0.05)
       { 
         drawbox(350+y*cos(j)+x,350+y*sin(j)+sqrt(i*i-x*x),1,1,b1,color);
	 drawbox(350+y*cos(j)+x,350+y*sin(j)-sqrt(i*i-x*x),1,1,b1,color);
       } 
     }
     j+=t;
   }
 }
 
 void shell(float &x,int &y,Fl_Box *b1)
 {
   for(x=-y;x<=y;x+=0.1)
   { 
     drawbox(350-y,350,2,2,b1,2);
     drawbox(350+y,350,2,2,b1,2);
     drawbox(350+x,350+sqrt(y*y-x*x),2,2,b1,2);
     drawbox(350+x,350-sqrt(y*y-x*x),2,2,b1,2);
   }
 }
 
 void nucleus(float &x,int &y,Fl_Box *b1)
 {
   for(y=5;y>0;y-=0.1)
   { 
     for(x=-y;x<=y;x+=0.1)
     { 
       drawbox(350+x,350+sqrt(y*y-x*x),1,1,b1,1);
       drawbox(350+x,350-sqrt(y*y-x*x),1,1,b1,1);
     }
   }
}

 void f(Fl_Widget*w)
 {
    Fl_Window *window = new Fl_Window (1000,700);
    Fl_Int_Input *p=(Fl_Int_Input*)w;
    const char *o=p->value();
    m=atoi(o);
    //m now has the value entered in the textbox

    ///label 3///
    int n,y=20,q;
    float x=-4,j,t;
    string a[118],b[118],c[118],d[118];
    ifstream e,f,g,h;
    
    ///label 2///
    srand(time(NULL));
    q=(random()%4)+212;
    window->color (q); // set its color

    Fl_Box *b1;

    f.open("elements");
    for( int i=0;i<118;i++) // input names of elements from file "elements" into an array
      f>>a[i];
    f.close();

    ///label 1///
    
    //for( int i=0;i<118;i++) // input names of elements from file "elements" into an array 
    //cout<<a[i].c_str()<<endl;

    e.open("elements3");
    for( int i=0;i<118;i++) // input discovery year of elements from file "elements3" into an array
      e>>b[i];
    e.close();

    g.open("elements2");
    for( int i=0;i<118;i++) // input atomic weight of elements from file "elements2" into an array
      g>>c[i];
    g.close();

    h.open("elements4");
    for( int i=0;i<118;i++) //input ionisation energy of elements from file"elements4"into an array
      h>>d[i];
    h.close();

    



   for(int n=1;n<=m;n++) 
   {
     if(n==1||n==3||n==11||n==19||n==37||n==55||n==87) 
     {
       if(n==1) j=7;
       if(n==3) j=pi2/(float)2;
       if(n==11) j=pi2/(float)8; //j= angle between adjacent electrons in same shell
       if(n==19) j=pi2/(float)8;
       if(n==37) j=pi2/(float)18;
       if(n==55) j=pi2/(float)18;
       if(n==87) j=pi2/(float)32;
       float t=j;
       electrons(j,t,x,y,0,b1);
       y+=20;
       shell(x,y,b1);
     } 
   }

   if(m>0)  j=pi2/(float)m;
   if(m>2)  j=pi2/(float)(m-2);
   if(m>10) j=pi2/(float)(m-10);
   if(m>18) j=pi2/(float)(m-18); // m-i= no of electrons in valence shell
   if(m>36) j=pi2/(float)(m-36);
   if(m>54) j=pi2/(float)(m-54);
   if(m>86) j=pi2/(float)(m-86);
   t=j;

   electrons(j,t,x,y,0,b1);
   nucleus(x,y,b1);

   window->end();
   window->show();
 }
 
 
 int main (int argc, char *argv[])
 {

   Fl_Window *window1 = new Fl_Window(500,500);
   Fl_Int_Input *inp = new Fl_Int_Input(0,0,500,100,"Enter atomic number here");
   inp->when(FL_WHEN_ENTER_KEY);
   inp->callback(f);
   window1->end();
   window1->show();

   return Fl::run();
 } 
