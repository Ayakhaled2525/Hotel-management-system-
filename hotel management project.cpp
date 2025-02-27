#include<iostream>
#include <iomanip>
#include <ctime>      //prints the current date and time
#include<string>
#include <cstdlib>      // for system()
#include <cctype>     // for isdigit function
using namespace std;

// function that prints the welcome screen

void Draw(){
      system("cls");      // clear console window
      system("color 0B");   //changes the color of cmd

cout<<"\t\t\t====================================\n";
cout<<"\t\t\t|                                  |\n";
cout<<"\t\t\t|   -----------------------------  |\n";
cout<<"\t\t\t|        Welcome To Our Hotel      |\n";
cout<<"\t\t\t|   -----------------------------  |\n";
cout<<"\t\t\t|                                  |\n";
cout<<"\t\t\t====================================\n";

time_t currentDT = time(0);
 cout << "\n\t\t\tDate and Time : " << ctime(&currentDT);
 cout<<"\n";
}

 // the number of rooms in hotel

   const int total_number_room=5;
  int roomindex[total_number_room] = {100,101,102,103,104};                              //hotel room number
  int room_price[total_number_room] = {300,500,400,300,500};                            //price for a day in dollar
  bool booked[total_number_room] = {false,true,true,false,false};                       //IS the room id booked or no
  string typeofroom[total_number_room] = {"single","suite","double","single","suite"};  // the type which the customer want

// Function that display Available Rooms
  void Available_Rooms(){

        cout<<"Available Rooms : \n";
        cout<<"--------------------------------------------------------\n";
        cout<<"Room number "<<"\t\t"<<"type of room "<<"\t\t"<<  "price\n";
        cout<<"--------------------------------------------------------\n";

        int count=0;     //the number of Available rooms;

       for(int i=0;i<total_number_room;i++){
           if(booked[i]==false){               // test if the room is not booked or no

               cout<< roomindex[i]<<"\t\t\t"<< typeofroom[i]<<"   \t\t"<< room_price[i]<<endl;
               count++;
           }
       }

       if(count==0){
           cout<<"sorry, there ara no Available Rooms now\n";
       }
    }

   //details of customer.

   struct customer {
       string name;                 // name of customer.
       string phone;                 // the number phone
       int numberrooms;              // the number of roome that customer wants.
       int guests;                    //number of guests.
       string Date_check_in;
       string Date_check_out;
       string id;                 // the National id
       int nightstayed;          // the number of nights stayed
       int rateing;
       string recomendation;
   };

   // Function to validate the National ID

   bool isValidNationalID(const string& id){

    // Check if the length is exactly 14

    if (id.length() != 14) {
        return false;
    }

    // Ensure all characters are digits

    for (char c : id){
        if (!isdigit(c)){
            return false;
        }
    }
    return true;
}

 customer person;
 int totalroomcost = 0;

