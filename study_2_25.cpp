//œ∞Ã‚4.1

//#include "Stack.h"
//#include<iostream>
//#include<algorithm>
//using namespace std;
//bool Stack::pop(string& elem)
//{
//	if (empty())
//		return false;
//	elem = _stack.back();
//	_stack.pop_back();
//	return true;
//}
//bool Stack::peek(string& elem)
//{
//	if (empty())
//		return false;
//	elem = _stack.back();
//	return true;
//}
//bool Stack::push(const string& elem)
//{
//	if (full())
//		return false;
//	_stack.push_back(elem);
//	return true;
//}
//bool Stack::find(const string& elem)const
//{
//	vector<string>::const_iterator end_it = _stack.end();
//	return ::find(_stack.begin(), end_it, elem) != end_it;
//}
//int Stack::count(const string& elem)const
//{
//	return ::count(_stack.begin(), _stack.end(), elem);
//}
//int main()
//{
//	Stack st;
//	string str;
//	while (cin >> str && !st.full())
//		st.push(str);
//	if (st.empty())
//	{
//		cout << '\n' << 
//			"Oops:no strings were read __bailing put\n";
//		return 0;
//	}
//	st.peek(str);
//	if (st.size() == 1 && str.empty())
//	{
//
//		cout << '\n' <<
//			"Oops:no strings were read __bailing put\n";
//		return 0;
//	}
//	cout << '\n' << "Read in " << st.size() << "string!\n"
//		<<"The strings,in reverse order:\n";
//	while (st.size())
//	{
//		if (st.pop(str))
//			cout << str << ' ';
//
//	}
//	cout << '\n' << "There are now " << st.size()
//		<< " elements in the stack!\n";
//}






//œ∞Ã‚4.2
#include "Stack.h"
#include<iostream>
#include<algorithm>
using namespace std;

bool Stack::push(const string& elem)
{
	if (full())
		return false;
	_stack.push_back(elem);
	return true;
}
bool Stack::find(const string& elem)const
{
	vector<string>::const_iterator end_it = _stack.end();
	return ::find(_stack.begin(), end_it, elem) != end_it;
}
int Stack::count(const string& elem)const
{
	return ::count(_stack.begin(), _stack.end(), elem);
}
int main()
{
	Stack st;
	string str;
	while (cin >> str && !st.full())
		st.push(str);
	if (st.empty())
	{
		cout << '\n' <<
			"Oops:no strings were read __bailing put\n";
		return 0;
	}
	if (st.size() == 1 && str.empty())
	{

		cout << '\n' <<
			"Oops:no strings were read __bailing put\n";
		return 0;
	}
	cout << '\n' << "Read in " << st.size() << "string!\n";
	cin.clear();
	cout << "what word to search for?";
	cin >> str;
	bool found = st.find(str);
	int count = found ? st.count(str) : 0;
	cout << str << (found ? " is" : " isn\'t") << " in the stack.";
	if (found)
		cout << "it occurs " << count << "times.\n";

}