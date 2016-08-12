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
spe_dict = {'virginica':0, 'setosa':1, 'versicolor':2};
para_dict = {0:'Sepal Length', 1:'Sepal Width', 2:'Petal Length', 3:'Petal Width'}

sl_data = [[], [], []]
sw_data = [[], [], []]
pl_data = [[], [], []]
pw_data = [[], [], []]
spe_data = [[], [], []]

for sl,sw,pl,pw,spe in data_rows:
	
	sl_data[spe_dict[spe]].append(float(sl))
	sw_data[spe_dict[spe]].append(float(sw))
	pl_data[spe_dict[spe]].append(float(pl))
	pw_data[spe_dict[spe]].append(float(pw))
	spe_data.append(spe)

#sl_data.sort()
#sw_data.sort()
#pl_data.sort()
#pw_data.sort()
#spe_data.sort()

full_data = [sl_data, sw_data, pl_data, pw_data]
print(full_data)

cw = pycla.get_arg("cw")
if cw == None:
	cw=1
else:
	cw = float(cw)

# Four axes, returned as a 2-d array
f, axarr = plt.subplots(3, 2)

for i in range(3):
	for j in range(2):
		axarr[i, j].scatter(full_data[j*2][i], full_data[j*2+1][i], color = ['red', 'blue'], alpha = .75)
		axarr[i, j].set_xlabel(para_dict[j*2])
		axarr[i, j].set_ylabel(para_dict[j*2+1])
		axarr[i, j].set_title(spe_dict.keys()[spe_dict.values().index(i)])
		
	


#for i in range(3):
#	for j in range(0,4,2):
#		axarr[i, j].scatter(full_data[j][i], full_data[j+1][i])
#		axarr[i, j].set_title(para_dict[j] + ' of ' + spe_dict.keys()[spe_dict.values().index(i)])
# plt.hist(sl_data)

outFile = pycla.get_arg("o")
if outFile == None:
	plt.tight_layout()
	plt.show()
else:
	plt.savefig(outFile, bbox_inches="tight")
	print("Plot saved to "+outFile) 
