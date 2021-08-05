#include<iostream>
#include<iomanip>

typedef struct{
	int marks;
	int max;
	int credits;
	int perc;
	int point;
	char grad;
}sub;

int main(){
	
	int sub_no, max, i, po_sum, cr_sum;
	
	std::cout << "Enter the number of subjects: ";
	std::cin >> sub_no;
	
	if(std::cin.fail()){
		std::cout << "Invalid input." << std::endl << "Exiting..." << std::endl;
		_exit(0);
	}
	
	//allocating memory for the structure
	sub *stds = new sub[sub_no];
	
	if(stds == NULL){
		std::cout << "Insufficient memory" << std::endl << "Try later." << std::endl;
		_exit(0);
	}
	
	std::cout << std::endl;
	//recording elements
	for(i=0; i<sub_no; i++){
		std::cout << "Enter marks for subject_" << (i+1) << " along with the max marks and credits: ";
		std::cin >> stds[i].marks >> stds[i].max >> stds[i].credits;
		
		if(std::cin.fail() || (stds[i].marks > stds[i].max)){
			std::cout << "Invalid input." << std::endl << "Exiting..." << std::endl;
			_exit(0);
		}
		
		std::cout << std::endl;
	}
	
	//converting marks to percent_maks
	for(i=0; i<sub_no; i++){
		
		stds[i].perc = ((double)stds[i].marks / stds[i].max) * 100;
		
		if(stds[i].perc < 51)
			stds[i].grad = 'F';
		
		if(stds[i].perc > 50 && stds[i].perc < 56)
			stds[i].grad = 'C';
		
		if(stds[i].perc > 55 && stds[i].perc < 61)
			stds[i].grad = 'b';
		
		if(stds[i].perc > 60 && stds[i].perc < 66)
			stds[i].grad = 'B';
		
		if(stds[i].perc > 65 && stds[i].perc < 71)
			stds[i].grad = 'a';
		
		if(stds[i].perc > 70 && stds[i].perc < 81)
			stds[i].grad = 'A';
		
		if(stds[i].perc > 80)
			stds[i].grad = 'O';
		
		switch(stds[i].grad){
			case 'F': stds[i].point = 0; break;
			case 'C': stds[i].point = 5; break;
			case 'b': stds[i].point = 6; break;
			case 'B': stds[i].point = 7; break;
			case 'a': stds[i].point = 8; break;
			case 'A': stds[i].point = 9; break;
			case 'O': stds[i].point = 10; break;
		}
	}
	
	//calculating sum of points and credits
	for(i=po_sum=cr_sum=0; i<sub_no; i++){
		po_sum += stds[i].point * stds[i].credits;
		cr_sum += stds[i].credits;
	}
	
	double sgpa = (double)po_sum/cr_sum;
	
//	std::cout.precision(2);
	std::cout << "The sgpa for the given stdudent and corresponding values is " << sgpa << std::endl << std::endl
			  << "Thank you for using the program" << std::endl;
	
	return 0;
}