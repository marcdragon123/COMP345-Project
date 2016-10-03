#ifndef DICE_HPP
#define DICE_HPP

 #include <iostream>
 #include <ctime>
 #include <cmath>
 #include <string>
 
 using namespace std;
 
 class Dice
 {
 public:
     Dice();
     int roll(int num, int size);
     int roll(int num, int size, int mod);
     int roll(string);
    
 };

#endif

