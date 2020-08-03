list1 = [1, 2, 3, 4]
list2 = list1
list2[0] = 10
print(list1)
print(list2)
print(id(list1))
print(id(list2))
