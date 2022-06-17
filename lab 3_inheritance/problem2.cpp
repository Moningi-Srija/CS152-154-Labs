/* Roll no. = 210050098
   Problem = Problem 2 (TV)*/
   
 #include <iostream>
 #include <cmath>
 using namespace std;
 
 class basicTV
 {
   protected:
   
  	double screensize;
  	double cost;
  	double weight;
  	string s = "this tv have only basic features";
  	 	
   public:
   
   	basicTV()
   	{
   	  //constructor
   	  screensize = 24;
   	  cost = 25000;
   	  weight = 2.0;
   	}
   	
   	void getcost()
   	{
   	  cout << "Cost : " << cost << endl;
   	}
   	
   	void getscreensize()
   	{
   	  //gets screen size in inches
  	  cout << "Screen size : " << screensize << "in" << endl;   	  
 	}
 	
 	void getweight()
 	{
 	  cout << "Weight : " << weight << "kg" << endl; 
 	}
 	
 	void displayfeatures()
 	{
 	  cout << s;
 	}
 };
 
 class TV2 : public basicTV
 {
   //this tv has only 2 features - videoin, audioin
   //this tv has 2 additional features to basic tv
   //cost increases by 1000 for every feature added
   //weight increases by 0.2kg for every feature added because of increase in circuitary
   
   public:
   
        TV2()
        {
   	  cost = 27000; 
   	  weight = 2.4;
   	  s = "this tv has 2 features - videoin, audioin";
   	}
   	
   	void videoin()
   	{
   	  cout << "This TV has the feature of videoin, pls switch on camera" << endl; 
   	}
   	
   	void audioin()
   	{
   	  cout << "This TV has the feature of audioin, pls switch on microphone" << endl;
   	} 
   
 };
 
 class TV1 : public TV2
 {
   //this tv has 5 features - internet, cable, videoin, audioin, audioout
   //this tv has 3 additional features to TV2
   
   public:
   	
   	TV1()
   	{
   	  cost = 30000;
   	  weight = 3.0;
   	  s = "this tv has 5 features - internet, cable, videoin, audioin, audioout";
   	}
   	
   	void internet()
   	{
   	  cout << "This TV has the feature of internet, pls connect to wifi and enjoy surfing in internet" << endl; 
   	}
   	
   	void cable()
   	{
   	  cout << "This TV has the feature of cable, pls connect some device" << endl;
   	}
   	
   	void audioout()
   	{
   	  cout << "This TV has the feature of audioout, pls switch on speakers" << endl;
   	}
 };
 
 class TV3 : public basicTV
 {
   //this tv has 4 features - cable, audioin, audioout, videoout
   //this tv has 4 additional feature to basic tv
  
   public:
   
        TV3()
        {
   	   cost = 29000;
   	   weight = 2.8;
   	   s = "this tv has 4 features - cable, audioin, audioout, videoout";
        }
        
     	void cable()
   	{
   	  cout << "This TV has the feature of cable, pls connect some device" << endl;
   	}
 
    	void audioin()
   	{
   	  cout << "This TV has the feature of audioin, pls switch on microphone" << endl;
   	}   	
   	
   	void audioout()
   	{
   	  cout << "This TV has the feature of audioout, pls switch on speakers" << endl;
   	}
   	
   	void videoout()
   	{
   	  cout << "This TV has the feature of videoout" << endl;
   	}
   	
 };
 
 class TV4 : public basicTV
 {
   //this tv has 3 features - internet, videoin, videoout
   //this tv has 3 additional feature to basic tv
   
   public:
   
        TV4()
        {
   	  cost = 28000;
   	  weight = 2.6;
   	  s = "this tv has 3 features - internet, videoin, videoout";
        }
   	
   	void internet()
   	{
   	  cout << "This TV has the feature of internet, pls connect to wifi and enjoy surfing in internet" << endl; 
   	}
   	
   	void videoin()
   	{
   	  cout << "This TV has the feature of videoin, pls switch on camera" << endl; 
   	}
   	
   	void videoout()
   	{
   	  cout << "This TV has the feature of videoout" << endl;
   	}
   	
 };
 
 int main()
 {
   
   basicTV basictv;
   TV1 tv1;
   TV2 tv2;
   TV3 tv3;
   TV4 tv4;
   
   basictv.displayfeatures();
   
   tv1.displayfeatures();
   tv1.getcost();
   tv1.cable();
   
   tv2.displayfeatures();
   tv2.getscreensize();
   tv2.videoin();
   
   tv3.displayfeatures();
   tv3.getweight();
   tv3.videoout();
   
   tv4.displayfeatures();
   tv4.internet();
      
 }
