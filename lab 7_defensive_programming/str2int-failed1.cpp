 #include <iostream>
 #include <string>
 #include <cassert>
 #include <climits>

 using namespace std;

 int str2int (string s)
 {
   // define your other needed variables
   int result;
   int i = s.size()-1;
   int length = s.size();
   int a = 0;
   long long integer = 0;
   long long place_value = 1;
   long long check;

   // add assertions here first
   assert(length>=1 && length<=12); // since the max int is 2147483647 has 10 digits and min int -2147483648 has 11, string size shouldn't exceed 11.

   // Ensuring the string has only numbers and no other characters
   if (s[0]=='-') a = 1;
   for(;a<length;a++) 
   {
     assert((s[a]<='9') && (s[a]>='0')); // to check if no other characters are present
   }
   
   // the logic, which does not check for any condition, can be buggy
   for( ; i > 0 ; i-- ) 
   {
     integer += ( (long long) (s[i]-'0') ) * place_value ;
     place_value *= 10 ;
     assert((integer<INT_MAX) && (integer>INT_MIN));
   }

   // add assertions for postcondition
   // Checking if whatever we did was indeed correct!
   check = integer;
   i = s.size()-1;
   if(s[0] != '-')
   {
     while ( check != 0 && i >= 0 ) 
     {
       assert(check%10==s[i]-'0'); // to ensure that we built the correct number
       check/=10;
       i--;
     }
      result = integer;
   }
   else
   {
     while ( check != 0 && i > 0 ) 
     {
       assert(check%10==s[i]-'0');
       check/=10;
       i--;
     }
     result = -integer;
   }

   return result;
};

 int main() 
 {
   // develop main which catches errors through assertions
   string s = "11114567778990";
   int converted = str2int(s);
   cout << converted << endl;
   
   // report bugs
   // will not work for -2147483648
 }
