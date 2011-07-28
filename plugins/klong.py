#
# Copyright 2011, Alexandre Deckner (alex@zappotek.com)
# Distributed under the terms of the MIT License.
#

from clang.cindex import Index, CursorKind
import microbe, re
from pprint import *

#def func1(text):
#    return "ok"

def get_cursor_id(cursor, cursor_list = []):
    #if not opts.showIDs:
    #    return None

    if cursor is None:
        return None

    # FIXME: This is really slow. It would be nice if the index API exposed
    # something that let us hash cursors.
    for i,c in enumerate(cursor_list):
        if cursor == c:
            return i
    cursor_list.append(cursor)
    return len(cursor_list) - 1

def get_info(node, depth=0):
    #if opts.maxDepth is not None and depth >= opts.maxDepth:
    #    children = None
    #else:
    children = [get_info(c, depth+1)
                for c in node.get_children()]
    
    return { 'id' : get_cursor_id(node),
             'kind' : node.kind,
             'usr' : node.get_usr(),
             'spelling' : node.spelling,
             'location' : node.location,
             'extent.start' : node.extent.start,
             'extent.end' : node.extent.end,
             'is_definition' : node.is_definition(),
             'definition id' : get_cursor_id(node.get_definition()),
             'children' : children }

def func1(text):
    index = Index.create()
    tu = index.parse('t.c', unsaved_files = [('t.c', text)])
    
    # Skip until past start_decl.
    it = tu.cursor.get_children()
    while it.next().spelling != 'start_decl':
        pass

    tu_nodes = list(it)
    
    for n in tu_nodes:
    	info = get_info(n)
        pprint(info)
        #microbe.select(info.extent.start, info.exten.end, range.color)
	
    return "ok"
