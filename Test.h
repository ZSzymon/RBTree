#ifndef TEST_H
#define TEST_H
#include <bits/stdc++.h>
#include "RBT.h"
using namespace std;
class Test{
   RBT<int> tree;
   std::map<int,int> toInsert,toDelete,notDeleted;


   void prepareNumbersToInsert(){
       int howMany = 100000;
       int key,val;
       for(int i=0;i<howMany; i++){
           key = rand()%INT_MAX;
           val = rand()%INT_MAX;
           auto pairToInsert = make_pair(key,val);

           toInsert.insert(pairToInsert);

       }
   }
   void prepareNumberToDelete(){
       auto howMany = toInsert.size();
       size_t i=0;
       for(auto it : toInsert){
           if(i<howMany/2 && i>howMany/5){
               toDelete.insert(it);
           }else{
               notDeleted.insert(it);
           }
           i++;
       }
   }
public:
   Test(){
       prepareNumbersToInsert();
       //prepareNumberToDelete();
   }
   void insertTest(){
       for(auto it : toInsert){
           tree.insert(it.first);
           auto inserted = tree.findKey(it.first);
           assert(inserted && inserted->key == it.first);

       }
   }

};
#endif // TEST_H
