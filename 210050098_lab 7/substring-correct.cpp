 /*
   Roll no. 210050098
   Program : Substring.cpp
 */
 #include <iostream>
 #include <string>
 #include <cassert>
 using namespace std;

 int find(string str, string sub)
 {  
   // add precondition assertions
   assert(str.size() >= 0);          // checks if string has some size
   assert(str.size() >= sub.size()); // checks if string is larger than or same as substring
   
   // add logic
   int pos = -7; //which is never possible, here -7 is a kind of errorcode
   for(int i=0; i<str.size(); i++)
   {
     bool issub = true;
     for(int j=0; (j<sub.size() && i+j < str.size()) ; j++)
     {
       issub = (issub && sub[j]==str[i+j]);
     }
     if(issub)
     {
       pos = i;
       continue;
     }
   }
   
   // add postcondition assertions
   if(pos != -7)
   {
     assert(str.size() - pos >= sub.size());
     // it will pass anyways, as substring is a part of string, but still to be more defensive.
   }
   
   return pos;
 }

 int main ()
 {
   // add testing code here which fails the above function and that failure
   // gets caught by the assertions that you have
   
   string str = "rushikeshkjoshisir";
   string sub = "joshi";
   
   int result = find(str, sub);
   if(result != -7)
   {
     cout << "first occurence is present from index " << result << " to " << result + sub.size() - 1 << endl;
   }
 }
