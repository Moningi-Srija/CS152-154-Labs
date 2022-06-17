 /* Roll no. 210050098
    Assertions: Defensive Programming */

 #include <iostream>
 #include <cassert>
 using namespace std;

 // A program which is not correct

 class Collection 
 {
   int *S;
   int cap, card;           //cap -> capacity, card -> cardinality
   // any additional variables

   public:
 	 Collection(int sz) 
 	 {
 	   //... add assertion(s)...
 	   
 	   assert(sz > 0);  //since collection cannot have negative number of elements, assuming collection with 0 size is allowed
 	      
	   S = new int [sz];
	   card = 0;
	   cap  = sz;
	   
	   assert(card < cap); //Anyways, it will be true always, but still for safety.
	 }

	 void push_back(int elem) 
	 {
           //... add assertion(s)...
           assert(card < cap);  // pre-conditions
           assert(card >= 0);

           //... add logic
           S[card] = elem;
           card++;

   	   //... add assertion(s)...
   	   assert(S[card-1] == elem); //Just to make sure that right element got added
	 }

	 int pop_back() 
	 {
           //... add assertion(s)...
           assert(card > 0); //to check that there is something to pop
           assert(card <= cap); //to be more defensive

           //... add logic
           int oldlast = S[card-1];
           card--;
  
           //... add assertion(s)...
           assert(card >=0 && card < cap && S[card] == oldlast); //to check that correct element got deleted
           return oldlast;
	 }
 };
 int main () 
 {
   // add testing code that tests the class above and fails it, the failures get caught by assertions
   Collection c(2);
   c.push_back(5);
   c.push_back(4);
   c.push_back(3);
   int deleted = c.pop_back();
   cout << deleted << endl;
    
   // make another version with correct implement and that passes all assertions
 }
