#include "dbiguint.h"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

dbiguint::dbiguint() 
{
  data_ = new unsigned short[1]; 
  data_[0] = 0;
  capacity_ = 1;
}

dbiguint::dbiguint(const string& s) {
  string s2 = s;
  capacity_= s.size();
  for(int i = 0; i < capacity_; i++){
    s2[i] = s[capacity_ - 1 - i];
  }
  data_ = new unsigned short[capacity_]; 
  capacity_= s.size();
  for(int ii = 0; ii < s2.size(); ii++){
    data_[ii] = s2[ii] - '0';
  }
}


int dbiguint::size() const{
  return capacity_;
}

unsigned short dbiguint::operator [](int pos) const {
    return data_[pos];

}
//This function is overloading '<<' cout is being replaced
//with out. 
ostream& operator<< (ostream& out, const dbiguint& b){
int capacity_ = b.size();
for (int i = capacity_ - 1 ; i >= 0; i--) {
    out << b[i];
    }
    return out;
    
}
  //copy existing digits and fill the rest with 0
void dbiguint::reserve(int newcapacity){
  if(newcapacity > capacity_){
    unsigned short *new_s;
    new_s = new unsigned short[newcapacity];
    for(int i = 0; i < capacity_; i++){
      new_s[i] = data_[i]; //Puting zeros in the extra spots
             // the loop starts at the value the old capacity ends fills in 
            //zeros for the remaindering spots until the capacity is reached
    }
    for(int ii = capacity_; ii < newcapacity; ii++){
      new_s[ii] = 0;
    }
    delete[] data_;
    capacity_ = newcapacity;
    data_ = new_s;
  }
  else if(newcapacity <= capacity_)
    return ; //return nothing if new_c is less then or equal to old
}

void dbiguint::operator +=(const dbiguint & b){
  if(capacity_ < b.capacity_){
    return reserve(b.size()); //Has to implement the reserve function
    //in order to use += for different sized strings
  }
  for(int i = 0; i < capacity_; i++){
    if(data_[i] + b.data_[i] >= 10 && i + 1 == capacity_){
      return reserve(capacity_ + 1);
      data_[i] = data_[i] + b.data_[i] - 10;
      data_[i + 1] += 1;
    }
    if(data_[i] + b.data_[i] >= 10)
    {
      data_[i] = data_[i] + b.data_[i] - 10;
      data_[i + 1] += 1;
    }
    else
    {
      data_[i] += b.data_[i];
    }
  }
}



