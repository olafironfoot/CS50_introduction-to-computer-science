import cs50
from student import Student     #from file import class

students = []
for i in range(3):

    print("name: ", end="")
    name = cs50.get_string()

    print("dorm: ", end="")
    dorm = cs50.get_string()

    #refering to object(aka variable) "students" as per line 4's "students" array(aka "list", in python). 
    #append into it, a class(aka struct) named Student(know as Objects also?.. see week 8 lecture 1:24min)
    #which has variables(strings), "name" and "dorm" as per student.py file.
    students.append(Student(name, dorm))    

#iterate over each element in list students, calling each element, 
#temporarily "student" as per line 20, character 33 & 47   
for student in students:
    print("{} is in {}.".format(student.name, student.dorm))

#erik's own note, see under workspace/test/x_In_ex_test.py for own explaination