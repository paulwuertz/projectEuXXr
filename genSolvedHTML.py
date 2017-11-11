import os

readme="""
* [Problem 1-50](#problem-1)
* [Problem 50-100](#problem-50)
* [Problem 101-150](#problem-100)
* [Problem 151-200](#problem-150)

---"""

def numSort(a):
    try:
        a=a.replace(".c","")
        return int(a)
    except Exception: return -1

for file in sorted(os.listdir("solved"),key=numSort):
    print(file)
    if file!="README.md":
        readme+="\n\n### Problem-"+file.replace(".c","")+"\n\n"
        readme+=open("solved/"+file).read().split("*/")[0].replace("/*","")+"\n\n---"

f=open("solved/README.md","w")
f.write(readme)
f.close()