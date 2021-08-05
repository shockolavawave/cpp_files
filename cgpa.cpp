#include<iostream>
#include<iomanip>

typedef class{
	public:
		std::string name;
		int marks;
		int max;
		int credits;
		int percent;	//percent marks
		int points;
		char grad;
	
}mem;

std::string toUpper(std::string str){
	int i;
	for(i = 0; i < str.length(); i++)
		if(islower(str[i]))
			str[i] = toupper(str[i]);
	
	return str;
}
int main(){
	
	int no_sem;
	std::cout << "Enter number of semesters: ";
	std::cin >> no_sem;
	
	if(std::cin.fail() || no_sem < 1){
		std::cout << "Invalid input. Exiting..." << std::endl;
		_exit(0);
	}
	
	int sems[no_sem];
	
	short i, j;
	
	//recording number of subjects in each sem
	for(i = 0; i < no_sem; i++){
		std::cout << std::endl << "Enter the number of subjects for semester_" << (i+1) << ": ";
		std::cin >> sems[i];
		
		if(std::cin.fail() || sems[i] < 1){
			std::cout << "Invalid input. Exiting..." << std::endl;
			_exit(0);
		}
	}
	
	mem **subs = new mem*[no_sem];
	//creating jagged object array
	for(i = 0; i < no_sem; i++)
		subs[i] = new mem[sems[i]];
	
	std::string buff = " ";
	//recording elements
	for(i =0; i < no_sem; i++){
		std::cout << "For semester_" << (i+1) << ": " << std::endl;
		
		for(j = 0; j < sems[i]; j++){
			std::cout << "Enter name of subject_" << (j+1) << ": ";
			std::cin >> buff;
			subs[i][j].name = toUpper(buff);
			
			std::cout << std::endl << "For " << subs[i][j].name << " enter the following:" << std::endl;
			
			std::cout << "marks obtained : ";
			std::cin >> subs[i][j].marks;
			
			if(std::cin.fail() || subs[i][j].marks < 0){	//negative marks not allowed
				std::cout << "Invalid input." << std::endl << "Exiting..." << std::endl;
				_exit(0);
			}
			
			std::cout << "maximum marks  : ";
			std::cin >> subs[i][j].max;
			
			//max should not be less than marks obtanied or not equal to 0
			if(std::cin.fail() || subs[i][j].max < subs[i][j].marks || subs[i][j].marks == 0){
				std::cout << "Invalid input." << std::endl << "Exiting..." << std::endl;
				_exit(0);
			}
			
			std::cout << "credits        : ";
			std::cin >> subs[i][j].credits;
			
			if(std::cin.fail() || subs[i][j].credits < 1){	//negative credits not allowed
				std::cout << "Invalid input." << std::endl << "Exiting..." << std::endl;
				_exit(0);
			}
			
			std::cout << std::endl;
		}
	}
	
	std::cout << "Calculating..." << std::endl << std::endl;
	//calculating percent marks, points and grades
	for(i = 0; i < no_sem; i++){
		for(j = 0; j < sems[i]; j++){
			
			subs[i][j].percent = (int) (((double)subs[i][j].marks / subs[i][j].max) * 100);

			if(subs[i][j].percent < 40)
				subs[i][j].grad = 'F';

			if(subs[i][j].percent >= 40 && subs[i][j].percent <= 45)
				subs[i][j].grad = 'C';

			if(subs[i][j].percent > 45 && subs[i][j].percent <= 55)
				subs[i][j].grad = 'b';

			if(subs[i][j].percent > 55 && subs[i][j].percent <= 65)
				subs[i][j].grad = 'B';

			if(subs[i][j].percent > 65 && subs[i][j].percent <= 75)
				subs[i][j].grad = 'a';

			if(subs[i][j].percent > 75 && subs[i][j].percent <= 85)
				subs[i][j].grad = 'A';

			if(subs[i][j].percent > 85)
				subs[i][j].grad = 'O';

			switch (subs[i][j].grad){
				case 'F': subs[i][j].points = 0; break;
				case 'C': subs[i][j].points = 5; break;
				case 'b': subs[i][j].points = 6; break;
				case 'B': subs[i][j].points = 7; break;
				case 'a': subs[i][j].points = 8; break;
				case 'A': subs[i][j].points = 9; break;
				case 'O': subs[i][j].points = 10; break;
			}
		}
	}
	
	std::cout.precision(2);
	
	//array of all sgpa(s) to be calculated
	double sgpa[no_sem];
	//arrays for storing the sumation of points and credits of respective semester
	int po_sum[no_sem] {0}, cr_sum[no_sem] {0};
	
	int sum = 0, cre = 0;
	for(i = 0; i < no_sem; i++) {
		for(j = 0; j < sems[i]; j++) {
			po_sum[i] += subs[i][j].points * subs[i][j].credits;
			cr_sum[i] += subs[i][j].credits;
		}
		
		sum += po_sum[i];
		cre += cr_sum[i];
		
		sgpa[i] = ((double)po_sum[i] / cr_sum[i]);
		std::cout << "The SGPA for semester_" << (i+1) << " is: " << sgpa[i] << std::endl;
	}
	
	double cgpa = (double)sum / cre;
	std::cout << std::endl << "The CGPA is: " << cgpa << std::endl <<
	
	std::endl << "Thank you for using the program! ^_^" << std::endl;
	
	return 0;
}