// function enables customer to book room.
 
 void BookRoom(){
       Available_Rooms();

 cout << "\nEnter Your Name : ";
 cin >> person.name ;
 cout <<"\n";
 cout << "Enter your Phone number : ";
 cin >> person.phone ; 
 cout <<"\n";
 cout << "Please enter your National ID (14 digits): ";
 cin >> person.id;
cout <<"\n";
 // call function that checks the id
  while(!isValidNationalID(person.id)){
        cout << "Invalid National ID. It must be exactly 14 digits ,Try again :\n";
 
       // clear the previous input
        cin.clear();
 
      // discard the previous input
       cin.ignore(100000,'\n');
       cin>>person.id;
 }

 cout<<"Enter the number of rooms : ";
 cin>>person.numberrooms ;
 cout << "\n";
 
 // check if Number of guests valid
  do{
      
 cout<<"Enter number of guests : ";
 cin>>person.guests ; 
 cout<< "\n";
 
     if (person.guests < 1){
          cout<<" number of guests must be at least one guest . Try again.\n";
              }
            }
            while(person.guests < 1);
                    
 // check if Number of Nights valid
  do{
      
 cout << "Enter Number of Nights Stayed: ";
 cin >> person.nightstayed ;
 cout << "\n";
     if (person.nightstayed< 1){
          cout<<" number of Nights must be at least one night . Try again.\n";
              }
            }
            
            while(person.nightstayed<1);
            
            
 cout<<"Enter check in date (DD/MM/YYYY) : ";
 cin>>person.Date_check_in;
 cout<<"\nEnter check out date (DD/MM/YYYY) : ";
 cin>>person.Date_check_out;

       // book the room
       for(int i=0;i<person.numberrooms;i++){
           int numberroom ;                    // number of room.  عدد الغرف
         bool validroom=true,RoomBooked;

         do{
              cout<<"Enter room Number "<<i+1<<" : ";
              cin>>numberroom;                    // input the room number he wants.  رقم الغرفة
              cout<<"\n";
              validroom = false;
              RoomBooked=false;

           for(int j=0;j<total_number_room;j++){
               if(roomindex[j]==numberroom){
                   validroom=true;
           
               if(booked[j]==false){
                   booked[j]=true;

                   cout<< "Room "<<numberroom<<" Has been successfully booked.\n";

                  //calculate the total cost of the rooms
                   totalroomcost += person.nightstayed *room_price[j];
               }
           
               else {
                   cout<<"Room "<<numberroom<<" is already booked\n";
                   RoomBooked=true;
               }
               break;
            }
          }
          
          if(!validroom){
               cout<<"Invalid Number. try again\n";
         }
         }
       
       while(!validroom||RoomBooked);
       }
    }
    
    // to allow customer to cancel booking
    void cancelbooking(){
        int Roomnumber;
        cout<<"Enter the Number of room to cancel book : ";
        cin >> Roomnumber;
       cout << "\n";
       
        bool roomexist=false;
       
       // loop to check if the room is exist and booked or not
        for(int i=0;i<total_number_room;i++){
           
            if(roomindex[i] == Roomnumber){
                roomexist=true;
              
              // if room is booked cancel booking
                if(booked[i]==true){
                    booked[i]=false;
                    cout<<"Room number " << Roomnumber << " has been canceled successfully \n";
                }
                
                else{
                    
                    cout<< "Room number is not already booked\n ";
                }
                
                break;
            }
        }
         if(!roomexist){
            cout<<"room number is not exist , try again \n";
        }
    }
    
    //function make customer Select
   void selection (){
       int choice;

       cout<<"1- display Available Rooms \n";
       cout<<"2- book room \n";
       cout<<"3- cancel the book \n";
       cout<<"Enter your choice :";
       cin>>choice;
       cout<<"\n";
       switch (choice){
   
           case '1' :
   
                 Available_Rooms();
                 cout<<"\n";
                 break;
   
             case '2' :
   
                 BookRoom();
                 cout<<"\n";   
                 break;
  
            case '3' :
                 
                 cancelbooking();
                  cout<<"\n";
                  break;
        
            default :
   
                  cout<<"please, Enter A vaild choice\n";
       }
       }

// shows the features of the system
void featuresMenu(){
cout<<"Features:\n";
cout<<"\n1)Rooms.\n";
cout<<"2)Food and Beverage.\n";
cout<<"3)Bill and Payment.\n";
}

int totalfbcost=0;     //making the total of food and beverage global to be accessible by bill and payment function.

