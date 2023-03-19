#include <iostream>
using namespace std;

void twos_compliment(bool* num, int int_type){
    // ones compliment
    for (int i = 0 ; i < int_type ; i++){
        if (num[i] == 0){
            num[i] = 1;
        }else{
            num[i] = 0;
        }
    }

    // twos compliment
    for (int i = int_type-1 ; i>=0 ; i--){
        if (num[i] == 0){
            num[i] = 1;
            break;
        }else{
            num[i] = 0;
        }
    }
}

bool *decimal_to_binary_unsigned_32_bit(unsigned int num){
    bool* bin_num = new bool[32]();
    int i = 31;
    while (num){
        int bit = num & 1; // will calculate last bit
        bin_num[i--] = bit;
        num = num >> 1;   // will remove the previously calculated bit from number.
    }
    return bin_num;
}

bool *decimal_to_binary_signed_32_bit(int num){
    if (num >= 0){
        return decimal_to_binary_unsigned_32_bit(num);
    }else{
        unsigned int n = -num;
        bool* bin_num = decimal_to_binary_unsigned_32_bit(n);
        twos_compliment(bin_num,32);
        return bin_num;
    }
}

bool *decimal_to_binary_unsigned_64_bit(unsigned long long num){
    bool* bin_num = new bool[64]();
    int i = 63;
    while (num){
        int bit = num & 1; // will calculate last bit
        bin_num[i--] = bit;
        num = num >> 1;   // will remove the previously calculated bit from number.
    }
    return bin_num;
}

bool *decimal_to_binary_signed_64_bit(long long num){
    if (num >= 0){
        return decimal_to_binary_unsigned_64_bit(num);
    }else{
        unsigned long long int n = -num;
        bool* bin_num = decimal_to_binary_unsigned_64_bit(n);
        twos_compliment(bin_num,64);
        return bin_num;
    }
}

void print_deci_32_bit_integer(bool* num){
    int i = 0;
    while (num[i] == 0){
        i++;
    }
    for (i;i<32;i++){
        cout << num[i];
    }cout << endl;
}

void print_deci_64_bit_integer(bool* num){
    int i = 0;
    while (num[i] == 0){
        i++;
    }
    for (i;i<64;i++){
        cout << num[i];
    }cout << endl;
}
 
int main(){


    while (1){

        // Main Menu
        cout << "****************************************************************" << endl;
        cout << "Main Menu !!!!" << endl;
        cout << "1. unsigned 32 bit integer" << endl;
        cout << "2. signed 32 bit integer" << endl;
        cout << "3. unsigned 64 bit integer" << endl;
        cout << "4. signed 64 bit integer" << endl;
        cout << "5. exit" << endl;

        // take choice from user.
        int choice;
        cout << "enter your choice: ";
        cin >> choice;

        // driver code 
        switch(choice){
            case 1: 
                long long num;
                cout << "enter your 32 bit unsigned integer: ";
                cin >> num;
                if (num < 0){
                    cout << "unsigned integer cannot be negative." << endl;
                    cout << "invalid input!!!" << endl;
                }
                else if (num == 0){
                    cout << "binary representation of " << num << " : ";
                    cout << 0 << endl;
                }
                else if (num > 4294967295){
                    cout << "exceeds unsigned integer range!!!!" << endl;
                }
                else{
                    bool* deci = decimal_to_binary_unsigned_32_bit(num);
                    cout << "binary representation of " << num << " : ";
                    print_deci_32_bit_integer(deci);
                    delete[] deci;
                }
                break; 

            case 2:
                cout << "enter your 32 bit signed integer: ";
                cin >> num;

                if (num > 2147483647 || num < -2147483648){
                    cout << "signed integer range exceeds" << endl;
                }else if (num == 0){
                    cout << "binary representation of " << num << " : ";
                    cout << 0 << endl;
                }else{
                    bool* deci = decimal_to_binary_signed_32_bit(num);
                    cout << "binary representation of " << num << " : ";
                    print_deci_32_bit_integer(deci);
                    delete[] deci;
                }   
                break;

            case 3:
                unsigned long long int u_64_int;
                cout << "enter your 64 bit unsigned integer: ";
                cin >> u_64_int;

                if (u_64_int < 0){
                    cout << "unsigned integer cannot be negative." << endl;
                    cout << "invalid input!!!" << endl;
                }else if (u_64_int == 0){
                    cout << "binary representation of " << u_64_int << " : ";
                    cout << 0 << endl;
                }else{
                    bool* deci = decimal_to_binary_unsigned_64_bit(u_64_int);
                    cout << "binary representation of " << u_64_int << " : ";
                    print_deci_64_bit_integer(deci);
                    delete[] deci;
                }
                break;


            case 4:
                long long int s_64_int;
                cout << "enter your 64 bit signed integer: ";
                cin >> s_64_int;


                if (s_64_int == 0){
                    cout << "binary representation of " << s_64_int << " : ";
                    cout << 0 << endl;
                }else{
                    bool* deci = decimal_to_binary_signed_64_bit(s_64_int);
                    cout << "binary representation of " << s_64_int << " : ";
                    print_deci_64_bit_integer(deci);
                    delete[] deci;
                }


            case 5:
                return 0;
            
            default:
                cout << "invalid input!!!!" << endl;
                cout << "enter again !!!" << endl;

        }
    }
    return 0;
}
