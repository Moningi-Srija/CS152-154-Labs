/*210050098
  Lab 2 Program : lift*/
  
 #include <iostream>
 using namespace std;
 
 class Lift
 {
   private:
        int ground = 0;
        int terrace = 4;  //assuming 5 floors
   	int current_floor;
   	int destination;
   	int person_floor;
   public:
   	Lift()
   	{
   	  //Constructor
   	  current_floor = 0;
   	}
        
        //ouside interface
        void want_to_go_up(int person_floor)
        {
          if(person_floor == terrace) {cout << "there is no floor up further, calling want_to_go_down" << endl; want_to_go_down(person_floor);}
                                                                        //calls the function down automatically, if person uses wrong button. 
          else
          {
            lift_message(person_floor);
            current_floor = person_floor;
          }
        }	
        
        void want_to_go_down(int person_floor)
        {
          if(person_floor == ground) {cout << "there is no floor down further, calling want_to_go_up" << endl; want_to_go_up(person_floor);}
                                                                        //calls the function down automatically, if person uses wrong button. 
          else
          {
            lift_message(person_floor);
            current_floor = person_floor;
          }
        }
        
        void lift_message(int person_floor)
        {
          cout << "Lift is currently at floor " << current_floor << endl;
          if(person_floor > current_floor) {cout << "coming up, pls wait..." << endl;}
          else if(person_floor < current_floor) {cout << "coming down, pls wait..." << endl;}
          else {cout << "Lift is opened,pls enter" << endl;}
        }
        
        //inside interface
        void go(int destination)
        {
          if(destination >= ground && destination <= terrace) {current_floor == destination ; cout << "destination reached" << endl;}
          else{cout << "no such floor,pls try again.";}
        }
};

 int main()
 {
   Lift l1;
   l1.want_to_go_up(3);l1.go(4);
   l1.want_to_go_up(4);
   l1.want_to_go_down(2);l1.go(0);
   l1.want_to_go_down(0);
   l1.go(2);
 } 
 
