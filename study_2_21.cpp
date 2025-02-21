//œ∞Ã‚2.1
//#include<iostream>
//using namespace std;
//extern bool fibon_elem(int, int&);
//bool print(int);
//
//int main()
//{
//	int pos, elem;
//	char ch;
//	bool more = true;
//	while (more)
//	{
//		cout << "Please enter a position:";
//		cin >> pos;
//		if (fibon_elem(pos, elem)&&print(pos))
//		{
//			cout << "element #" << pos
//				<< " is " << elem << endl;
//			
//		}
//		else
//			cout << "Sorry.Could not caculate element #"
//			<< pos << endl;
//		cout << "would you like to try again?(y/n)";
//		cin >> ch;
//		if (ch != 'y' && ch != 'Y')
//			more = false;
//
//	}
//	return 0;
//}
//
//bool fibon_elem(int pos, int& elem)
//{
//	if (pos <= 0 || pos > 1024)
//	{
//		elem = 0;
//		return false;
//	}
//	elem = 1;
//	int n_2 = 1, n_1 = 1;
//	for (int ix = 3; ix <= pos; ++ix)
//	{
//		elem = n_1 + n_2;
//		n_2 = n_1;
//		n_1 = elem;
//	}
//}
//bool print(int pos)
//{
//	if (pos <= 0 || pos > 1024)
//	{
//		cerr << "invaild position:" << pos
//			<< "--cannot handle request\n";
//		return false;
//	}
//	cout << "The Fiboancci sequence for"
//		<< pos << "position:\n\t";
//	switch (pos)
//	{
//	default:
//	case 2:
//		cout << "1 ";
//	case 1:
//		cout << "1 ";
//		break;
//	}
//	int elem;
//	int n_2 = 1, n_1 = 1;
//	for (int ix = 3; ix <= pos; ++ix)
//	{
//		elem = n_1 + n_2;
//		n_2 = n_1;
//		n_1 = elem;
//		cout << elem << (!(ix % 10) ? "\n\t" : " ");
//	}
//	cout << endl;
//	return true;
//}





//œ∞Ã‚2.2
#include<string>
#include<iostream>
#include<vector>
using namespace std;
bool calc_elements(vector<int>& vec, int pos);
void display_elems(vector<int>& vec, const string& title, ostream& os = cout);
int main()
{
	vector<int>pent;
	const string title("Pentagonal Numeric Series");
	if (calc_elements(pent, 0))
		display_elems(pent, title);
	if(calc_elements(pent,8))
		display_elems(pent, title);
	if(calc_elements(pent,14))
		display_elems(pent, title);
	if(calc_elements(pent,138))
		display_elems(pent, title);

	return 0;
}
bool calc_elements(vector<int>& vec, int pos)
{
	if (pos <= 0 || pos > 64)
	{
		cerr << "Sorry.Invalid position:" << pos << endl;
		return false;
	}
	for (int ix = vec.size() + 1; ix <= pos; ++ix)
		vec.push_back(ix*(ix * 3 - 1) / 2);
	return true;
}
void display_elems(vector<int>& vec, const string& title, ostream& os)
{
	os << '\n' << title << "\n\t";
	for (int ix = 0; ix < vec.size(); ++ix)
		os << vec[ix] << ' ';
	os << endl;
}