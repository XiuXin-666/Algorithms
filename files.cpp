//#include <iostream>
//#include <stdio.h>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//int main() {
//	int n; // 需要操作的次数
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
//					start = files.erase(start);//删除元素之后，就会返回指向删除元素的后一位的迭代器，所以不要在for循环中加start++
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