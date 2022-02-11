import csv
rows = []

with open('/Users/vibhorrawal/Downloads/input.csv', 'r') as fin :
    csvreader = csv.reader(fin)
    header = next(csvreader)
    for row in csvreader:
        rows.append(row)

users = sorted({row[0] for row in rows})
fruits = sorted({row[1] for row in rows})

records = {}
for user in users:
    records[user] = {}
    for fruit in fruits:
        records[user][fruit] = 0

for row in rows:
    user, fruit = row
    records[user][fruit] += 1

header = ['Name']
for fruit in fruits:
    header.append(fruit)

rows = []
for user in users:
    userRow = [user]
    for fruit in fruits:
        userRow.append(records[user][fruit])
    rows.append(userRow)

with open('output.csv', 'w') as outfile:
    outfile.write(','.join(header))
    outfile.write('\n')
    for row in rows:
        outfile.write(', '.join([str(element) for element in row]))
        outfile.write('\n')
