/*210050098
  Lab 2 Program : fan*/
 
 #include <iostream>
 using namespace std;
 
 class Fan
 {
   private:
   	int speed[5]={1,2,3,4,5};
   	bool state;
   	int present_speed;
   	int no_of_turns = 0;
   public:
        Fan()
        {
          //Constructor
          no_of_turns = 0;
          state = true;
          present_speed = speed[0];         
        }
        
   	void switchOn()
   	{state = true;}
   	
   	void switchOff()
   	{state = false;}
   	
   	void rotateCW()
   	{
   	  if(state == false)     {cout << "Please switch on the fan"<<endl;}
   	  else
   	  {
   	    if(no_of_turns%5 == 4 ) {cout << "This is the highest speed"<<endl;}
   	    else
   	    {
   	      no_of_turns++;
   	      present_speed = speed[no_of_turns%5];
   	    }
   	  }
   	}
   	
   	void rotateCCW()
   	{
   	  if(state == false)     {cout << "Please switch on the fan"<<endl;}
   	  else
   	  {
   	    if(no_of_turns%5 == 0 ) {cout << "This is the least speed"<<endl;}
   	    else
   	    {
   	      no_of_turns--;
   	      present_speed = speed[no_of_turns%5];
   	    }
   	  }
   	}
   	
   	int getSpeed()
   	{
   	  if(state == false){return 0;}
   	  else {return present_speed;}
   	}	
   	
   	void getState()
   	{
   	  if(state == true){cout << "Fan is on"<<endl;}
   	  else {cout << "Fan is Off"<<endl;}
   	}
 };
 
 int main()
 {
 	Fan f1;
 	f1.rotateCW(); cout << 10*f1.getSpeed() << "rpm" << endl;
 	f1.rotateCCW(); cout << 10*f1.getSpeed() << "rpm" << endl;
 	f1.switchOff(); cout << 10*f1.getSpeed() << "rpm" << endl;
 	f1.rotateCW();
 	f1.switchOn();
 	f1.getState();
 }
