//YUNPENG LING
//CS 20A Section 4098
//Assignment 5A 
//This program use a recursive function to find the biggest element in the linked list






#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm> 



//Create a struct for linked list
struct LingsList{
    
 int value;
 LingsList *next;
    
    
};



//This recursive function finds out the biggest value in the linked list
int biggest(LingsList *current)
{
    
    //base condition used to end the function
    if(current->next==nullptr)
    {
        return (current->value);
        
        }
    
    //recursion--- call the function itself
    int rest =biggest(current->next);
    
    
    return std::max(rest, current->value);
    
}



int main()
{


  //Create a simple linked list
  LingsList *head = nullptr;
  head = new LingsList;
  
 //Store value to the list
 head->value = 43;
 head->next=nullptr;
 
 LingsList *second = new LingsList;
 second->value = 87;
 second->next=nullptr;
 head->next = second;
  
  
  //Pass the list head to 'biggest function'
  std::cout<<"The biggest value in this linked list is: "<<biggest(head);
}