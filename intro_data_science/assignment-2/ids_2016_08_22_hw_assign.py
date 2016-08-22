#!/usr/bin/env python3

import sys
sys.path.append("../..")

import matplotlib.pyplot as plt
import math as m
import pandas as pd

from modules import pycla

def error(msg):
        print("ERROR: "+msg+"\n\nUSAGE:\n$ "+sys.argv[0]+" <options>\n\nOPTIONS:")
        print("-i <file-name>\t: Input File (.csv).")
        print("-rep <boolean>\t: true for replacement, false for no replcement.")
        print("-col <column-name>\t: height or weight.")
        print("-bw <num>\t: Width of bar(float). The distance between bars is 0.1.")
        print("-o <file-name>\t: Output File (.png OR .pdf)")

def getRange(data):
    return "[{:.5f}, {:.5f}]".format(min(data),max(data))

def printHeightWeightFeatures(dataFrame, isPrint=False):
    dataDict = {
        "height":{
            "mean" : dataFrame.mean()["height"],
            "median" : dataFrame.median()["height"],
            "variance" : dataFrame.var()["height"],
            "std_dev" : dataFrame.std()["height"],
            "range" : getRange(dataFrame["height"]),
            "iqr" : dataFrame.quantile(0.75)["height"] - dataFrame.quantile(0.25)["height"]
        },
        "weight":{
            "mean" : dataFrame.mean()["weight"],
            "median" : dataFrame.median()["weight"],
            "variance" : dataFrame.var()["weight"],
            "std_dev" : dataFrame.std()["weight"],
            "range" : getRange(dataFrame["weight"]),
            "iqr" : dataFrame.quantile(0.75)["weight"] - dataFrame.quantile(0.25)["weight"]
        }
    }

    if isPrint == True:
        print("mean height =",dataDict["height"]["mean"])
        print("mean weight =",dataDict["weight"]["mean"])
        print("median height =",dataDict["height"]["median"])
        print("median weight =",dataDict["weight"]["median"])
        print("variance in height =",dataDict["height"]["variance"])
        print("variance in weight =",dataDict["weight"]["variance"])
        print("standard deviation in height =",dataDict["height"]["std_dev"])
        print("standard deviation in weight =",dataDict["weight"]["std_dev"])
        print("range of height values =",dataDict["height"]["range"])
        print("range of weight values =",dataDict["weight"]["range"])
        print("interquartile range of height = ", dataDict["height"]["iqr"])
        print("interquartile range of weight = ", dataDict["weight"]["iqr"])
        print()

    return dataDict

inFile = pycla.get_arg("i")
if inFile == None:
	error("No Input CSV File!")
	exit()

rep = pycla.get_arg("rep")
if rep.lower() == "false":
	rep = False
elif rep.lower() == "true":
	rep = True
else:
	rep = False 

isWith = "without"
if rep == True:
    isWith = "with"

dataFrame = pd.read_csv(inFile)

data = dict()

print("Full Dataset")
data[25000] = printHeightWeightFeatures(dataFrame, isPrint=False)
print("1000 Random Samples {0} repitition".format(isWith))
data[1000] = printHeightWeightFeatures(dataFrame.sample(n=1000,replace=rep), isPrint=False)
print("2000 Random Samples {0} repitition".format(isWith))
data[2000] = printHeightWeightFeatures(dataFrame.sample(n=2000,replace=rep), isPrint=False)
print("3000 Random Samples {0} repitition".format(isWith))
data[3000] = printHeightWeightFeatures(dataFrame.sample(n=3000,replace=rep), isPrint=False)

graphs = ["mean","median","variance","std_dev", "iqr"]
xlabels = [1000,2000,3000,25000]

f, axarr = plt.subplots(2, 3)
plt.tight_layout()

barWidth = pycla.get_arg("bw")
if barWidth == None:
    barWidth = 0.8
else:
    barWidth = float(barWidth)

xlefts = [i*(barWidth+0.1) for i in range(len(xlabels))]
xLabelLefts = [i+(barWidth/2)for i in xlefts]
i=0
j=0

col=pycla.get_arg("col")
if col == None or col not in ["weight","height"]:
    col = "weight"

for typ in graphs:
    axarr[i,j].bar(left=xlefts,height=[data[1000][col][typ],data[2000][col][typ],data[3000][col][typ],data[25000][col][typ]], width=barWidth)
    axarr[i,j].set_xticks(xLabelLefts)
    axarr[i,j].set_xticklabels(xlabels)
    axarr[i,j].set_title(typ+" - "+col)
    i+=1
    if i==2:
        i=0
        j+=1

axarr[1,2].set_visible(False)

outFile = pycla.get_arg("o")
if outFile == None:
	plt.show()
else:
	plt.savefig(outFile, bbox_inches="tight")
	print("Plot saved to "+outFile) 