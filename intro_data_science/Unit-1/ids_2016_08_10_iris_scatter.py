#!/usr/bin/env python3

import sys
sys.path.append("../..")

import matplotlib.pyplot as plt
import matplotlib.patches as mpatches
import csv
import sys
import math as m
from modules import pycla
import numpy as np

def error(msg):
		print("ERROR: "+msg+"\n\nUSAGE:\n$ "+sys.argv[0]+" <options>\n\nOPTIONS:")
		print("-i <file-name>\t: Input File (.csv).")
		print("-ig <num>\t: Ignore first num rows of data.")
		print("-o <file-name>\t: Output File (.png OR .pdf)")
		print("-x <op>\t: Feature to plot on x-axis (pl,pw,sw,sl)")
		print("-y <op>\t: Feature to plot on y-axis (pl,pw,sw,sl)")

#READ CSV FILE
inFile = pycla.get_arg("i")
if inFile == None:
	error("No Input CSV File!")
	exit()
csv_fil = open(inFile)
data_rows = csv.reader(csv_fil)

#IGNORE FIRST ig LINES
ig = pycla.get_arg("ig")
if ig==None:
	ig = 0
else:
	ig = int(ig)
data_rows = list(data_rows)[ig:]

data = {"virginica":{"sl":[],"sw":[],"pl":[],"pw":[]},"setosa":{"sl":[],"sw":[],"pl":[],"pw":[]},"versicolor":{"sl":[],"sw":[],"pl":[],"pw":[]},}

for row in data_rows:
	data[row[-1]]["sl"].append(float(row[0]))
	data[row[-1]]["sw"].append(float(row[1]))
	data[row[-1]]["pl"].append(float(row[2]))
	data[row[-1]]["pw"].append(float(row[3]))

print(data)

x = pycla.get_arg("x")
if x == None or x not in ["pl","pw","sl","sw"]:
	x = "pl"
else:
	x = str(x).strip()

y = pycla.get_arg("y")
if y == None or y not in ["pl","pw","sl","sw"]:
	y = "pw"
else:
	y = str(y).strip()

red_patch = mpatches.Patch(color=(1,0,0,0.75), label='Versicolor')
green_patch = mpatches.Patch(color=(0,1,0,0.75), label='Setosa')
blue_patch = mpatches.Patch(color=(0,0,1,0.75), label='Virginica')

plt.scatter(data["virginica"][x],data["virginica"][y],color=(0,0,1,0.75))
plt.scatter(data["setosa"][x],data["setosa"][y],color=(0,1,0,0.75))
plt.scatter(data["versicolor"][x],data["versicolor"][y],color=(1,0,0,0.75))

plt.legend(handles=[red_patch,green_patch,blue_patch])

if x == "sw":
	plt.xlabel("Sepal Width")
elif x=="sl":
	plt.xlabel("Sepal Length")
elif x=="pl":
	plt.xlabel("Petal Length")
elif x=="pw":
	plt.xlabel("Petal Width")


if y == "sw":
	plt.ylabel("Sepal Width")
elif y=="sl":
	plt.ylabel("Sepal Length")
elif y=="pl":
	plt.ylabel("Petal Length")
elif y=="pw":
	plt.ylabel("Petal Width")

outFile = pycla.get_arg("o")
if outFile == None:
	plt.tight_layout()
	plt.show()
else:
	plt.savefig(outFile, bbox_inches="tight")
	print("Plot saved to "+outFile) 
