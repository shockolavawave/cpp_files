#include<iostream>
#include<cstdlib>
#include<climits>

int main(){
	
	int size, j, k;
	long long int num, i, i_count, con, *fac, *left, *right;
	
	// to scope of the program is kept within 0 till LLONG_MAX
	/* --- int:
		   size					size of *fac
		   j, k 				used in loops or sizes of *left and *right
		   
		   long long int:
		   num					holds the input from user
		   i					used in loop but lli type is needed
		   						to increase the scope of the calculations
		   i_count				count iterations (just for the record)
		   con					conjugate - used while recording the factors
		   *fac, *left, *right 	these are used for dynamic memory allocation
	--- */
	
	std::cout << "Enter a positive number: ";
	std::cin >> num;
	
	if(std::cin.fail() || isalpha(num)){
		std::cout << "Invalid input! The input should only be a single integer." << std::endl
				  << "Exiting..." << std::endl;
		exit(0);
	}
	
	if(num<0){				//if num is negative
		std::cout << std::endl << "The entered number is negative." << std::endl
				  << "Exiting..." << std::endl;
		exit(0);
	}

	if(num==LLONG_MAX){
		std::cout << "Input too huge to be computed for this system." << std::endl
				  << "Exiting..." << std::endl;
		exit(0);
	}
	
	if(!num){				//if num is 0
		std::cout << std::endl << "0 has infinite factors." << std::endl;
		exit(0);
	}
	
	if(num==1){				//if num is 1
		std::cout << std::endl << "1 is neither prime nor composite." << std::endl;
		std::cout << "Hence, 1 is its own factor." << std::endl;
		exit(0);
	}
	
	//creating first element
	fac = (long long int*)calloc(1, sizeof(long long int));
	
	//recording the factors
	con = num;							//con starts with num and then becomes lesser after every hit
	for(i=1,size=0;	i<con; i++){		//use of con will help reduce the number of iterations
		
		if(!(num%i)){
			fac = (long long int*)realloc(fac, (size+2)*sizeof(long long int));
			
			if(fac==NULL){					//checking for memory availability
				std::cout <<"Running out of memory." << std::endl << "Exiting..." << std::endl;
				exit(0);
			}
			
			fac[size] = i;					//assigning the number
			fac[size+1] = num/i;			//assigning its conjugate to the next element, later sorted
			con = num/i;
			size+=2;
		}
		
		if(i>(num/2))					// factors beyond num/2 are illogical
			break;
	}
	
	i_count = i;
	//if only 1 is the factor| a automatically becomes 2, hence a prime number
	if(size==2){
		std::cout << std::endl << "The entered number is a prime number." << std::endl
				  << "No. of iterations: " << i_count << std::endl;
		exit(0);
	}
	
	left = (long long int*)calloc((size/2), sizeof(long long int));
	right = (long long int*)calloc((size/2), sizeof(long long int));
	
	//sorting even to left| odd to right
	for(i=j=k=0; i<size; i++){
		
		if(!(i%2)){
			left[j] = fac[i];
			j++;
		}else{
			right[k] = fac[i];
			k++;
		}
	}
	
	//putting left in ascending fashion and
	//right is decending fashion infac again
	for(j=0,k=(size/2); j<size;	j++){
		
		if(j<(size/2))				//first fill the left half
			fac[j] = left[j];
		else{						//then fill the right half in reverse
			k--;
			fac[j] = right[k];
		}
	}
	
	//freeing left and right
	free(left); free(right);
	
	//if num is a perfect square, a duplicate factor is recorded
	//removing redundancies
	for(j=k=0; j<size; j++,k++){
		
		if(fac[j]==fac[j+1]){
			k++;
			size--;		//size should reduce for every hit
		}
		
		fac[j] = fac[k];
	}
	
	//resizing fac
	fac = (long long int*)realloc(fac, size*(sizeof(long long int)));
	
	//displaying the recorded factors
	std::cout << std::endl << "The factors of " << num << " are:" << std::endl << std::endl;
	for(j=0; j<size; j++){
		
		std::cout << fac[j] << "  ";
		
		if(!(j%5))						//for better readability
			std::cout << std::endl;
	}
	
	//freeing up fac
	free(fac);
	std::cout << std::endl << std::endl << "There are total number of " << size << " factors." << std::endl
			  << "(No. of iterations: " << i_count << " )"<< std::endl;
	
	return 0;
}
