import argparse
parser = argparse.ArgumentParser()
parser.add_argument("-d","--distance",help="Add the set distance")
parser.add_argument("-t","--turning",help="Add the turning delay")
args = parser.parse_args()
print("Hello!")
print("Here are your args: " + str(args.distance) + " and " + str(args.turning))
dist = args.distance
turn = args.turning

print(int(turn) + int(dist))
    
