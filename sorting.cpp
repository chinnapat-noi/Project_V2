#ifndef sorting_cpp
#define sorting_cpp

#include <iostream>
#include <cstdlib>
#include <string> 

using namespace std;

#include "NodeLL.h"

void sorting_function() {
     int sorting_choice,dailyuse_sorting_choice,drink_sorting_choice,food_sorting_choice,specific_sorting_choice; 
     cout << "== Please Insert The Type of Product to Sorting == " << endl;
     cout << "--> 1) Food Product " << endl;
     cout << "--> 2) Drinks Product " << endl;
     cout << "--> 3) Daily Use Product " << endl;
     cout << "--> 4) Specific Use Product " << endl; 
     cout << "--> 5) Go Back To Menu " << endl;
     cout << "--> Enter Your Choice : "; cin >> sorting_choice; 
     switch(sorting_choice) {
        case 1: //Food
           cout << "== Food Product Sorting Program == " << endl; 
           cout << "--> 1) Sorting by Node ID ?" << endl;
           cout << "--> 2) Sorting by MFD ?" << endl; 
           cout << "--> 3) Sorting by Exp ?" << endl;
           cout << "--> 4) Sorting by Weight ? " << endl;
           cout << "--> 5) Go Back To Menu " << endl;
           cout << "--> Enter Your Choice : ";
           cin >> food_sorting_choice;
           switch(food_sorting_choice) {
               case 1:  a.sorting_by_NodeID();
                 break;
               case 2:  a.sorting_by_mfd(); 
                 break;
               case 3:  a.sorting_by_exp();
                 break;
               case 4:  a.sorting_by_weight(); 
                 break;
               default: clear();
                 break;
           }

        break;
        case 2: //Drink
           cout << "== Drinks Product Sorting Program == " << endl;
           cout << "--> 1) Sorting by Node ID ?" << endl;
           cout << "--> 2) Sorting by MFD ?" << endl; 
           cout << "--> 3) Sorting by Exp ?" << endl;
           cout << "--> 4) Sorting by Weight ? " << endl;
           cout << "--> 5) Sorting by Volume of Drink ? " << endl;
           cout << "--> 6) Go Back To Menu " << endl;
           cout << "--> Enter Your Choice : ";
           cin >> drink_sorting_choice;
           switch(drink_sorting_choice) {
               case 1: b.sorting_by_NodeID(); 
                 break;
               case 2:  b.sorting_by_mfd();
                 break;
               case 3:  b.sorting_by_exp();
                 break;
               case 4: b.sorting_by_weight();
                 break;
               case 5: b.sorting_by_volume(); 
                 break;
               default: clear();
                 break;
           }
        break;
        case 3: //DailyUse
           cout << "== Daily Use Product Sorting Program == " << endl; 
           cout << "--> 1) Sorting by Node ID ?" << endl;
           cout << "--> 2) Sorting by MFD ?" << endl; 
           cout << "--> 3) Sorting by Exp ?" << endl;
           cout << "--> 4) Sorting by Weight ? " << endl;
           cout << "--> 5) Go Back To Menu " << endl;
           cout << "--> Enter Your Choice : ";
           cin >> dailyuse_sorting_choice;
           switch(dailyuse_sorting_choice) {
               case 1: c.sorting_by_NodeID(); 
                 break;
               case 2: c.sorting_by_mfd();
                 break;
               case 3: c.sorting_by_exp();
                 break;
               case 4: c.sorting_by_weight();
                 break;
               default: clear();
                 break;
           }
        break;
        case 4: //Specific Use 
           cout << "== Specific Use Product Sorting Program == " << endl; 
           cout << "--> 1) Sorting by Node ID ?" << endl;
           cout << "--> 2) Sorting by MFD ?" << endl; 
           cout << "--> 3) Sorting by Exp ?" << endl;
           cout << "--> 4) Sorting by Weight ? " << endl;
           cout << "--> 5) Go Back To Menu " << endl;
           cout << "--> Enter Your Choice : ";
           cin >> specific_sorting_choice;
           switch(specific_sorting_choice) {
               case 1: d.sorting_by_NodeID(); 
                 break;
               case 2: d.sorting_by_mfd();
                 break;
               case 3: d.sorting_by_exp();
                 break;
               case 4: d.sorting_by_weight();
                 break;
               default: clear(); 
                 break;
           }
        break;
        default : clear();
     }
}

//Convert String MFD and EXP to Integer
//compareDates(current->return_mfg(),temp->return_mfg()) > 0 was true !

