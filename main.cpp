#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <typeinfo>
using namespace std;

#define DEV_MODE false // default is false
#define DWORD "NO" // defalut word in file: "NO"

bool dev = DEV_MODE;
#include "NodeLL.cpp"


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
int s_choice = 0, add_choice,s_flag=0;
////////////////////////////////////////
//function
void clear();
//Son code
void add_stock();
void delete_stock(int);
void show_delete_stock();
void edit_stock();

#include "sorting.cpp"
#include "Son_manip.cpp"

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
    ifstream RF,RD,RDA,RS;//read text file readfood readdrink readdaily readspecific
    ofstream WF,WD,WDA,WS;//create text file
    ///////////////////////////////////////////////////////


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
        
    int choice = 0;
    string extra; // use to accept developer's password
    do{
        if(dev) cout << "[!] Developer Mode" << endl;
        cout << "== Please select command ==" << endl;
        cout << "--> 1 : Load data" << endl;
        cout << "--> 2 : Showall" << endl;
		cout << "--> 3 : Add , Delete , Edit your stock" << endl;
        cout << "--> 4 : Sorting Your Stock " << endl;
        cout << "--> 9 : Exit" << endl;
        cout << "--> 99 : Then type: \"dev\" to switch developer mode" << endl;

        user_choices:
        cout << "Input number : "; cin >> choice;
        if(cin.fail()) {
            cin.clear();
            cin.ignore(50,'\n');
            goto user_choices;
        }

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
			case 3 : //Manipulate data
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
            case 4: sorting_function(); break;
            case 99 :
                    cin >> extra;
                    if(extra == "dev") dev = !dev;
                    else choice = 0;
            default : clear();
        }
    }while(choice != 9); //eit program with 9

    return 0;
}

void clear() {
#if defined(__linux__) // Or #if __linux__
  system("clear");
  cout << "[!] This system is running on LINUX" << endl;
#elif __APPLE__
  system("clear");
  cout << "[!] This system is running on MacOS" << endl;
#elif _WIN32
  system("cls");
  cout << "[!] This system is running on Windows" << endl;
#endif
}