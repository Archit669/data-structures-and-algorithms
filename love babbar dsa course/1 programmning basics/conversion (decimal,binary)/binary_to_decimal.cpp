#include <iostream>
using namespace std;

unsigned long long int pow(int num , int power){
    if (power == 0){
        return 1;
    }
    return (num*pow(num,power-1));
}

int check_bin_format(string num){
    for (int i = 0 ; i < num.length() ; i++){
        if (i != 0 || i != 1){
            return 0;
        }
    }
    return 1;
}

void twos_compliment(string &num, int int_type){
    // ones compliment
    for (int i = 0 ; i < int_type ; i++){
        if (num[i] == '0'){
            num[i] = '1';
        }else{
            num[i] = '0';
        }
    }

    // twos compliment
    for (int i = int_type-1 ; i>=0 ; i--){
        if (num[i] == '0'){
            num[i] = '1';
            break;
        }else{
            num[i] = '0';
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


long long int unsigned_binary_to_decimal_32_bit(string num){
    unsigned int ans = 0;
    int power = 0;
    for(int i = num.length()-1 ; i >= 0 ; i--){
        if (num[i] =='0' || num[i] == '1'){
            ans+= ((int)num[i]-48) * pow(2,power);
            power++;
        }else{
            return -1;
        }
    }
    return ans;
}


long long int signed_binary_to_decimal_32_bit(string num){
    if (num[0] == '1' && num.length()==32){  
        twos_compliment(num,32);
        return -(unsigned_binary_to_decimal_32_bit(num));
    }else{
        return unsigned_binary_to_decimal_32_bit(num);
    }
}

unsigned long long int unsigned_binary_to_decimal_64_bit(string num){
    unsigned long long int ans = 0;
    int power = 0;
    for(int i = num.length()-1 ; i >= 0 ; i--){
        if (num[i] =='0' || num[i] == '1'){
            ans+= ((int)num[i]-48) * pow(2,power);
            power++;
        }else{
            return -1;
        }
    }
    return ans;
}

long long int signed_binary_to_decimal_64_bit(string num){
    if (num[0] == '1' && num.length()==64){  
        twos_compliment(num,64);
        return -(unsigned_binary_to_decimal_64_bit(num));
    }else{
        return unsigned_binary_to_decimal_64_bit(num);
    }
}


 
int main(){

    while (1){
        // Main Menu
        cout << "\n***************************************************\n";
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
            {
                string num;
                cout << "enter your unsigned 32 bit integer: " ;
                cin >> num;
                if (num.length()>32){
                    cout << "invalid input!!!" << endl;
                }else{
                    
                    if (check_bin_format(num)){
                        cout << "invalid binary input!!!" << endl;
                    }else{
                        long long int ans = unsigned_binary_to_decimal_32_bit(num);
                        cout << "binary representation of " << num << " is " << ans << endl;
                    }
                }
                break;
            }
            case 2:
            {
                string s_32bit_num;
                cout << "enter your signed 32 bit integer: ";
                cin >> s_32bit_num;
                if (s_32bit_num.length()>32){
                    cout << "invalid input!!!" << endl;
                }else{
                    long long int ans = signed_binary_to_decimal_32_bit(s_32bit_num);
                    if (check_bin_format(s_32bit_num)){
                        cout << "invalid binary input!!!" << endl;
                    }else{
                        cout << "binary representation of " << s_32bit_num << " is " << ans << endl;
                    }
                }
                break;
            }

            case 3:
            {
                string num;
                cout << "enter your unsigned 64 bit integer: " ;
                cin >> num;
                if (num.length()>64){
                    cout << "invalid input!!!" << endl;
                }else{
                    
                    if (check_bin_format(num)){
                        cout << "invalid binary input!!!" << endl;
                    }else{
                        unsigned long long int ans = unsigned_binary_to_decimal_64_bit(num);
                        cout << "binary representation of " << num << " is " << ans << endl;
                    }
                }
                break;
            }

            case 4:
            {
                string s_64bit_num;
                cout << "enter your signed 64 bit integer: ";
                cin >> s_64bit_num;
                if (s_64bit_num.length()>64){
                    cout << "invalid input!!!" << endl;
                }else{
                    
                    if (check_bin_format(s_64bit_num)){
                        cout << "invalid binary input!!!" << endl;
                    }else{
                        long long int ans = signed_binary_to_decimal_64_bit(s_64bit_num);
                        cout << "binary representation of " << s_64bit_num << " is " << ans << endl;
                    }
                }
                break;
            }

            case 5:
                cout << "exiting!!!" << endl;
                return 0;

            case 6:
                cout << "invalid input!!!" << endl;
                cout << "enter again!!!" << endl;
                
        }

    }
    return 0;
}