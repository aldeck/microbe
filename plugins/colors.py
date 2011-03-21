import microbe, re


class TextRange :
	def __init__(self, start, end, color):
		self.start = start
		self.end = end
		self.color = color
		
textRanges = []
textRanges.append(TextRange(5, 7, 1));
textRanges.append(TextRange(33, 78, 2));
textRanges.append(TextRange(55, 65, 3));
textRanges.append(TextRange(200, 300, 4));
    
# textChanged
def func1(text):
    for range in textRanges:
    	#print "colors: select", range.start, range.end, range.color
        microbe.select(range.start, range.end, range.color)
       
    return "ok"    
    

