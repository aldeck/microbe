#!/usr/bin/env python

#
# Copyright 2011, Alexandre Deckner (alex@zappotek.com)
# Distributed under the terms of the MIT License.
#

## Copyright (C) 2008 Ben Smith <benjamin.coder.smith@gmail.com>

##    This file is part of pyctags.

##    pyctags is free software: you can redistribute it and/or modify
##    it under the terms of the GNU Lesser General Public License as published
##    by the Free Software Foundation, either version 3 of the License, or
##    (at your option) any later version.

##    pyctags is distributed in the hope that it will be useful,
##    but WITHOUT ANY WARRANTY; without even the implied warranty of
##    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
##    GNU General Public License for more details.

##    You should have received a copy of the GNU Lesser General Public License
##    and the GNU Lesser General Public Licens along with pyctags.  If not,
##    see <http://www.gnu.org/licenses/>.


import sys

from pyctags import exuberant_ctags, ctags_file
from pyctags.harvesters import name_lookup_harvester, by_name_harvester
import os

source_files = list()

for (dirpath, dirs, files) in os.walk("/Big2/microbe/"):
    for f in files:
        if f[-4:] == '.cpp' or f[-2:] == ".h" :
            source_files.append(os.path.join(dirpath, f))

generator = exuberant_ctags(files=source_files)
list_o_tags = generator.generate_tags(generator_options={'--fields' : '+n'})



names = name_lookup_harvester()
by_name = by_name_harvester()
tagfile = ctags_file(list_o_tags, harvesters=[names, by_name])

print ("Found %d tags in %d source files." % (len(tagfile.tags), len(source_files)))



import microbe, re

regexs = {}
for tag in tagfile.tags:
	#print tag.name, tag.line_number, tag.extensions['kind']
	#print tag.name + "####" + tag.extensions['kind']
	regexs[tag.name + "####" + tag.extensions['kind']] = re.compile(tag.name)




def func1(text):

    for name, regexp in regexs.items():
        matches = regexp.finditer(text)
        colors = { 'm' : 1, 'f' : 2, 's' : 3, 'c' : 4, 't' : 5, 'v' : 6 , 'd' : 7}
        for match in matches:
            microbe.select(match.start(), match.end(), colors[name.split('####')[1]])
            #print "match", match.start(), match.end()

    return "ok"

