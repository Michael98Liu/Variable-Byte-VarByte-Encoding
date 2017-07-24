#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <ctime>
using namespace std;

void write(vector<uint8_t> num, ofstream& ofile){
	for(vector<uint8_t>::iterator it = num.begin(); it != num.end(); it++){
		ofile.write(reinterpret_cast<const char*>(&(*it)), 1);
	}
}

void VBEncode(unsigned int num, ofstream& ofile){
	vector<uint8_t> result;
	uint8_t b;
	while(num >= 128){
		int a = num % 128;
		bitset<8> byte(a);
		byte.flip(7);
		num = (num - a) / 128;
		b = byte.to_ulong();
		result.push_back(b);
	}
	int a = num % 128;
	bitset<8> byte(a);
	b = byte.to_ulong();
	result.push_back(b);
	write(result, ofile);
}

void encode(){
	ifstream ifile;
	ifile.open("test_uncomp");
	ofstream ofile;
	ofile.open("test_comp");
	string line;
	string value;

	getline(ifile, line);
	stringstream lineStream(line);
	while(lineStream >> value){
		VBEncode(stoi(value), ofile);
	}
	ofile.close();
	ifile.close();

}

int main(){
	int start=clock();	
	encode();
	int finish=clock();
	cout << "Compressed in: " << (finish-start)/double(CLOCKS_PER_SEC) << " seconds." << endl;
	return 0;
}

