#program to determine whether the given string unique characters or not

#method 1: Using a dictionary
#run-time: n (where n is the length of the string)
dic = {}
string = "string"
flag = 1
for char in string:
  if char not in dic:
    dic[char] = 1
  elif dic[char] == 1:
    dic[char]+=1
    print "Not Unique"
    flag = 0
print dic
if flag == 1:
  print "Unique"

#method 2: without using any data structure
#run-time: nlogn + n (where nlogn is used for sorting and n is the length of the string)
lis = list(string)
lis.sort()
lis = ''.join(lis)
print lis
f2 = 1
for i in range(0, len(lis)-1):
  if lis[i]==lis[i+1]:
    print"NOT UNIQUE"
    f2 = 0
if f2 == 1:
  print "Unique"  
