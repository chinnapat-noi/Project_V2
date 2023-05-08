#ifndef Son_manip_cpp
#define Son_manip_cpp

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
			
		}while(!a.check_NodeID(NodeID)); /*SHOULD BE EDIT DUE WITH ERROR HANDLING*/
	}
}
#endif