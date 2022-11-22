def secretagent():
    for i in range(3):
      password=input("Enter password:")
      if password=="secret007":
        print("Access Granted!")
        break
      else:
        print("Impostor...access denied!")
    
print("Welcome Secret agent...let's get started...")  
  #print("You have tried 3 times and failed. Goodbye forever!")

secretagent()