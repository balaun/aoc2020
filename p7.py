# Advent of Code 2020: day 7
# by Matt Balaun, balaun@gmail.com

class Bag:
	color=""
	contains=[]

	def __init__(self, color):
		self.color=color
		self.contains=[]
	
input = open('day7input', 'r')
lines = input.readlines()

bags = set() #create empty set for holding bags as created

count = 0
for line in lines:
	#print("Line{}: {}".format(count, line.strip()))
	count+=1
	fields=line.split()
	#print(fields)
	b = Bag(fields[0] + " " + fields[1])
	#print(b.color)
	if (fields[4] != "no"):
		qty = int(fields[4])
		while (qty > 0):
			b.contains.append(fields[5] + " " + fields[6])
			#print("\t" + fields[5] + " " + fields[6])
			qty -= 1
		if (len(fields) > 8):
			qty = int(fields[8])
			while (qty > 0):
				b.contains.append(fields[9] + " " + fields[10])
				#print("\t" + fields[9] + " " + fields[10])
				qty -= 1
			if (len(fields) > 12):
				qty = int(fields[12])
				while (qty > 0):
					b.contains.append(fields[13] + " " + fields[14])
					#print("\t" + fields[13] + " " + fields[14])
					qty -= 1
				if (len(fields) > 16):
					qty = int(fields[16])
					while (qty > 0):
						b.contains.append(fields[17] + " " + fields[18])
						#print("\t" + fields[17] + " " + fields[18])
						qty -= 1
					if (len(fields) > 20):
						print("OOPS! ERROR! EXPAND ANOTHER LEVEL!")

	bags.add(b)
	#print(b.color)
	#print(b.contains)


# at this point we have a set of Bag objects, each of which knows it's own color and what other colors it contains (and their quantity, sort of).

target=["shiny gold"]#we want to encase this color in at least one other bag

encasers = set() #empty set for colors that can hold our target

added=1
while (added):
	added = 0
	for t in target:
		for b in bags:
			if ((t in b.contains) and (not(b.color in encasers))):
				added = 1
				encasers.add(b.color)
				print(t + " can be contained by " + b.color)
				if not(b.color in target):
					target.append(b.color)
		target.remove(t)

print(encasers)
print(len(encasers))


