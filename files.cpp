//#include <iostream>
//#include <stdio.h>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int main() {
//	int n; // ��Ҫ�����Ĵ���
//	cin >> n;
//	vector<string> files;
//	vector<string> commands(n);
//	for (int i = 0; i < n; i++) {
//		cin >> commands[i];
//		if (commands[i] == "touch") {
//			string file;
//			cin >> file;
//			if (std::find(files.begin(), files.end(), file) == files.end()) {
//				files.push_back(file);
//			}
//		}
//		else if (commands[i] == "rename") {
//			string file;
//			string newfile;
//			cin >> file >> newfile;
//			if (std::find(files.begin(), files.end(), file) != files.end() && std::find(files.begin(), files.end(), newfile) == files.end()) {
//				for (auto start = files.begin(); start != files.end(); ) {
//					if (*start == file) {
//						*start = newfile;
//					}
//					else {
//						start++;
//					}
//				}
//			}
//		}
//		else if (commands[i] == "rm") {
//			string file;
//			cin >> file;
//			if (std::find(files.begin(), files.end(), file) == files.end()) {
//				continue;
//			}
//			for (auto start = files.begin(); start != files.end();) {
//				if (*start == file) {
//					start = files.erase(start);//ɾ��Ԫ��֮�󣬾ͻ᷵��ָ��ɾ��Ԫ�صĺ�һλ�ĵ����������Բ�Ҫ��forѭ���м�start++
//				}
//				else {
//					start++;
//				}
//			}
//		}
//		else if (commands[i] == "ls") {
//			for (string i : files) {
//				cout << i << endl;
//			}
//		}
//	}
//	return 0;
//}