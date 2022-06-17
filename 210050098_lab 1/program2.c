/*210050098
 Lab 1 program2.c*/
 
 #include <fstream>
 #include <iostream>
 #include <cstdlib>
 using namespace std;
 
 int main(int argc,char*argv[])
 {
   char ascii[95],d;
   int  ascii_count[95];
   for(int j=0;j<95;j++)
     {
         ascii_count[j]=0;
         ascii[j] = char(j+33);
     }
   ifstream in_file;
   in_file.open(argv[1]);
   while(in_file >> d)
   {
     for(int i=0;i<95;i++)
     {
        if(ascii[i]==d){ascii_count[i]++;}
     }
     if(in_file.eof()){break;}
   }
   for(int i=0;i<95;i++)
   {
     if(ascii_count[i] != 0) 
     {
       cout << "frequency of " << ascii[i] << " is " << ascii_count[i] << endl;
     } 
   } 
 }
 
