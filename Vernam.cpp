#include <iostream>
#include <string>
using namespace std;

int char_to_int(char c){
    return int(c) - 97;
}

string dec_to_bin(int n){
    //base case
    if (n == 0)
        return "";
    string dec = "";
    while (n != 0){
        dec = char((n % 2) + 48) + dec;
        n/=2;
    }
    int len = dec.length();
    while (len < 5){
        dec = '0' + dec;
        len = dec.length();
    }
        

    return dec;
}

//Encrypt Funtion
string vernamEnc(string plain, string key){
    int i = 0;
    string res = "";
    int temp;
    while (i < plain.length()){
        temp = (plain[i]^key[i]);
        res += char(temp);
        i++;
    }
    return res;
}

string string_to_hex(const string input)
{
    static const char hex_digits[] = "0123456789ABCDEF";

    std::string output;
    output.reserve(input.length() * 2);
    for (unsigned char c : input)
    {
        output.push_back(hex_digits[c >> 4]);
        output.push_back(hex_digits[c & 15]);
    }
    return output;
}

//Decypt Function
string vernamDec(string cipher,string key)
{
	string num_key;
	string result= "";
	for (int i = 0; i < key.length(); i++)
	{
			//num_key += key[i] - 'a';
			int X = (key[i] ^ cipher[i]);

			char temp = char(X);
			result += temp;
	}
	//cout << result<<endl;

	return result;
}

int main(){
    cout << "The cipher text: " << string_to_hex(vernamEnc("hello world", "abcdehabcde")) << endl;
    cout<< "The plain text: " << vernamDec(vernamEnc("hello world", "abcdehabcde"), "abcdehabcde");
}