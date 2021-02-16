import os

# print(os.getcwd())
# print(os)
# print(__file__ + "\n")
# full_path = os.path.realpath(__file__)
# print(full_path)
# # print(os.listdir())
#
# import glob
#
# files = glob.glob(os.getcwd() + '/**/*.cc', recursive=True)
# print(len(files))


path = os.getcwd()
rank = dict()
print(path)

for root, dirs, files in os.walk(path):
    if(root == path):
        continue
    rel = root.replace(path + '/', "")
    cc = [file for file in files if file.endswith(".cc")]
    folder = ""
    for s in rel.split("/"):
        folder += s + '/'
        if rank.get(folder) is None:
            rank[folder] = len(cc)
        else:
            rank[folder] = len(cc) + rank.get(folder)

rank
# print(rank)

for f, c in rank.items():
    folder = f.split('/')
    for _ in range(len(folder)):
        print('----', end="")

    print(folder[-2], c)
