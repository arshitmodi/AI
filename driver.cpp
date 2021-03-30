#include <iostream>
#include "markov.cpp"
#include "HMM.cpp"

using namespace std;

void hidden_markov()
{	
	int num_hidden_states;
	int num_observable_states;
	
	cout << endl << "Enter the number of hidden states: ";
	cin >> num_hidden_states;
	cout << "Enter the number of observable states: ";
	cin >> num_observable_states;
	
	HMM model(num_hidden_states, num_observable_states);
	
	cout << endl << "Enter 1 for problem 1, 2 for problem 2, 3 for problem 3, or 0 to exit Hidden Markov Model." << endl;
	
	int option;
	
	while(1)
	{
		cout << endl << "Enter the desired option: ";
		cin >> option;
		
		switch(option)
		{
			case 0:
			return;
			
			case 1:
			{
				double probability = model.forward();
				cout << endl << "The probability of the given observation sequence is: " << probability << endl;
				break;
			}
		
			case 2:
			{
				vector <string> most_probable_states = model.Viterbi();
				cout << endl << "The most probable sequence of hidden states is: ";
				for(string & s: most_probable_states)
				{
					cout << s << " ";
				}
				cout << endl;
				break;
			}
		
			case 3:
			{
				cout << endl << "Enter the desired number of iterations: " << endl;
				int num_iterations;
				cin >> num_iterations;
				model.backward(num_iterations);
				break;
			}
		}
	}
}

int main()
{
	cout << endl << "1 - Markov Model" << endl;
	cout << "2 - Hidden Markov Model" << endl;
	cout << "3 - Markov Decision Process" << endl;
	cout << "4 - Kalman Filter" << endl;
	
	int option;
	
	while(1)
	{
		cout << endl << "Enter the desired option. Enter 0 to exit: ";
		cin >> option;
		
		switch(option)
		{
			case 0:
			return 0;
			
			case 1:
			{
				
				break;
			}
			
			case 2:
			{
				hidden_markov();
				break;
			}
			
			case 3:
			break;
			
			case 4:
			break;
		}
	}
}