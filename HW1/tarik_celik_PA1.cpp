#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

using namespace std;

const char * RANDOM_GEN_ARG = "-r"; //to create a constant variable for argument for computer to generate secret number.
const char * USER_ENTER_ARG = "-u"; //to create a constant variable for argument for computer to set secret number to given number.
const int MAX_ITERATION = 100;      //to create a constant variable for Iteration limit.


long long Power_of_Int(int number, int n){
    /*
    * This function takes two integer one of them is a number other one is power number 
    *  and calculates the power of given number.
    * It returns power of the number.
    */
    long long result = 1;           
    while(n--) result *= number; //to create a loop for multiply the number by itself n times.to get nth power.    
    return result; //to return nth power of given number.
}


bool Is_it_Num(char ch){
    /*
    * This function takes a char as a parameter and it checks is it number or not with ASCII value.
    * It is boolean function if given char is number then it returns true.
    */
    if(47 < ch && ch < 58) return true; //to check given char is number or not with using ASCII values.
    return false;
}


bool Is_it_Positive(char * chArr){
    /*
    * This function takes a char array as a parameter and it checks number is positive or not which is in char array.
    * It is boolean function if given number in char array is positive then it returns true.
    */

    if(chArr[0] == '0') return false; //to checking first digit of number is 0 or not.
    else{

        for(int i = 0; chArr[i] != '\0'; ++i){
            if(!Is_it_Num(chArr[i])) return false;   // Check if current character is a number, if not return false.
        }
        return true;    // Returns true since no exceptions are found.
    }
}


int Get_Digit(long long number, int index){
    /*
    * This function is takes a number and index as a parameter and it returns given index of given number.
    */

    while(index--) number /= 10; // Divide number by 10 index times to get the digit at given index to rightmost.

    return number % 10;// Then return the digit by mod 10.
}


long long Swap_Digits(long long number, int index1, int index2){
    /*
    * This function takes a number and two index number and it swaps two digits of this number which are in given index.
    * It returns swapped version of given number.
    */

    int digit1 =  Get_Digit(number, index1);    //to swap the first digit.
    int digit2 =  Get_Digit(number, index2);    //to swap the second digit.

    long long digit_factor1 = Power_of_Int(10, index1);   // Factor that when it's multiplied with digit1 results at index index1.
    long long digit_factor2 = Power_of_Int(10, index2);   // Factor that when it's multiplied with digit2 results at index index2.

    return number + (digit1 - digit2) * (digit_factor2 - digit_factor1);
}


int Get_Misplaced(long long number, long long user_guess){
    /*
    * This function takes number and user guess and it compares two of them then it counts how many digit in misplaced.
    * It returns number of misplaced digits.
    */

    int mis_placed_digit_num = 0; //to define an integer for count number of misplaced digits.
    
    long long temp = user_guess; //to define a temporary number for store the copy of user guess.

    for(int i = 0; number; ++i){ // Loop until number hits to 0. i is the current digit's index.
       
        for(int j = 0; temp; ++j){ // Loop until copy of user guess hits to 0. j is the current digit's index.

            if(number % 10 == temp % 10 && i != j){  //to check same numbers in different indexes or not.
                ++mis_placed_digit_num;    // Increase by 1.
                break;                  // to break the loop because current digit is found.
            }

            temp /= 10; //to get next digit of user guess.
        }
 
        number /= 10; //to get next digit of number.
 
        temp = user_guess; //to get copy for next loop.
    }

    return mis_placed_digit_num;  //to return number of misplaced digits.
}


int Get_Exact_Digits(long long number, long long user_guess){
    /*
    * This function takes number and user guess and it compares their digits 
    *   and counts digits which are equal and have same indexes.
    * It returns number of digits which are equal and have same indexes.(number of exactly same digits.)
    */

    int exact_digit_num = 0; //to define an integer for number of exact digits.
     
    while(number && user_guess){  //to create a loop which is go on as long as neither number is zero.

       
        if(number % 10 == user_guess % 10) ++exact_digit_num;  //to check if digits are the same,then increase exact_digit_num by 1.
       
        number /= 10; //to get next digit of number.
        user_guess /= 10; //to get next digit of user guess.
    }

    return exact_digit_num; //to return number of exactly same digits.
}


int Get_Digit_Num(long long number){
    /*
    * This function is a basic function it takes a number as a parameter and it calculates number of digits of given parameter.
    * It returns number of digits of given number.
    */

    int digit_count = 1; //to define an integer for store the number of digits.

    while(number /= 10) ++digit_count; //to calculate number of digits with dividing number by 10 each step.

    return digit_count;
}


