#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
namespace stringX {
	void replace_all(string& mainString, string stringToReplace, string stringToReplaceWith) {
		for (int i = mainString.find(stringToReplace); i != string::npos; i = mainString.find(stringToReplace)) {
			mainString.replace(i, stringToReplace.size(), stringToReplaceWith);
		}
	}
	void replace(string& mainString, string stringToReplace, string stringToReplaceWith, int findNthOccurrence) { //if 4th param is null (0), will replace first instance of string
		int inc = 0;
		int nth = mainString.find(stringToReplace);
		while (nth != string::npos) {
			if (inc == findNthOccurrence) {
				break;
			}
			else {
				nth = mainString.find(stringToReplace, nth + stringToReplace.size());
				inc++;
			}
		}
		mainString.replace(nth, stringToReplace.size(), stringToReplaceWith);
	}
	void splitString(string mainString, vector<string>& vec, string stringToSplitWith) {
		int fPos = 0;
		int lPos = mainString.find(stringToSplitWith);
		while (lPos != string::npos) {
			vec.push_back(mainString.substr(fPos, lPos - fPos));
			fPos = lPos + stringToSplitWith.size();
			lPos = mainString.find(stringToSplitWith, fPos);
		}
		vec.push_back(mainString.substr(fPos));
	}
	int numofstr(string main, string numOf) {
	    int find = -1;
	    int j = 0;
	    while ((find = main.find(numOf, find + 1)) != string::npos) j++;
	    return j;
	}
	bool isnum(string mainString) {
		return mainString.find_first_not_of("0123456789") == string::npos;
	}
	void removeNonInt(string& mainString) {
		int pos = 0;
		string tempMain = "";
		while (pos != mainString.size()) {
			if (isnum(string(1, mainString[pos]))) {
				tempMain.append(string(1,mainString[pos]));
			}
			pos++;
		}
		mainString = tempMain;
	}
        void reverse(std::string & string) {
	    std::string ts;
	    for (int i = 0; i < string.size(); i++) {
	        ts += string[string.size() - 1 - i]; // size - 1 cuz size returns starting from 1 but index starts from 0 so ye
	    }
	    string = ts;
	}
	void encrypt(std::string& data) {
	    std::string td;
	    for (int i = 0; i < data.size(); i++) {
	        char fc = data[i];
	        int sc = (int)fc;
	        std::string ti = std::to_string(sc - 1);
	        int tioti = std::stoi(ti);
	        td += (char)tioti;
	    }
	    reverse(td);
	    data = td;
	}
	void decrypt(std::string& data) {
	    std::string td;
	    for (int i = 0; i < data.size(); i++) {
	        int fc = (int)data[i];
	        std::string ti = std::to_string(fc + 1);
	        int tioti = std::stoi(ti);
	        td += (char)tioti;
	    }
	    reverse(td);
	    data = td;
	}
}