int compareDates(const string& date1 , const string& date2) {

   int year1,year2,month1,month2;

   //reading store scanf from month and year 
   sscanf(date1.c_str(), "%d/%d" , &month1, &year1);
   sscanf(date2.c_str(), "%d/%d" , &month2, &year2);

   if(year1 < year2) {
      return -1;
   }
   else if(year1 > year2) {
      return 1;
   }
   else {
      if(month1 < month2) {
         return -1;
      }
      else if(month1 > month2) {
         return 1;
      }
      else return 0;
   }
}

//Sorting Linked List Here

void LLFood::sorting_by_NodeID() {
   clear();

   food* current = hol;
   food* sorted = nullptr;

   if (current == nullptr || current->move_next() == nullptr)
      return;
        
   while (current != nullptr) {
      food* nextNode = current->move_next();
      food* prev = nullptr;
      food* temp = sorted;

      while (temp != nullptr && current->return_NodeID() > temp->return_NodeID()) {
         prev = temp;
         temp = temp->move_next();
      }

      if (prev == nullptr) {
         current->set_next(sorted);
         sorted = current;
      } else {
         prev->set_next(current);
         current->set_next(temp);
      }

      current = nextNode;
   } 

   hol = sorted;
   cout << "=== Successfully Sorted === " << endl;
   a.show_all();
}


void LLFood::sorting_by_mfd() {
   clear();

   food* current = hol;
   food* sorted = nullptr;

   if (current == nullptr || current->move_next() == nullptr)
      return;
        
   while (current != nullptr) {
      food* nextNode = current->move_next();
      food* prev = nullptr;
      food* temp = sorted;

      while (temp != nullptr && compareDates(current->return_mfg(),temp->return_mfg()) > 0) {
         prev = temp;
         temp = temp->move_next();
      }

      if (prev == nullptr) {
         current->set_next(sorted);
         sorted = current;
      } else {
         prev->set_next(current);
         current->set_next(temp);
      }

      current = nextNode;
   } 

   hol = sorted;
   cout << "=== Successfully Sorted === " << endl;
   a.show_all();
}


void LLFood::sorting_by_exp() {

   food* current = hol;
   food* sorted = nullptr;

   if (current == nullptr || current->move_next() == nullptr)
      return;
        
   while (current != nullptr) {
      food* nextNode = current->move_next();
      food* prev = nullptr;
      food* temp = sorted;

      while (temp != nullptr && compareDates(current->return_exp(),temp->return_exp()) > 0) {
         prev = temp;
         temp = temp->move_next();
      }

      if (prev == nullptr) {
         current->set_next(sorted);
         sorted = current;
      } else {
         prev->set_next(current);
         current->set_next(temp);
      }

      current = nextNode;
   } 

   hol = sorted;
   cout << "=== Successfully Sorted === " << endl;
   a.show_all();

}

void LLFood::sorting_by_weight() {
   clear();

   food* current = hol;
   food* sorted = nullptr;

   if (current == nullptr || current->move_next() == nullptr)
      return;
        
   while (current != nullptr) {
      food* nextNode = current->move_next();
      food* prev = nullptr;
      food* temp = sorted;

      while (temp != nullptr && current->return_weightAll() > temp->return_weightAll()) {
         prev = temp;
         temp = temp->move_next();
      }

      if (prev == nullptr) {
         current->set_next(sorted);
         sorted = current;
      } else {
         prev->set_next(current);
         current->set_next(temp);
      }

      current = nextNode;
   } 

   hol = sorted;
   cout << "=== Successfully Sorted === " << endl;
   a.show_all();
}

void LLDrinks::sorting_by_NodeID() {
   clear();

   drinks* current = hol;
   drinks* sorted = nullptr;

   if (current == nullptr || current->move_next() == nullptr)
      return;
        
   while (current != nullptr) {
      drinks* nextNode = current->move_next();
      drinks* prev = nullptr;
      drinks* temp = sorted;

      while (temp != nullptr && current->return_NodeID() > temp->return_NodeID()) {
         prev = temp;
         temp = temp->move_next();
      }

      if (prev == nullptr) {
         current->set_next(sorted);
         sorted = current;
      } else {
         prev->set_next(current);
         current->set_next(temp);
      }

      current = nextNode;
   } 

   hol = sorted;
   cout << "=== Successfully Sorted === " << endl;
   b.show_all();

}

