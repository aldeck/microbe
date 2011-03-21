import microbe, re


class TextRange :
	start = 0
	end = 0
	color = 0
	def __init__(self, _start, _end, _color):
		start = _start
		end = _end
		color = _color
		
textRanges = []		

"""		
def func0(a):	
	print "python '" + a + "'"	
	print microbe.select(7, 12);
	return "yes"
	
def func00(text):
    regexp = re.compile('[^/]/\*(.|[\r\n])*?\*/')
    matches = regexp.finditer(text)
    for match in matches:
        microbe.select(match.start(), match.end())
        print "match", match.start(), match.end()
        
    return "ok"
"""
    
# textChanged
def func1(text):
    for range in textRanges:
        microbe.select(range.start, range.end, range.color)
       
    return "ok"    
    

