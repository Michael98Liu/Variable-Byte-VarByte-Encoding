#define DATA "./test"
#include <fstream>
#include <iostream>
#include <bitset>
#include <vector>
#include <cmath>
using namespace std;

void write(vector<uint8_t> num, ofstream& ofile){
	for(vector<uint8_t>::iterator it = num.begin(); it != num.end(); it++){
		ofile.write(reinterpret_cast<const char*>(&(*it)), 1);
	}
	ofile.close();
}

std::vector<char> read_com(ifstream& infile){
	char c;
	vector<char> result;
	while(infile.get(c)){
		result.push_back(c);
	}
	return result;
}

void VBEncode(unsigned int num){
	ofstream ofile;
	ofile.open(DATA, ios::binary);
	vector<uint8_t> result;
	uint8_t b;
	while(num >= 128){
		int a = num % 128;
		bitset<8> byte(a);
		byte.flip(7);
		num = (num - a) / 128;
		b = byte.to_ulong();
		cout << byte << endl;
		result.push_back(b);
	}
	int a = num % 128;
	bitset<8> byte(a);
	cout << byte << endl;
	b = byte.to_ulong();
	result.push_back(b);
	write(result, ofile);
}

std::vector<int> VBDecode(string filename){
	ifstream ifile;
	ifile.open(filename, ios::binary);
	char c;
	int num;
	int p;
	vector<int> result;
	vector<char> vec = read_com(ifile);

	for(vector<char>::iterator it = vec.begin(); it != vec.end(); it++){
		c = *it;
		bitset<8> byte(c);
		num = 0;
		p = 0;
		while(byte[7] == 1){
			byte.flip(7);
			num += byte.to_ulong()*pow(128, p);
			cout << "num " << num << endl;
			p++;
			it ++;
			c = *it;
			byte = bitset<8>(c);
		}
		num += (byte.to_ulong())*pow(128, p);

		result.push_back(num);
	}
	return result;
}

int main(){
	uint8_t a = 255;
	vector<char> c;
	vector<int> i;
	int in;
	cin >> in;
	VBEncode(in);
	i = VBDecode(DATA);
	for(vector<int>::iterator it = i.begin(); it != i.end(); it++){
		cout << "result " << *it << endl;
	}

	return 0;
}