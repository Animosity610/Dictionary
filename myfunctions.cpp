#include "myfunctions.h"
using namespace std;
// first functionality,  uses binary search to find a word
int binSearch(vector<string> data, string word, int n, int &cnt)
{
	int l = 0;
	int r = n - 1;
	while(l<=r){
		cnt++;
		int mid = l + (r - l)/2;
		if (word == data[mid]){
			return mid;
		}
		else if(word > data[mid]){
			l = mid + 1;
		}
		else{
			r = mid - 1;
		}

	}
	return -1;
}


//look for prefix using binary search
int prefixBinSearch(vector <string> data, string word, int n, int &cnt){
	int l = 0;
	int r = n - 1;
	string pref = "";
	while(l <= r){
		cnt++;
		int mid = l + (r - l) / 2;
		if (data[mid].length() >= word.length() && word == data[mid].substr(0, word.length())){
			return mid;
		}
		else if(data[mid].length() <= word.length() && data[mid] < word ){
			l = mid +1; 
		}
		else if(data[mid].length() > word.length() && data[mid] < word){
			l = mid + 1;
		}
		else if(data[mid].length() <= word.length() && data[mid] > word){
			r = mid -1;
		}
		else if(data[mid].length() > word.length() && data[mid] > word){
			r = mid - 1;
		}
	}
	return -1;
}
// first appeareance of the prefix
void firstIndex(vector<string> data, string word, int n, int &cnt, int &pos, int len){

	while(pos>=0 && word == data[pos].substr(0,len-1)){ 
				pos--;
				cnt++;
				}
				pos++;
				cnt--;
}