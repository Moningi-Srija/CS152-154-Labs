/*210050098
  Lab 2 Program : ATM*/
  
 #include <iostream>
 using namespace std;
 
 struct acc{int accno ; int balance;};
 
 class atm
 {
   private:
   	acc a[176]; //for simplicity assuming 
   	int amount;
   	char yes = 'y', no = 'n',response;
   	int receiver_acc;
  
   public:
        int accno;
   	atm()
   	{
          //constructor
          for(int i=0;i<176;i++)
          {a[i].accno = 210050000 + i; a[i].balance=0;}  //similar to our rollno.s 	
   	}
   	
   	void start(int no)
   	{
   	  cout << "\t\tWELCOME\t\t\n" ;
   	  //cout << "Please enter account number\n";
   	  accno = no;
          //cin >> accno;  for forming an interface this can be used.
   	}
   	
   	void deposit(int amount)
   	{
   	  a[accno-210050000].balance+=amount;
   	  cout << "deposit successful\n" << "Thank you for visiting\n";
   	}
   	
   	void withdraw(int amount)
   	{
   	  if(a[accno-210050000].balance < amount) 
   	  {
   	    cout << "error : greater than balance withdrawl is not possible\n";
   	    cout << "would you like to withdraw your complete balance? (y/n)\n";
   	    cin  >> response;
   	    if(response == yes) {withdraw(a[accno-210050000].balance);  cout << "withdrawl successful\n";}
   	    else if(response == no) {cout << "Thank you for visiting\n";}
   	    else {cout << "invalid response\n";}
   	  }
   	}
   	
   	void checkBalance()
   	{
   	  cout << "Your present balance : " << a[accno-210050000].balance << "\nThank you for visiting\n";
   	}
   	
   	void transfer(int receiver_acc,int amount)
   	{
   	  if(a[accno-210050000].balance > amount)
   	  {
   	    a[accno-210050000].balance-=amount;
   	    a[receiver_acc-210050000].balance+=amount;
   	    cout << "transfer successful\n" ;
   	    checkBalance(); 
   	  }
   	  else
   	  {
   	    cout << "transfer not possible\n";
   	    cout << "Thank you for visiting\n";
   	  }
   	}
 };
 
 int main()
 {
   atm a1;
   a1.start(210050098);       
   a1.deposit(10000);
   a1.withdraw(2000);
   a1.checkBalance();
   a1.transfer(210050100,6000); //for example
   a1.withdraw(1000);
   a1.checkBalance();
   //to start a new session we can use a1.start() again.
 }
