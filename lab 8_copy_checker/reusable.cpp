 class analyse_code 
 {
   // can be abstract class, which can be extended 
   // in your implementation files
   
   public:
   	ifstream f1, f2;
   	string takeword1;
   	string takeword2;
   	int numword1;
   	int numword2;
   	float sim = 0;
   	int numf1 = 0;
   	int numf2 = 0;
   	int totnum = 0;
   	int index;
   	int numcommon=0;
   	struct word
   	{
   	  string word;
   	  int nword;
   	  bool rword;
   	};
   	
   	word w1[1000];
   	word w2[1000];
   	
   	analyse_code()
   	{
   	    for (int i=0; i<1000; i++) 
   	    {
     	      w1[i].nword = 0;
     	      w1[i].rword = false;
     	      
     	      w2[i].nword = 0;
     	      w2[i].rword = false;
    	    }
            index = 0;
   	}
   	
 };

 int analyse1(int a, int b)
 {
   int similarity1 = a*100/b;
   return similarity1;
 }
 
 int analyse2(float a, int b, int c)
 {
   int similarity2 = int((a*100)/ max(b,c));
   return similarity2;
 }
 
 int analyse3(float a, int b, int c, int d)
 {
   int similarity3 = int(10*a/max(c,d));
   return similarity3;
 }

