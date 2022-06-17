/*210050098
  Lab 2 Program : RoomScheduler*/
  
  #include <iostream>
  using namespace std;
  
  class roomscheduler
  {
    private:
    	struct week{string day; bool status;};
    	struct room{string name;week w[7];string dept;};
    	room r[5];
    	week wg[7];        //used to check for id;
        char response;
        int did;           //did stands for Day ID
        int rid;           //rid stands for Room ID
        int no_room = 1000;
        int no_day = 10;
    public:
    	 roomscheduler()
    	 {
    	   //constructor
    	   r[0].dept = "lecture hall";
    	   r[1].dept = "lecture hall";
    	   r[2].dept = "conference hall";
    	   r[3].dept = "faculty lounge";
    	   r[4].dept = "faculty lounge";
    	   r[0].name = "LH#1";
    	   r[1].name = "LH#2";
    	   r[2].name = "CH#1";
    	   r[3].name = "FL#1";
    	   r[4].name = "FL#2";
    	   
    	   for(int j=0;j<5;j++)
    	   {
    	     for(int i=0;i<7;i++)
    	     {
    	       r[j].w[i].status = false;
    	     }
    	     r[j].w[0].day = "Sunday";
    	     r[j].w[1].day = "Monday";
    	     r[j].w[2].day = "Tuesday";
    	     r[j].w[3].day = "Wednesday";
    	     r[j].w[4].day = "Thursday";
    	     r[j].w[5].day = "Friday";
    	     r[j].w[6].day = "Saturday";
    	   }
    	     wg[0].day = "Sunday";
    	     wg[1].day = "Monday";
    	     wg[2].day = "Tuesday";
    	     wg[3].day = "Wednesday";
    	     wg[4].day = "Thursday";
    	     wg[5].day = "Friday";
    	     wg[6].day = "Saturday";
    	   
    	 }
    	 
    	 int room_id(string room_name)
    	 {
    	   for(int i=0;i<5;i++)
    	   {
    	     if(r[i].name == room_name) {return i;}
    	   }
    	   return no_room; //which implies there is no such room
    	 }
    	 
    	 int day_id(string day)
    	 {
    	   for(int i=0;i<7;i++)
    	   {
    	     if(wg[i].day == day) {return i;}
    	   }
    	   return no_day;
    	 }
    	 void display_schedule(string day)
    	 {
    	   did = day_id(day);
    	   cout << "\t\t\t\t WELCOME \t\t\t\t" << endl;
    	   cout << "\t\tSchedule for " << wg[did].day << "\t\t" << endl;
    	   cout << "Department       " << "Room " << "  Status" << endl;
    	   for(int i=0;i<5;i++)
    	   {
    	     cout << r[i].dept << "   " << r[i].name << " ";
    	     if(r[i].w[did].status == true) 
    	       cout << "  booked" << endl;
    	     else 
    	       cout << "  available" << endl;
    	   }
    	 }
    	 
    	 void display_schedule_week()
    	 {
    	   cout << "\t\t\tSCHEDULE OF THIS WHOLE WEEK" << endl;
    	   display_schedule("Sunday");
    	   display_schedule("Monday");
    	   display_schedule("Tuesday");
    	   display_schedule("Wednesday");
    	   display_schedule("Thursday");
    	   display_schedule("Friday");
    	   display_schedule("Saturday");
    	 }
    	 
    	 void booking_request(string room_name,string day)
    	 {
    	   rid = room_id(room_name);
    	   did = day_id(day);
    	   if(r[rid].w[did].status == 0)
    	   {
    	     r[rid].w[did].status = 1;
    	     cout << "Booked " << room_name << " for " << day << " successfully" << endl;
     	   }
     	   else
     	   {
     	     cout << "Sorry, the room " << room_name << "is aldready booked for " << day << endl;
     	   }
    	 }
    	 
    	 void cancellation_request(string room_name,string day)
    	 {
    	   did = day_id(day);
    	   rid = room_id(room_name);
    	   r[rid].w[did].status = 0;
    	   cout << "Cancelled the booking of room " << room_name << " for " << day << " successfully" << endl;
    	 }
  };
  
  int main()
  {
    roomscheduler rs;
    rs.display_schedule("Sunday");
    rs.booking_request("LH#1","Tuesday");
    rs.booking_request("LH#1","Tuesday");
    rs.booking_request("CH#1","Wednesday");
    rs.booking_request("FL#1","Sunday");
    rs.booking_request("CH#1","Sunday");
    rs.display_schedule("Tuesday");
    rs.display_schedule("Wednesday");
    rs.display_schedule("Sunday");
    rs.cancellation_request("CH#1","Sunday");
    rs.display_schedule("Sunday");
    rs.display_schedule_week();
  }
