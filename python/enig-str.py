with open("text.txt",'r') as f:
    str = f.read()
str = str.upper()
out = ""
for word in str:
    if word.isalpha():
        out += word
    if word == ' ':
        out += 'XX'
    if word == ',':
        out += 'XNX'
    if word == '.':
        out += 'XPX'
print(out)
