"""
List
"""

l = [1, 2, 3, 4]

print("Rev : ",l[::-1])

lCopy = l[:]

del l[1]        #Index
l.remove(1)     #Val

print("l : ",l)
l.insert(1, 2)  #Index, Val
print("Added 2 : ",l, " at index : ", l.index(2))

print("Concatenation : ",l+lCopy)

l.extend(lCopy)
print("Extended l : ", l)

"""
Tuples
"""
print()
t = (1,)        #if no comma -> int (only for t of len 1)
print(t+(2,3))

a, *b, c = (1, 2, 3, 4, 5, 6)
print("Unpacking mulitple : ",b)

"""
Dict
"""

print()
d = {(1,2):[1, 2, 3]}   #Key must be immuteable
print(d.keys())
print(d.values())

print(d.get("Uh"))      #Avoids KeyError and returns None
print(d.get("one", 1))  #Default arg, doesn't modify the dict

d.setdefault("five", 5) #Inserts only if key not present
d.setdefault("five", 6)
print("setdefault : ",d) 

d.update({"four":4})    #OR d["four"] = 4
del d[(1,2)]
print(d)

defaults = {'timeout': 10, 'retries': 3}
overrides = {'timeout': 30}

config = {**defaults, **overrides}
print("Depacking multiple : ", config)

"""
Sets
"""

print()
s = {(1,), 2, 3, 4, 5, 5}
s2 = {(1,), 4, 6, 9}
s.add(5)
s.add(6)

print(s, s2)
print("Intersection & : ", s & s2)
print("Union | & : ", s | s2)
print("Difference - : ", s - s2)
print("Symmetric Difference ^ : ", s ^ s2)
print("Is Super set of  >= : ", s >= s2)
print("Is Sub set of  <= : ", s <= s2)

sCopy = s.copy()

"""
File Handling
"""

print()
"""
# Reading
with open("myfile.txt") as f: 
    for line in f:
        print(line)
    contents = json.load(file)          # reads a json object

#Writing
contents = {"aa": 12, "bb": 21}
with open("myfile1.txt","w+") as file:
    file.write(str(contents))           #Writes a str

    file.write(json.dumps(contents))    #Writes an object to a file

"""

"""
Iterables

object that can be treated as a sequence.   i = d.keys()
cannot address these elements by index.     i[0] => TypeError

i = iter(d)

Next
next(i)             #Once exhausted -> raises StopIteration excpetion

"""


"""
Functions
"""

def add(x, y): 
    print("x is {} and y is {}".format(x, y))
    return x + y

def varargs(*args):             #Var num of pos args
    return args

def keyword_args(**kwargs):     #Var num of keyword args
    return kwargs

"""
Scope

Inside a fn
def setGlobalX(num):
    global x
    x = num
    print(x)


"""


"""
Anonymous fns / Lambda

(lambda x: x > 2)(3)                    # => True
(lambda x, y: x ** 2 + y ** 2)(2, 1)    # => 5

list(map(add_10, [1, 2, 3])) # => [11, 12, 13] 
list(map(max, [1, 2, 3], [4, 2, 1])) # => [4, 2, 3]
list(filter(lambda x: x > 5, [3, 4, 5, 6, 7]))
{x for x in 'abcddeef' if x not in 'abc'} # => {'d', 'e', 'f'}
"""

