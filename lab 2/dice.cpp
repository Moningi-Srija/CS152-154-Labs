/*210050098
  Lab 2 Program : dice*/
  
 #include <iostream>
 using namespace std;
 
 class Dice
 {
   private:
   	int face_value;
   public:
   	Dice()
   	{
   	  //Constructor
   	  face_value = 1;
   	}
   	
   	void toss(int n)
   	{
   	  srand(time(NULL));
   	  //tosses n times
   	  for(int i=0;i<n;i++)
   	  {
   	    face_value = (rand()%6)+1;
   	  }
   	  cout << "Dice showed up " << face_value << endl;
   	}
   	
   	int get_face_value()
   	{
   	  return face_value;
   	}
 };
 
 int main()
 {
   Dice d1;
   d1.get_face_value();
   d1.toss(6);
   d1.toss(12);
   cout << d1.get_face_value() << endl;
 }
