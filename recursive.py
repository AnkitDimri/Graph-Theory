# Recursive Algorithm for checking whether a given degree sequence is graphical or not.
# Also, count the number of recursive calls that will be made for each input degree sequence.
# Implementation in Python

# Author: AKSHAY JAIN github: httos://www.github.com/akshayjain3450

# ALGORITHM
# S = d1,d2,d3,...,dn
# 1. If any d[i] >= n then fail
# 2. If there is an odd number of odd degrees then fail
# 3. if there is a d[i] < 0 then fail
# 4. if all d[i] = 0 then report success
# 5. reorder S into non-increasing order
# 6. Let k = d[i]
# 7. Remove d[i] from S
# 8. Subtract 1 from the first k terms of the remaining sequence
# 9. Go to step 3 above


def degree_sequence(sequence,counter): #recursive function
	for i in sequence: #check if any member in sequence is negative. if yes graph is not possible
		if i < 0:
			print("Graphical representation not possible")
			print("Recursive Call",counter)
			exit()

	result = check(sequence)

	if result == True:
		print("Graphical representation is possible")
		print("Recursive Call",counter)
		exit()

	sorted_sequence = sorting(sequence)

	key = sorted_sequence[0] #key to note how many elements in the squence needs to be decremented

	sorted_sequence.pop(0) #remove the first element

	for i in range(0,key):
		sorted_sequence[i] = sorted_sequence[i] - 1 #decrease each element by 1

	return degree_sequence(sorted_sequence,counter + 1)

def sorting(temp): # function to sort the sequence in non-asscending order
	temp.sort(reverse = True) #sequence sorted in non-asscending order
	return temp

def check(temp): #check if all elements are zero, if yes graph is possible
	for i in temp:
		if i != 0:
			return False
	return True

sequence = [] #Create a empty list for user input of sequence

number = int(input("Enter the number of the elements you want in sequence: ")) #input for sequence

print("Enter the sequence: ")

for i in range(0,number): #iterate for entering elements
	element = int(input())
	sequence.append(element)

print("Sequence Entered: ")
print(sequence) #sequence entered

for i in sequence: #To check if degree of any vertice is greater than equal to the number of vertices
	if i >= number:
		print("Atleast one vertice has degree greater or equal to the number of elements in the sequence")
		exit()

count_odd = 0
for i in sequence: #If the number of verties having odd degree are odd
	if i % 2 == 1:
		count_odd = count_odd + 1

if count_odd % 2 == 1:
	print("There are odd number of vertices having odd degree")
	exit()

counter = 1

degree_sequence(sequence,counter)
