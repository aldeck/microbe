#
# Copyright 2011, Alexandre Deckner (alex@zappotek.com)
# Distributed under the terms of the MIT License.
#

f = open('tags', 'r')

for line in f:
    #print line

    row = line[0:-1].split('\t')
    #print row
    parse = False
    elems = []
    for elem in row:
        if parse == False and elem.find('/^') != -1:
            parse = True

        if not parse:
        	elems.append(elem)
            #print elem

        if parse == True and elem.find('$/;"') != -1:
            parse = False

    print elems


    #if tagline[0].find('!_TAG_') == -1:
    #   print tagline[] + " : " + tagline[0]
