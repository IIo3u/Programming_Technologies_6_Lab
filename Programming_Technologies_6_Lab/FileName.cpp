#include <iostream>

using namespace std;

template<std::size_t N> 
void SelectSort(int(&arr)[N])
{

	for (int i = 0; i < N - 1; i++)
	{
		int min_index = i;
		for (int j = i + 1; j < N; j++)
		{
			if (arr[min_index] > arr[j])
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			int temp = arr[min_index];
			arr[min_index] = arr[i];
			arr[i] = temp;
		}
	}
};

template<std::size_t N1, std::size_t N2>
bool SimilarArrays(int(&A)[N1], int(&B)[N2])
{
	int alignments = 0;
	for (int i = 0; i < N1; i++) 
	{
		for (int j = 0; j < N2; j++) 
		{
			if (A[i] == B[j]) 
			{
				alignments++;
			}
		}
	}
	if (alignments >= 10) return true;
	else return false;
}

int main()
{
	int A[10];
	int B[15];

	cout << "Enter data for A array:" << endl;
	for (int i = 0; i < 10; i++) 
	{
	ITERA:
		cin >> A[i];
		if (!cin)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Wrong data, try else." << endl;
			goto ITERA;
		}
	}

	cout << "Enter data for B array:" << endl;
	for (int i = 0; i < 15; i++)
	{
	ITERB:
		cin >> B[i];
		if (!cin)
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Wrong data, try else." << endl;
			goto ITERB;
		}
	}
	cout << endl;

	
	SelectSort(A);
	SelectSort(B);

	bool answer;

	answer = SimilarArrays(A, B);
	if (answer == true) 
	{
		cout << "Answer: true" << endl;
	}
	else 
	{
		cout << "Answer: false" << endl;
	}

}


