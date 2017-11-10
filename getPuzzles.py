import sys
from urllib.request import urlopen
from bs4 import BeautifulSoup
import html2text

url="https://projecteuler.net/problem="

fr=int(sys.argv[1])
to=int(sys.argv[2])

print(fr,to)

for pr in range(fr,to+1):
    response = urlopen(url+str(pr))
    html = response.read()
    soup = BeautifulSoup(html,"lxml")
    pzHTML=soup.find_all("div", class_="problem_content");
    
    f=open("unsolved/"+str(pr)+".c","w")
    f.write("/*")
    f.write(html2text.html2text(str(pzHTML[0]).strip()))
    f.write("*/")

    f.write("""
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

int main(int argc, char const *argv[]){
    long int a = atoi(argv[1]);
    return 0;
}
    """)
