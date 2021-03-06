/******************************************************************************
 Author		: Lichao Ma
 Date  		: Apr 3,2016
 Version	: v0.1
 Description:
	-v0.1	Greedy algorithm for reducing test cases
 *****************************************************************************/

#include <vector>
#include <numeric>
#include <iostream>
#include <memory>
using namespace std;

class Greedy{
public:

//Count the number of test cases in a test suite
size_t getCount(vector<vector<bool> > &tests){
	return tests.size();
}

//Count the number of covered statement in a test case
size_t getCount(vector<bool> test){
	return std::accumulate(test.begin(),test.end(),0);
}

double getCoverage(vector<vector<bool> > &tests,vector<bool> &coverage){
	if(tests.empty()||tests[0].empty())
		return 0;

	// Init the selected test cases
	coverage.resize(tests[0].size(),false);
	double size=coverage.size();
	for(auto &t:tests)
		addTo(t,coverage);
	double num=std::accumulate(coverage.begin(),coverage.end(),0);
	return num/size;
}


// Greedy algorithm to reduce redundant test cases,the reduced cases are
// stored in vector 'selected' .
void reduce(vector<vector<bool> > &tests,vector<bool> &selected){
	// Init the selected test cases
	selected.resize(tests.size(),false);

	if(tests.empty()||tests[0].empty())
		return;

	size_t size=tests[0].size();
	cout<<"size="<<size<<endl;
	// Calculate the coverage of the original test cases
	//std::unique_ptr<vector<bool> > target(new vector<bool>(size));
	vector<bool>  *target=new vector<bool>(size);

	for(auto &t:tests)
		addTo(t,*target);

	// Init the selected with the maximum coverage first
	size_t i=findMaxRow(tests,selected);
	vector<bool> *tested=new vector<bool>(tests[0].size());
	(*tested)=tests[i];  //This line is buggy!
	//std::copy(tests[i].begin(),tests[i].end(),tested.begin());
	selected[i]=true;
	clearTo((*tested),tests);

	// Iteratively select the test cases with the maximum additional coverage
	// until the selected test cases cover all original test cases
	while((*tested)!=(*target)){
		size_t j=findMaxRow(tests,selected);
		addTo(tests[j],(*tested));
		selected[j]=true;
		clearTo((*tested),tests);

		//cout<<"tested size = "<<getCount(tested)<<endl;
	}
	delete target;
}


private:

size_t findMaxRow(	const vector<vector<bool> > &tests,
					const vector<bool> &selected){
	size_t row=0;
	size_t maxNum=0;
	for(size_t i=0;i<tests.size();i++){
		if(!selected[i]){
			size_t num=accumulate(tests[i].begin(),tests[i].end(),0);
			if(num>maxNum){
				row=i;
				maxNum=num;
			}
		}
	}
	return row;
}

void addTo(const vector<bool> &src,vector<bool> &trg){
	for(size_t i=0;i<src.size();i++)
		trg[i]=trg[i]|src[i];
}

void clearTo(const vector<bool> &src,vector<bool> &trg){
	for(size_t i=0;i<src.size();i++)
		trg[i]=trg[i]&(!src[i]);
}

void clearTo(const vector<bool> &src,vector<vector<bool> > &trg){
	for(auto &t:trg)
		clearTo(src,t);
}

};



/*
#include <iostream>
int main(){
	vector<vector<bool> > testCases={
			{ true,  false, true, true,  false, false },
			{ false, true,  true, false, true,  true },
			{ false, false, true, true,  true,  true },
			{ false, false, true, false, true,  false },};

	vector<bool> reducedCases;

	cout<<"Greedy self test\n";

	Greedy g;
	g.reduce(testCases,reducedCases);
	for(auto r:reducedCases)
		cout<<r<<",";
}
*/
