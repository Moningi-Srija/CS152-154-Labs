/* Roll no. = 210050098
   Problem = Problem 0*/
   
 /*
   considering the products as calculators and features as
   some mathematical functions.
   
   parental hierarchy
   
   productC is super class.
   productB is subclass of productC.
   productA is subclass of productB.
 */
   
 #include <iostream>
 #include <cmath>
 using namespace std;
 
 class productC
 {
   //super class with only feature 1
   //feature1 - only simple arithmetic operations.
   private:
   	
   protected:
   
   	int a;
   	
   public:
   	
   	productC()
   	{
   	  //Constructor
   	  a = 7;
   	}
   	
   	void add(int b)
   	{
   	  cout << "added b " <<  a+b << endl;
   	}
   	void subtract(int b)
   	{
   	  cout << "subtracted b " << a-b << endl;
   	}
   	void multiply(int b)
   	{
   	  cout << "multiplied with b " << a*b << endl;
   	}
   	
 };
 
 class productB : public productC
 {
   //child class with feature 2 added
   //feature 3 - some other mathematical operations got added
   public:
   	
   	void square()
   	{
   	  cout << "squared " << a*a << endl;
   	}
   	void cube()
   	{
   	  cout << "cubed " << a*a*a << endl;
   	}
   	
 };
 
 class productA : public productB
 {
   //child class of subclass productB
   //feature 2 - some other mathematical operations got added
   
   public :
   	
   	void increment()
   	{
   	  cout << "incremented " << a+1 << endl;
   	}
   	void decrement()
   	{
   	  cout << "decremented" << a-1 << endl;
   	}
 };
 
 int main()
 {
 
   productC pc;      //has feature 1
   productB pb;      //has features 1 & 3
   productA pa;      //has features 1, 3 & 2
   
   pc.add(5);
   pc.multiply(5);
   
   pb.square();
   pb.subtract(5);
   
   pa.cube(); 
   pa.add(2);
   pa.increment();
 }
