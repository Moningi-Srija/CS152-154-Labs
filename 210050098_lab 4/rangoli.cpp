/*210050098 
  Program : Rangoli Drawing using fltk*/
  
  #include <FL/Fl.H>
  #include <FL/Fl_Window.H>
  #include <FL/Fl_Box.H>
  #include <FL/fl_draw.H>
  #include <iostream>
  #include <cstdlib>
  #include <cmath>
  
  class rangoli : public Fl_Widget
  {
    protected:
    	int cx,cy,a,w,h,k;
        
    public:
    	rangoli(int winx, int winy, int s1, int s2, char *label=0) : Fl_Widget(winx, winy, s1, s2, label)
    	{
    	  //constructor
    	  w = s1;
    	  h = s2;
    	  a = s1; 
    	  cx = winx;
    	  cy = winy;  
    	}
    	
    	void setk()
    	{
    	  std::cout << "k?" << std::endl;
    	  std::cin >> k;
    	}
    	
    	void draw()
    	{
    	  for(int i=0;i<k;i++)
    	  {
    	    
    	    fl_color((int(random())+i*5)%256);          
    	    
    	    fl_polygon(500,500,500+(140*cos((M_PI/(k/2.0))*i)),500+(140*sin((M_PI/(k/2.0))*i)),
    	               500+(140*cos((M_PI/(k/2.0))*i))+(140*cos((M_PI/(k/2.0))*(i+1))),
    	               500+(140*sin((M_PI/(k/2.0))*i))+(140*sin((M_PI/(k/2.0))*(i+1))),
    	               500+(140*cos((M_PI/(k/2.0))*(i+1))),500+(140*sin((M_PI/(k/2.0))*(i+1))));  
    	               
    	    fl_color(((int(random())+i*7)%256));
    	    
    	    fl_polygon(500,500,500+(70*cos((M_PI/(k/2.0))*i)),500+(70*sin((M_PI/(k/2.0))*i)),
    	               500+(70*cos((M_PI/(k/2.0))*i))+(70*cos((M_PI/(k/2.0))*(i+1))),
    	               500+(70*sin((M_PI/(k/2.0))*i))+(70*sin((M_PI/(k/2.0))*(i+1))),
    	               500+(70*cos((M_PI/(k/2.0))*(i+1))),500+(70*sin((M_PI/(k/2.0))*(i+1)))); 
    	               
    	            
    	    fl_color(((int(random())+i*3)%256));
    	    
    	    fl_polygon(500,500,500+(35*cos((M_PI/(k/2.0))*i)),500+(35*sin((M_PI/(k/2.0))*i)),
    	               500+(35*cos((M_PI/(k/2.0))*i))+(35*cos((M_PI/(k/2.0))*(i+1))),
    	               500+(35*sin((M_PI/(k/2.0))*i))+(35*sin((M_PI/(k/2.0))*(i+1))),
    	               500+(35*cos((M_PI/(k/2.0))*(i+1))),500+(35*sin((M_PI/(k/2.0))*(i+1)))); 
    	               
    	  }
    	}
  };
  
  int main()
  {
    Fl_Window w(1000,1000,"Rangoli");
    w.color(64);
    rangoli r(0,0,1000,1000);
    r.setk();
    w.resizable(r);
    w.show();
    return Fl::run();
  }
