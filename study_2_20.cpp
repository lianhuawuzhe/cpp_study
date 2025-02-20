//习题1.4
// 
//#include<iostream>
//#include<string>
//using namespace std;
//int main(){
//	string first_name, last_name;
//	cout << "Please enter your first name:";
//	cin >> first_name;
//	cout << "hi," << first_name
//		<< "Please enter your last_name:";
//	cin >> last_name;
//	cout << "\n";
//	cout << "Hello,"
//		<< first_name << ' ' << last_name
//		<< "… and good bye!";
//	return 0;
//}








//习题1.5

//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//	string user_name;
//	cout << "Please enter your name : ";
//	cin >> user_name;
//	switch (user_name.size())
//	{
//	case 0:
//		cout << "Ah,the user with no name."
//			<< "Well,ok,hi,user with no name\n";
//		break;
//	case 1:
//		cout << "A 1-character name?Hmm,have you read Kafka?:"
//			<< "Hello," << user_name << endl;
//		break;
//	default:
//		cout << "Hello," << user_name
//			<< "--happy to make your acquaintance!\n";
//		break;
//	}
//	return 0;
//}


//#include<iostream>
//#include<cstring>
//#include<iomanip>
//using namespace std;
//int main()
//{
//	const int nm_size = 10;
//	char user_name[nm_size];
//
//	cout << "Please enter your name : ";
//	cin >>setw(nm_size) >> user_name;
//	switch (strlen(user_name))
//	{
//	case 0:
//		cout << "Ah,the user with no name."
//			<< "Well,ok,hi,user with no name\n";
//		break;
//	case 1:
//		cout << "A 1-character name?Hmm,have you read Kafka?:"
//			<< "Hello," << user_name << endl;
//		break;
//	case 9:
//		cout << "That is a very big name,indeed--"
//			<< "We may have needed to shorten it!\n"
//			<< "In any case,\n";
//	default:
//		cout << "Hello," << user_name
//			<< "--happy to make your acquaintance!\n";
//		break;
//	}
//	return 0;
//}






//习题1.6
//#include<iostream>
//#include<vector>
//using namespace std;
//int main()
//{
//	vector<int>ivec;
//	int ival;
//	while (cin >> ival)
//		ivec.push_back(ival);
//	int sum = 0;
//	for ( int ix = 0; ix < ivec.size(); ++ix)
//		sum += ivec[ix];
//	int average = sum / ivec.size();
//	cout << "Sum of " << ivec.size()
//		<< "elements:" << sum
//		<< ".Average:" << average << endl;
//	return 0;
//}


//#include<iostream>
//using namespace std;
//int main()
//{
//	const int array_size = 128;
//	int ia[array_size];
//	int ival, icnt = 0;
//	while (cin >> ival && icnt < array_size)
//		ia[icnt++] = ival;
//	int sum = 0;
//	for (int ix = 0; ix < icnt; ++ix)
//		sum += ia[ix];
//	int average = sum / icnt;
//	cout << "Sum of " << icnt
//		<< "elements:" << sum
//		<< ".Average:" << average << endl;
//	return 0;
//}
//







//习题1.7


//#include<iostream>
//#include<fstream>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//int main()
//{
//	ifstream in_file("C:\\My Document\\text.txt");
//	if (!in_file)
//	{
//		cerr << "oops!unable to open input file\n";
//		return -1;
//	}
//	ofstream out_file("C:\\My Document\\text.sort");
//	if (!out_file)
//	{
//		cerr << "opps!unable to open output file\n";
//		return -2;
//	}
//	string word;
//	vector<string>text;
//	while (in_file >> word)
//		text.push_back(word);
//	int ix;
//	cout << "unsorted text:\n";
//	for (ix = 0; ix < text.size(); ++ix)
//		cout << text[ix] << ' ';
//	cout << endl;
//	sort(text.begin(), text.end());
//	out_file << "sorted text:\n";
//	for (ix = 0; ix < text.size(); ++ix)
//		out_file << text[ix] << ' ';
//	out_file << endl;
//
//	return 0;
//}


//习题1.8

const char* msg_to_usr(int num_tries)
{
	const int rsp_cnt = 5;
	static const char* usr_msg[rsp_cnt] =
	{
		"Go on",
		"Oops",
		"Sorry",
		"Ah",
		"OOO"
	};
	if (num_tries < 0)
		num_tries = 0;
	else
	if (num_tries >= rsp_cnt)
			num_tries = rsp_cnt - 1;
	return usr_msg[num_tries];
}


