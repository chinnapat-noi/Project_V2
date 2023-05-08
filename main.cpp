#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <typeinfo>
using namespace std;

#define DEV_MODE false // default is false
#define DWORD "NO" // defalut word in file: "NO"

bool dev = DEV_MODE;
#include "NodeLL.cpp"
//#include "editData.cpp"

//Global var
////////////////////////////////////////
LLFood a; LLDrinks b; LLDai c;      LLSpec d;
food *f;  drinks *dr; dailyUse *da; specificPurpose *s;
	
long NodeID;
long LotID, LotNo;
string name;
string mfg, exp;
string updateTime;
string Usefor;
string caution;
string details;
double weightAll;
int quantityContainer, quantityEach;
double weightEach,volumeEach;
////////////////////////////////////////

void clear();
void add_stock();

//Son code
void delete_stock(int);
void show_delete_stock();
void edit_stock();

int s_choice = 0, add_choice,s_flag=0;
//NODE N; //LLNODE *n;
/////////////////////////////////////////////

int main(int argc, char **argv){
    clear();
    int i;
    /////////////////////////////////////////
    int num_lines = 1; // number of data lines 
    /////////////////////////////////////////
    if(dev){
    cout << "The argc is " << argc << endl;
    for(i = 0; i < argc ; i++){
        cout << "argv[" << i << "] is " << argv[i] << endl;
    }
}
    ///////////////////////////////////////////////////////
//    LLFood a; LLDrinks b; LLDai c;      LLSpec d;
//    food *f;  drinks *dr; dailyUse *da; specificPurpose *s;
    ///////////////////////////////////////////////////////
    
    ///////////////////////////////////////////////////////
    ifstream RF,RD,RDA,RS;//read text file readfood readdrink readdaily readspecific
    ofstream WF,WD,WDA,WS;//create text file
    ///////////////////////////////////////////////////////
    
    //

    //

    //////////////////////////create default///////////////
    RF.open("stock_food.txt");//ให้developerเก็บข้อมูล
    if(RF.fail())//if my text file doesn't exist, create one
    {
    WF.open("stock_food.txt");//create+name+open file
    WF.close();//fclose()
    }
    RF.close();//fclose()
    RD.open("stock_drink.txt");//ให้developerเก็บข้อมูล
    if(RD.fail())//if my text file doesn't exist, create one
    {
    WD.open("stock_drink.txt");//name+open file
    WD.close();//fclose()
    }
    RD.close();//fclose()
    RDA.open("stock_dailyuse.txt");//ให้developerเก็บข้อมูล
    if(RDA.fail())//if my text file doesn't exist, create one
    {
    WDA.open("stock_dailyuse.txt");//name+open file
    WDA.close();//fclose()
    }
    RDA.close();//fclose()
    RS.open("stock_specificuse.txt");//ให้developerเก็บข้อมูล
    if(RS.fail())//if my text file doesn't exist, create one
    {
    WS.open("stock_specificuse.txt");//name+open file
    WS.close();//fclose()
    }
    RS.close();//fclose()
    ///////////////////////////////////////////////////////
    
        /*long NodeID;
        long LotID, LotNo;
        string name;
        string mfg, exp;
        string updateTime;
        string Usefor;
        string caution;
        string details;
        double weightAll;
        int quantityContainer, quantityEach;
        double weightEach,volumeEach;*/
        
    int choice = 0;
    string extra;
    do{
        if(dev) cout << "[!] Developer Mode" << endl;
        cout << "Please select command" << endl;
        cout << "1 : Load data" << endl;
        cout << "2 : Showall" << endl;
		cout << "3 : Add Delete or Edit stock" << endl;
        cout << "9 : Exit" << endl;
        cout << "99 : Then type: \"dev\" to switch developer mode" << endl;
        cout << "Input number : "; cin >> choice;
        switch(choice){
            case 1 : //Load data
                clear();
                RF.open("stock_food.txt");
                while(RF>>name>>mfg>>exp>>LotNo>>weightAll>>quantityContainer>>quantityEach>>weightEach)/*collect food*/
                {
                    f = new food(name,mfg,exp,LotNo,weightAll,quantityContainer,quantityEach,weightEach);             a.add_node(f);
                }
                RF.close();
                RD.open("stock_drink.txt");
                while(RD>>name>>mfg>>exp>>LotNo>>weightAll>>quantityContainer>>quantityEach>>volumeEach)/*collect drink*/
                {
                    dr = new drinks(name,mfg,exp,LotNo,weightAll,quantityContainer,quantityEach,volumeEach);           b.add_node(dr);
                }  
                RD.close();
                RDA.open("stock_dailyuse.txt");
                while(RDA>>name>>mfg>>exp>>LotNo>>Usefor>>weightAll>>quantityContainer>>quantityEach>>caution)/*collect dailyUse*/
                {
                    da = new dailyUse(name,mfg,exp,LotNo,Usefor,weightAll,quantityContainer,quantityEach,caution);    c.add_node(da);
                }
                RDA.close();                  
                RS.open("stock_specificuse.txt");
                while(RS>>name>>mfg>>exp>>LotNo>>Usefor>>weightAll>>quantityContainer>>quantityEach>>details)/*collect specificPurpose*/
                {
                    s = new specificPurpose(name,mfg,exp,LotNo,Usefor,weightAll,quantityContainer,quantityEach,details);  d.add_node(s); 
                }
                RS.close();
                cout << "[!] Data has been loaded." << endl;
                break;
            case 2 : //Showall
                    clear();
                    a.show_all();
                    b.show_all();
                    c.show_all();
                    d.show_all();
                    cout << "" << endl;
                    break;
			case 3 :
					clear();
					do{
						s_flag = 0;
						cout<<"Please select command"<<endl;
						cout<<"1 : Add stock"<<endl;
						cout<<"2 : Delete stock"<<endl;
						cout<<"3 : Edit stock"<<endl;
						cout<<"4 : Back to main menu"<<endl;
						cout<<"Input number : "; cin >> s_choice;
						
						switch(s_choice){
							case 1 :
								add_stock();
								s_flag=1;
								//clear();
								break;
							case 2 :
								show_delete_stock();
								s_flag=1;
								clear();
								break;
							case 3 :
								edit_stock();
								s_flag=1;
								break;
							default :
								s_flag=1;
								clear();
						}
		
					}while(s_choice != 4 && s_flag == 0);
					break;
            case 99 :
                    cin >> extra;
                    if(extra == "dev") dev = !dev;
                    else choice = 0;
            default : clear();
        }
    }while(choice != 9);
	
    return 0;
}

