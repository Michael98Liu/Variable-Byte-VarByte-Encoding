#define INDEX "/home/qi/forwardIndex/compressedIndex"
#define INFO "/home/qi/forwardIndex/docInfo"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cmath>
#include <bitset>
#include <ctime>
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
			p++;
			it ++;
			c = *it;
			byte = bitset<8>(c);
		}
		num += (byte.to_ulong())*pow(128, p);
		//cout << "num: " << num << endl;
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
	ofile.open("test_uncomp");
	string line;
	string value;
	vector<string> vec;
	char c;
	vector<char> cv;
	vector<int> de;

	for(int i = 0; i < 10000; i ++){	
		vec.clear();
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
			ofile << *it << ' ';
		}
		cv.clear();
	}
	ofile.close();
	index.close();
	info.close();

}

int main(){
	int start=clock();	
	decomp_index();
	int finish=clock();
	cout << "Decompressed in: " << (finish-start)/double(CLOCKS_PER_SEC) << " seconds." << endl;
	return 0;
}