void LLDrinks::sorting_by_mfd() {
   clear();

   drinks* current = hol;
   drinks* sorted = nullptr;

   if (current == nullptr || current->move_next() == nullptr)
      return;
        
   while (current != nullptr) {
      drinks* nextNode = current->move_next();
      drinks* prev = nullptr;
      drinks* temp = sorted;

      while (temp != nullptr && compareDates(current->return_mfg(), temp->return_mfg()) > 0) {
         prev = temp;
         temp = temp->move_next();
      }

      if (prev == nullptr) {
         current->set_next(sorted);
         sorted = current;
      } else {
         prev->set_next(current);
         current->set_next(temp);
      }

      current = nextNode;
   } 

   hol = sorted;
   cout << "=== Successfully Sorted === " << endl;
   b.show_all();
}

void LLDrinks::sorting_by_exp() {
   clear();

   drinks* current = hol;
   drinks* sorted = nullptr;

   if (current == nullptr || current->move_next() == nullptr)
      return;
        
   while (current != nullptr) {
      drinks* nextNode = current->move_next();
      drinks* prev = nullptr;
      drinks* temp = sorted;

      while (temp != nullptr && compareDates(current->return_exp(), temp->return_exp()) > 0) {
         prev = temp;
         temp = temp->move_next();
      }

      if (prev == nullptr) {
         current->set_next(sorted);
         sorted = current;
      } else {
         prev->set_next(current);
         current->set_next(temp);
      }

      current = nextNode;
   } 

   hol = sorted;
   cout << "=== Successfully Sorted === " << endl;
   b.show_all();

}

void LLDrinks::sorting_by_weight() {
  clear();

   drinks* current = hol;
   drinks* sorted = nullptr;

   if (current == nullptr || current->move_next() == nullptr)
      return;
        
   while (current != nullptr) {
      drinks* nextNode = current->move_next();
      drinks* prev = nullptr;
      drinks* temp = sorted;

      while (temp != nullptr && current->return_weightAll() > temp->return_weightAll()) {
         prev = temp;
         temp = temp->move_next();
      }

      if (prev == nullptr) {
         current->set_next(sorted);
         sorted = current;
      } else {
         prev->set_next(current);
         current->set_next(temp);
      }

      current = nextNode;
   } 

   hol = sorted;
   cout << "=== Successfully Sorted === " << endl;
   b.show_all();

}

void LLDrinks::sorting_by_volume() {
   clear();

   drinks* current = hol;
   drinks* sorted = nullptr;

   if (current == nullptr || current->move_next() == nullptr)
      return;
        
   while (current != nullptr) {
      drinks* nextNode = current->move_next();
      drinks* prev = nullptr;
      drinks* temp = sorted;

      while (temp != nullptr && current->return_volumeAll() > temp->return_volumeAll()) {
         prev = temp;
         temp = temp->move_next();
      }

      if (prev == nullptr) {
         current->set_next(sorted);
         sorted = current;
      } else {
         prev->set_next(current);
         current->set_next(temp);
      }

      current = nextNode;
   } 

   hol = sorted;
   cout << "=== Successfully Sorted === " << endl;
   b.show_all();

}

void LLDai::sorting_by_NodeID() {
   clear();

   dailyUse* current = hol;
   dailyUse* sorted = nullptr;

   if (current == nullptr || current->move_next() == nullptr)
      return;
        
   while (current != nullptr) {
      dailyUse* nextNode = current->move_next();
      dailyUse* prev = nullptr;
      dailyUse* temp = sorted;

      while (temp != nullptr && current->return_NodeID() > temp->return_NodeID()) {
         prev = temp;
         temp = temp->move_next();
      }

      if (prev == nullptr) {
         current->set_next(sorted);
         sorted = current;
      } else {
         prev->set_next(current);
         current->set_next(temp);
      }

      current = nextNode;
   } 

   hol = sorted;
   cout << "=== Successfully Sorted === " << endl;
   c.show_all();
}

void LLDai::sorting_by_mfd() {
   clear();

   dailyUse* current = hol;
   dailyUse* sorted = nullptr;

   if (current == nullptr || current->move_next() == nullptr)
      return;
        
   while (current != nullptr) {
      dailyUse* nextNode = current->move_next();
      dailyUse* prev = nullptr;
      dailyUse* temp = sorted;

      while (temp != nullptr && compareDates(current->return_mfg(), temp->return_mfg()) > 0) {
         prev = temp;
         temp = temp->move_next();
      }

      if (prev == nullptr) {
         current->set_next(sorted);
         sorted = current;
      } else {
         prev->set_next(current);
         current->set_next(temp);
      }

      current = nextNode;
   } 

   hol = sorted;
   cout << "=== Successfully Sorted === " << endl;
   c.show_all();
}

