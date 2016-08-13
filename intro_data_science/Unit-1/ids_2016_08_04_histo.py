#!/usr/bin/env python3

import sys
sys.path.append("../..")

import matplotlib.pyplot as plt
import csv
import sys
import math as m
from modules import pycla

def error(msg):
		print("ERROR: "+msg+"\n\nUSAGE:\n$ "+sys.argv[0]+" <options>\n\nOPTIONS:")
		print("-i <file-name>\t: Input File (.csv).")
		print("-ig <num>\t: Ignore first num rows of data.")
		print("-o <file-name>\t: Output File (.png OR .pdf)")

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

#CHECK FOR CORRECT DATATYPE
try:
	float(list(data_rows)[0][0])
except ValueError:
	error("Invalid Dataytype!")
	exit()

data = [float(row[0])for row in data_rows]
plt.hist(data,range(m.floor(min(data)), m.ceil(max(data))))

outFile = pycla.get_arg("o")
if outFile == None:
	plt.show()
else:
	plt.savefig(outFile, bbox_inches="tight")
	print("Plot saved to "+outFile) 