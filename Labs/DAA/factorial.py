def factorial(n):
    if n == 1:
        return 1
    return n * factorial(n-1)

fac = factorial(50)
print(fac)

