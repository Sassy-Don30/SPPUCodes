def InputData(Set):
    num = int(input("Enter number of elements in set:"))
    for i in range(num):
        stu = int(input("Enter roll number:"))
        Set.append(stu)


def Intersection(set1, set2):
    intersectionSet = []
    for i in set1:
        for j in set2:
            if i == j:
                intersectionSet.append(i)
    return intersectionSet


def Union(set1, set2):
    unionSet = []
    for i in range(len(set1)):
        unionSet.append(set1[i])
    for i in set2:
        if i not in unionSet:
            unionSet.append(i)
    return unionSet


def Difference(set1, set2):
    diffSet = []
    for i in set1:
        if i not in set2:
            diffSet.append(i)
    return diffSet


print("Enter data regarding cricket players.")
cricketPlayers = []
InputData(cricketPlayers)

print("Enter data regarding badminton players.")
badmintonPlayers = []
InputData(badmintonPlayers)

print("Enter data regarding football players.")
footballPlayers = []
InputData(footballPlayers)

while True:
    print("1.List of students who play both cricket and badminton \n2.List of players who play cricket and badminton "
          "but not both \n3.Number of students who play neither cricket nor badminton \n4.Number of students who play "
          "cricket and football but not badminton \n5.Exit")
    choice = int(input("Enter choice:"))
    if choice == 1:
        print(Intersection(cricketPlayers, badmintonPlayers))
    elif choice == 2:
        x = Union(cricketPlayers, badmintonPlayers)
        y = Intersection(cricketPlayers, badmintonPlayers)
        print(Difference(x, y))
    elif choice == 3:
        x = Intersection(footballPlayers, cricketPlayers)
        y = Difference(footballPlayers, x)
        z = Intersection(footballPlayers, badmintonPlayers)
        w = Difference(y, z)
        print(len(y))
    elif choice == 4:
        x = Union(cricketPlayers, footballPlayers)
        y = Difference(x, badmintonPlayers)
        print(len(y))
    elif choice == 5:
        print("Byeeee")
        break
