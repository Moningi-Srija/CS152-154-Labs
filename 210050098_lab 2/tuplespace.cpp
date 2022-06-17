/*210050098
  Lab 2 Program : TupleSpace*/
  
  #include <iostream>
  using namespace std;
  
  class tuplespace
  {
    private:
        struct pair{long long int key;int value;};
    	int request_key;
    	bool repeat;
    	char response;
    	int found;
    	int size;
    	pair vp[1000];
    public:
    	tuplespace()
    	{
    	  //constructor
    	  size = 10;
    	  for(int i=0;i<1000;i++)
    	  {
    	    vp[i].key = 0;
    	    vp[i].value = 0;
    	  }
    	  for(int i=0;i<10;i++)
    	  {
    	    vp[i].key = 210050000+i;
    	    vp[i].value = i*i*i;
    	  }
    	}
    	
    	bool check(long long int key)
    	{
    	  for(int i=0;i<size;i++)
    	  {
    	    if(vp[i].key == key) {repeat = true;}
    	  }
    	  return repeat;
    	}
    	
    	int get_element(long long int key)
    	{
    	  for(int i=0;i<size;i++)
    	  {
    	    if(vp[i].key == key) {return i;}
    	  }
    	  return 10,000;
    	}
    	
    	int get_value(long long int key)
    	{
    	  int j=get_element(key);
    	  return vp[j].value;
    	}
    	
    	void find_value(long long int key)
    	{
    	  int l=get_value(key);
    	  cout << l << endl;
    	}
    	
    	void add_element(long long int key, int value)
    	{
    	  bool k = check(key);
    	  if(k == true)
    	  {
    	    repeat = false;
    	    cout << "a key-value pair aldready exists with the given key\n" ;
    	    cout << "do you want to replace it? (y/n)\n";
    	    cin  >> response;
    	    if(response == 'y')
    	    {
    	       replace_element(key,value);
    	    }
    	    else {return;}
    	  }
    	  else
    	  {
    	    size+=1;
    	    vp[size].key = key;
    	    vp[size].value = value;
    	  }
    	}
    	
    	void replace_element(long long int key, int value)
    	{
    	  found = get_element(key);
    	  vp[found].value = value;
    	}
    	
    	void delete_element(long long int key)
    	{
    	  for(int i=0;i<size;i++)
    	  {
    	    if(vp[i].key == key) 
    	    {
    	      vp[i].key = 0;
    	      vp[i].value = 0;
    	    }
    	  }
    	}
  };
  
  int main()
  {
    tuplespace ts;
    ts.find_value(210050006);
    //ts.add_element(210050006,70); this redirects to replace if response is yes
    ts.add_element(210050098,100);
    ts.replace_element(210050098,500);
    ts.find_value(210050098);
  }
