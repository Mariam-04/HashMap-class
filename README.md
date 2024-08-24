What Does This Code Do?
This code creates a basic HashMap (like a dictionary) that can store key-value pairs (like ID and name) and quickly find them later. It includes different ways to handle situations where two keys try to go to the same spot in the map (a problem called "collision").

Main Parts of the Code
HashMap Class:

Stores key-value pairs.
Handles collisions using linear probing (checking the next spot).
Allows you to insert, find, and delete items.
QHashMap Class:

A version of HashMap that uses quadratic probing to handle collisions (jumping further each time).
DHashMap Class:

A version of HashMap that uses double hashing to handle collisions (calculating a new position based on the key).
populateHash Function:

Reads a file and fills the HashMap with data.
How to Use the Code
Compile the Code:

g++ -o hashmap main.cpp
Run the Program:

./hashmap
File Format:

Ensure you have a file called student.txt with lines like:
101 John
102 Alice
What Happens When You Run the Program?
The program reads data from student.txt and stores it in three different hash maps (normal, quadratic, and double hashing).
It then performs some operations, like finding and deleting specific items.
