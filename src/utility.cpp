/**
 * @file utility.cpp
 * @author Aditya Kumar Singh
 * @brief   Contain some helper function
 * @details This contains helper function. such as function for conversion from
 * array of char to string, printing error message and many more. feel fill to see
 * utility.h for function declaration
 * @bug No bug
 * @warning Don't modify with prior knowledge
 */

#include "utility.h"

/**
 *  @brief Print error message
 */

void ErrorMessage(){
    std::cout << "\v\t-------------------------------------------------------------\n";
    std::cout << "\t\t\t\t E R R O R\n";
    std::cout << "\t Try \"./endecry -h\"\n";
    std::cout << "\t-------------------------------------------------------------\n\v";
}

/**
 *  @brief Prints all the option that Endecry can do
 */

void PrintAlgorithmOption(){
    std::cout << "\t-----------------------------------------------------------------\n";
    std::cout << "\t                     Encryption Algorithms             \n\n";
    std::cout << "\t     1. XOR           2. caesar           3. shift     \n";
    std::cout << "\t     4. Vigenere      5. DES              6. AES       \n";
    std::cout << "\t-----------------------------------------------------------------\n";
}

void PrintHashOption(){
    std::cout << "\t-----------------------------------------------------------------\n";
    std::cout << "\t                           Hashing                           \n\n";
    std::cout << "\t     1. MD2\n";
    std::cout << "\t-----------------------------------------------------------------\n\v";
}
/**
 *  @brief Prints error message when unable to open file
 */
void PrintCannotOpenFile(){
    std::cout << "\v\t-------------------------------------------------------------\n";
    std::cout << "\t-------------------!ERROR! Can't Opening file! ----------------\n";
    std::cout << "\t-------------------------------------------------------------\n\v";
}
void PrintError(){
    std::cout << "\v\t-------------------------------------------------------------\n";
    std::cout << "\t------------------------ ERROR ------------------------------\n";
    std::cout << "\t-------------------------------------------------------------\n\v";
}

/**
 * @brief Reads the address of file
 * @return address of the file
 */

fs::path GetInputFile(){
    fs::path path;
    std::cout << "Input file : ";
    std::cin >> path;
    return path;
}

/**
 * @brief Read what task user want to perform
 * @return Algorithm which is going to perform
 */

std::string GetAlgorithm(int whichOne){
    if(whichOne == 1 || whichOne == 2)
        PrintAlgorithmOption();
    else if(whichOne == 3){
        PrintHashOption();
    }
    std::string algorithm, temp;
    // reading which algorithm user want to use
    // cross checking against database
    while(true){
        std::cout << "\tEnter name: ";
        std::cin >> algorithm;
        fs::path path = fs::current_path();
        path = path.parent_path();
        path /= "src/file/algo.txt";
        std::ifstream in(path);
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

std::string CharStarToString(const char *input){
    std::string out;
    int i = 0;
    while(input[i]){
        out += input[i++];
    }
    return out;
}


/**
 * Covert string to integer
 * @param option  string
 * @return return integer if possible
 *         otherwise return -1 which indicate string is not
 *         convertible to integer
 */
int StringToInt(const std::string& option){
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
    std::string option;
    std::cout << "\t-----------------------------------------------------------------\n";
    std::cout << "\t                        WHAT TO DO\n";
    std::cout << "\t1. Hash    2. Encrypt    3. Decrypt    4. Information    5. Help\n";
    std::cout << "\tOption: ";
    std::cin >> option;
    int op = StringToInt(option);
    while (op < 1 || op > 5){
        std::cout << "\tWrong Input\n\tOption: ";
        std::cin >> option;
        op = StringToInt(option);
    }
    std::cout << "\t-----------------------------------------------------------------\n\v";
    switch (op) {
        case 1: return 'H';
        case 2: return 'E';
        case 3: return 'D';
        case 4: return 'I';
        case 5: return 'h';
    }
    return 'I';
}