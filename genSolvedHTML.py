import os
#[create an anchor](#anchors-in-markdown)

readme="""
* [Problem 1-50](#Problem-1)
* [Problem 50-100](#Problem-50)
* [Problem 101-150](#Problem-100)
* [Problem 151-200](#Problem-150)
---"""

for file in sorted(os.listdir("solved")):
    readme+="\n\n(###Problem-"+file.replace(".c","")+")\n\n"
    readme+=open("solved/"+file).read().split("*/")[0].replace("/*","")

f=open("solved/README.md","w")
f.write(readme)
f.close()