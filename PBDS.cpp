#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;

// less -> 1 2 3 
// less_equal 1 3 3 4
// greater 4 3 2 1
// greater_equal 4 3 3 1 

// ***************

//  keep the duplicate values use pair<int,int> 

// 1-> value 
// 2-> number of occurences   

// *************

int main (){
pbds p;
p.insert(1);

	// Inserting elements - 1st query
	A.insert(1);
	A.insert(10);
	A.insert(2);
	A.insert(7);
	A.insert(2);


for(auto i:p){
    cout<<i<<'\n';
}

// finding kth element - 4th query
// **********  it returns the ilterator 
	cout << "0th element: " << *A.find_by_order(0) << endl;
	cout << "1st element: " << *A.find_by_order(1) << endl;
	cout << "2nd element: " << *A.find_by_order(2) << endl;
	cout << "3rd element: " << *A.find_by_order(3) << endl;

// ************ finding number of elements smaller than X - 3rd query

// less than n+1 ------->  less than equal to n ***********

//  find greater can be achived using the 
//  A.size() - order_of_key 
//  it tells the 
	cout << "No. of elems smaller than 6: " << A.order_of_key(6) << endl; // 2
	cout << "No. of elems smaller than 11: " << A.order_of_key(11) << endl; // 4
	cout << "No. of elems smaller than 1: " << A.order_of_key(1) << endl; // 0
	cout << endl;


//  larger than equal to x 

cout << "Lower Bound of 6: " << *A.lower_bound(6) << endl;
	cout << "Lower Bound of 2: " << *A.lower_bound(2) << endl;

//  just larger value than x

cout << "Upper Bound of 6: " << *A.upper_bound(6) << endl;
	cout << "Upper Bound of 1: " << *A.upper_bound(1) << endl;
	cout << endl;

	A.erase(1);
	A.erase(11); 
    
    // element that is not present is not affected
}