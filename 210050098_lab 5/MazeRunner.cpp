/*Roll no : 210050098 
  Game : MazeRunner*/
  
  #include <FL/Fl.H>        // needed in every fltk program
  #include <FL/Fl_Window.H> // needed to use the Fl_Window class
  #include <FL/Fl_Box.H>
  #include <FL/fl_draw.H>
  #include <FL/Fl_Button.H> 
  
  #include <bits/stdc++.h>
  
  //global variables
  int WINDOWX = 300;
  int WINDOWY = 300;
  int t=50; 
  
  using namespace std;
  
  //The Parent Class of all, The Abstract class which all other classes implement
 class Object : public Fl_Widget 
 {
   protected:
   	int x, y, w, h;

   public:
   	Object (int x, int y, int w, int h) : Fl_Widget (x,y,w,h)
   	{
          this->x=x; this->y=y;
          this->w=w; this->h=h;
        }

        //The Abstract and dynamically bound Virtual Functions
        virtual void wipe()=0;
        virtual void refresh(int dx, int dy)=0;
  };
  
  class Maze : public Object
  {
    protected:
    	int mazesize; //Typically a square
    	
    public:
    	Maze(int x, int y, int w, int h) : Object(x,y,w,h)
    	{
    	  //Constructor
    	  //A widget for maze gets created
    	  mazesize = w;
    	}
    	
    	virtual void draw()
    	{   	  
    	  //Borders
   	  fl_color(FL_WHITE);
   	  fl_line(2*t+50,0+50,3*t+50,0+50);   //Moving everything by 50 to give sime sace for border
   	  fl_line(3*t+50,6*t+50,4*t+50,6*t+50);
   	  fl_color(FL_BLACK);
   	  
   	  //Inner Maze Horizontal Lines
   	  fl_line(1*t+50,5*t+50,5*t+50,5*t+50);
   	  fl_line(4*t+50,4*t+50,6*t+50,4*t+50);
   	  fl_line(0+50,3*t+50,2*t+50,3*t+50); fl_line(3*t+50,3*t+50,5*t+50,3*t+50);
   	  fl_line(1*t+50,2*t+50,3*t+50,2*t+50); fl_line(4*t+50,2*t+50,6*t+50,2*t+50);
   	  fl_line(1*t+50,1*t+50,2*t+50,1*t+50); fl_line(4*t+50,1*t+50,5*t+50,1*t+50);
   	  
   	  //Inner Maze Vertical Lines
   	  fl_line(1*t+50,4*t+50,1*t+50,5*t+50);
   	  fl_line(2*t+50,0+50,2*t+50,1*t+50); fl_line(2*t+50,3*t+50,2*t+50,4*t+50); fl_line(2*t+50,5*t+50,2*t+50,6*t+50);
   	  fl_line(3*t+50,0+50,3*t+50,2*t+50); fl_line(3*t+50,3*t+50,3*t+50,5*t+50);
   	  fl_line(4*t+50,1*t+50,4*t+50,2*t+50);
   	  
   	  //Instructions at the bottom
   	  fl_color(FL_CYAN);
   	  fl_draw("Use arrow keys in keyboard to navigate.",1*t,9*t);
   	  
   	  //Cheese
   	  fl_color(3);
   	  fl_polygon(3.25*t,0.75*t,3.75*t,0.75*t,3.75*t,0.25*t,3.25*t,0.25*t); 
    	}
    	
    	virtual void wipe()
    	{
    	  fl_color(FL_WHITE);
    	  fl_polygon(0,0,300,0,300,300,0,300);
    	}
    	
    	virtual void refresh(int dx, int dy)
    	{
    	  fl_color(FL_CYAN);
    	  fl_font(FL_COURIER,85);
    	  fl_draw("CONGO!!, Enjoy the cheese!",150,150);
    	}	
  };
  
  class Mouse : public Object
  {
    time_t Deadline;
    double e = 0.05*t; // e -> epsilon
    double l = 10; // l -> limit
    int hits = 0;
    bool won = false;
    public:
    	
    	Mouse(int x, int y, int w, int playtime) : Object(x,y,w,w)
    	{
    	  //constructor
    	  //A widget for mouse gets created
    	  Deadline = time(0) + playtime;
    	}
    	
    	virtual void draw()
    	{
    	  fl_color(FL_MAGENTA);
    	  fl_rectf(x,y,w,h);
    	  
    	  //Borders
    	  fl_color(FL_BLACK);
    	  fl_line(0+50,0+50,6*t+50,0+50);
    	  fl_line(0+50,0+50,0+50,6*t+50);
    	  fl_line(6*t+50,0+50,6*t+50,6*t+50);
    	  fl_line(0+50,6*t+50,6*t+50,6*t+50);
   	  fl_color(FL_WHITE);
   	  fl_line(2*t+50,0+50,3*t+50,0+50);
   	  fl_line(3*t+50,6*t+50,4*t+50,6*t+50);
   	  fl_color(FL_BLACK);
   	  
   	  //Inner Maze Horizontal Lines
   	  fl_line(1*t+50,5*t+50,5*t+50,5*t+50);
   	  fl_line(4*t+50,4*t+50,6*t+50,4*t+50);
   	  fl_line(0+50,3*t+50,2*t+50,3*t+50); fl_line(3*t+50,3*t+50,5*t+50,3*t+50);
   	  fl_line(1*t+50,2*t+50,3*t+50,2*t+50); fl_line(4*t+50,2*t+50,6*t+50,2*t+50);
   	  fl_line(1*t+50,1*t+50,2*t+50,1*t+50); fl_line(4*t+50,1*t+50,5*t+50,1*t+50);
   	  
   	  //Inner Maze Vertical Lines
   	  fl_line(1*t+50,4*t+50,1*t+50,5*t+50);
   	  fl_line(2*t+50,0+50,2*t+50,1*t+50); fl_line(2*t+50,3*t+50,2*t+50,4*t+50); fl_line(2*t+50,5*t+50,2*t+50,6*t+50);
   	  fl_line(3*t+50,0+50,3*t+50,2*t+50); fl_line(3*t+50,3*t+50,3*t+50,5*t+50);
   	  fl_line(4*t+50,1*t+50,4*t+50,2*t+50);
   	  
   	  //Instructions at the bottom
   	  fl_color(FL_CYAN);
   	  fl_draw("Use arrow keys in keyboard to navigate.",1*t,7.5*t);
    	}
    	
    	virtual void wipe()
    	{
    	  fl_color(FL_GREEN);
    	  fl_rectf(x,y,w,h);
    	}
    	
    	virtual void refresh(int dx, int dy)
    	{ 
    	  if( //Borders
    	      (y+dy >= 0+50-l && y+dy <=0+50+l && ((x+dx > 0+50 && x+dx < 2*t+50) || (x+dx > 3*t+50 && x+dx < 6*t+50))) ||
    	      (x+dx >= 0+50-l && x+dx <=0+50+l && y+dy > 0+50 && y+dy < 6*t+50) ||
    	      (x+dx >= 6*t+50-l && x+dx <=6*t+50+l && y+dy > 0+50 && y+dy < 6*t+50) ||
    	      (y+dy >= 6*t+50-l && y+dy <=6*t+50+l && ((x+dx > 0+50 && x+dx < 3*t+50) || (x+dx > 3*t+50 && x+dx < 6*t+50))) ||
    	      
    	      //Inner Maze Horizontal Lines
    	      (y+dy >= 5*t+50-l && y+dy <= 5*t+50+l && x+dx > 1*t+50 && x+dx < 5*t+50) ||
    	      (y+dy >= 4*t+50-l && y+dy <= 4*t+50+l && x+dx > 4*t+50 && x+dx < 6*t+50) ||
    	      (y+dy >= 3*t+50-l && y+dy <= 3*t+50+l && x+dx > 0*t+50 && x+dx < 2*t+50) ||
    	      (y+dy >= 3*t+50-l && y+dy <= 3*t+50+l && x+dx > 3*t+50 && x+dx < 5*t+50) ||
    	      (y+dy >= 2*t+50-l && y+dy <= 2*t+50+l && x+dx > 1*t+50 && x+dx < 3*t+50) ||
    	      (y+dy >= 2*t+50-l && y+dy <= 2*t+50+l && x+dx > 4*t+50 && x+dx < 6*t+50) ||
    	      (y+dy >= 1*t+50-l && y+dy <= 1*t+50+l && x+dx > 1*t+50 && x+dx < 2*t+50) ||
    	      (y+dy >= 1*t+50-l && y+dy <= 1*t+50+l && x+dx > 4*t+50 && x+dx < 5*t+50) ||
    	      
    	      //Inner Maze Vertical Lines
    	      (x+dx >= 1*t+50-l && x+dx <=1*t+50+l && y+dy > 4*t+50 && y+dy < 5*t+50) ||
    	      (x+dx >= 2*t+50-l && x+dx <=2*t+50+l && y+dy > 0*t+50 && y+dy < 1*t+50) ||
    	      (x+dx >= 2*t+50-l && x+dx <=2*t+50+l && y+dy > 3*t+50 && y+dy < 4*t+50) ||
    	      (x+dx >= 3*t+50-l && x+dx <=3*t+50+l && y+dy > 0*t+50 && y+dy < 2*t+50) ||
    	      (x+dx >= 3*t+50-l && x+dx <=3*t+50+l && y+dy > 3*t+50 && y+dy < 5*t+50) ||
    	      (x+dx >= 4*t+50-l && x+dx <=4*t+50+l && y+dy > 1*t+50 && y+dy < 2*t+50) 
    	    )
    	  {
    	    cout << "Oops! It is a wall!"<< endl;
    	    hits+=1;
    	  }
    	  
    	  else
    	  {
    	    x = x + dx;
    	    y = y + dy;
    	    
    	    resize(x,y,w,h);   //Resizing the Widget to Fit
    	  
    	    fl_color(FL_MAGENTA);
    	    fl_rectf(x,y,w,h);
    	  }
    	  
    	  if(pow((x-3.5*t),2) + pow((y-0.5*t),2) < pow(0.5*t,2))
    	  {
    	    won = true;
    	  }
    	  
    	}
    	
    	virtual int handle(int e)
    	{
    	  if(e == FL_KEYBOARD)
    	  {
    	    if(time(0) < Deadline)
    	    {
    	      if( Fl :: event_key() == FL_Up)
    	      {
    	        wipe();
    	        refresh(0,-10);
    	        draw();
    	      }
    	      
    	      if( Fl :: event_key() == FL_Down)
    	      {
    	        wipe();
    	        refresh(0,10);
    	        draw();
    	      }
    	      
    	      if( Fl :: event_key() == FL_Right)
    	      {
    	        wipe();
    	        refresh(10,0);
    	        draw();
    	      }
    	      
    	      if( Fl :: event_key() == FL_Left)
    	      {
    	        wipe();
    	        refresh(-10,0);
    	        draw();
    	      }
    	    }
    	    else
    	    {
    	      if(won == true) 
    	      {
    	        cout << "Hurray! You found the cheese, You won" << " after hitting " << hits << " times to the wall" << endl; 
    	      }
    	      else
    	      {
    	        cout << "Time Over, You hitted wall " << hits << " no. of times, Better luck next time" << endl;
    	      }
    	      window()->hide();
    	    }
    	  }
    	  return 1;
    	} 	
  };
  
  int main(int argc, char *argv[])
  {
    cout << "This is the MazeRunner Game!\n" << "Help the rat to find it's food";
    cout << "In how many seconds do you think that you can complete this job?";
    
    int playtime;
    cin >> playtime;
    
    Fl_Window *window;
    window = new Fl_Window(WINDOWX+100, WINDOWY+100, "Reach the food!!");
    
    Maze maze(WINDOWX/2,WINDOWY/2,400,400);
    Mouse mouse(4.25*t, 6.75*t, 20, playtime);
    
    window->color(FL_GREEN);
    window->end();
    window->show(); 
    
    return (Fl::run());
  }
  