void clear(){
    system("clear");
    //clear();
}

//Son code
void choice_insert_func(){
	switch(add_choice){
			case 1 :
				cout<<"Enter name : "; cin>>name;
				cout<<"Enter mfg : "; cin>>mfg;
				cout<<"Enter exp : "; cin>>exp;
				case1_LotNo:
				cout<<"Enter LotNo : "; cin>>LotNo;
				if(cin.fail()) {
					cin.clear();
					cin.ignore(50,'\n');
					goto case1_LotNo;
				}
				
				case1_weightAll:
				cout<<"Enter weightAll : "; cin>>weightAll;
				if(cin.fail()) {
					cin.clear();
					cin.ignore(50,'\n');
					goto case1_weightAll;
				}
				
				case1_quantityContainer:
				cout<<"Enter quantityContainer : "; cin>>quantityContainer;
				if(cin.fail()) {
					cin.clear();
					cin.ignore(50,'\n');
					goto case1_quantityContainer;
				}
				
				case1_quantityEach:
				cout<<"Enter quantityEach : "; cin>>quantityEach;
				if(cin.fail()) {
					cin.clear();
					cin.ignore(50,'\n');
					goto case1_quantityEach;
				}
				
				case1_weightEach:
				cout<<"Enter weightEach : "; cin>>weightEach;
				if(cin.fail()) {
					cin.clear();
					cin.ignore(50,'\n');
					goto case1_weightEach;
				}
				
				f = new food(name,mfg,exp,LotNo,weightAll,quantityContainer,quantityEach,weightEach);
				a.add_node(f);
				break;
				//return;
			case 2 :
				cout<<"Enter name : "; cin>>name;
				cout<<"Enter mfg : "; cin>>mfg;
				cout<<"Enter exp : "; cin>>exp;
				case2_LotNo:
				cout<<"Enter LotNo : "; cin>>LotNo;
				if(cin.fail()) {
					cin.clear();
					cin.ignore(50,'\n');
					goto case2_LotNo;
				}
				
				case2_weightAll:
				cout<<"Enter weightAll : "; cin>>weightAll;
				if(cin.fail()) {
					cin.clear();
					cin.ignore(50,'\n');
					goto case2_weightAll;
				}
				
				case2_quantityContainer:
				cout<<"Enter quantityContainer : "; cin>>quantityContainer;
				if(cin.fail()) {
					cin.clear();
					cin.ignore(50,'\n');
					goto case2_quantityContainer;
				}
				
				case2_quantityEach:
				cout<<"Enter quantityEach : "; cin>>quantityEach;
				if(cin.fail()) {
					cin.clear();
					cin.ignore(50,'\n');
					goto case2_quantityEach;
				}
				
				case2_volumeEach:
				cout<<"Enter volumeEach : "; cin>>volumeEach;
				if(cin.fail()) {
					cin.clear();
					cin.ignore(50,'\n');
					goto case2_volumeEach;
				}
				
				dr = new drinks(name,mfg,exp,LotNo,weightAll,quantityContainer,quantityEach,volumeEach);
				b.add_node(dr);
				break;
			case 3 :
				cout<<"Enter name : "; cin>>name;
				cout<<"Enter mfg : "; cin>>mfg;
				cout<<"Enter exp : "; cin>>exp;
				case3_LotNo:
				cout<<"Enter LotNo : "; cin>>LotNo;
				if(cin.fail()) {
					cin.clear();
					cin.ignore(50,'\n');
					goto case3_LotNo;
				}
				
				cout<<"Enter Usefor : "; cin>>Usefor;
				
				case3_weightAll:
				cout<<"Enter weightAll : "; cin>>weightAll;
				if(cin.fail()) {
					cin.clear();
					cin.ignore(50,'\n');
					goto case3_weightAll;
				}
				
				case3_quantityContainer:
				cout<<"Enter quantityContainer : "; cin>>quantityContainer;
				if(cin.fail()) {
					cin.clear();
					cin.ignore(50,'\n');
					goto case3_quantityContainer;
				}
				
				case3_quantityEach:
				cout<<"Enter quantityEach : "; cin>>quantityEach;
				if(cin.fail()) {
					cin.clear();
					cin.ignore(50,'\n');
					goto case3_quantityEach;
				}
				
				cout<<"Enter caution : "; cin>>caution;
				
				da = new dailyUse(name,mfg,exp,LotNo,Usefor,weightAll,quantityContainer,quantityEach,caution);
				c.add_node(da);
				break;
			case 4 :
				cout<<"Enter name : "; cin>>name;
				cout<<"Enter mfg : "; cin>>mfg;
				cout<<"Enter exp : "; cin>>exp;
				case4_LotNo:
				cout<<"Enter LotNo : "; cin>>LotNo;
				if(cin.fail()) {
					cin.clear();
					cin.ignore(50,'\n');
					goto case4_LotNo;
				}
				
				cout<<"Enter Usefor : "; cin>>Usefor;
				
				case4_weightAll:
				cout<<"Enter weightAll : "; cin>>weightAll;
				if(cin.fail()) {
					cin.clear();
					cin.ignore(50,'\n');
					goto case4_weightAll;
				}
				
				case4_quantityContainer:
				cout<<"Enter quantityContainer : "; cin>>quantityContainer;
				if(cin.fail()) {
					cin.clear();
					cin.ignore(50,'\n');
					goto case4_quantityContainer;
				}
				
				case4_quantityEach:
				cout<<"Enter quantityEach : "; cin>>quantityEach;
				if(cin.fail()) {
					cin.clear();
					cin.ignore(50,'\n');
					goto case4_quantityEach;
				}
				
				cout<<"Enter details : "; cin>>details;
				
				s = new specificPurpose(name,mfg,exp,LotNo,Usefor,weightAll,quantityContainer,quantityEach,details);
				d.add_node(s);
				break;
			default : clear();
		}
}

