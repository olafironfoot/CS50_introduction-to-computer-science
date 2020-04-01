from x import X     #so line 18 is declared and knows where to look

#create list
xs = []

#define variables
name = 0
dorm = 0

#for loop , 3 iterations
for i in range(3):
    #stores value in name and dorm variables
    name += 1
    dorm += 2
    
    #append into list xs, class/struct X, which contains name and dorm
    #this creates a space pointed to in file "x.py", to remember name and dorm in memory
    xs.append(X(name, dorm))    #for i-th in the list xs,append X(name, dorm)
    
#iterate over each element in list xs, calling each element, temporarily "x"    
#just like saying "i" in range(3).
for i in xs:    #for(i = 0; i < number; i++) --> for i in, list[number], print "1.name", "2.name", "3.name", "1.dorm", "2.dorm", "3.dorm"
    #print the following
    print("{} is in {}.".format(i.name, i.dorm))    #calling i-th .name and .dorm of that list
    #alternatively can print hello
    print("hello")
    