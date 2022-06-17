/*210050098
  Lab 2 Program : DrinksVendingMachine*/
  
  #include <iostream>
  using namespace std;
  
  struct drink{string name; int ID; int stock; int cost;};
  
  class VM
  {
    private:
    	int wallet_money;
    	int no_of_drinks;
    	int request_id;
        int coin;
        drink d[10];
    public:
        VM()
        {
          //constructor
          wallet_money = 0;
          no_of_drinks = 5;
          for(int i=0;i<10;i++) 
          {
            d[i].ID = i+1;
            d[i].stock = 3;
            d[i].cost = 10*(i+1);
          }
          d[0].name = "fanta";
          d[1].name = "limca";
          d[2].name = "tango";
          d[3].name = "lassi";
          d[4].name = "water";
        }
        
        //customer related
        
        void display_drink(int i)
        {
          cout << d[no_of_drinks].name;
          cout << d[i].name << "  " << d[i].ID << "    " << d[i].cost << "  "; 
          if(d[i].stock == 0) {cout << "unavailable\n";}
          else {cout << "available\n";}   
        }
        
        void menu()
        {
          cout << "\t\tWELCOME" << endl;
          cout << "NAME  " << "ID  " << "cost  " << "status\n";
          for(int i=0;i<no_of_drinks;i++)
          {display_drink(i);}
        }
        
        void counter(int request_id,int coin)
        {
          cout << "pls enter ID and insert coin\n";
          //cin >> request_id >> coin; in normal case
          if(d[request_id-1].cost != coin) {cout << "wrong coin, returning back coin\n";}
          else 
          {
            d[request_id-1].stock-=1;
            wallet_money+=coin;
            cout << "enjoy your drink\n";
          }
        }
        
        //stock
        
        void add(int ID,int stock)
        {
          d[ID-1].stock+=stock;
        }
        
        void new_drink(string name,int id,int stock,int cost)
        {
          d[no_of_drinks].name = name;
          d[no_of_drinks].ID = id;
          d[no_of_drinks].stock = stock;
          d[no_of_drinks].cost = cost;
          no_of_drinks+=1;
        }
        
        void get_money()
        {cout << "wallet_money " << wallet_money << endl;}
    	
  };
  
  int main()
  {
    VM v;
    v.menu();
    v.counter(3,20);
    v.counter(3,30);
    v.counter(3,30);
    v.counter(3,30);
    v.menu();
    v.add(5,3);
    v.new_drink("shake",6,3,60);
    v.menu();
    v.get_money(); 
    v.counter(6,60);
    v.get_money();
  }
