/*210050098
 Lab 1 program1.c*/
 
 #include <cstdlib>
 #include <iostream>
 using namespace std;
 int main(int argc,char*argv[])
 {
   int no_face[6],N,t;
   
   N =atoi(argv[1]);
   for (int i=0;i<N;i++)
     no_face[i]=0;
   srand(time(NULL));
   
   for(int i=0;i<N;i++)
   {
      t = rand()%6; no_face[t]++;       
   }
   
   for(int i=0;i<6;i++)
   {
     cout << "Probability for " << i+1 << " " << double(no_face[i])/N << endl;
   }
   exit(0);
 }
