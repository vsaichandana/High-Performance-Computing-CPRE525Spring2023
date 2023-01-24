"""
Author: Saichandana V
Purpose: Lab Assignment 3
Submitted: 01/24/2023
This code demonstrates how to use the append(), insert(), remove(), index(), count(), sort(), and reverse() methods on a list. Each method is used, and the resulting list is printed after each method call."""

# Initialize a list with both numbers and strings
my_list = [1, 2, "apple", "banana", 3, "orange"]

# Use the append method to add an element to the end of the list
my_list.append("kiwi")
print("Updated list after append:", my_list)

# Use the insert method to add an element at a specific index
my_list.insert(2, "mango")
print("Updated list after insert:", my_list)

# Use the remove method to remove a specific element
my_list.remove("banana")
print("Updated list after remove:", my_list)

# Use the index method to find the index of a specific element
index = my_list.index("orange")
print("Index of 'orange':", index)

# Use the count method to find the number of occurrences of an element
count = my_list.count(2)
print("Count of 2:", count)

# Use the sort method to sort the list
my_list = [str(i) for i in my_list]
my_list.sort()
print("Sorted list:", my_list)

# Use the reverse method to reverse the order of the list
my_list.reverse()
print("Reversed list:", my_list)

# my_list = [1, 2, 3, 4, 5, 'a', 'b', 'c']
#
# # Append method
# my_list.append(6)
# print("Append: ", my_list)
#
# # Insert method
# my_list.insert(2, 'd')
# print("Insert: ", my_list)
#
# # Extend method
# my_list.extend([7, 8, 9])
# print("Extend: ", my_list)
#
# # Remove method
# my_list.remove(4)
# print("Remove: ", my_list)
#
# # Pop method
# my_list.pop(5)
# print("Pop: ", my_list)
#
# # Clear method
# my_list.clear()
# print("Clear: ", my_list)
#
# # Index method
# my_list = [1, 2, 3, 4, 5, 'a', 'b', 'c']
# print("Index: ", my_list.index(3))
#
# # Count method
# my_list = [1, 2, 3, 4, 5, 'a', 'b', 'c']
# print("Count: ", my_list.count(1))
#
# # Sort method
# my_list = [1, 2, 3, 4, 5, 'a', 'b', 'c']
# my_list.sort()
# print("Sort: ", my_list)
#
# # Reverse method
# my_list = [1, 2, 3, 4, 5, 'a', 'b', 'c']
# my_list.reverse()
# print("Reverse: ", my_list)
