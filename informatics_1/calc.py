stack = []
for element in input().split():
    if element in "+*-":
        a = stack[-2]
        b = stack[-1]
        # print(stack[-1])
        # print(stack[-2])
        stack.pop()
        stack.pop()
        if element == '+':
            result = a + b
        elif element == '-':
            result = a - b
        elif element == '*':
            result = a * b
        stack.append(result)
    else:
        stack.append(int(element))
print(stack[0])
