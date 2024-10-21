#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <cmath>
#include <cctype>
	
using namespace std;
class billNode{ 
public: 
 int roomNum;
float price; 
string ic; 
string name; 
double total;
 string DateIn;
 string DateOut;
int days;
billNode *next;
};
class billQueue{ 
billNode *frontPtr, *backPtr; 
public:
billQueue(){
backPtr=NULL; 
frontPtr=NULL;
}
~billQueue(){
billNode *temp =frontPtr;
while(temp){
        frontPtr=temp->next;
        delete temp;
        temp=frontPtr;
}
}
bool isEmpty(){
        return (backPtr==NULL&&frontPtr==NULL);
}
// Implementation of queue
void enqueue(int rn, float p, string ic_, string n, string in, string out, int d){
    billNode * temp=new billNode;
    if(backPtr==NULL){
        temp->next=NULL;
        temp->roomNum=rn; 
        temp->price=p;
        temp->ic=ic_;
        temp->name=n;
        temp->DateIn=in;
        temp->DateOut=out;
        temp->days=d;
        backPtr=frontPtr=temp;
 }    
 else{
        backPtr->next=temp;
        temp->roomNum=rn;
        temp->price=p;
        temp->ic=ic_;
        temp->name=n;
        temp->DateIn=in;
        temp->DateOut=out;
        temp->days=d;
        temp->next=NULL;
        backPtr=temp;
 }
}
void displayInvoice(billNode * temp){
        if(temp->days<=1){
                temp->days==1;
        }
        temp->total=temp->price*1.06*(temp->days*1.0);
        cout << "\n===========BOOKING NEED TO CONFIRM==============="<<endl;
        cout << "\n CUSTOMER NAME\t : "<< temp->name<<endl;
        cout << "\n ROOM NUMBER \t: "<< temp->roomNum<<endl;
        cout << "\n CHECK IN DATE:\t"<< temp->DateIn<<endl;
        cout << "\n CHECK OUT DATE:\t"<< temp->DateOut<<endl;
        cout << "\n DAYS STAYED:\t"<< temp->days<<endl;
        cout << "\n TOTAL AMOUNT:\t"<< temp->total<<endl;
        cout << "\nCUSTOMER IC:\t"<<temp->ic<<endl;
}
// Implimentation of queue
string dequeue(){
        billNode * temp = new billNode;
        temp= frontPtr;
        if (frontPtr==NULL){
                cout << "No pending booking need to be confirmed "<<endl;
                return "NULL";
        }
        else if(temp->next!=NULL){
                int choice;
                displayInvoice(temp);
                do{
                        cout <<"\n Do you want to confirm your booking? (0-Pending, 1-Confirmed, 2-Cancelled):"<<endl;
                        cin >> choice;
                        if (choice==1){
                                temp=temp->next;
                                frontPtr=temp;
                                return "Booking Confirmed";
                        }
                        else if (choice==0){
                                temp= temp-> next;
                                frontPtr=temp;
                                 return "Booking Pending ";
                        }
                        else if(choice ==2){
                           temp=temp->next;
                                frontPtr=temp;
                                return "Booking Cancelled";     
                        }
                
                }while(choice<0&&choice>2);
        }
}
billNode *getFrontRN(){
        billNode * t =new billNode;
        if (frontPtr!=NULL){
                t=frontPtr;
        }
        return t;
}
};
class custNode{
        public:
        string custName;
         string custPhone;
          string ic;
           string DateIn;
            string DateOut;
            int roomNum;
            custNode *next;

};
class customer{
        custNode *head;
        public:
        customer()
        {head=NULL;}
void sortedCustIn(string n, string p, string ic,  string in,  string out,int rn){
        int currIndex=0;
        custNode *currNode=head;
        custNode *prevNode=NULL;
        while(currNode&& n>currNode->custName){
                prevNode=currNode;
                currNode=currNode->next;
                currIndex++;
        }
        custNode* newNode=new custNode();
        newNode->custName=n;
        newNode->custPhone=p;
        newNode->ic=ic;
        newNode->DateIn=in;
        newNode->DateOut=out;
        newNode->roomNum=rn;
        if(currIndex==0){
                newNode->next=head;
                head=newNode;
                }else{
                        newNode->next=prevNode->next;
                        prevNode->next=newNode;
        }
       } 
       void deleteCust( string ic, int rn){
        custNode *currNode=head;
        custNode *prevNode=NULL;
        int currIndex=1;
        string IC= currNode->ic.substr(0,12);
        int y=atoi(IC.c_str());
        int x=atoi(ic.c_str());
        while((currNode&&x!=y)||(currNode&&currNode->roomNum!=rn)){
                prevNode=currNode;
                currNode=currNode->next;
                currIndex++;
        }
        if (x==y){
                if(currNode){
                        if(prevNode){
                                prevNode->next=currNode->next;
                                delete currNode;
                        }
                        else {
                                head=currNode->next;
                                delete currNode;
                        }
                }
                 cout << "ROOM BOOKED("<<rn<<") UNDER CUSTOMER WITH IC "<<ic<<" HAS BEEN DELETED"<<endl;
        }
       else{
        cout << "BOOKING RECORD OF"<<rn<<" UNDER CUSTOMER WITH IC "<<ic<<" I CAN NOT FOUND" <<endl; 
       }

       }
       bool findCust(string _ic){
        custNode *currNode = head;
        int currIndex=1;
        string IC= currNode->ic.substr(0,13);
        int y=atoi(IC.c_str());
        int x=atoi(_ic.c_str());
        if (x==y){
                return true;
        }
        else 
        return false;
       }
       void displayCustRoom(){
        int num=0;
        custNode* currNode = head;
        cout<<"|-------------------BOOKING IN HOTEL--------------------------|"<<endl;
        cout<<left<<setw(40)<<"NAME"<<setw(11)<<"ROOM"<<setw(15)<<"PHONE"<<setw(20)<< "IC"<<setw(12)<<"DATE IN"<< setw(12)<<"DATE OUT"<<endl;
        while(currNode != NULL){
               cout <<left<<setw(40)<<currNode->custName<<setw(11)<<currNode->roomNum<<setw(15)<<currNode->custPhone<<setw(20)<<currNode->ic<<setw(12)<<currNode->DateIn<<setw(12)<<currNode->DateOut<<endl;
            currNode= currNode->next;
                num++;
        }
        cout<<"\n NUMBER OF ROOM IN HOTEL :"<< num<<endl;
       }
};
class roomNode{
        public:
        int floorNo;
        int roomNum;
        int roomType;
        float price;
        int status;
        roomNode *next;
        roomNode *prev;
};
string rt(int rt){
        if(rt==1){
                return "SINGLE";
        }
        else if(rt==2){
                return "Double";
        }
        else if(rt==3){
                return "FAMILY";
        }
        else if (rt==4){
                return "PREMIUM";
        }
        else 
        return "DEFAULT";
}
string status(int status){
        if( status==1){
                return "BOOKED CONFIRMED";
        }
       else if(status==2){
          return "AVAILABLE";
        }
        else {
                return "DEFAULT";
        }
}
class room{
private:
roomNode *head;
public:
room(){
        head=NULL;
}
void insertSortedRoom( int roomNum){
        
        int currIndex=0;
        roomNode *currNode=head;
        roomNode *prevNode=NULL;
        while(currNode&&roomNum>currNode->roomNum){
            prevNode=currNode;
            currNode=currNode->next;
            currIndex++;
        }
        roomNode *newNode=new roomNode;
        newNode->roomNum=roomNum;
        newNode->floorNo=roomNum%1000;
        newNode->roomType=(roomNum-(roomNum%1000*1000))/100;
        newNode->price=setprice(newNode);
        newNode->status=0;
        if(currIndex==0){
                newNode->next=head;
                head=newNode;
        }
        else{
                newNode->next=prevNode->next;
                prevNode->next=newNode;
        }
}
float setprice(roomNode *n){
        float p=0;
        roomNode *newNode=new roomNode;
        newNode =n;
        if(newNode->roomType==1){
                p+=80.00;
        }
        else if(newNode ->roomType==2){
                p+=120.00;
        }
        else if(newNode ->roomType==3){
                p+=150.00;
        }
        else if(newNode ->roomType==4){
                p+=200.00;
        }
        else {
                p=0.00;
        }
        p+=(newNode->floorNo*10.00);
        return p;
}
void deleteRoom(int rn){
        roomNode *prevNode=NULL;
        roomNode *currNode=head;
        int currIndex=1;
        while(currNode&&currNode->roomNum!=rn){
                prevNode=currNode;
                currNode=currNode->next;
                currIndex++;
        }
        if( currNode){
                if(prevNode){
                        prevNode->next=currNode->next;
                        delete currNode;
                }
                else {
                        head=currNode->next;
                        delete currNode;
                }
                cout << "YOU SUCCESSFULLY DELETE THE ROOM WITH NUMBER :"<<rn<<endl;
        }
        else {
                cout << "ROOM NUMBER ("<<rn<<") DOES NOT EXIST "<<endl;
        }
}
bool bookRoom(int rn){
        roomNode *newNode=new roomNode;
        newNode=findRoom(rn);
        if(!newNode){
                cout << "ROOM NUMBER "<<rn<<"CAN NOT BE FOUND\n"<<endl;
                return false;
        }
        else {
                if( newNode->status==0){
                        newNode->status=1;
                         cout << "ROOM NUMBER "<<rn<<"IS SUCCESSFULLY BOOKED\n"<<endl;
                return true;
                }
                else{
                         cout << "ROOM NUMBER "<<rn<<"IS NOT AVAILABLE\n"<<endl;
                return false;
                }
        }
}
bool cancelRoom(int rn){
        roomNode *newNode=new roomNode;
        newNode=findRoom(rn);
        if(!newNode){
                cout << "ROOM NUMBER "<<rn<<"CAN NOT BE FOUND\n"<<endl;
                return false;
        }
        else {
                if( newNode->status==1){
                        newNode->status=0;
                         cout << "ROOM NUMBER "<<rn<<"IS SUCCESSFULLY CANCELLED\n"<<endl;
                return true;
                }
                else{
                         cout << "BOOKING ROOM NUMBER "<<rn<<"CAN NOT BE FOUND\n"<<endl;
                         cout<< "UNABLE TO MAKE CANCELLATION"<<endl;
                return false;
                }
        }
}
// };


bool findBookRoom(int rn){
    roomNode*newNode=new roomNode;
    newNode=findRoom(rn);
    if(!newNode){
        return false;
    }
    else{
        if(newNode->status==1){
            return true;
        }
        else{
            return false;
        }
    }
}
roomNode* findRoom(int rn){
    roomNode *currNode=head;
    int currIndex=1;
    while(currNode&&currNode->roomNum!=rn){
        currIndex++;
    }
    if(currNode)
        return currNode;
    else
        return 0;
}
void displayRoom(){
    int num=0;
    roomNode*currNode=head;
    cout<<"===========ROOM IN HOTEL=========="<<endl;
    cout<<"----------------------------------"<<endl;
    cout<<"FLOOR\tROOM NO.\tROOM TYPE\tPRICE\tSTATUS"<<endl;

    while(currNode!=NULL){
        cout<<currNode->floorNo<<"\t"<<currNode->roomNum<<"\t\t"<<rt(currNode->roomType)<<"\t\t"<<currNode->price<<"\t"<<status(currNode->status)<<"\t"<<endl;
     currNode=currNode->next;
     num++;
    }
    cout<<"\nNUMBER OF ROOM IN HOTEL:"<<num<<endl<<endl<<endl;
 }
};
int getDays(string date) {
    int year=atoi(date.substr(0,4).c_str());
    int month= atoi(date.substr(4,2).c_str());
    int day= atoi(date.substr(6,2).c_str());
    int ans=0;
    for (int i=1900;i<year;++i){
        if (((year%4==0)&&(year%100!=0))|| (year%400==0)) {
            ans+=366;
        } else {
            ans+=365;
        }
    }
    for (int i=1; i<month;i++) {
        switch(i){
            case 1: ans+=31; break;
            case 2: ans+=(((year%4==0)&&(year%100!=0))||(year%400==0))?29:28; break;
            case 3: ans+= 31; break;
            case 4: ans+= 30; break;
            case 5: ans+= 31; break;
            case 6: ans+= 30; break;
            case 7: ans+= 31; break;
            case 8: ans+= 31; break;
            case 9: ans+= 30; break;
            case 10:ans+= 31; break;
            case 11:ans+= 30; break;
            case 12:ans+= 31; break;
        }
    }
    return ans+=day-1;
}
int daysBetweenDates(string date1, string date2) {
    return abs(getDays(date1)-getDays(date2));
}

