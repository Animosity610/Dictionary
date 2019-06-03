#include<iostream>
#include <fstream>
#include <vector>
#include<string>
#include "myfunctions.h"
using namespace std;
int main(int argcount, char *args[])
{
	string filename;
	int nubmerOfWord=5;
	vector <string> data;//stores words from dictionary
	vector <string> output;//stores words for output
	string word = "";
	

	//cout<<"argcount: "<<argcount<<endl;

	for(int i=1; i<argcount; i++)
	{
		if(string(args[i])=="-d" && i+1 < argcount)
			filename = args[i+1];// after -d comes the filename

		if(string(args[i])=="-l" && i+1 < argcount)
			nubmerOfWord = stoi(args[i+1]);// after 0l comes the number of words to be printed
	}

	if(filename == "")
	{
		cout<<"usage ./mydictionary -d <dictionaryfile> -l <nubmerOfWord>"<<endl;
	}
	else
	{
		cout<<"Filaname: "<<filename<<endl;
		cout<<"nubmerOfWord:"<<nubmerOfWord<<endl;
	}	
	ifstream fin(filename);
	if(fin.is_open()){
		string tmp = "";
		while(fin){
			fin>>tmp;
			data.push_back(tmp);//puts a word from a textfile to the vector

		}
	}
	for (int i = 0; i< data.size(); i++){
		cout<<i<<" "<<data[i]<<endl;// prints all the words for the user with their indexes
	}
	cout<<data.size()<<" words found in the dictionary"<<endl;
	while(true){
		int cnt = 0;
		int pos = -1;
		int matches = 0;
		output.clear();
		cout<<">> ";
		cin>>word;
		// checks if user wants to exit the application
		if (word == "exit" || word == "quit"){
			break;
		}
		//first functionality
		if(word.find('*') == -1 && word.find('?') == -1){
		pos = binSearch(data, word, data.size(), cnt);
		if(pos == -1){
			cout<<"not found"<< endl;
		}
		else{
			cout<<"word found at position "<<pos<<endl;
			cout<<cnt<<" comparisons carried out"<<endl;
		}
		}
		//error message if input contains both '*' and '?'
		else if(word.find('*') != -1 && word.find('?') != -1){
			cout<<"Error, invalid input!"<<endl;
		}


		// second functionality
		else if(word.find('*') != -1){
			int len = word.length();
			word = word.substr(0, len - 1);//takes a substring without *
			cout<<len<<" pref without *->"<<word<<endl;
			pos = prefixBinSearch(data, word, data.size(), cnt);
			if(pos == -1){
				cout<<"prefix is not found"<<endl;
			}
			else{
				firstIndex( data, word, data.size(), cnt, pos, len);
				cout<<"found at position "<< pos<<endl;
				cout<<"number of comparisons up to the first match "<< cnt<< endl;
				int lim = nubmerOfWord;
				while(word == data[pos].substr(0, len-1) && pos <= data.size()-1){
				output.push_back(data[pos]);//adds to the output vector
				pos++;
			}
			int loop = 0;
			if (nubmerOfWord<output.size()){
				loop = nubmerOfWord;
			}
			else{
				loop = output.size();
			}
			for (int i= 0; i <loop; i++){
				cout<<i+1<<" "<<output[i]<<endl;// prints the matching words
			}
			cout<<output.size()<<" matches found"<<endl;


			}

		}
		else if(word.find('?') != -1){
			int ques = word.find('?');
			int len = word.length();
			string first = word.substr(0, ques);
			string second = word.substr(ques + 1, len - 1);
			pos = prefixBinSearch(data, first, data.size(),cnt);
			firstIndex(data, first, data.size(), cnt, pos, first.length()+1);
			cout<<cnt<<" word comparisons executed"<<endl;
			while(first == data[pos].substr(0, ques)){
				if(data[pos].length() == word.length() && first == data[pos].substr(0, ques) && second == data[pos].substr(ques+1, len-1)){
					output.push_back(data[pos]);
				}
				pos++;
			}
			int loop = 0;
			if (nubmerOfWord<output.size()){
				loop = nubmerOfWord;
			}
			else{
				loop = output.size();
			}
			for (int i= 0; i < loop; i++){
				cout<<i+1<<" "<<output[i]<<endl;
			}
			cout<<output.size()<<" matches found"<<endl;
		}
	}
	return 0;
}