/*
   Drill Exercise on Page 83-84 (slightly modified)
   
   Program that produces a simple form letter
   Based on user input
*/

#include "../../std_lib_facilities.h"

int main()
{
   string user_name;
   string recipient_name;
   string friend_name;
   char friend_gender = 0;
   int age = 0;
   

   cout << "Enter your name: ";
   cin >> user_name;

   cout << "Enter the name of the person you want to write to: ";   
   cin >> recipient_name;

   cout << "Enter the age of the recipient: ";
   cin >> age;

   if (age <= 0 || age >= 110) 
      simple_error("you're kidding");

   cout << "Enter the name of a friend: ";
   cin >> friend_name;

   cout << "Enter your friend's gender (\"m\" for male, \"f\" for female): ";
   cin >> friend_gender;
   
   
   cout << "\nDear " << recipient_name << ",\n" << "How are you ? Hope everything is OK.\n"
        << "Have you seen " << friend_name << " lately ?\n";
   
   if (friend_gender == 'm')
      cout << "If you see " << friend_name << " please ask him to call me.\n";
   
   else 
      cout << "If you see " << friend_name << " please ask her to call me.\n";

   cout << "I hear you just had a birthday and you are " << age << " years old.\n";

   if (age < 12)
      cout << "Next year you will be " << age + 1 << "\n";
   
   else if (age == 17)
      cout << "Next year you will be able to vote.\n";
   
   else if (age > 70) 
      cout << "I hope you are enjoying retirement.\n";
   
   cout << "Yours sincerely,\n\n" << user_name  << '\n';  // Two blank lines for a signature 
}