int Char_to_Int(char * chArr){
    /*
    * This function takes a char array as a parameter and it converts this array elements to an integer with using ASCII values.
    * It returns an integer ehich is converted from char array.
    */

    int result = 0; //to define an integer for store the number which is converted from given char array.

    for(int i = 0; chArr[i] != '\0'; ++i) //to create a loop which reads to end of the char array.
    result = result * 10 + chArr[i] - 48; //to convert elements of char array to integer and multiply by 10 for get the digits.

    return result; //to return number which is came from char array.
}


int Random_Range(int lower, int upper){

    /* This function takes a random integer then takes mod to get it in range of the difference
    *   then adds lower to get it in range of the limits.
    */ 
    return rand() % (upper - lower) + lower;    
}


int Random_Range(int upper){
    return Random_Range(0, upper);   //to use overloading.
}


long long Generate_Secret_Num(int digit_count){
    /*
    * This function takes an integer as a parameter which is number of digits and it generates random number with given number of digits.
    *  Also the generated number's every digit must be different.
    * It returns randomly generated secret number. 
    */

    long long new_secret_num = 1234567890;//to define an integer for secret number and set it as 1234567890 because every digit must be different.

    for(int i = 1; i < 10; ++i){ //to create a loop for swap the digits randomly and get random number.
        //loop starts at 1 because leftmost digit must not to be 0.

        
        new_secret_num = Swap_Digits(new_secret_num, i, Random_Range(i, 10));//to swap the digit at index i with the digit at a random index between i-9.
    }

    new_secret_num = Swap_Digits(new_secret_num, 0, Random_Range(9));//to swap digit 0 with a random digit that is not at leftmost.

    return new_secret_num / Power_of_Int(10, 10 - digit_count); //to return only the first digit_count many digits because user wants specific number of digits.(start taking at left side.)
}


void Play_Mastermind(long long Secret_Num){
    /*
    * This function takes randomly generated secert number as a parameter and it takes input for user guess
    *  then it compares two of them with using other functions which are defined upside.
    *
    * It gives chance to user up to MAX_ITERATION to guess the secret number.
    *
    * It informs the user exact digits and misplaced digits.
    *
    * If user input is wrong format then it gives error message and terminate the program.
    *
    * It returns anything because function type is void.
    */

    long long user_guess; //to define a input variable for the user's guesses.
 
    int digit_count = Get_Digit_Num(Secret_Num); //to define an integer for number of digits of the secret number.
 
    for(int i = 1; i < MAX_ITERATION; ++i){ //to create a loop for playing game it limited by MAX_ITERATION.
      
        cin >> user_guess; //to Get user guess.

        if(cin.fail()){ //to check user enter a proper integer or not.
            cout << "E2\n";    //to print the error message.
            return;                 //to terminate the program.
        }
      
        else if(Get_Digit_Num(user_guess) != digit_count || Get_Misplaced(user_guess, user_guess)){//to check number of digits of user guess are matched or not. 
            cout << "E1\n";    //to print the error message.
            return;                 //to terminate the program.
        }
        
        else if(Secret_Num == user_guess){ //to check user guesses the number correctly or not.
            cout << "FOUND " << i << endl;    // Inform the user that they won.
            return;                                     //to terminate the program.
        }
        
        else //for inform user's wrong guess.
            cout << Get_Exact_Digits(Secret_Num, user_guess) << " " << Get_Misplaced(Secret_Num, user_guess) << endl;  //to inform them.
    }

    
    cout << "FAILED\n"; //to print a failed message because the number of guesses reaches to MAX_ITERATION.
}


int main(int argc, char** argv){
 
    if(argc != 3){ //to check the number of given arguments are equal to 3 or not.
        cout << "E0\n";//to print out the error message if number of arguments are not equal to 3.
    }
    else{

        if(!strcmp(argv[1], RANDOM_GEN_ARG) && argv[2][1] == '\0' && Is_it_Positive(argv[2])){ //to create loop for user enter -r.
                //this loop checks given number is a positive number and less than 10 or not.

            srand(time(0)); //to set random seed.

            long long Secret_Number = Generate_Secret_Num(Char_to_Int(argv[2])); //to generate a secret number with calling Generate_Secret_Num function.

            Play_Mastermind(Secret_Number); //to call Play_Mastermind function for start the game.(for option -r.)
        }
      
        else if(!strcmp(argv[1], USER_ENTER_ARG) && Is_it_Positive(argv[2]) && !Get_Misplaced(Char_to_Int(argv[2]), Char_to_Int(argv[2]))){ //to create a loop for user enter -u.
                //this loop checks given number is positive and given number's digits are unique.

            Play_Mastermind(Char_to_Int(argv[2])); //to call Play_Mastermind function for start the game.(for option -u.)
        }
        
        else{ 
            cout << "E0\n"; //to print error message if user is not enter proper arguments for -r and -u option.
        }
    }
    return 0;
}
