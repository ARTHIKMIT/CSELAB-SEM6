"""
7. Write a Python class which has two methods get_String and print_String. The
get_String accept a string from the user and print_String print the string in upper
case.
"""

class st:
    s = ""
    def get_String(self):
        self.s = input("Enter String : ")
    
    def print_String(self):
        print("Sting in Upper case : ", self.s.upper())

s = st()
s.get_String()
s.print_String()