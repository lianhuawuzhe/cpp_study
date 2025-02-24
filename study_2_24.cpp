//习题3.
//#include<map>
//#include<set>
//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//void initalize_exclusion_set(set<string>&);
//void process_file(map<string,int>&, const set<string>&,ifstream&);
//void user_query(const map<string, int>&);
//void display_word_count(const map<string, int>&, ofstream&);
//int main()
//{
//	ifstream ifile("C:\\My Document\\column.txt");
//	ofstream ofile("C:\\My Document\\column.map");
//	if (!ifile || !ofile)
//	{
//		cerr << "Unable to open file -- baling out!\n";
//		return -1;
//	}
//	set<string>exclude_set;
//	initalize_exclusion_set(exclude_set);
//
//	map<string, int>word_count;
//	process_file(word_count, exclude_set,ifile);
//	user_query(word_count);
//	display_word_count(word_count, ofile);
//	return 0;
//}
//void initalize_exclusion_set(set<string>&exs)
//{
//	static string _exclude_words[25] = {
//		"the","and","but","that","then",
//		"are","been","can","a","could",
//		"did","for","of","had","have",
//		"him","his","her","its","is",
//		"were","which","when","with","would"
//
//	};
//	exs.insert(_exclude_words, _exclude_words + 25);
//}
//void process_file(map<string, int>& word_count,
//	const set<string>& exclude_set,  ifstream& ifile)
//{
//	string word;
//	while (ifile >> word)
//	{
//		if (exclude_set.count(word))
//			continue;
//		word_count[word]++;
//	}
//}
//void user_query(const map<string, int>& word_map)
//{
//	string search_word;
//	cout << "Please enter a word to search :( q to quit)";
//	cin >> search_word;
//	while (search_word.size()&&search_word!="q")
//	{
//		map<string, int>::const_iterator it;
//		if ((it = word_map.find(search_word)) != word_map.end())
//			cout << "Found! " << it->first << " occurs " << it->second << " times.";
//		else cout << "\nAnother search?(q t quite)";
//		cin >> search_word;
//		
//	}
//
//}
//void display_word_count(const map<string, int>& word_map,
//	ofstream& os)
//{
//	map<string, int>::const_iterator iter = word_map.begin(),
//		end_it = word_map.end();
//	while (iter != end_it)
//	{
//		os << iter->first << "("
//			<< iter->second << ")" << endl;
//		++iter;
//	}
//	os << endl;
//}






//习题3.2
//#include<iostream>
//#include<fstream>
//#include<string>
//#include<vector>
//#include<algorithm>
//using namespace std;
//template<typename elemType>
//
//void display_vector(const vector<elemType>&vec,
//	ostream&os=cout,int len=8)
//{
//	typename vector<elemType>::const_iterator iter = vec.begin(),
//		end_it = vec.end();
//	int elem_cnt = 1;
//	while (iter != end_it)
//	{
//		os << *iter++
//			<< (!(elem_cnt++ % len) ? '\n':' ');
//	}
//	os << endl;
//}
//class LessThan
//{
//public:
//	bool operator()(const string& s1, const string& s2)
//	{
//		return s1.size() < s2.size();
//	}
//};
//int main()
//{
//	ifstream ifile("C:\\My Document\\MooCat.txt");
//	ofstream ofile("C:\\My Document\\MooCat.sort");
//	if (!ifile || !ofile)
//	{
//		cerr << "Unable to open file--bailing out!\n";
//		return -1;
//	}
//	vector<string>text;
//	string word;
//	while (ifile >> word)
//		text.push_back(word);
//	sort(text.begin(), text.end(), LessThan());
//	display_vector(text, ofile);
//
//	return 0;
//}



//习题3.3
#include<map>
#include<string>
#include<vector>
#include<iostream>
#include<fstream>
#include<algorithm>
using namespace std;
typedef vector<string>vstring;
void populate_map(ifstream& nameFile, map<string, vstring>& families)
{
	string textline;
	
	while (getline(nameFile, textline))
	{
		string fam_name;
		vector<string>child;
		string::size_type pos = 0, prev_pos = 0,
			text_size = textline.size();
		while ((pos = textline.find_first_of(' ', pos)) 
			!= string::npos)
		{
			string::size_type end_pos = pos - prev_pos;
			if (!prev_pos)
				fam_name = textline.substr(prev_pos, end_pos);
			else child.push_back(textline.substr(prev_pos, end_pos));
			prev_pos = ++pos;
		}
		if (prev_pos < text_size)
			child.push_back(textline.substr(prev_pos, pos-prev_pos));
		if (!families.count(fam_name))
			families[fam_name] = child;
		else cerr<<"Oops!we already have a"
			<< fam_name << "family in our map!\n";
	}
}
void display_map(const map<string, vstring>& families, ostream& os)
{
	map<string, vstring>::const_iterator
		it = families.begin(),
		end_it = families.end();
	while (it != end_it)
	{
		os << "The " << it->first << "family";
		if (it->second.empty())
			os << "has no children.";
		else 
		{
			os << "has" << it->second.size() << "children.\n";
			vector<string>::const_iterator
				iter = it->second.begin(),
				end_iter = it->second.end();
			while (iter != end_iter)
			{
				os << *iter << " ";
				++iter;
			}
		}
	}
}
void query_map(const string& family, 
	const map < string, vstring>& families)
{
	map<string, vstring>::const_iterator
		it = families.find(family);
		if (it == families.end())
		{
			cout << "Sorry.The " << family
				<< "is mt currently entered.\n";
			return;
		}
		cout << "The " << family;
		if (!it->second.size())
			cout << "has no children.\n";
		else
		{
			cout << "has" << it->second.size() << "children:";
			vector<string>::const_iterator
				iter = it->second.begin(),
				end_iter = it->second.end();
			while (iter != end_iter)
			{
				cout << *iter << " ";
				++iter;
			}
			cout << endl;

		}
}
int main()
{
	map<string, vstring>families;
	ifstream nameFile("C:\\My Dcument\\families.txt");
	if (!nameFile)
	{
		cerr << "Unable to find families.txt file.\n ";
		return -1;
	}
	populate_map(nameFile, families);
	string family_name;
	while (1)
	{
		cout << "Please enter a family name or q to quit.";
		cin >> family_name;
		if (family_name == "q")
			break;
		query_map(family_name, families);
	}
	display_map(families, cout);

	return 0;
}








//习题3.4
//#include<iterator>
//#include<vector>
//#include<iostream>
//#include<algorithm>
//#include<fstream>
//using namespace std;
//class even_elem {
//public:
//	bool operator()(int elem)
//	{
//		return elem % 2 ?false:true;
//	}
//};
//int main()
//{
//	//创建
//	ofstream even_file("C:\\My Document\\even_file"),
//		odd_file("C:\\My Document\\odd_file");
//	if (!even_file || !odd_file)
//	{
//		cerr << "arghh!unable to open the output files.bailing out!";
//		return -1;
//	}
//	//读取到input
//	vector<int>input;
//	istream_iterator<int> in(cin), eos;
//	copy(in, eos, back_inserter(input));
//	//区分
//	vector<int>::iterator division = partition(input.begin(),
//		input.end(), even_elem());
//	
//	//写入
//	ostream_iterator<int>even_iter(even_file, "\n"),
//		odd_iter(odd_file," ");
//	copy(input.begin(), division, even_iter);
//	copy(division, input.end(), odd_iter);
//
//}
