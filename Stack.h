//œ∞Ã‚4.1

//#include<string>
//#include<vector>
//using namespace std;
//class Stack {
//public:
//	bool push(const string&);
//	bool pop(string& elem);
//	bool peek(string& elem);
//	
//	bool empty() const
//	{
//		return _stack.empty();
//	}
//	bool full()
//	{
//		return _stack.size() == _stack.max_size();
//	}
//	int size()const
//	{
//		return _stack.size();
//	}
//private:
//	vector<string>_stack;
//};






//œ∞Ã‚4.2
#include<string>
#include<vector>
using namespace std;
class Stack {
public:
	bool push(const string&);
	bool find(const string& elem)const;
	int count(const string& elem)const;
	bool empty() const
	{
		return _stack.empty();
	}
	bool full()
	{
		return _stack.size() == _stack.max_size();
	}
	int size()const
	{
		return _stack.size();
	}
private:
	vector<string>_stack;
};