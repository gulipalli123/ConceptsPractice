#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

bool comp(int x, int y)
{
	return x > y;
}

void vectorDemo()
{
	vector<int> A{ 1,5,7,2,3 };

	std::cout << "A[2] = " << A[2] << std::endl;
	sort(A.begin(), A.end());

	bool present = binary_search(A.begin(), A.end(), 5);

	std::cout << "present=" << present << std::endl;

	A.push_back(80);
	A.push_back(90);
	A.push_back(95);
	A.push_back(100);
	A.push_back(123);

	vector<int>::iterator it = lower_bound(A.begin(), A.end(), 100);
	std::cout << "it=" << *it << std::endl;
	vector<int>::iterator it2 = upper_bound(A.begin(), A.end(), 100);
	std::cout << "it2 =" << *it2 << std::endl;

	sort(A.begin(), A.end(), comp);
	for (int& x : A)
		x++;
	for(int x : A)
		std::cout << x << " ";
	std::cout << std::endl;
}
void setsDemo()
{
	set<int> S;
	S.insert(1);
	S.insert(5);
	S.insert(2);
	S.insert(-1);
	S.insert(-10);

	for (int i : S)
		std::cout << i << " ";
	std::cout << "\n";
	std::cout << *S.lower_bound(-1) << "\n";
	std::cout << *S.upper_bound(-1) << "\n";
	auto it = S.upper_bound(5);
	if (it == S.end())
		std::cout << "not in range" << std::endl;
	auto it1 = S.find(-1);
	if (it1 != S.end())
		std::cout << *it1 << "\n";
}
//problem on intervals
void desired_interval(int x)
{
	set<pair<int, int>> S;
	S.insert({ 2,5 });
	S.insert({ 10,230 });
	S.insert({ 25,60 });
	S.insert({ 65, 90 });

	//Find the interval where a given number is present
	auto  p = pair<int, int>(x, INT16_MAX);
	auto it = S.upper_bound(p);
	if (it == S.begin())
		cout << "element is not present" << endl;
	it--;
	pair<int, int> p1 = *it;
	if (p1.first <= x && x <= p1.second)
		cout << "element is present in" << p1.first << " " << p1.second;
	else
		cout << "element is not present" << endl;

}
/*int main()
{
	vectorDemo();
	setsDemo();
	desired_interval(26);
}*/