 #include <iostream>
 #include <string>
 #include <fstream>
 #include <cstdlib>

 using namespace std;

 /* This game lets you create the world around you using the four elements of archemedes - Air, Fire, Water and Earth. You can combine two of the known elements and create a new element. This goes  on till all elements have been created. 
 
 The elements are a structure, having five attributes, namely -
 Name, mom and dad (the creator elements) and status (whether it has been created or not).
 
 The user has several options 
 -> To Combine and Create
 -> To Look up the database of created elements
 -> To look up all the information (which has been explored by the user) of a certain element
 -> To Look up the list of possible elements
 -> To exit the program if the user gets infy bored
 */

 struct element
 {
   string name;
   string mom, dad;
   string status;
 };

 /* Functions 
 	 Create:
	 -> has three input parameters- string1 and string2 and the array of all elements,'thing'.
	 status of both strings is checked. if they have been created, function moves further. else, function terminates.
	 -> if the baap1 and baap2 match with the given strings, the element is created i.e. its status is set to created. The element is then copied into
	 another file.

	 Look:
	 -> has one parameter - array 'thing'.
	 -> all elements with status 'created' are printed.

	 Lookinfo:
	 -> has two parameters - search string and 'thing'.
	 -> the function looks for all elements of array where the search string is found either in baaps or name. if the status is 'created' then the element is shown to user.

	 Lookall:
	 -> this function has one parameter - the array 'thing'.
	 -> all names are printed. only names. no other info.

*/
 int create(string a, string b, element *arr)
 {
   int errcode = -1;
   for(int x=0;x<364;x++)
   {
     if((arr[x].name == a || arr[x].name == b) && arr[x].status != "created")
     {
       cout<<"\nERROR!!\n. Element used not created." << endl;
       return (errcode);
     }
     
     if(((arr[x].mom == a && arr[x].dad == b) || (arr[x].dad == a && arr[x].mom == b)) && arr[x].status!= "created")
     {
       cout << "CONGRATULATIONS!!!! " << endl ;
       cout << "NEW ELEMENT CREATED! - " << endl;
       cout << arr[x].name << endl;
       arr[x].status = "created";	
       return (x);
     }
   }

   cout<<"\nSORRY!\n No new Created.\n";
   return (errcode);
 }

 void look(element arr[])
 {
   int x=1;
   for(int i=0;i<364;i++)
   {
     if(arr[i].status == "created")
     {
       cout<<x<<"."<<" "<<arr[i].name;//" = "<<arr[i].mom<<" + "<<arr[i].dad<<".\n";
       x++;
     }
   }
 }

 void lookinfo(string a, element arr[])
 {
   int x=1;
   for(int i=0;i<364;i++)
   {
     if((arr[i].name == a || arr[i].mom == a || arr[i].dad== a) && arr[i].status == "created")
     {
       cout<<"\n"<<x<<"."<<" "<<arr[i].name<<" = "<<arr[i].mom<<" + "<<arr[i].dad<<".\n";
       x++;
     }
   }
 }

 void lookall(element arr[])
 {
   for(int i=0;i<364;i++)
   {
     cout<<arr[i].name<<"\n";
   }
 }
 
 void intro()
 {
   cout<<"\n\n*******************************************************************************************************************" << endl;
   cout <<"This game lets you create the world around you using the four     elements of archemedes - Air, Fire, Water and Earth." << endl;
   cout << " You can combine two of the known elements and create a new element. This goes on till all elements have been created."<< endl;
   cout << "\n\n\n**Please do not use Capital Letters. \n\n\n**Enter all data in small case.Like password, this program is case sensitive" << endl;
   
   
 }

 int main()
 {
   intro();
   
   ifstream newu;
   ofstream newo;
   
   string newg,ans,user_name;

   //Asking the User whether they have played the Game Before. Much like Load/Save Profile.
 
   cout<<"_________________________________________________________________________________________________________________________________-" << endl;
   cout<<"Are you a new user?Enter 'yes' if you are. If you are not a new user then enter no. " <<endl;
   
   cin>>ans;
   int newa=0;
   if(ans=="yes")
   {
     do
     {
       newa=0;
       cout<<"Please enter your name : ";
       cin>>user_name;
       newu.open("user.c");
       newu>>newg;
       
       while(!newu.eof())
       {
         if(newg==user_name)
          {
            cout<<"\nSorry, user already exists.\n";
            newa=1;
            break;
          }
          newu>>newg;
       }
       newu.close();
     }
     
     while(newa==1);
         newo.open("user.c",ios::app );

         newo<<"newUser"<<" "<<user_name<<endl<<user_name<<" "<<endl<<" ";
         newo.close();
         cout<<"outofIfLoop";
   }

    // Confirming User Existence.

    else
    {
      int baba=0;
      while(baba==0)
      {
        cout<<"\nPlease enter your name : ";
        cin>>user_name;
        newu.open("user.c");
        while(!newu.eof() && baba==0)
        {
          newu>>newg;
          if(newg==user_name)
          {
            cout<<"\nPleasure to meet you again, "<<user_name<<endl;
            baba=1;
          }
        }
        if(baba==0)
        {
          cout<<"\nSorry! User Name Does not exist\n";
          newu.close();
        }
      }
    }
	
   string g; 
   /*garbage string*/
   /* Create two files. One to read all the elements from, and one to store the Created elements In.*/
   ifstream f,e,oo;
   f.open("data.c" );           // This File contains all the Data.
   ofstream o;
   o.open("user.c",ios::app  ); // This File Saves User Profiles.
   oo.open("user.c");
   	
   element thing[364]; 
   // This is the array of elements that will read the data from the file - data.c
   /* To read the elements into the array 'thing', one by one, from the opened file.*/

   for(int i=0;i<364;i++)
   {
     //Reading The Name, Baap1 and Baap2 of the Thing.
     //cout<<f;
     f>>thing[i].name;
     //f>>g;
     f>>thing[i].mom;
     //f>>g;
     f>>thing[i].dad;
     //As Fire, Earth, Air and Water are elemental, their Status is being set to "Created".
     if(thing[i].name == "fire" || thing[i].name == "water" || thing[i].name == "air" || thing[i].name == "earth")
     {
       thing[i].status = "created";
       thing[i].mom = "elemental";
       thing[i].dad = "elemental";
     }

     // If in case the user has already unlocked certain elements, their status is being set to Created.

     e.open("user.c");
     e>>g;
     while(!e.eof())
     {
       while(g!=user_name && !e.eof())
       {
         e>>g;
       }
       e>>g;
       while(g!=user_name && !e.eof() )
       {
         if(thing[i].name == g)
         {
           thing[i].status ="created";
         }
         e>>g;
       } 
     }
      e.close();
   }
   f.close();
   
  /* Provide the user with the Choices in the form of a menu.*/
  int i=0;
  string a,b,c;
  /* Begin Infy loop. that is, Menu*/
  
  int l=-1,tabo=0;
  while (i==0)
  {
    if(l!=-1)
    {
      // Writing the Created Element's Information in the User Profile.        	   
      o<<user_name<<endl<<thing[l].name<<" = "<<thing[l].mom<<" + "<<thing[l].dad<<endl<<user_name<<endl;
    }
    l=-1;
    cout<< "\n\n------------------------------------------------------------------------------------------------------------\n\n" << endl;
    cout << "Enter your choice\n1. Combine and Create\n2.Look up all created elements\n3.Look up info of one element\n4.Look up all possible elements\n5. Exit\n :" << endl;
    int choice;
    cin>>choice;

    switch (choice)
    {
      case 1 :
      {
        cout<<"\nEnter the Elements you want to combine : ";
	cin>>a>>b;
	l=create(a,b,thing);
	break;
      }
      case 2 :
      {	
        cout<<"\n\n-----------------------------------You have the following Elements--------------------------------------\n\n--Fire, Earth, Air and Water are elemental. \n" << endl;
        e.open("user.c");
        e>>g;
        while(!e.eof())
        {
          e>>g;
          if(g==user_name)
          {
            e>>g;
            while(g!=user_name)
            {
              cout<<"--";
              for(int ii =0;ii<5;ii++)
              {
                cout<<g<<" ";
                e>>g;
              }
              cout<<endl;
            }
          }
        }
        e.close();
        break;
      }
      case 3 :
      {
	cout<<"\nEnter the element whose info you want : ";
	cin>>c;
	lookinfo(c,thing);
	break;
      }
      case 4 :
      {
        lookall(thing);
        break;
      }
      case 5 :
      {
        o<<endl<<" "<<user_name<<" "<<user_name<<" ";
        return 0;
      }
    }
  }
  return 0;
}
