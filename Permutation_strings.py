#Function to decide if a string is a permutation of another string

def perm_strings(s1, s2):
  s1 = sorted(s1)
  s2 = sorted(s2)
  if s1 != s2: return False
  else: return True
  
s1 = "god"
s2 = "dogh"
print perm_strings(s1, s2)