void add_stock(){
	clear();
	do{
		cout<<"Please select the category you wish to add"<<endl;
		cout<<"1 : Food"<<endl;
		cout<<"2 : Drink"<<endl;
		cout<<"3 : Daily use"<<endl;
		cout<<"4 : Appliance"<<endl;
		cout<<"5 : Back"<<endl;
		cin>>add_choice;
		
		choice_insert_func();
		
	}while(add_choice != 5);
}

void show_delete_stock(){
	clear();
	cout<<"Please select the category you wish to delete"<<endl;
	cout<<"1 : Food"<<endl;
	cout<<"2 : Drink"<<endl;
	cout<<"3 : Daily use"<<endl;
	cout<<"4 : Appliance"<<endl;
	cout<<"5 : Back"<<endl;
	do{
		cin>>add_choice;
		s_flag = 0;
		switch(add_choice){
			case 1 :
				a.show_all();
				s_flag = 1;
				break;
			case 2 :
				b.show_all();
				s_flag = 1;
				break;
			case 3 :
				c.show_all();
				s_flag = 1;
				break;
			case 4 :
				d.show_all();
				s_flag = 1;
				break;
			default :  clear();
		}
	}while(add_choice != 5 && s_flag == 0);
	//int inNodeID=0;
	if(add_choice !=5){
		do{
			cout<<"Please Enter NodeID you wish to delete"<<endl;
			cin>>NodeID;
			
			if(add_choice==1){
				if(a.check_NodeID(NodeID)) {
					a.delete_stock(NodeID);
					break;
				}
			}
			else if(add_choice==2){
				if(b.check_NodeID(NodeID)) {
					b.delete_stock(NodeID);
					break;
				}
			}
			else if(add_choice==3){
				if(c.check_NodeID(NodeID)) {
					c.delete_stock(NodeID);
					break;
				}
			}
			else{
				if(d.check_NodeID(NodeID)) {
					d.delete_stock(NodeID);
					break;
				}
			}
			
		}while(!a.check_NodeID(NodeID));
	}
}