void LLDai::sorting_by_exp() {
   clear();

   dailyUse* current = hol;
   dailyUse* sorted = nullptr;

   if (current == nullptr || current->move_next() == nullptr)
      return;
        
   while (current != nullptr) {
      dailyUse* nextNode = current->move_next();
      dailyUse* prev = nullptr;
      dailyUse* temp = sorted;

      while (temp != nullptr && compareDates(current->return_exp(), temp->return_exp()) > 0) {
         prev = temp;
         temp = temp->move_next();
      }

      if (prev == nullptr) {
         current->set_next(sorted);
         sorted = current;
      } else {
         prev->set_next(current);
         current->set_next(temp);
      }

      current = nextNode;
   } 

   hol = sorted;
   cout << "=== Successfully Sorted === " << endl;
   c.show_all();
}

void LLDai::sorting_by_weight() {
   clear();

   dailyUse* current = hol;
   dailyUse* sorted = nullptr;

   if (current == nullptr || current->move_next() == nullptr)
      return;
        
   while (current != nullptr) {
      dailyUse* nextNode = current->move_next();
      dailyUse* prev = nullptr;
      dailyUse* temp = sorted;

      while (temp != nullptr && current->return_weightAll() > temp->return_weightAll()) {
         prev = temp;
         temp = temp->move_next();
      }

      if (prev == nullptr) {
         current->set_next(sorted);
         sorted = current;
      } else {
         prev->set_next(current);
         current->set_next(temp);
      }

      current = nextNode;
   } 

   hol = sorted;
   cout << "=== Successfully Sorted === " << endl;
   c.show_all();

}

void LLSpec::sorting_by_NodeID() {
   clear();

   specificPurpose* current = hol;
   specificPurpose* sorted = nullptr;

   if (current == nullptr || current->move_next() == nullptr)
      return;
        
   while (current != nullptr) {
      specificPurpose* nextNode = current->move_next();
      specificPurpose* prev = nullptr;
      specificPurpose* temp = sorted;

      while (temp != nullptr && current->return_NodeID() > temp->return_NodeID()) {
         prev = temp;
         temp = temp->move_next();
      }

      if (prev == nullptr) {
         current->set_next(sorted);
         sorted = current;
      } else {
         prev->set_next(current);
         current->set_next(temp);
      }

      current = nextNode;
   } 

   hol = sorted;
   cout << "=== Successfully Sorted === " << endl;
   d.show_all();
}

void LLSpec::sorting_by_mfd() {
   clear();

   specificPurpose* current = hol;
   specificPurpose* sorted = nullptr;

   if (current == nullptr || current->move_next() == nullptr)
      return;
        
   while (current != nullptr) {
      specificPurpose* nextNode = current->move_next();
      specificPurpose* prev = nullptr;
      specificPurpose* temp = sorted;

      while (temp != nullptr && compareDates(current->return_mfg(),temp->return_mfg()) > 0) {
         prev = temp;
         temp = temp->move_next();
      }

      if (prev == nullptr) {
         current->set_next(sorted);
         sorted = current;
      } else {
         prev->set_next(current);
         current->set_next(temp);
      }

      current = nextNode;
   } 

   hol = sorted;
   cout << "=== Successfully Sorted === " << endl;
   d.show_all();
}

void LLSpec::sorting_by_exp() {
   clear();

   specificPurpose* current = hol;
   specificPurpose* sorted = nullptr;

   if (current == nullptr || current->move_next() == nullptr)
      return;
        
   while (current != nullptr) {
      specificPurpose* nextNode = current->move_next();
      specificPurpose* prev = nullptr;
      specificPurpose* temp = sorted;

      while (temp != nullptr && compareDates(current->return_exp(),temp->return_exp()) > 0) {
         prev = temp;
         temp = temp->move_next();
      }

      if (prev == nullptr) {
         current->set_next(sorted);
         sorted = current;
      } else {
         prev->set_next(current);
         current->set_next(temp);
      }

      current = nextNode;
   } 

   hol = sorted;
   cout << "=== Successfully Sorted === " << endl;
   d.show_all();
}

void LLSpec::sorting_by_weight() {
  clear();

   specificPurpose* current = hol;
   specificPurpose* sorted = nullptr;

   if (current == nullptr || current->move_next() == nullptr)
      return;
        
   while (current != nullptr) {
      specificPurpose* nextNode = current->move_next();
      specificPurpose* prev = nullptr;
      specificPurpose* temp = sorted;

      while (temp != nullptr && current->return_weightAll() > temp->return_weightAll()) {
         prev = temp;
         temp = temp->move_next();
      }

      if (prev == nullptr) {
         current->set_next(sorted);
         sorted = current;
      } else {
         prev->set_next(current);
         current->set_next(temp);
      }

      current = nextNode;
   } 

   hol = sorted;
   cout << "=== Successfully Sorted === " << endl;
   d.show_all();

}

#endif