/*210050098
  Lab 1 program2.cpp*/
 
 #include <iostream>
 #include <cstdlib>
 #include <fstream>
 using namespace std;
 
 ifstream in_file;               // global
 
 class analyse_text_file
 {
   private:
     char ascii[95],d;                                   //here ascii refers to the character it reads
     int  ascii_count[95];                               //ascii from 33 to 127 --> 95 elements
                                   
   public:
     analyse_text_file()
     {
       //Constructor
       for(int j=0;j<95;j++)
       {
         ascii_count[j]=0;
       }
       for(int k=33;k<128;k++)                           //without including whitespaces ! is the first character whose ascii value is 33
       {
         ascii[k-33]=char(k);                            
       }
     }
     
     void check_freq()
     {
       while(in_file >> d)
       {
         for(int i=0;i<95;i++)
         {
           if(ascii[i]==d){ascii_count[i]++;}
         }
         if(in_file.eof()){break;}
       } 
     }
     
     void print_freq()
     {
       for(int i=0;i<95;i++)
       {
         if(ascii_count[i] != 0) 
         {
           cout << "frequency of " << ascii[i] << " is " << ascii_count[i] << endl;
         } 
       }
     }
     
     
 };
 
 int main(int argc, char *argv[])
 {
   in_file.open(argv[1]);
   analyse_text_file given_file;
   given_file.check_freq();
   given_file.print_freq();
 }
 
 
