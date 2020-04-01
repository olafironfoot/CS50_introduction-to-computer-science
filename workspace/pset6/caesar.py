import cs50
import sys
#variables

success = False
#ensure there's key during cmd line from user
while success == False:
    
    if len(sys.argv) != 2:
        print("please enter a ...key..")
        exit(0)
    
    else:
        key = int(sys.argv[1])
        success = True

print("plaintext:")
userSecretMessage = cs50.get_string()

print("ciphertext:")
for char in userSecretMessage:
    if str.isalpha(char):
        # print("{}".format(char))
        if str.islower(char):
            char = chr(((ord(char) - ord('a') + key) % 26) + ord('a'))
            print("{}".format(char), end="")
        else:
            char = chr(((ord(char) - ord('A') + key) % 26) + ord('A'))
            print("{}".format(char), end="")
    else:
        print("{}".format(char), end="")
print()
exit(0)


#get secret message
#scramble message
#print scrambled message