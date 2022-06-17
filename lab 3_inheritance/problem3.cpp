/*210050098
  Program : problem 3 (Smart phone)*/
  
  #include <iostream>
  #include <cmath>
  using namespace std;
  
  class basicphone
  {
    protected:
    
    	int price;
    	string os;               //operating system
    	double displaysize;      
    	string sr;               //screen resolution
    	string size;             //phone dimensions
    	double weight;
    	int ram;
    	double processor;
    	string processortype;
    	string camera;
    	int internalstorage;
    	string batterycapacity;
    	
     public:
        
        void getprice()
        {
          cout << "price in US dollars : $" << price << endl;
        }
        
        void getos()
        {
          cout << "operating system : " << os << endl;
        }
        
        void getdisplaysize()
        {
          cout << "display size : " << displaysize << endl;
        }
        
        void getsr()
        {
          cout << "screen resolution : " << sr << endl;
        }
        
        void getsize()
        {
          cout << "size : " << size << endl;
        }
        
        void getweight()
        {
          cout << "weight : " << weight << endl;
        }
        
        void getram()
        {
          cout << "RAM :" << ram << endl;
        }
        
        void getprocessor()
        {
          cout << "processor : " << processor << "GHz" << processortype << endl;
        }
        
        void getcamera()
        {
          cout << "Camera : " << camera << endl;
        }
        
        void getinternalstorage()
        {
          cout << "INternal Storage : " << internalstorage << endl;
        }
        
        void getbatterycapacity()
        {
          cout << "Battery Capacity : " << batterycapacity << endl;
        }
       
  };
  
  class feature1
  {
    public:
	  void storageexpansion()
	  {
	    cout << "Storage Expansion is possible" << endl;
	  }
  };
  
  class feature2
  {
    public:
	  void batteryreplacement()
	  {
	    cout << "Battery Replacement is possible" << endl;
	  }
  };
  
  class iPhone5s : public basicphone
  {
    public:
    
        iPhone5s()
        {
          price = 199;
    	  os = "IOS 7";               
    	  displaysize = 4.0;      
    	  sr = "1136x640";               
    	  size = "123.8x58.6x7.6mm";             
    	  weight = 112;
    	  ram = 1;
    	  processor = 1;
    	  processortype = "dual-core";
    	  camera = "8MP/1MP";
    	  internalstorage = 32;
    	  batterycapacity = "250h";
    	}
    	
  };
  
  class productA : public basicphone, public feature1, public feature2
  {
    public:
    
        productA()
        {
    	  price = 399;
    	  os = "Android 4.2";               
    	  displaysize = 5.0;      
    	  sr = "1920x1080";               
    	  size = "136.6x69.8x7.9mm";             
    	  weight = 130;
    	  ram = 2;
    	  processor = 1.7;
    	  processortype = "quad-core";
    	  camera = "13MP/2MP";
    	  internalstorage = 32;
    	  batterycapacity = "2600mAh";
    	}
    	
  };
  
  class productB : public basicphone, public feature1, public feature2
  {
    public:
    
       productB()
       {
         price = 399;
    	 os = "Android 4.1";               
    	 displaysize = 4.7;      
    	 sr = "1920x1080";               
    	 size = "137.8x69.3x10.4mm";             
    	 weight = 156;
    	 ram = 2;
    	 processor = 1.7;
    	 processortype = "quad-core";
    	 camera = "4MP/2.1MP";
    	 internalstorage = 32;
    	 batterycapacity = "2300mAh";
       }
    	
  };
  
  class productC : public basicphone
  {
    public:
        
        productC()
        {
    	   price = 199;
    	   os = "Windows Phone 8";               
    	   displaysize = 4.5;      
    	   sr = "1280x768";               
    	   size = "130.4x71.4x10.4mm";             
    	   weight = 158;
    	   ram = 2;
    	   processor = 1.5;
    	   processortype = "dual-core";
    	   camera = "4.1MP/1.2MP";
    	   internalstorage = 32;
    	   batterycapacity = "2000mAh";
    	}
    	
  };
  
  class productD : public basicphone
  {
    public:
     
      productD()
      {
    	 price = 199;
    	 os = "Android 4.2.2";               
    	 displaysize = 5.5;      
    	 sr = "1920x1080";               
    	 size = "149x77x7.9mm";             
         weight = 147;
    	 ram = 2;
    	 processor = 2.2;
    	 processortype = " ";
    	 camera = "13MP/5MP";
    	 internalstorage = 16;
    	 batterycapacity = "3050mAh";
      }
  };
  
  class productE : public basicphone, public feature1
  {
    public:
    	
    	productE()
    	{
    	  price = 150;
    	  os = "BlackBerry 10";               
    	  displaysize = 4.2;      
    	  sr = "1280x780";               
    	  size = "130x65.6x9mm";             
    	  weight = 137.5;
    	  ram = 2;
    	  processor = 1.5;
    	  processortype = "dual-core";
    	  camera = "6MP/2MP";
    	  internalstorage = 16;
    	  batterycapacity = "1800mAh";
    	}
    	
  };
  
  int main()
  {
    iPhone5s iphone;
    productA pa;
    productB pb;
    productC pc;
    productD pd;
    productE pe;
    
    iphone.getos();
    iphone.getcamera();
    
    pa.storageexpansion();
    pa.batteryreplacement();
    pa.getprice();
    
    pb.storageexpansion();
    pb.batteryreplacement();
    pb.getdisplaysize();
    
    pc.getprocessor();
    
    pd.getram();
    
    pe.storageexpansion();
    pe.getsr();
    
  }
  
  
  
