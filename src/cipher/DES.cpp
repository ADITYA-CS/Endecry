#include "DES.h"


DES :: DES(){
    Permutation_choice_1_ = new int[56]{
            57, 49, 41, 33, 25, 17,  9,
            1, 58, 50, 42, 34, 26, 18,
            10,  2, 59, 51, 43, 35, 27,
            19, 11,  3, 60, 52, 44, 36,
            63, 55, 47, 39, 31, 23, 15,
            7, 62, 54, 46, 38, 30, 22,
            14,  6, 61, 53, 45, 37, 29,
            21, 13,  5, 28, 20, 12,  4};

    Permutation_choice_2_ = new int[48]{
            14, 17, 11, 24,  1,  5,
            3, 28, 15,  6, 21, 10,
            23, 19, 12,  4, 26, 8,
            16,  7, 27, 20, 13,  2,
            41, 52, 31, 37, 47, 55,
            30, 40, 51, 45, 33, 48,
            44, 49, 39, 56, 34, 53,
            46, 42, 50, 36, 29, 32};

    Initial_permutation_ = new int[64]{
            58,50,42,34,26,18,10,2,
            60,52,44,36,28,20,12,4,
            62,54,46,38,30,22,14,6,
            64,56,48,40,32,24,16,8,
            57,49,41,33,25,17,9,1,
            59,51,43,35,27,19,11,3,
            61,53,45,37,29,21,13,5,
            63,55,47,39,31,23,15,7};

    Inverse_permutation_ = new int[64]{
            40,8,48,16,56,24,64,32,
            39,7,47,15,55,23,63,31,
            38,6,46,14,54,22,62,30,
            37,5,45,13,53,21,61,29,
            36,4,44,12,52,20,60,28,
            35,3,43,11,51,19,59,27,
            34,2,42,10,50,18,58,26,
            33,1,41,9,49,17,57,25};
    Permutation_table_ = new int[32]{
            16,7,20,21,29,12,28,17,
            1,15,23,26,5,18,31,10,
            2,8,24,14,32,27,3,9,
            19,13,30,6,22,11,4,25
    };
    Expension_table_ = new int[48]{
            32,1,2,3,4,5,4,5,
            6,7,8,9,8,9,10,11,
            12,13,12,13,14,15,16,17,
            16,17,18,19,20,21,20,21,
            22,23,24,25,24,25,26,27,
            28,29,28,29,30,31,32,1
    };
    S_box_ = new int**[8];

    for(int i = 0; i < 8; i++)
        S_box_[i] = new int*[4];

    S_box_[0][0] = new int[16]{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7};
    S_box_[0][1] = new int[16]{0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8};
    S_box_[0][2] = new int[16]{4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0};
    S_box_[0][3] = new int[16]{15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13};

    S_box_[1][0] = new int[16]{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10};
    S_box_[1][1] = new int[16]{3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5};
    S_box_[1][2] = new int[16]{0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15};
    S_box_[1][3] = new int[16]{13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9};

    S_box_[2][0] = new int[16]{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8};
    S_box_[2][1] = new int[16]{13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1};
    S_box_[2][2] = new int[16]{13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7};
    S_box_[2][3] = new int[16]{1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12};

    S_box_[3][0] = new int[16]{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15};
    S_box_[3][1] = new int[16]{13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9};
    S_box_[3][2] = new int[16]{10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4};
    S_box_[3][3] = new int[16]{3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14};

    S_box_[4][0] = new int[16]{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9};
    S_box_[4][1] = new int[16]{14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6};
    S_box_[4][2] = new int[16]{4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14};
    S_box_[4][3] = new int[16]{11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3};

    S_box_[5][0] = new int[16]{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11};
    S_box_[5][1] = new int[16]{10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8};
    S_box_[5][2] = new int[16]{9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6};
    S_box_[5][3] = new int[16]{4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13};

    S_box_[6][0] = new int[16]{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1};
    S_box_[6][1] = new int[16]{13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6};
    S_box_[6][2] = new int[16]{1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2};
    S_box_[6][3] = new int[16]{6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12};

    S_box_[7][0] = new int[16]{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7};
    S_box_[7][1] = new int[16]{1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2};
    S_box_[7][2] = new int[16]{7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8};
    S_box_[7][3] = new int[16]{2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11};

}


void DES :: Generate_key(std::string key){ // bit string
    std::string pc_string; // string generated by Permutation_choice_1_

    // selecting 56 bit from 64 bit key
    // using Permutation_choice_1_ table
    for(int i = 0; i < 56; i++){
        pc_string += key[Permutation_choice_1_[i] - 1];
    }

    // split the pc_string into two equal half
    std::string left = pc_string.substr(0,28);
    std::string right = pc_string.substr(28);

    // perform circular shift
    for(int i = 0; i < 16; i++){
        // for round 1, 2, 9, 16
        // circular shift by 1
        // for other round
        // perform circular shift by 2
        if(i == 0 || i == 1 || i == 8 || i == 15){
            left = circular_shift_one(left);
            right = circular_shift_one(right);
        } else{
            left = circular_shift_two(left);
            right = circular_shift_two(right);
        }

        // combine left and right part
        pc_string = left + right;
        subkey_[i] = "";
        for(int j = 0; j < 48; j++){
            subkey_[i] += pc_string[Permutation_choice_2_[j] - 1];
        }
    }
}

//void reverse_key(vector<string>);
std::string DES :: circular_shift_one(std::string str){
    char ch = str[0];
    int size = str.size();
    for(int i = 1; i < size; i++){
        str[i - 1] = str[i];
    }
    str[size - 1] = ch;
    return str;
}

