import cs50

while True:
    #ask user for a height
    print("height:")
    h = cs50.get_int()

    if h > 23 or h < 0:
        print("Retry:")
    
    else:
        for i in range(h):
            #print number of spaces
            print(" " * (h - 1 - i), end="")
            #print number of "#"
            print("#" * (h - (h-i) + 2), end="")
            #print next row
            print()
            #be nice and exit
        exit(0)