// food and beverages function
void Foodbeverage(){
       system("color 70");
      string foodnumber;
      float price,quantity;
       char choice;

cout<<"=================\n";
cout<<"|               |\n";
cout<<"|  OUR MENU :)  |\n";
cout<<"|               |\n";
cout<<"=================\n";

//stock of food and beverage items

int coffeestock = 20,teastock = 15, waterstock = 20, frenshtoaststock = 10,omeletstock = 12, steakstock = 10, pizzastock = 10,cheesecakestock = 14, browniestock = 12;

//menu elements

string food[13]={"Beverage:\n","1)Black Coffee  10$","2)Tea  6$","3)Water  3$\n",
"Breakfast:\n","5)Frensh Toast  15$","6)Omelet  12$\n ",
"Launch:\n","8)Steak   30$","9)Pizza  25$\n","Desserts:\n",
"11)cheese cake  12$","12)Brownie  13$\n"};

// Display the menu
for(int i=0;i<13;i++){
        cout<< food[i]<<"\n";
      }

      // loop allow ordering multiple items
      do {
            cout<<"Enter The Food number : ";
            cin>>foodnumber;
              cin.ignore(); // clear the buffer
           // checks the foodnumber that the user enter

while ( foodnumber != "1" && foodnumber != "2" && foodnumber !="3" && foodnumber !="5" && foodnumber !="6" && foodnumber !="8" && foodnumber !="9"&& foodnumber!="11"&& foodnumber!="12" ){
                  cout<<"please enter a valid number :";
                    cin>>foodnumber;
             cin.ignore(); // clear the buffer
            }

            cout<<"Enter The quantity :";
            cin>>quantity ; 
          cin.ignore(); // clear the buffer
             // checks the quantity that the user enter

             if( quantity <=0 || (quantity >= 65 && quantity <= 90)|| (quantity >= 97 && quantity <= 122) || (int)quantity != quantity ){
                  cout<<"\nplease enter a specified quantity :";
                  cin>>quantity ; 
                   cin.ignore(); // clear the buffer
             }

      //determine the price
      price = 0;
       switch(stoi(foodnumber)){

    case 1://blackcoffee

           if(quantity > coffeestock){
            cout<<"There is no enough stock of Blackcoffee\n";
            continue;
           }

      price = 10;
      coffeestock  -= quantity;
      break;

     case 2: //tea

            if(quantity > teastock) {
            cout<<"There is no enough stock of Tea\n";
            continue;
           }

       price = 6;
       teastock -= quantity;
       break;

     case 3: //water

         if(quantity > waterstock){
            cout<<"There is no enough stock of water\n";
            continue;
           }
      price = 3;
      waterstock -= quantity;
      break;

     case 5: // frenshtoast

           if(quantity > frenshtoaststock){
            cout<<"There is no enough stock of Frenshtoast\n";
            continue;
           }

       price = 15;
       frenshtoaststock -= quantity;
       break;

       case 6: //omelet

             if(quantity > omeletstock){
            cout<<"There is no enough stock of Omelet\n";
            continue;
           }

         price = 12;
         omeletstock -= quantity;
         break;

       case 8: //steak

             if(quantity > steakstock){
            cout<<"There is no enough stock of Steak\n";
            continue;
           }

            price = 30;
            steakstock -= quantity;
            break;

       case 9: //pizza

             if(quantity > pizzastock){
            cout<<"There is no enough stock of Pizza\n";
            continue;
           }

            price = 25;
            pizzastock -= quantity;
            break;

       case 11: // cheese cake

             if(quantity > cheesecakestock){
            cout<<"There is no enough stock of Cheese Cake\n";
            continue;
           }

             price = 12;
             cheesecakestock -= quantity;
             break;

       case 12:   //brownie

             if(quantity > browniestock){
            cout<<"There is no enough stock of Brownies\n";
            continue;
           }

        price = 13;
        browniestock -= quantity;
        break;

      
      }

      //calculate the total
      totalfbcost += price * quantity;

      cout << "Do you want to order another item? (y/n): ";
        cin >> choice;
      }

      while(choice == 'y' || choice == 'Y');
}

//function that Display the Bill and payment
void billpayment(){
      system("color 0A");
    // Calculating final total
    int totalamount = totalroomcost + totalfbcost;

    // Printing the invoice

    cout << "\n========================================\n";
    cout << "            HOTEL INVOICE\n";
    cout << "========================================\n";
    cout << "Customer Name: " << person.name << "\n";
    cout << "Nights Stayed: " << person.nightstayed << "\n";
    cout << "Total Room Cost: $" << totalroomcost<< "\n";
    cout << "----------------------------------------\n";
    cout << "Total Food & Drinks Cost: $" << totalfbcost<< "\n";
    cout << "----------------------------------------\n";
    cout << "Final Total Amount: $" << totalamount << "\n";
    cout << "========================================\n";
    cout << "Thank you for staying with us!\n";
}

int main(){

    Draw();                // prints the welcome screem

    featuresMenu();        //prints the features to make the user choose

    char featurenumber ;   //input the number of Feature

    char answer;

 //loop for selecting multiple features

 do{
      cout<<"Choose the Feature number : ";
     cin>>featurenumber;
     cout <<"\n";
         // check the inputed feature number
        while (cin.fail()||featurenumber<'1' || featurenumber>'3'){
            cin.clear();
        cin.ignore(1000, '\n');

            cout<<"Please enter a valid number !:";
            cin>>featurenumber;
      }

     
     switch(featurenumber){
         
       case '1':   // Rooms

             selection();
                break;

       case '2':   //food and beverages

             Foodbeverage();
             break;

       case '3':      // bill and payment
            
            billpayment();
            break;

       default :
            
            cout<<"Please Enter a Valid Feature Number!\n";
            break;
         }
      cout<<"Do You Want To Select another Feature (y/n) :";
      cin>>answer;
      cout<<"\n";
 }

 while (answer == 'y' || answer == 'Y');

 int rateing , recomendation;       // to take the rate of the customer visit

 cout<<"Can you please give a rating for us out of 5 :";
 cin>>person.rateing;
cout <<"\n";

 // Clear the newline left by cin >> person.rateing
cin.ignore();

 if(person.rateing <= 3){
      cout<<"please give us your recomendations yo enhance your visit the next time : ";

      getline(cin,person.recomendation);
      cout <<"\n";
 }
 
 cout<<"Thanks For Your Visit .";

return 0; 

} 

                             // الحمد لله الذي بنعمته تتم الصالحات //
                             
