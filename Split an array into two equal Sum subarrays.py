def split_array(nums):
  l = len(nums)
  print sum(nums)
  s = sum(nums)
  half = s/2
  breakpoint = None
  
  for i in nums:
    s = s-i
    if s == half:
      breakpoint = nums.index(i)
      break
  
  if breakpoint == None:
    print "Not Possible"
  
  else:
    
    first_half = nums[:breakpoint+1]
    second_half = nums[breakpoint+1:]
    print first_half
    print second_half
  


nums = [2,3,5]
split_array(nums)
