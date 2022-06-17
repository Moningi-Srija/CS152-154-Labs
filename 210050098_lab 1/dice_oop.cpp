/*210050098
  Lab 1 program1.cpp*/
  
 #include <iostream>
 #include <cstdlib>
 using namespace std;
 
 class Dice
 {
    private:
      int no_face[6],trials;         //no_face[i] stores the no. of times face i+1 shows up.
    public:
      Dice()
      {
        //constructor
        for(int i=0;i<6;i++)
          no_face[i]=0;
        trials = 0;
        srand(time(NULL));
      }
      
      void trial()
      {
        //we are using random no.generator and using this function
        //to create an artificial situation of tossing dice.
        int r = rand()%6;
        no_face[r]++;trials++;
      }
      
      void coutprob()
      {
        //we are calling it rand prob as it changes everytime
        for(int i=0;i<6;i++)
           {
             //here double(no_face[i])/trials gives the probability for face i to occur
             cout <<"probability for "<< i+1 << " " << double(no_face[i])/trials << " " << endl;
           }
      }   
 };
 
 int main(int argc,char*argv[])
 {
   Dice dice;
   int N=atoi(argv[1]);
   for(int i=0;i<N;i++)    //this is equivalent to real life situation of tossing die N times.
     dice.trial();         
   dice.coutprob();   
 }
 
