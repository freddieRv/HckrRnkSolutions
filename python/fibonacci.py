def fibonacci(n):
    if n in [0, 1]:
        return n
    else:
        return fibonacci(n - 1) + fibonacci(n - 2)



n = int(input())
print(fibonacci(n))
