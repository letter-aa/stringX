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
		mainString.replace(mainString.find(stringToReplace, findNthOccurrence), stringToReplace.size(), stringToReplaceWith);
	}
	void splitString(string mainString, vector<string> &vec, string stringToSplitWith) {
        int fPos = 0;
        int lPos = mainString.find(stringToSplitWith);
        while (lPos != string::npos){
            vec.push_back(mainString.substr(fPos,lPos - fPos));
            fPos = lPos + stringToSplitWith.size();
            lPos = mainString.find(stringToSplitWith,fPos);
        }
        vec.push_back(mainString.substr(fPos));
    }
    int numOfStr(string mainString, string strToCount){
        int amount = 0;
	    string tempMain = mainString;
	    while(tempMain.find(strToCount) != string::npos){
	        //cout << mainString;
	        if(string(1, tempMain[0]) == strToCount){
	            tempMain = tempMain.substr(1);
	            amount++;
	        } else {
	            tempMain = tempMain.substr(1);
	        }
	    }
	    return amount;
    }
}
