#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
using namespace std;

class Bill{
    private:
        string Item;
        int Rate,Quantity;
    public:
    Bill():Item(""),Rate(0),Quantity(0){} 
   
   void setItem(string item){
    Item=item;
   }
   void setRate(int rate){
    Rate=rate;
   }
   void setQuantity(int quantity){
    Quantity=quantity;
   }
   string getItem(){
    return Item;
   }
   int getRate(){
    return Rate;
   }
   int getQuantity(){
    return Quantity;
   }
};
void addItem(Bill b){
    bool close=false;
    while(!close){
        int choice;
        cout<<"\t1.Add"<<endl;
        cout<<"\t2.close"<<endl;
        cout<<"\t.Enter Choice"<<endl;
        cin>>choice;
        if(choice==1){
            system("cls");
            string item;
            int rate,quantity;
        cout<<"\tEnter Item name:";
        cin>>item;
        b.setItem(item);
        cout<<"\tEnter Rate";
        cin>>rate;
        b.setRate(rate);
        cout<<"\tEnter Quantity";
        cin>>quantity;
        b.setQuantity(quantity);

        ofstream out("E:/projects/Bill.txt",ios::app);
        if(!out){
            cout<<"\tError:File Can't Open"<<endl;
        }else{
         out<<"\t"<<b.getItem()<<" : "<<b.getRate()<<" : "<<b.getQuantity()<<endl;
        }
        out.close();
        cout<<"\tItem added Successfully"<<endl;
        Sleep(3000);
        }
        else if(choice==2){
            system("cls");
            close=true;
            cout<<"\tBack to Main Menu"<<endl;
            Sleep(3000);

        }

    }

}
void PrintBill(){
    system("cls");
    int count=0;
    bool close = false;
    while(!close){
    system("cls");
    int choice;
      cout<<"\t1.Add Bill"<<endl;
        cout<<"\t2.Close Session"<<endl;
        cout<<"\tEnter Choice"<<endl;
        cin>>choice;
        if(choice==1){
            string item;
            int quantity;
            cout<<"\tEnter Item:";
            cin>>item;
            cout<<"\tEnter Quantity:";
            cin>>quantity;
       ifstream in("E:/projects/Bill.txt");
       ofstream out("E:/Bill Temp.txt");

       string line;
       bool found=false;
       while(getline(in,line)){
         stringstream ss;
         ss<<line;
         string itemname;
         int itemrate,itemquantity;
         char delimiter;
         ss>>itemname>>delimiter>>itemrate>>delimiter>>itemquantity;
       if(item==itemname){
        found=true;
        if(quantity<=itemquantity){
           int amount = itemrate * quantity;
           cout<<"\t Item | Rate | Quantity | Amount "<<endl;
           cout<<"\t"<<itemname<<" | "<<itemrate<<" | "<<quantity<<" | "<<amount<<endl;
           int newQuant=itemquantity - quantity;
           itemquantity=newQuant;
           count+=amount;
           out<<"\t"<<itemname<<" : "<<itemrate<<" : "<<itemquantity<<endl<<endl;;

        }else{
            //if quantity less than
            cout<<"\tSorry"<<item<<" Ended"<<endl;
        }
       }else{
           out<<line<<endl;
       }
        }
        if(!found){
            cout<<"\tSorry Item Not Found"<<endl;
        }
        out.close();
        in.close();
        remove("E:/projects/Bill.txt");
        rename("E:/Bill Temp.txt","E:/projects/Bill.txt");
    }

    else if(choice==2){
        close=true;
        cout<<"\tCounting Total Bill"<<endl;

    }
    Sleep(3000);
}
system("cls");
cout<<endl<<endl;
cout<<"\t Total Bill ------------:"<<count<<endl<<endl;
cout<<"\t Thanks for Shopping"<<endl;
Sleep(5000);
}
int main(){
    Bill b;
    bool exit = false;
    while(!exit){
        system("cls"); //hide previouse output ans shows current output
        int val;
        cout<<"\tWelcome To SuperMarket Billing System"<<endl;
        cout<<"\t**************************"<<endl;
        cout<<"\t\t1.Add Item"<<endl;
        cout<<"\t\t2.Print Bill"<<endl;
        cout<<"\t\t3.Exit"<<endl;
        cout<<"\tEnter your choice: ";
        cin>>val;
    
    if(val==1){
        system("cls");
        addItem(b);
        Sleep(3000);

    }else if(val==2){
      
      PrintBill();
     
    }
    else if(val==3){
      system("cls");
      exit=true;
      cout<<"tGood Luck!"<<endl;
      Sleep(3000);
    }
    }

    }