int main(){
        //CREATE HOTEL ROOM
    room h;
    customer cn;
    billQueue bq;
    int choice;
    //ADD DEFAULT ROOM
    int
    defaultroom[]={1101,1202,1303,1102,1103,1104,2201,2202,2203,3301,3302,3303,3303,4401,4401};
    for (int x=0;x<15;x++)
    {
       h.insertSortedRoom(defaultroom[x]);
    }
    do{
        // system("CLS");
        cout<<"==========    HOTEL BOOKING SYSTEM     =========="<<endl;
        cout<<"\t\t\tLOGIN AS"<<endl;
        cout<<"\t\t\t1. ADMIN\n\t\t\t2. CUSTOMER \n\t\t\t3. EXIT\n"<<endl;
        cout<<"CHOICE : ";
        cin>>choice;
        switch(choice){
            case 1:{
                int ch1;
                int rn;
                int cont1;
                do{
                    system("CLS");
                    cout<<"========== ADMIN MENU =========="<<endl;
                    cout<<"\t1. ADD ROOM\n\t2. DELETE ROOM\n\t3. DISPLAY ROOM\n\t4. CHANGE PRICE\n\t5. CHECK CUSTOMER BOOKING LIST\n\t6. REVIEW AND CONFIRM PENDING BOOKING\n\t7. BACK TO MAIN MENU\n"<<endl;
                    cout<<"CHOICE : ";
                    cin>>ch1;
                    switch(ch1){
                        case 1:
                        cont1=1;
                            cout<<"\nENTER THE ROOM NUMBER YOU WANT TO ADD : ";
                            cin>>rn;
                        //     if(!h.findRoom(rn)){
                                h.insertSortedRoom(rn);
                                cout<<"YOUR SUCCESSFULLY ADD ROOM NUMBER(" <<rn<<") TO THE LIST"<<endl;
                        //        }
                        //        else{
                        //             cout<<"ROOM NUMBERED "<<rn<<" EXISTED. ENTER OTHER ROOM NUMBER." <<endl;
                        //             cout<<"DO YOU WANT TO CONTINUE TO ADD MORE ROOM (1-YES, 0-NO):";
                        //             cin>>cont1;
                        //         }
                        break;
                        case 2:
                        cont1=1;
                        do{
                            cout<<"\nENTER THE ROOM NUMBER YOU WANT TO DELETE :";
                            cin>>rn;
                            if(h.findRoom(rn)){
                                h.deleteRoom(rn);
                            }
                            else{
                                cout<<"ROOM CANNOT BE FOUND! ENTER OTHER ROOM NUMBER."<<endl;
                            }
                            cout<<"DO YOU WANT TO CONTINUE TO DELETE MORE ROOM(1-YES, 0-NO):";
                            cin>>cont1;
                         }while(cont1!=0);
                            break;
                            case 3:
                            h.displayRoom();
                            break;
                            case 4:
                            cont1=1;
                            do{
                                cout<<"\nENTER THE ROOM  NUMBER THAT YOU WANT CHANGE PRICE: "<<endl;
                                cout<<"ROOM NUMBER        :";
                                cin>>rn;
                                if(h.findRoom(rn)){
                                    float p;
                                    cout<<"CHANGE TO PRICE RM :";
                                    cin>>p;
                                    roomNode *newNode=h.findRoom(rn);
                                    newNode->price=p;
                                    cout<<"YOU SUCCESSFULLY CHANGE THE PRICE OF ROOM "<<rn<< "TO PRICE RM"<<p<<endl<<endl;
                                }
                                else{
                                    cout<<"ROOM NUMBER ("<<rn<<") CANNOT BE FOUND. ENTER OTHER ROOM NUMBER."<<endl<<endl;
                                }
                                cout<<"DO YOU WANT TO CONTINUE TO CHANGE PRICE OF OTHER ROOMS (1-YES,0-NO):";
                                cin>>cont1;
                               }while(cont1!=0);
                               break;
                               case 5:
                               cn.displayCustRoom();
                               break;
                               case 6:
                               cont1=1;
                               cout<<"\n\n======    START TO REVIEW BOOKING INFORMATION ======\n";
                               do{
                                billNode* rno=new billNode;
                                rno=bq.getFrontRN();
                                string con=bq.dequeue();
                                roomNode *t=new roomNode;
                                t=h.findRoom(rno->roomNum);
                                if(con=="BOOKED & CONFIRMED"){
                                    t->status=0;
                                    break;
                                }else if(con=="BOOKED & PENDING"){
                                    t->status=1;
                                    bq.enqueue(rno->roomNum,rno->price,rno->ic,rno->name,rno->DateIn,rno->DateOut,rno->days);
                                    break;
                                }
                                else{}
                                cout<<"DO YOU WANT TO CONTINUE TO REVIEW(1-YES,0-NO):";
                                cin>>cont1;
                               } while(cont1!=0);
                               break;
                               case 7:
                                      break;
                               default:
                               cout<<"INVALID CHOICE."<<endl;
                               break;
                               }
                               system("pause");
                              getch();
                }while(ch1!=7);
                break;
                }  
                           //     cas1 end 
                      break;

             case 2:{
            int ch2;
            int rn,rn2;
            int cont2;
                do{
                      system("CLS");
                      cout<<"========COUSTOMER MENUE========"<<endl;
                      cout<<"\t1.DISPLAY ROOM\n\t2.BOOK A ROOM\n\t3.CANCEL ROOM\n\t4.BACK TO MAIN MENUE"<<endl;
                      cout<<"CHOICE :";
                      cin>>ch2;
                      switch(ch2){
                      case 1:
                           h.displayRoom();
                           break;
                      case 2:
                           cont2=1;
                           do{
                           cout<<"\nENTER THE ROOM NUMBER YOU WANT TO BOOK:";
                           cin>>rn;
                           bool book=h.bookRoom(rn);
                           if(book){
                           string n,p,ic,in,out;
                           int din,min,yin,dout,mout,yout;
                           char s;
                           cout<<"=======YOUR PERSONAL DETAILS========"<<endl;
                           cout<<"ENTER YOUR NAME :";
                           cin.ignore();
                           getline(cin,n);
                           cout<<"ENTER YOUR PHONE NO :";
                           getline(cin,p);
                           cout<<"ENTER YOUR IC(xxxxxx-xx-xxxx):";
                           getline(cin,ic);
                           cout<<"DATE IN (YYYYMMDD) :";
                           getline(cin,out);
                           int days=daysBetweenDates(in,out);
                           cn.sortedCustIn(n,p,ic,in,out,rn);
                           cout<<"\n-----------------------\n";
                           cout<<"\nPLEASE PROCEED TO BILL AT COUNTER\n";
                           cout<<"\n-----------------------\n";
                           roomNode*t=new roomNode;
                           t=h.findRoom(rn);
                           bq.enqueue(rn,t->price,ic,n,in,out,days);
                                }
                            cout<<"DO YOU WANT TO CONTINUE TO BOOK ROOM(1-YES,0-N0):";
                              cin>>cont2;
                        } while(cont2!=0);
                          break;  
                      
                          case 3:   
                          cont2=1;
                               do{
                                    string ic2;
                                    int rn2=0;
                                    cout<<"\nENTER THE ROOM NUMBER YOU WANT TO CANCEL :";
                                    cin>>rn2;
                                    cout<<"ENTER YOUR IC TO MAKE CANCELLATION(xxxxxx-xx-xxxx):";
                                    cin.ignore();
                                    getline(cin,ic2);
                                    bool targetRoom=h.findBookRoom(rn2);
                                    if(targetRoom){
                                    bool targetCust=cn.findCust(ic2);
                                    if(targetCust){
                                    h.cancelRoom(rn2);
                                    cn.deleteCust(ic2,rn2);
                                    }
                                    else{
                                         cout<<"\nRECORD CANNOT BE FOUND\nUNABLE TO MAKE CANCELLATION"<<endl;
                                        }
                                                }      
                                     else{
                                         cout<<"RECORD CANNOT BE FOUND\nUNABLE TO MAKE CANCELLATION"<<endl;
                                        }
                                        cout<<"DO YOU WANT TO CONTINUE TO CANCEL ROOM (1-YES,0-NO):";
                                        cin>>cont2;
                                } while(cont2!=0);
                                break;
                                case 4:
                                  break;
                                  default:
                                  cout<<"INVALID CHOICE."<<endl;
                                  break;
                      }
                         system("pause");
                         getch();
                }while(ch2!=4);
                        break;
// cas 2 end
                case 3:
                cout<<"THANK YOU! BYE BYE."<<endl;
               exit(0);
               default:
               cout<<"INVALID CHOICE."<<endl;
               break;
}
//  switch ends       // 
 getch();      
}
return 0;
}while(choice!=3);
} 