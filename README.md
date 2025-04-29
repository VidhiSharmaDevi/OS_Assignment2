# OS_Assignment2

Banker's algorithm - Deadlock avoidance
This project implements the Banker's Algorithm in C for deadlock avoidance. It determines whether a system is is a safe state and output the safe sequence if it's in a safe state. 
- 5 Processes -> P0 - P4
- 3 Resources -> A, B, C
- Each resource has a n number of instances
## Key Technologies Used
- File Handling
- GitHub
- C 
## Designing resource matrices
The system uses these structures:
- int available [3]
- int max [5][3];
- int allocation [5][3];
- int need [5][3];
Where:
- available is the number of instances available of resource i
- max is the maximum demand of process i for resource j
- allocation is the resources currently held by process i
- need is max - allocation
## Setting up input file
- Available resources: 3 3 2
- Allocation matrix:

0 1 0
  
2 0 0

3 0 2

2 1 1

0 0 2
- Max matrix:

7 5 3
  
3 2 2

9 0 2

2 2 2

4 3 3

## Implementing the Banker's Algorithm
1. Calculate the Need matrix
2. Find a process whose need can be satisfied with available resources
3. If such process is found:
	a. Assume it finishes (add its allocation back to available)
	b. Mark it as finished
	c. Add it to the safe sequence
4. Repeat until all processes are finished or no safe process is found
Key functions used:
bool isSafe(int available[], int max[][3], int allocation[][3], int n, int m)
## Example of safe sequence output
If the system is safe, the output will look like:
"System is in safe state"
"Safe sequence is: P1 P3 P4 P0 P2"
If the system is not safe:
"System is not in a safe state"
## Compilation and execution
gcc main.c -o banker

./banker

