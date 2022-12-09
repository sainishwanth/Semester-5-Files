from tkinter import *
from tkinter import ttk
import random

#global variables
weights = []
profits = []
n = 0
Max_W = 0
Max_P = 0
ref = []
check = 0
def knapSack(profits, weights, W, n):
    K = [[0 for x in range(W + 1)] for x in range(n + 1)]
    for i in range(n + 1):
        for w in range(W + 1):
            if i == 0 or w == 0:
                K[i][w] = 0
            elif weights[i-1] <= w:
                K[i][w] = max(profits[i-1] + K[i-1][w-weights[i-1]],  K[i-1][w])
            else:
                K[i][w] = K[i-1][w]
  
    return K[n][W]

def Random_Assignment():
    global weights, profits, n, Max_W
    n = 15

    weights = []
    profits = []

    mul = random.randint(2,5)
    for i in range(n):
        profits.append(random.randint(2,6)*mul)
        random.seed = random.randint(900,40000)
        mul = random.randint(2,5)
        weights.append(random.randint(1,5)*mul)

    Max_W = random.randint(20,100)
    if not (Max_W < sum(weights)):
        while Max_W < sum(weights):
            Max_W = random.randint(20,100)

def open_popup(tk_Window, txt):
   top = Toplevel(tk_Window)
   top.geometry("400x150")
   top.title("Error!")
   Label(top, text= txt, font=('Mistral 18 bold')).pack()
   return

def verifyCheck(Str: StringVar, tk_Window):
    global Max_P
    
    if Str.get() == '':
        open_popup(tk_Window, "Field's Cannot Be Empty!")
        return
    try:
        int(Str.get())
    except:
        open_popup(tk_Window, "Please enter an interger value")
        return
    if int(Str.get()) == Max_P:
        open_popup(tk_Window, "Correct!")
    else:
        open_popup(tk_Window, "Wrong!")
def main():
    global profits, weights, Max_W, n, ref, check, Max_P
    Random_Assignment()
    Max_P = knapSack(profits, weights, Max_W, n)
    print(Max_P)
    print(profits)
    print(weights)
    mainWindow = Tk()
    mainWindow.geometry("750x450")
    mainWindow.title("knapSack Game")
    row = 0
    col = 1
    for i in range(n):
        if i == 1:
            col = 1
        if i == 5:
            row = 0
            col = 2
        if i == 10:
            row = 0
            col = 3
        p = profits[i]
        w = weights[i]
        btn = Button(mainWindow, text=f"Profits-{p}\nWeights-{w}", font=('Fira Code', 20), background="red")
        row += 1
        btn.grid(row = row, column= col,  padx=5)
        ref.append(btn)
    Str = StringVar()
    l = Label(mainWindow, text="Enter the Max Profit", font=('Fira Code', 30))
    l.grid(column=2, row=10)
    Str = StringVar()
    e = Entry(mainWindow, textvariable=Str)
    e.grid(column=2, row=11)
    btn_submit = Button(mainWindow, text="Submit", font=('Fira Code', 15), command=lambda: verifyCheck(Str, mainWindow))
    btn_submit.grid(column=2, row=12)
    mainWindow.mainloop()
if __name__ == "__main__":
    main()