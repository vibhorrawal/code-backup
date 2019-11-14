with open("text.txt",'r') as f:
    str = f.read()
str = str.upper()
out = ""
for word in str:
    if word.isalpha():
        out += word
    if word == '.' or word == ',' or word == ' ':
        out += word
print(out)
