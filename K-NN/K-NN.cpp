#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;


struct Company {

	int gain;  
	int level; 
	int isWinning;
	double distance; 
	Company(int _gain, int _level, bool _isWinning, double _distance = 0) : gain(_gain), level(_level), isWinning(_isWinning)
	{}
};

bool compare(Company f1, Company f2)
{ 
	return (f1.distance < f2.distance);
}

int classifyCompany(vector<Company>& f, int k, Company CompanyToClassify, bool flag)
{

	for (size_t i = 0; i < f.size(); i++)
	{   

		if (!flag)
		{
				f[i].distance = sqrt((f[i].gain - CompanyToClassify.gain) * (f[i].gain - CompanyToClassify.gain) +
				(f[i].level - CompanyToClassify.level) * (f[i].level - CompanyToClassify.level));
		}
		else
		{
			f[i].distance = (abs(f[i].gain - CompanyToClassify.gain) + abs(f[i].level - CompanyToClassify.level));
		}
	}
	std::sort(f.begin(), f.end(), compare); 

	int freq1 = 0;     
	int freq2 = 0;     
	for (int i = 0; i < k; i++)
	{    

		if (f[i].isWinning == 0)
		{
			freq1++;
		}
		else
		{
			freq2++;
		}
	}

	return (freq1 > freq2 ? 0 : 1); 
}

int main()
{


	vector<Company> examples{ Company(1562,100,1), Company(703,100,0), Company(1213,100,0), Company(1471,100,1), Company(1315,100,1), Company(691,100,0), Company(1439,100,1), Company(1458,80,1), Company(1294,80,1), Company(611,80,0),
	 Company(959,80,0), Company(1301,80,1), Company(1076,80,1), Company(1569,80,1), Company(680,80,0), Company(708,50,0), Company(604,50,0), Company(925,50,0), Company(1213,50,0),
	 Company(1471,50,1), Company(1215,50,1), Company(1071,50,0), Company(952,20,1), Company(602,20,0), Company(654,20,0), Company(725,20,0), Company(604,20,0), Company(1256,20,1), Company(1404,20,1), Company(1256,20,1) };


	
	vector<Company> testSet{ Company(982,100,0), Company(1304,100,1),Company(1256,100,1),Company(1377,80,1),Company(675,80,0),
							 Company(978,50,1),Company(600,50,0),Company(654,50,0),Company(1569,20,1),Company(680,20,0)};


	int countSuccessesByEuclidian = 0;
	int countSuccessesByManhattan = 0;
	for (size_t i = 0; i < testSet.size(); i++)
	{
		int result1 = classifyCompany(examples, 21, testSet[i], 0);
		int result2 = classifyCompany(examples, 21, testSet[i], 1);
		cout << "Result from kNN with euclidian is: " << result1 << " the result from kNN with manhattan is: " << result2 << " and the original value is: " << testSet[i].isWinning << endl;
		if (result1 == testSet[i].isWinning) countSuccessesByEuclidian++;
		if (result2 == testSet[i].isWinning) countSuccessesByManhattan++;
	}
	double percentSuccesses = (countSuccessesByEuclidian / (double)testSet.size()) * 100;

	cout << "The number of incorrectly classified examples against the number of correctly classified examples from the test set is:" << "\n"
		<< percentSuccesses << "% - are the correctly classified examples, and the incorrectly - " << 100 - percentSuccesses << "% !" << endl;


	double percentSuccesses1 = (countSuccessesByManhattan / (double)testSet.size()) * 100;

	cout << "The number of incorrectly classified examples against the number of correctly classified examples from the test set is:" << "\n"
		<< percentSuccesses1 << "% - are the correctly classified examples, and the incorrectly - " << 100 - percentSuccesses1 << "% !" << endl;


	return 0;
}