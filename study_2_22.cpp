//习题2.3
//#include<string>
//#include<iostream>
//#include<vector>
//using namespace std;
//extern void really_calc_elems(vector<int>&, int);
//void display_elems(vector<int>& vec, const string& title, ostream& os = cout);
//bool calc_elems(vector<int>& vec, int pos);
//int main()
//{
//	vector<int>pent;
//	const string title("Pentagonal Numeric Series");
//	if (calc_elems(pent, 0))
//		display_elems(pent, title);
//	if (calc_elems(pent, 8))
//		display_elems(pent, title);
//	if (calc_elems(pent, 14))
//		display_elems(pent, title);
//	if (calc_elems(pent, 138))
//		display_elems(pent, title);
//
//	return 0;
//}
//inline bool calc_elems(vector<int>& vec, int pos)
//{
//	if (pos <= 0 || pos > 64)
//	{
//		cerr << "Sorry.Invalid position:" << pos << endl;
//		return false;
//	}
//	if (vec.size() < pos)
//		really_calc_elems(vec, pos);
//	return true;
//}
//void really_calc_elems(vector<int>&vec, int pos)
//{
//	for (int ix = vec.size() + 1; ix <= pos; ++ix)
//		vec.push_back(ix * (ix * 3 - 1) / 2);
//}
//void display_elems(vector<int>& vec, const string& title, ostream& os)
//{
//	os << '\n' << title << "\n\t";
//	for (int ix = 0; ix < vec.size(); ++ix)
//		os << vec[ix] << ' ';
//	os << endl;
//}








//习题2.4
//#include<vector>
//#include<iostream>
//using namespace std;
//inline bool check_validity(int pos)
//{
//	return (pos <= 0 || pos > 64 ? false : true);
//}
//const vector<int>* pentagonal_series(int pos)
//{
//	static vector<int>_elems;
//	if (check_validity(pos) && (pos > _elems.size()))
//		for (int ix = _elems.size() + 1; ix <= pos; ++ix)
//			_elems.push_back((ix * (ix * 3 - 1)) / 2);
//	return &_elems;
//
//}
//bool pentagonal_elem(int pos, int& elem)
//{
//	if (!check_validity(pos))
//	{
//		cout<<"Sorry.Invalid position:"<<pos<<endl;
//		elem=0;
//		return false;
//	}
//	const vector<int>*pent=pentagonal_series(pos);
//		elem=(*pent)[pos-1];
//		return true;
//}
//int main()
//{
//	int elem;
//	if (pentagonal_elem(8, elem))
//		cout << "element 8 is " << elem << '\n';
//	if(pentagonal_elem(88,elem))
//		cout << "element 88 is " << elem << '\n';
//	if (pentagonal_elem(12,elem))
//		cout << "element 12 is " << elem << '\n';
//	if (pentagonal_elem(64, elem))
//		cout << "element 64 is " << elem << '\n';
//	return 0;
//}







//习题2.5
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
inline int max(int t1, int t2)
{
	return t1 > t2 ? t1 : t2;
}
inline float max(float t1, float t2)
{
	return t1 > t2 ? t1 : t2;
}
inline string  max(const string& t1, const string& t2)
{
	return t1 > t2 ? t1 : t2;

}


inline int max(const vector<int>& vec)
{
	return *max_element(vec.begin(), vec.end());
}
inline float max(const vector<float>&vec)
{
	return *max_element(vec.begin(), vec.end());
}
inline string max(const vector<string>& vec)
{
	return *max_element(vec.begin(), vec.end());
}


inline int max(const int* parray, int size)
{
	return *max_element(parray, parray + size);
}
inline float max(const float* parray, int size)
{
	return *max_element(parray, parray + size);
}
inline string max(const string* parray, int size)
{
	return *max_element(parray, parray + size);
}
int main()
{
	string sarray[] = { "we","were","her","pride","of","ten" };
	vector<string>svec(sarray, sarray + 6);

	int iarray[] = { 12,70,2,169,1,5,29 };
	vector<int>ivec(iarray, iarray + 7);

	float farray[] = { 2.5,24.8,18.7,4.1,23.9 };
	vector<float>fvec(farray, farray + 5);
	int imax = max(max(ivec), max(iarray, 7));
	float fmax = max(max(fvec), max(farray, 5));
	string smax = max(max(svec), max(sarray, 6));


	cout << "imax should be 169--found:" << imax << '\n';
	cout << "fmax should be 24.8--found:" << fmax << '\n';
	cout << "smax should be were--found:" << smax << '\n';

	return 0;
}





//习题2.6
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
template<typename Type>
inline Type Max(Type t1, Type t2)
{
	return t1 > t2 ? t1 : t2;
}
template<typename elemType>
inline elemType Max(const vector<elemType>& vec)
{
	return *max_element(vec.begin(), vec.end());
}
template <typename arrayType>
inline arrayType Max(const arrayType* parray, int size)
{
	return* max_element(parray, parray + size);
}
int main()
{
	string sarray[] = {"we","were","her","pride","of","ten"};
	vector<string>svec(sarray, sarray + 6);

	int iarray[] = { 12,70,2,169,1,5,29 };
	vector<int>ivec(iarray, iarray + 7);

	float farray[] = { 2.5,24.8,18.7,4.1,23.9 };
	vector<float>fvec(farray, farray + 5);
	int imax = Max(Max(ivec), Max(iarray, 7));
	float fmax = Max(Max(fvec), Max(farray, 5));
	string smax = Max(Max(svec), Max(sarray, 6));


	cout << "imax should be 169--found:" << imax << '\n';
	cout << "fmax should be 24.8--found:" << fmax << '\n';
	cout << "smax should be were--found:" << smax << '\n';

	return 0;
}