void edit_stock(){
	clear();
	cout<<"Please select the category you wish to delete"<<endl;
	cout<<"1 : Food"<<endl;
	cout<<"2 : Drink"<<endl;
	cout<<"3 : Daily use"<<endl;
	cout<<"4 : Appliance"<<endl;
	cout<<"5 : Back"<<endl;
	do{
		cin>>add_choice;
		s_flag = 0;
		switch(add_choice){
			case 1 :
				a.show_all();
				s_flag = 1;
				break;
			case 2 :
				b.show_all();
				s_flag = 1;
				break;
			case 3 :
				c.show_all();
				s_flag = 1;
				break;
			case 4 :
				d.show_all();
				s_flag = 1;
				break;
			default :  clear();
		}
	}while(add_choice != 5 && s_flag == 0);
	int tmpNodeID;
	if(add_choice!=5){
		do{
			cout<<"Please Enter NodeID you wish to edit"<<endl;
			cin>>NodeID;
			
			if(add_choice==1){
				if(a.check_NodeID(NodeID)) {
					tmpNodeID = a.LLreturn_NodeID(NodeID);
					a.delete_stock(NodeID);
					clear();
					choice_insert_func();
					a.LLedit_NodeID(tmpNodeID);
					break;
				}
			}
			else if(add_choice==2){
				if(b.check_NodeID(NodeID)) {
					tmpNodeID = b.LLreturn_NodeID(NodeID);
					b.delete_stock(NodeID);
					clear();
					choice_insert_func();
					b.LLedit_NodeID(tmpNodeID);
					break;
				}
			}
			else if(add_choice==3){
				if(c.check_NodeID(NodeID)) {
					tmpNodeID = c.LLreturn_NodeID(NodeID);
					c.delete_stock(NodeID);
					clear();
					choice_insert_func();
					c.LLedit_NodeID(tmpNodeID);
					break;
				}
			}
			else{
				if(d.check_NodeID(NodeID)) {
					tmpNodeID = d.LLreturn_NodeID(NodeID);
					d.delete_stock(NodeID);
					clear();
					choice_insert_func();
					d.LLedit_NodeID(tmpNodeID);
					break;
				}
			}
			
		}while(!a.check_NodeID(NodeID));
	}
}