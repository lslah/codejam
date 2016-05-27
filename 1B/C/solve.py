import sys
import networkx as nx
from networkx.algorithms import bipartite

def solve(lines):
    G = nx.Graph()
    for line in lines:
        words = line.split(" ")
        G.add_edge(words[0]+'L', words[1]+'R')
    matching = nx.bipartite.maximum_matching(G)
    count = 0
    words = [line.split(" ") for line in lines]
    lwords = set([word[0]+'L' for word in words])
    rwords = set([word[1]+'R' for word in words])
    for word in lwords:
        if not matching.has_key(word):
            count += 1
    for word in rwords:
        if not matching.has_key(word):
            count += 1
    return len(lines) - (count + len(matching)/2)

def main():
    text = sys.stdin.readlines()
    text = [line[:-1] for line in text]
    T = int(text[0])
    r = 1
    for i in range(T):
        L = int(text[r])
        res = solve(text[r+1:r+L+1])
        print("Case #%d: %d" % (i+1, res))
        r = r+L+1

if __name__ == '__main__':
    main()
