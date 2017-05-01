#include <iostream>
#include <vector>
using namespace std;


void Adjust (vector<string>& s) {
	while (true) {
		int width;
		int begin;
		int words;
		words = 0;
		begin = 0;
		vector<string>oneline;
		//Get user input of width
		cout << "Enter the width of text: " ;
		cin >> width;
		if (width == 0) {
			break;
		}
		//Print top border
		for (int i = 0; i < width; ++i) {
			if (i == 0) cout << "|" ;
			cout << "-" ;
			if (i == width - 1) cout << "|" << endl ;
		}
		//Go through all of the words
		for (int i = 0, len = s.size(); i < len; ++i) {
			int space;
			int white;

			words += s[i].length();
			space = i - begin;
			white = words + space;

			//Check for space to push_back into oneline and for last line of input
			if (width - white >= 0) {
				oneline.push_back(s[i]);
				if (i == len - 1) {
					white = width - words;

					//Push whitespaces in
					while (white > 0) {
						for (int j = 0, vlen = oneline.size(); j < vlen; ++j) {
							if (white == 0) {
								break;
							}
							oneline[j] += " ";
							white -= 1;
						}
					}


					//Print oneline
					for (int j = 0, ven = oneline.size(); j < ven; ++j) {
						if (j == 0) cout << "|";
							cout << oneline[j];
						if (j == ven - 1) cout << "|" << endl;
					}
					//Reset variables
					oneline.clear();
					begin = i;
					words = 0;
				}
			}

			//Check if line still has room
			if (width - white < 0)  {
				white = width - (words - s[i].length());

				//Push whitespaces in
				while (white > 0) {
					for (int j = 0, vlen = oneline.size(); j < vlen; ++j) {
						if (white == 0 || j == vlen - 1) {
							break;
						}
						oneline[j] += " ";
						white -= 1;
					}
				}

				//Print oneline
				for (int j = 0, ven = oneline.size(); j < ven; ++j) {
					if (j == 0) cout << "|";
					cout << oneline[j];
					if (j == ven - 1) cout << "|" << endl;
				}
				//Reset variables
				oneline.clear();
				begin = i;
				words = 0;
				i -= 1;
			}
		}
		//Print bottom border
		for (int i = 0; i < width; ++i) {
			if (i == 0) cout << "|" ;
			cout << "-" ;
			if (i == width - 1) cout << "|" << endl;
		}
	}
}

int main() {
	string sentence;
	vector<string>paragraph;
		cout << "Enter text, empty return will quit the input" << endl << "> ";
		while(getline(cin,sentence)) {
			string word;

			if (sentence == "") {
				break;
			}

			cout << "> ";
			for (int i = 0, len = sentence.length(); i < len; ++i) {

				if (sentence[i] != ' ' && sentence[i] != '\t' ) {
					word += sentence[i];
				}

				if ((i != 0 && sentence[i] == ' ' && sentence[i-1] != ' ') || i == len - 1){
				paragraph.push_back(word);
				word.clear();
				}
			}
		}
		Adjust(paragraph);	//adjust the input


	return 0;
}
