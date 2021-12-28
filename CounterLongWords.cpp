#include "CounterLongWords.h"
#include<string>
#define DIV " .,;!?"

CounterLongWords::CounterLongWords()
{
	std::string path = "Test1.txt";
	std::string wrd = find(path);
	std::cout << wrd<<"\n";

}

std::string CounterLongWords::find(std::string path)
{
	std::string str = "",strN="", line = "";
	std::ifstream f;
	f.open(path);
	if (f.is_open()) {
		while (getline(f, line, '\0'))
		{
			strN = findMax(line);
			if (str < strN)
				str = strN;
		}
		f.close();
	}
	else
		std::cout << "File was't opened\n";
    return std::string(str);
}



std::string CounterLongWords::findMax(std::string line)
{

	int pos1 = 0, pos2 = 0, i = 0, cnt = 0,numInWrd=0,nMaxCnt = 0;
	char c, cPrev;
	int cntMaxWrd = 0;
	std::string out;
	while (line[i] != '\0') {
		c = line[i];
		if (c == DIV[0] || c == DIV[1] || c == DIV[2] || c == DIV[3] || c == DIV[4] || c == DIV[5] || c == DIV[6]) {
			cPrev = line[i - 1];//если прошлый не раздеилтель
			pos2 = i;
			if (cPrev != DIV[0] && cPrev != DIV[1] && cPrev != DIV[2] && cPrev != DIV[3] && cPrev != DIV[4] && cPrev != DIV[5] && cPrev != DIV[6]) {
				numInWrd = pos2 - pos1;
				if (numInWrd > nMaxCnt) {
					out = line.substr(pos1, pos2 - pos1);
					nMaxCnt = numInWrd;
					cntMaxWrd = 1;
					
				}
				else if (numInWrd == nMaxCnt) {
					std::string check = line.substr(pos1, pos2 - pos1);
					if (check == out) {
						cntMaxWrd += 1;
							
					}
				}

				pos1 = pos2;
			}
		}

		else {
			if (i != 0) {
				if (line[i - 1] == DIV[0] || line[i - 1] == DIV[1] || line[i - 1] == DIV[2]
					|| line[i - 1] == DIV[3] || line[i - 1] == DIV[4] || line[i - 1] == DIV[5]
					|| line[i - 1] == DIV[6]) {
					pos2 = i;
					pos1 = i;
				}
			
			}
		}
		i++;
	}

	std::cout <<"count of words " << cntMaxWrd << "\n";
	return std::string(out);
}

