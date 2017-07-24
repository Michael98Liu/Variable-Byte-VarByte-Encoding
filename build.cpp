#define INDEX ""
#define INFO ""
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
using namespace std;


std::vector<int> VBDecode(vector<char> vec){
	char c;
	int num;
	int p;
	vector<int> result;

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

void decomp_index(){
	ifstream index;
	ifstream info;
	ofstream ofile;
	index.open(INDEX);
	info.open(INFO);
	ofile.open("test_data");
	string line;
	string value;
	vector<string> vec;
	char c;
	vector<char> cv;
	vector<int> de;

	for(int i = 0; i < 20; i++){
		getline(info, line);
		stringstream lineStream(line);
		while(lineStream >> value){
			vec.push_back(value);
		}
		index.seekg(stoi(vec[2]));
		while(index.tellg() != (stoi(vec[2]) + stoi(vec[3]))){
			index.get(c);
			cv.push_back(c);
		}
		de = VBDecode(cv);

		for(vector<int>::iterator it = de.begin(); it != de.end(); it++){
			ofile.write(reinterpret_cast<const char *>(&(*it)), sizeof(*it));
		}
		ofile.close();
	}

}

int main(){
	decomp_index();
	return 0;
}