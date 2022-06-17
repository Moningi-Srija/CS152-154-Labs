/*210050098
  Program : problem 1 (Laptop)*/
  
  #include <iostream>
  #include <cmath>
  using namespace std;
  
  class laptop
  {
    public:
    	int price;
    	string model;
    	string processor = "Intel Core i5-8250U 1.6-3.4GHz (4c/8t)";
    	string graphiccard = "NVIDIA GeForce MX150 2GB GDDR5";
    	string ram = "8GB DDR4";
    	string screen = "15.6in TN matte";
    	string resolution = "1920 x 1080";
    	double weight = 4.90;
    	
    	void getprice()
    	{
    	  cout << "Price : $" << price << endl;
    	}
    	
    	void getmodel()
    	{
    	  cout << "Model : " << model << endl;
    	}
    	
    	void getprocessor()
    	{
    	  cout << "Processor : " << processor << endl;
    	}
    	
    	void getgraphiccard()
    	{
    	  cout << "Graphic Card : " << graphiccard << endl;
    	}
    	
    	void getram()
    	{
    	  cout << "RAM : " << ram << endl; 
    	} 
    	
        void getscreen()
        {
          cout << "Screen : " << screen << endl;
        }
        
        void getresolution()
        {
          cout << "Resolution : " << resolution << endl;
        }    	
        
        void getweight()
        {
          cout << "Weight : " << weight << "lbs" << endl;
        }
  };
  
  class feature1
  {
    //Hard Drive
    
    public:
    
    	void HDD()
    	{
    	  cout << "This laptop has 1TB HDD" << endl;
    	}
    	
  };
  
  class feature2
  {
    //SSD
    
    public:
    	
    	void SSD()
    	{
    	  cout << "THis laptop has 256GB SSD" << endl;
    	}
  };
  
  class laptop1 : public laptop, public feature1
  {
    public:
    	
    	laptop1()
    	{
    	  //constructor
    	  price = 548.5;
    	  model = "Acer Aspire 3 A315-41-R8UU";
    	  processor = "AMD Ryzen 5 2500U 2.0-3.6GHz (4c/8t)";
    	  graphiccard = "AMD Radeon Vega 8";
    	  weight = 5.7;
    	}
    
  };
  
  class laptop2 : public laptop, public feature2
  {
    public:
    	
    	laptop2()
    	{
    	  price = 569.99;
    	  model = "Acer Aspire 5 A515-51G-5504";
    	}
  };
  
  class laptop3 : public laptop, public feature2
  {
    public:
    	
    	laptop3()
    	{
    	  price = 549;
    	  model = "Acer Aspire 5 A515-51G-53V6";
    	}
  };
  
  class laptop4 : public laptop, public feature2
  {
    public:
    	
    	laptop4()
    	{
    	  price = 559.99;
    	  model = "Acer Aspire 5 A517-51G-54GK";
    	  processor = "Intel Core i5-7200U 2.5-3.1GHz (2c/4t)";
    	  graphiccard = "NVIDIA GeForce 940MX 2GB GDDR5";
    	  screen = "17.3in IPS matte";
    	  weight = 6.61;
    	}	
  };
  
  class laptop5 : public laptop, public feature2
  {
    public:
    	
    	laptop5()
    	{
    	  price = 599.99;
    	  model = "Acer Aspire E5-576G-5762";
    	  ram = "8GB DDR3L";
    	  weight = 5.27;
    	}
  };
  
  int main()
  {
    laptop1 l1;
    laptop2 l2;
    laptop3 l3;
    laptop4 l4;
    laptop5 l5;
    
    l1.HDD();
    l1.getram();
    
    l2.SSD();
    l2.getresolution();
    
    l3.getmodel();
    l3.getprice();
    
    l4.getprocessor();
    l4.getweight();
    
    l5.getscreen();
    l5.getgraphiccard();
  }
  
