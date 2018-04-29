# Goat Latin is a made-up language based off of English, sort of like Pig Latin. The rules of Goat Latin are as follows:
# 1. If a word begins with a consonant (i.e. not a vowel), remove the first letter and append it to the end, then add 'ma'.
# For example, the word 'goat' becomes 'oatgma'.
# 2. If a word begins with a vowel, append 'ma' to the end of the word.
# For example, the word 'I' becomes 'Ima'.
# 3. Add one letter "a" to the end of each word per its word index in
# the sentence, starting with 1.  That is, the first word gets "a" added
# to the end, the second word gets "aa" added to the end, the third word
# in the sentence gets "aaa" added to the end, and so on.
#

def goat_latin(sentence):
  vowels = ['a','e','i','o','u']
  new_sentence = []
  for word in sentence:
    fl = word[:1]
    if fl in vowels:
      nword = word+"ma"
      
    else:
      nword = word[1:] + fl + "ma"
      
    aa = 'a'*(sentence.index(word)+1)
    word = nword + aa
    new_sentence.append(word)
    
  print new_sentence

sentence = ["This", "is", "a", "goat"]
goat_latin(sentence)
