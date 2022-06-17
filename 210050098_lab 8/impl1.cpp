 #include <fstream>
 #include <iostream>
 #include <string>
 #include <cassert>
 using namespace std;
 #include "similarity.h"
 #include "reusable.cpp"

 
 int checksimilarity(string n1, string n2)
 {
   analyse_code aw;
   
   aw.f1.open(n1);
   aw.f2.open(n2);
   
   while(!aw.f1.eof() || !aw.f2.eof())
   {
     aw.f1 >> aw.takeword1;
     aw.f2 >> aw.takeword2;
     if(aw.takeword1 == aw.takeword2)
     {
       aw.sim++;
     }
     aw.totnum++;
     assert(aw.sim <= aw.totnum);
   }
   
   assert(aw.sim >=0 && aw.totnum >=0);
   
   aw.f1.close();
   aw.f2.close();
   
   assert(!aw.f1.is_open() && !aw.f2.is_open());
   int result = analyse1(aw.sim, aw.totnum);
   return result;
 }


 


