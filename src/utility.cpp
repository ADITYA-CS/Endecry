/**
 * @file utility.cpp
 * @author Aditya Kumar Singh
 * @brief   Contain some helper function
 * @details This contains helper function. such as function for conversion from
 * array of char to string, printing error message and many more feel fill to see
 * utility.h for function declaration
 * @bug No bug
 * @warning Don't modify with prior knowledge
 */

#include "utility.h"
using namespace std;

/**
 *  @brief Print error message
 */

void ErrorMessage(){
    cout << "\v\t-------------------------------------------------------------\n";
    cout << "\t\t\t\t E R R O R\n";
    cout << "\t Try \"./endecry -h\"\n";
    cout << "\t-------------------------------------------------------------\n\v";
}

/**
 *  @brief Prints all the option that Endecry can do
 */

void PrintAlgorithmOption(){
    cout << "\t-----------------------------------------------------------------\n";
    cout << "\t                     Encryption Algorithms             \n\n";
    cout << "\t     1. XOR           2. caesar           3. shift     \n";
    cout << "\t     4. Vigenere      5. DES              6. AES       \n";
    cout << "\t-----------------------------------------------------------------\n";
    cout << "\t                           Hashing                           \n\n";
    cout << "\t     1. SHA-1         2. BLAKE            3. MD4       \n";
    cout << "\t     3. Whirlpool     4. MD2              5. SHA-3     \n";
    cout << "\t-----------------------------------------------------------------\n\v";
}

/**
 *  @brief Prints error message when unable to open file
 */
void PrintCannotOpenFile(){
    cout << "\v\t-------------------------------------------------------------\n";
    cout << "\t-------------------!ERROR! Can't Opening file! ----------------\n";
    cout << "\t-------------------------------------------------------------\n\v";
}
void PrintError(){
    cout << "\v\t-------------------------------------------------------------\n";
    cout << "\t------------------------ ERROR ------------------------------\n";
    cout << "\t-------------------------------------------------------------\n\v";
}

/**
 * @brief Reads the address of file
 * @return address of the file
 */

fs::path GetInputFile(){
    fs::path path;
    cout << "Input file : ";
    cin >> path;
    return path;
}

/**
 * @brief Read what task user want to perform
 * @return Algorithm which is going to perform
 */

string GetAlgorithm(){
    PrintAlgorithmOption();
    string algorithm, temp;
    // reading which algorithm user want to use
    // cross checking against database
    while(true){
        cout << "\tEnter name: ";
        cin >> algorithm;
        fs::path path = fs::current_path();
        path = path.parent_path();
        path /= "src/file/algo.txt";
        ifstream in(path);
        if(!in.is_open()){
            PrintError();
            exit(10);
        }
        bool can_perform = false;
        while(getline(in,temp)){
            if(temp == algorithm){
                in.close();
                can_perform = true;
                break;
            }
        }
        if(can_perform){
            break;
        } else{
            in.close();
            PrintError();
            abort();
        }
    }

    return algorithm;
}

/**
 * @brief Create the address for output file
 * @param input Address of the input file
 * @return Address of the output file
 */
// output file location for resultant data
fs::path  GetOutputFile(const fs::path &input){
    fs::path path = input;
    path += ".endecry";
    return path;
}

/**
 * @brief Convert array of char to string
 * @param input Pointer to array of char
 * @return string
 */

string CharStarToString(const char *input){
    string out;
    int i = 0;
    while(input[i]){
        out += input[i++];
    }
    return out;
}


/**
 * @brief print how to use the Endecry, and other related stuff
 * @todo implement the function
 */

void PrintHelpPage(){

}

/**
 * Covert string to integer
 * @param option  string
 * @return return integer if possible
 *         otherwise return -1 which indicate string is not
 *         convertible to integer
 */
int StringToInt(const string& option){
    if(option.size() > 2 || option.empty()){
        return -1;
    }
    for(auto x : option){
        if(x < '0' || x > '9'){
            return -1;
        }
    }
    int res = 0;
    for (auto x : option) {
        res *= 10;
        res += x - '0';
    }
    return res;
}

/**
 *  Take input from user and determine which task to perform
 * @return  H   for Hash
 *          E   for Encryption
 *          D   for Decryption
 *          I   for Information
 *          h   for Help
 *          Default is I.
 */
char TaskToPerform(){
    string option;
    cout << "\t-----------------------------------------------------------------\n";
    cout << "\t                        WHAT TO DO\n";
    cout << "\t1. Hash    2. Encrypt    3. Decrypt    4. Information    5. Help\n";
    cout << "\tOption: ";
    cin >> option;
    int op = StringToInt(option);
    while (op < 1 || op > 5){
        cout << "\tWrong Input\n\tOption: ";
        cin >> option;
        op = StringToInt(option);
    }
    cout << "\t-----------------------------------------------------------------\n\v";
    switch (op) {
        case 1: return 'H';
        case 2: return 'E';
        case 3: return 'D';
        case 4: return 'I';
        case 5: return 'h';
    }
    return 'I';
}