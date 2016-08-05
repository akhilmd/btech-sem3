#!/usr/bin/env python3

import sys

def get_arg(op_chr = None):
	if op_chr == None:
		return [sys.argv[i] for i in range(1,len(sys.argv)) if sys.argv[i].startswith("-")==False and sys.argv[i-1].startswith("-")==False]

	try:
		val = sys.argv[sys.argv.index("-"+op_chr)+1]
		return val
	except ValueError:
		return None

if __name__ == "__main__":
	print("-i =",get_arg("i"))
	print("-o =",get_arg("o"))
	print("   =",get_arg())