std::string DES :: circular_shift_two(std::string str){
    char ch1 = str[0], ch2 = str[1];
    int size = str.size();
    for(int i = 2; i < size; i++){
        str[i - 2] = str[i];
    }
    str[size - 2] = ch1;
    str[size - 1] = ch2;
    return str;
}

int DES :: BinaryToDecimal(const std::string& binary){
    int res = 0;
    for(auto x : binary){
        res *= 2;
        res += x - '0';
    }
    return res;
}

std::string  DES :: DecimalToBinary(int decimal){
    std::string binary;
    int d;
    while(decimal){
        d = decimal % 2;
        binary += d == 1 ? '1' : '0';
        decimal /= 2;
    }
    while(binary.size() != 8){
        binary += '0';
    }
    reverse(binary.begin(), binary.end());
    return binary;
}

std::string  DES :: XorString(std::string A, std::string B){
    std::string res;
    int size = A.size();
    int d;
    for(int i = 0; i < size; i++){
        d = (int)(A[i] - '0') + (int)(B[i] - '0');
        d %= 2;
        res += (char) ('0' + d);
    }
    return res;
}

void  DES ::  Reverse_key(){
    std::stack<std::string> s;
    for(auto & i : subkey_){
        s.push(i);
    }
    for(auto & i : subkey_){
        i = s.top();
        s.pop();
    }
}

std::string DES :: f(std::string message, std::string &key){
    // expand the message from 32-bits to 48-bits
    // using Expension_table_
    std::string expanded;
    for(int i = 0; i < 48; i++){
        expanded += message[Expension_table_[i] - 1];
    }
    // do xor of 'expanded' and 'key'
    std::string xored = XorString(expanded, key);

    // now compress 48-bit xored to 32-bit using S_box_
    std::string compressed;
    for(int i = 0; i < 8; i++){
        std::string r = xored.substr(i*6,1) + xored.substr(i*6 + 5,1);
        std::string c = xored.substr(6 * i + 1, 4);
        int row = BinaryToDecimal(r);
        int column = BinaryToDecimal(c);
        int val = S_box_[i][row][column];
        compressed += DecimalToBinary(val);
    }

    // now apply Permutation_table_ to shuffle
    std::string res;
    for(int i = 0; i < 32; i++){
        res += compressed[Permutation_table_[i] - 1];
    }
    return res;
}

std::string DES :: Padding(std::string &text){
    std::string res = text;
    res += "10000000";
    while(res.size() != 64){
        res += "00000000";
    }
    return res;
}

std::string DES :: StringToBitString(const std::string &temp){
    std::string res;
    for(char i : temp){
        res += DecimalToBinary((int)(i - 0));
    }
    return res;
}

std::string DES :: BinaryToAscii(const std::string &input){
    std::string res;
    for(int i = 0; i < 64; i+=8){
        std::string temp = input.substr(i,8);
        int d = 0;
        for(int j = 0; j < 8 ; j++){
            d *= 2;
            d += temp[j] - '0';
        }
        if(d != 0 && d != 128)
            res += (char)d;
    }
    return res;
}
/*
 *
 */
std::string DES :: Encrypt(std::string message){

    // apply initial permutation using Initial_permutation_
    std::string ip;
    for(int i = 0; i < 64; i++){
        ip += message[Initial_permutation_[i] - 1];
    }

    // divide ip into two equal part
    std::string left = ip.substr(0,32);
    std::string right =  ip.substr(32);
    std::string l, r, black_box; // two string buffer
    for(auto & i : subkey_){
        l = right;
        black_box = f(right, i);
        r = XorString(left, black_box);
        left = l;
        right = r;
    }

    // combine left and right
    // storing in ip
    ip = right + left;

    // finally apply Inverse_permutation_
    std::string res;
    for(int i = 0; i < 64; i++){
        res += ip[Inverse_permutation_[i] - 1];
    }
    return res;
}


void   DES :: Encrypt(fs::path &input, const std::string &key){

    fs::path output = input;
    output += ".endecry"; // adding extension

    std::ifstream in;
    std::ofstream out;
    // opening file
    try{
        in.open(input);
        if(!in.is_open()){
            throw std::string("Error occurs while opening reading file");
        }
        out.open(output);
        if(!out.is_open()){
            in.close(); // closing input file, before throwing exception
            throw std::string("Error occurs while opening file");
        }
    } catch (const std::string & e) {
            std::cout << e << "\n";
            exit(501);
    }

    Generate_key(key);
    std::string temp;
    char ch;
    while(in.get(ch)){
        temp += ch;
        if(temp.size() == 8){
            temp = StringToBitString(temp);
            temp = Encrypt(temp);
            out << temp;
            temp = "";
        }
    }
    // do padding for remaining character
    if(!temp.empty()){
        temp = StringToBitString(temp);
        temp = Padding(temp);
        temp = Encrypt(temp);
        out << temp;
    }

    // close file
    in.close();
    out.close();
}

void DES :: Decrypt(fs::path & input, const std::string & key){
    fs::path output = input;
    output += ".endecry"; // adding extension

    std::ifstream in;
    std::ofstream out;
    // opening file
    try{
        in.open(input);
        if(!in.is_open()){
            throw std::string("Error occurs while opening reading file");
        }
        out.open(output);
        if(!out.is_open()){
            in.close(); // closing input file, before throwing exception
            throw std::string("Error occurs while opening file");
        }
    } catch (const std::string & e) {
        std::cout << e << "\n";
        exit(502);
    }
    // TO decrypt, generate key and reverse it
    Generate_key(key);
    Reverse_key();

    std::string temp;
    char ch;
    while(in.get(ch)){
        temp += ch;
        if(temp.size() == 64){
            temp = Encrypt(temp);
            out << BinaryToAscii(temp);
            temp = "";
        }
    }

    // close file
    in.close();
    out.close();
}