 #include <fstream>
 #include <iostream>
 #include <string>
 #include <cassert>
 using namespace std;
 #include "similarity.h"
 #include "reusable.cpp"

 // definition of the same function, but another variant
 // exactly the same name! which you cannot specify in the same file!

 int checksimilarity (string n1, string n2) 
 {
   analyse_code aw;
   
   aw.f1.open(n1);
   aw.f1.seekg(0,ios::beg);
   while(!aw.f1.eof())
   {
     aw.f1 >> aw.takeword1;
     aw.w1[aw.numf1].word = aw.takeword1;
     aw.w1[aw.numf1].nword = 1;
     aw.numf1++;
   }
   aw.f1.close();
   
   aw.f2.open(n2);
   aw.f2.seekg(0,ios::beg);
   while(!aw.f2.eof())
   {
     aw.f2 >> aw.takeword2;
     aw.w2[aw.numf2].word = aw.takeword2;
     aw.w2[aw.numf2].nword = 1;
     aw.numf2++;
   }
   aw.f2.close();
   assert(aw.numf1 >=0 && aw.numf2 >=0);
   
   for(int i=0; i<aw.numf1; i++)
   {
     assert(aw.w1[i].nword >= 1);
     for(int j=0; j<i; j++)
     {
       if((!aw.w1[i].rword) && aw.w1[i].word == aw.w1[j].word)
       {
         aw.w1[j].rword = true; 
         assert(aw.w1[j].nword >= 1);
       }
     }
   }
   
   for(int i=0; i<aw.numf1; i++)
   {
     assert(aw.w2[i].nword >= 1);
     if(!aw.w1[i].rword)
     {
       for(int j=0; j<aw.numf2; j++)
       {
         if(aw.w1[i].word == aw.w2[j].word)
         {
           assert(aw.w2[j].nword >= 1);
           aw.sim++;
         }   
       }
     }
   }
   
   assert(!aw.f1.is_open() && !aw.f2.is_open());
   int result = analyse2(aw.sim,aw.numf1,aw.numf2);
   return result;
 }

