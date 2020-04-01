import cs50

#if user enter below 0, prompt again
change = -1

#ask for how much change user needs
while change < 0:
    print("O hai! How much change is owed?")
    change = cs50.get_float()
    
#change float to whole numbers
change = change * 100
change = int(change)

#coincounter
coincounter = 0

#minue each coin of the interger off the input number
while change >= 25:
    change = change - 25
    coincounter += 1
    
while change >= 10:
    change = change - 10
    coincounter += 1

while change >= 5:
    change = change - 5
    coincounter += 1
    
while change >= 1:
    change = change - 1
    coincounter += 1
    
for coincounter in range(change):
    change = change - 25
    coincounter += 1
    
#print number on coin counter
print("{} is the optimal number of coins to be returned".format(coincounter))