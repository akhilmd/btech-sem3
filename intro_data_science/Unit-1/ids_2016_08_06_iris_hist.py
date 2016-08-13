#!/usr/bin/env python3

import sys
sys.path.append("../..")

import matplotlib.pyplot as plt
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

labels = data_rows[0]
data_rows = data_rows[1:]

sl_data = list()
sw_data = list()
pl_data = list()
pw_data = list()
spe_data = list()

for sl,sw,pl,pw,spe in data_rows:
	sl_data.append(float(sl))
	sw_data.append(float(sw))
	pl_data.append(float(pl))
	pw_data.append(float(pw))
	spe_data.append(spe)

sl_data.sort()
sw_data.sort()
pl_data.sort()
pw_data.sort()
spe_data.sort()

cw = pycla.get_arg("cw")
if cw == None:
	cw=1
else:
	cw = float(cw)

# Four axes, returned as a 2-d array
f, axarr = plt.subplots(2, 2)
axarr[0, 0].hist(sl_data,np.arange(m.floor(min(sl_data)), m.ceil(max(sl_data)),cw))
axarr[0, 0].set_title('Sepal Length')
axarr[0, 1].hist(sw_data,np.arange(m.floor(min(sw_data)), m.ceil(max(sw_data)),cw))
axarr[0, 1].set_title('Sepal Width')
axarr[1, 0].hist(pl_data,np.arange(m.floor(min(pl_data)), m.ceil(max(pl_data)),cw))
axarr[1, 0].set_title('Petal Length')
axarr[1, 1].hist(pw_data,np.arange(m.floor(min(pw_data)), m.ceil(max(pw_data)),cw))
axarr[1, 1].set_title('Petal Width')

# plt.hist(sl_data)

outFile = pycla.get_arg("o")
if outFile == None:
	plt.show()
else:
	plt.savefig(outFile, bbox_inches="tight")
	print("Plot saved to "+outFile) 